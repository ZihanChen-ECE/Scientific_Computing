#include <iostream>
#include <rarray>
int output(rarray<double,2> number_of_ants,float totants, int m, int t)
{
//Out put the timestep and number of ants.
	float sum = totants;
        for (int i=0;i<m;i++) {
            for (int j=0;j<m;j++) {
                sum += number_of_ants[i][j];
            }
        }
        std::cout << t<< " " << sum << std::endl;
	return 0;
}
