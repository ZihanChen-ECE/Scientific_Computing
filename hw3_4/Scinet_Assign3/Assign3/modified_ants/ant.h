/*
 * ant.h
 *
 *  Created on: Jan 27, 2016
 *      Author: zihan
 */
#include <rarray>
#ifndef ANT_H_
#define ANT_H_

double initial(rarray<double,2> number_of_ants,  rarray<double,2> velocity_of_ants, const int total_ants, int m);
double timestep(rarray<double,2> number_of_ants, rarray<double,2> new_number_of_ants, rarray<double,2> velocity_of_ants,const float c1, const float c2, const float c3, int m);

#endif /* ANT_H_ */
