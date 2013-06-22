/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Filename:	ProblemTwelve.c
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	A program that will find the smallest triangle number with n factors, where
 *				n is a user inputted number.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Author:		Jonathan Burrows
 *	Date:		December 13th, 2012.
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
#include "ProblemTwelve.h"

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Function:	first_with_n_factors
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Finds the first triangle number with N factors.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	@param:		n,			The number of factors the found triangle number must have.
 *	@return:	current_triangle_number,	The first triangle number found with n factors.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Algorithm:	Every tree node is visited. It is broken down into factors by checking
 *				every value below the seeve of the tree node for modularity. If modular,
 *				the value is a factor. The number of factors are added together. Once a 
 *				tree node with enough factors is found, that value is returned.
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
unsigned long long first_with_n_factors(int n){
    unsigned long long current_triangle_number = 0, factors, seeve;
    unsigned long long i, j;

	/*	Every tree value is checked to see how many factors it has.	*/
    for(j=1;;j++){
		/*	Finds the next tree value.	*/
        current_triangle_number += j;
		
		/*	Finds the maximum value a factor of this number could be.	*/
        seeve = sqrt(current_triangle_number);
		
		/*	Checks every number up to and including seeve to be a factor of the tree value,
		 *	and counts the total number of factors.*/
		factors = 0;
        for(i=1; i <= seeve; i++){
            /*checks to see if the tree root can be factored by current value. */
            if(current_triangle_number%i==0){
			
                /*	This is a case where the factor is the square root of the number.*/
                if(i*i==current_triangle_number){
                    factors++;
                }
                /*otherwise it can be broken down into two factors*/
                else{
                    factors=factors+2;
                }
                /*if the required factors have been found the tree
                 * root is returned as the value.*/
                if(factors >= n){
                    return current_triangle_number;
                }
            }
        }
    }
}

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Function:	main
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Retrieves a user entered value, n, and finds and displays the first triangle
 *				number with N factors.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Errors:		If an error occured whilst getting user input, the program exits.
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
int main(int argc, char** argv){
	int n;
	unsigned long long value;
	
	fprintf(stdout, "\nThis program will find the smallest triangle number with n factors"
					", where n is a user entered number.");
					
	while(1){
		n = input_int();					/*Gets a user input and stores it in n.*/
		/*	Checks if a error or close command occured from getting input.	*/
		if( n == -2){
			fprintf(stderr, "\nError occured whilst retrieving input.");
			break;
		}
		if( n == -1){
			fprintf(stdout, "\nA close command was issued.");
			break;
		}
		
		value = first_with_n_factors(n);	/*Proceeds to calculation.*/
		
		fprintf(stdout, "\nThe first triangle number with %d roots is %"SCNu64"\n\n\n\n",
				n, value);
		
		/*	Asks the user if they would like to perform another operation.	*/
		if( another_input() == 1){
			continue;						/*Another operation is desired.*/
		}
		else break;							/*No more operations desired, break and close.*/
	}
	
	fprintf(stdout, "\nThe program will close in: ");
	countdown(5);
    return 0;
}
