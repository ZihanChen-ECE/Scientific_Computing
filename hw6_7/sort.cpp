#include <iostream>
#include <cstdlib>
using namespace std;

double** insertsort(double *array, int size)
{
	double key = 0.0;
  	double position = 0.0;
  	double **NewArray;
  	NewArray = new double*[size];
  	for(int i=0;i<size;i++)
	  {
	  	NewArray[i] = new double[2];
	    NewArray[i][0] = array[i];
	    NewArray[i][1] = i+1;  
	  }
	for(int j = 1; j<size; j++)
	{
		int i = j-1;
		key = NewArray[j][0];
    	position = NewArray[j][1];
    		while (i > -1 && NewArray[i][0] < key)
			{
				NewArray[i+1][0] = NewArray[i][0];
	    		NewArray[i+1][1] = NewArray[i][1]; 
				i--;
				NewArray[i+1][0] = key;
	      		NewArray[i+1][1] = position;
			}	
		}

	return NewArray;
}

