#include <rarray>
#include <rarrayio>
#include "output.h"
#include <cmath>

double timestep(rarray<double,2> number_of_ants, rarray<double,2> new_number_of_ants, rarray<double,2> velocity_of_ants,const float c1,const float c2,const float c3,int m)
{
//record the number of ants and velocity of ants in each timestep
	float totants = 0.0;

        new_number_of_ants.fill(0.0);

        for (int i=0;i<m;i++) {
            for (int j=0;j<m;j++) {
                int di = c1*sin(velocity_of_ants[i][j]);
                int dj = c1*cos(velocity_of_ants[i][j]);
                int i2 = i + di;
                int j2 = j + dj;
                // some ants do not walk
                new_number_of_ants[i][j]+=c2*number_of_ants[i][j];
                // the rest of the ants walk, but some fall of the table
                if (i2>=0 and i2<m and j2>=0 and j2<m) {
                    new_number_of_ants[i2][j2]+=c3*number_of_ants[i][j];
                }
            }
        }
        for (int i=0;i<m;i++) {
            for (int j=0;j<m;j++) {
                number_of_ants[i][j] = new_number_of_ants[i][j];
                totants += number_of_ants[i][j];
            }
        }
	return totants;
}
