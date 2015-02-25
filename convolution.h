/*
 * convolution.h
 *
 *  Created on: Nov 30, 2014
 *      Author: afonsoal
 */

#ifndef CONVOLUTION_H_
#define CONVOLUTION_H_

#include <fstream>
#include <iostream>
#include <utility>
#include <vector>

class convolution {

private:



public:
	struct poly {

		double								coefficients[4];
		std::vector <std::pair <int,int> >  exponents;
	};


	convolution();
	void construct_bilinear_polynomial(poly (&bilinear_poly)[4]);

};




#endif /* CONVOLUTION_H_ */
