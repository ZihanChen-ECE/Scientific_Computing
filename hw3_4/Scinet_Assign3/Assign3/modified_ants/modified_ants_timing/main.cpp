#include <rarray>
#include <rarrayio>
#include "ant.h"
#include "ticktock.h"
#include "output.h"

int main()
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
	// define a stopwatch timer:
        TickTock stopwatch;
	
	// start timer:
        //stopwatch.tick();

		initial(number_of_ants,  velocity_of_ants, total_ants, m);//initial condition
	
	// measure time and save elapsed time
        //double calctime = stopwatch.silent_tock();
        // time output as well:
        //stopwatch.tick();
        // Stop and print out all timings
        //std::cout << "Timing summary:" << std::endl;
        //std::cout << "#Initialization took:\t" << calctime << " sec" << std::endl;
        //stopwatch.tock("#Report took:     "); // this combines the elapsed time measurement and output


	float caltime1 = 0.0;
	float caltime2 = 0.0;
	float temp1 = 0.0;
	float temp2 = 0.0;
	
		for (int t = 0; t < 40; t++) 
		{
		
	// start timer:
        stopwatch.tick();

		float totants = 0.0;
		output(number_of_ants, totants, m, t);

	temp1 = stopwatch.silent_tock();
	caltime1+=temp1;

	stopwatch.tick();
		timestep(number_of_ants, new_number_of_ants, velocity_of_ants, c1, c2, c3, m);//record the timestep and output	

	temp2 = stopwatch.silent_tock();
	caltime2+=temp2;
				
		}
	std::cout << "Timing for output: "<<caltime1<<std::endl;
	std::cout << "Timing for timestep: "<<caltime2<<std::endl;

	// measure time and save elapsed time
        //calctime = stopwatch.silent_tock();
        // time output as well:
        //stopwatch.tick();
        // Stop and print out all timings
        //std::cout << "Timing summary:" << std::endl;
        //std::cout << "#Simulation took:\t" << calctime << " sec" << std::endl;
        //stopwatch.tock("#Report took:     "); // this combines the elapsed time measurement and output	

	return 0;


}
