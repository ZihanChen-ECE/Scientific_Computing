#include <cmath>
#include <iostream>
#include "ticktock.h"

int main()
{
    // ants walk on a table
    float number_of_ants[356][356];
    float new_number_of_ants[356][356];
    float velocity_of_ants[356][356];
    const int total_ants = 1010; // initial number of ants
    
    // define a stopwatch timer:
    TickTock stopwatch;
    // start timer:
    //stopwatch.tick();

    // initialize
    for (int i=0;i<356;i++) {
        for (int j=0;j<356;j++) {
            velocity_of_ants[i][j] = M_PI*(sin((2*M_PI*(i+j))/3560)+1);
        }
    }
    int n = 0;
    float z = 0;
    for (int i=0;i<356;i++) {
        for (int j=0;j<356;j++) {
            number_of_ants[i][j] = 0.0;
        }
    }
    while (n < total_ants) {
        for (int i=0;i<356;i++) {
            for (int j=0;j<356;j++) {
                z += sin(0.3*(i+j));
                if (z>1 and n!=total_ants) {
                    number_of_ants[i][j] += 1;
                    n += 1;
                }
            }
        }
    }

    // measure time and save elapsed time
    //double calctime = stopwatch.silent_tock();
    // time output as well:
    //stopwatch.tick();
    // Stop and print out all timings
    //std::cout << "Timing summary:" << std::endl;
    //std::cout << "#Initialization took:\t" << calctime << " sec" << std::endl;
    //stopwatch.tock("#Report took:     "); // this combines the elapsed time measurement and output


    // run simulation
    
    
	float caltime1 = 0.0;
	float caltime2 = 0.0;
	float caltime3 = 0.0;
	float temp1 = 0.0;
	float temp2 = 0.0;
	float temp3 = 0.0;

    for (int t = 0; t < 40; t++) {

	// start timer:
        stopwatch.tick();
        float totants = 0.0;
        for (int i=0;i<356;i++) {
            for (int j=0;j<356;j++) {
                totants += number_of_ants[i][j];
            }
        }
        std::cout << t<< " " << totants << std::endl;
	//time for output	
	temp1 = stopwatch.silent_tock();
	caltime1+=temp1;


	// start timer:
        stopwatch.tick();
        for (int i=0;i<356;i++) {
            for (int j=0;j<356;j++) {
                new_number_of_ants[i][j] = 0.0;
            }
        }
		
        for (int i=0;i<356;i++) {
            for (int j=0;j<356;j++) {
                int di = 1.9*sin(velocity_of_ants[i][j]);
                int dj = 1.9*cos(velocity_of_ants[i][j]);
                int i2 = i + di;
                int j2 = j + dj;
                // some ants do not walk
                new_number_of_ants[i][j]+=0.8*number_of_ants[i][j];
                // the rest of the ants walk, but some fall of the table
                if (i2>=0 and i2<356 and j2>=0 and j2<356) {
                    new_number_of_ants[i2][j2]+=0.2*number_of_ants[i][j];
                }
            }
        }
	//time for simulate number of ants	
	temp2 = stopwatch.silent_tock();
	caltime2+=temp2;

	// start timer:
        stopwatch.tick();
        for (int i=0;i<356;i++) {
            for (int j=0;j<356;j++) {
                number_of_ants[i][j] = new_number_of_ants[i][j];
                totants += number_of_ants[i][j];
            }
        }
	//time for updating total ants	
	temp3 = stopwatch.silent_tock();
	caltime3+=temp3;
    
    }
    // measure time and save elapsed time
    //calctime = stopwatch.silent_tock();

    // time output as well:
    //stopwatch.tick();

    // Stop and print out all timings
    //std::cout << "Timing summary:" << std::endl;
    //std::cout << "#Simulation took:\t" << calctime << " sec" << std::endl;
    //stopwatch.tock("#Report took:     "); // this combines the elapsed time measurement and output
    
	std::cout<<"time for output: "<<caltime1<<std::endl;
	std::cout<<"time for simulate number of ants: "<<caltime2<<std::endl;	
	std::cout<<"time for updating total ants: "<<caltime3<<std::endl;


    return 0;
}             
 
