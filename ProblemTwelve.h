/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Filename:	ProblemTwelve.h
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	A program that will find the smallest triangle number with n factors, where
 |				n is a user inputted number.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Author:		Jonathan Burrows
 |	Date:		December 13th, 2012.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
#ifndef PROBLEMTWELVE_H
#define PROBLEMTWELVE_H 1

#include <stdio.h>
#include <math.h>
#include <inttypes.h>

#include "inputs.h"

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	first_with_n_factors
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	Finds the first triangle number with N factors.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	@param:		n,			The number of factors the found triangle number must have.
 |	@return:	current_triangle_number,	The first triangle number found with n factors.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Algorithm:	Every tree node is visited. It is broken down into factors by checking
 |				every value below the seeve of the tree node for modularity. If modular,
 |				the value is a factor. The number of factors are added together. Once a 
 |				tree node with enough factors is found, that value is returned.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
extern unsigned long long first_with_n_factors(int n);

#endif
