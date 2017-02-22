#include <cmath>
#include <rarray>
#include <rarrayio>
#include <cmath>
double initial(rarray<double,2> number_of_ants,  rarray<double,2> velocity_of_ants, const int total_ants, int m)
{
//initial the 2-D array, number_of_ants and velocity_of_ants, using rarray
	for (int i=0;i<m;i++) {
        for (int j=0;j<m;j++) {
            velocity_of_ants[i][j] = M_PI*(sin((2*M_PI*(i+j))/3560)+1);
        }
    }

	float z = 0;
	int n = 0;

	number_of_ants.fill(0.0);

	while (n < total_ants)
	{
        for (int i=0;i<m;i++)
	  {
            for (int j=0;j<m;j++)
		{
                    z += sin(0.3*(i+j));
                    if (z>1 and n!=total_ants)
                    {
                	    number_of_ants[i][j] += 1;
                	    n += 1;
                	}
         }
      }
    }

    return 0;

}
