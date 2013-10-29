/* 
	Computational Model for Polynomial
	Use C and GNUPLOT to model a polynomial	
	
	Author: Andrew Bocz
*/
#include <stdio.h>
#include <gsl/gsl_poly.h>
#include "basic_lib_compc.h"
#define N 7  
#define M 20
/* Functions */
int main(void) {
    /* Variables */
	int i;
    int j;   
    double intervalStart, intervalEnd;
    double x[M];
    double y[M];  
	double coefficients[N] = {4.5, -3, 6, -6.5, 5, 1.5, 2};  
    printf("The polynomial has the follow coefficients: \n");
    for (i=0; i < N; i++)
       printf("%f ", coefficients[i]);
    printf(" \n");
    /* Estimated interval */  
    intervalStart = -4.0;
    intervalEnd = 4.0;
	/* Calculate a vector */
    linspace(x, intervalStart, intervalEnd, M);
    poly_eval(coefficients, x, y);
    printf("\nPlotting Points \n");
    for(j=0; j < M; j++)
        printf("%+.18f %+.18f \n", x[j], y[j]);	   
    return 0;
}
/* Function for Evaluating Polynomials */
void poly_eval (double c[], double xvec[], double yvec[]) {
    yvec[0] = gsl_poly_eval(c, N, xvec[0]);
	int i;
    for (i = 1; i < M; i++)
        yvec[i] = gsl_poly_eval(c, N, xvec[i]);			
    
    return;
}
