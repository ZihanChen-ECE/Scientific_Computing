#define BOOST_TEST_MODULE TestTimestep
#include <boost/test/included/unit_test.hpp>
//#include <boost/test/unit_test.hpp>
#include <rarray>
#include <rarrayio>
#include <cmath>
#include "ant.h"

//BOOST_AUTO_TEST_SUITE(TestTimestep)
BOOST_AUTO_TEST_CASE(TestTimestep)
{
	// ants walk on a table
	const int m = 356;
	rarray<double,2> number_of_ants(m,m);
	rarray<double,2> new_number_of_ants(m,m);
	rarray<double,2> velocity_of_ants(m,m);
	const int total_ants = 1010;// initial number of ants
	
	//const variables
	const float c1 = 1.9;
	const float c2 = 0.8;
	const float c3 = 0.2;
	float tants = 0;
	const float ra = total_ants;	

	for (int i=0;i<m;i++) {
        for (int j=0;j<m;j++) {
            velocity_of_ants[i][j] = M_PI*(sin((2*M_PI*(i+j))/3560)+1);
        }}

	float z = 0;
	int n = 0;
	number_of_ants.fill(0.0);
	while (n < total_ants){
        for (int i=0;i<m;i++){
            for (int j=0;j<m;j++){
                    z += sin(0.3*(i+j));
                    if (z>1 and n!=total_ants){
                	    number_of_ants[i][j] += 1;
                	    n += 1;}}}}
	
	tants = timestep(number_of_ants, new_number_of_ants, velocity_of_ants, c1, c2, c3, m);	
	std::cout<<tants<<std::endl;
	BOOST_CHECK(tants < ra);
	BOOST_REQUIRE(tants < ra);
	if(tants > ra||tants == ra) BOOST_ERROR("Ouch...");
	if(tants > ra||tants == ra) BOOST_FAIL("Ouch...");
	BOOST_CHECK_MESSAGE(tants < ra, "msg...");
	//BOOST_CHECK_EQUAL(tants,ra);
}

//BOOST_AUTO_TEST_SUITE_END()
