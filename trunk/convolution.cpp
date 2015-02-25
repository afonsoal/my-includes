/*
 * convolution.cpp

 *
 *  Created on: Nov 30, 2014
 *      Author: afonsoal
 */

#include "convolution.h"
#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
convolution::convolution () {}

void convolution::construct_bilinear_polynomial (poly (&bilinear_poly)[4])
{
//	poly bilinear_poly[4];
	auto init = std::initializer_list<double>( {1, -1, -1,  1} );
	std::copy(init.begin(), init.end(), bilinear_poly[0].coefficients);
		init = std::initializer_list<double>( {0,  1,  0, -1} );
	std::copy(init.begin(), init.end(), bilinear_poly[1].coefficients);
		init = std::initializer_list<double>( {0,  0,  1, -1} );
	std::copy(init.begin(), init.end(), bilinear_poly[2].coefficients);
		init = std::initializer_list<double>( {0,  0,  0,  1} );
	std::copy(init.begin(), init.end(), bilinear_poly[3].coefficients);

	bilinear_poly[0].exponents.push_back(std::make_pair(0,0));
//	bilinear_poly[0].exponents.emplace_back(1,0);
	bilinear_poly[0].exponents.push_back(std::make_pair(1,0));
	bilinear_poly[0].exponents.push_back(std::make_pair(0,1));
	bilinear_poly[0].exponents.push_back(std::make_pair(1,1));

	bilinear_poly[1].exponents = bilinear_poly[0].exponents;
	bilinear_poly[2].exponents = bilinear_poly[0].exponents;
	bilinear_poly[3].exponents = bilinear_poly[0].exponents;

	std::cout << "bilinear_poly[0].coefficients[0]: " << bilinear_poly[0].coefficients[0] << "\n";
	std::cout << "bilinear_poly[0].coefficients[1]: " << bilinear_poly[1].coefficients[0] << "\n";
	std::cout << "bilinear_poly[3].exponents	  : " << bilinear_poly[2].exponents[2].first << "\n";
}
// Function that will return a poly C(x,y) = A(x,y)*B(x,y), where A and B are bilinear polynomials
//void convolution::multiply_bilinear_polynomials
//(poly (&C_poly)[4], 		(&A_poly)[4],		(&B_poly)[4])
//{
//
//}
