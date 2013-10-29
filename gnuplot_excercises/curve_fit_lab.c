/* 
	Computational Model for Polynomial, using Curve Fitting
	Use C and GNUPLOT to model a polynomial, using curve fitting
	
	Author: Andrew Bocz
*/
#include <stdio.h>
#include <gsl/gsl_poly.h>
#include "basic_lib.h"
#include "polyfitgsl.h"
/* Constants */
#define NC 3 
#define NP 8
#define M 30  
/* Functions */
int main(void){
	/* Variables */
	int i;
	double x[] = {5500, 8500, 13500, 20500, 29500, 40500, 53500, 68500};
	double y[] = {0, 3000, 5000, 7000, 9000, 11000, 13000, 15000};
	/* Vector for coefficients */
	double coeff[NC];
	/* Estimated Values */
	double xc[M]; 
	double yc[M];  
	printf("Applying curve fitting to the polynomial\nGenerated data points (x,y): \n");
	for (i = 0; i < NP; i++)
		printf(" %f %f \n", x[i], y[i]);
	polynomialfit(NP, NC, x, y, coeff); 
	printf("\nCoefficients of polynomial found:\n");
	for(i=0; i < NC; i++)
		printf("%lf\n", coeff[i]);
	/* Evaluate after Curve Fitting */
	linspace(xc, 0.0, 7.0, M);
	polyval(coeff, xc, yc, NC, M);
	printf("\nData points calculated with the polynomial \n");
	for(i=0; i < M; i++)
		printf("%d  %+.18f  %+.18f \n", i, xc[i], yc[i]);	 
	return 0;
}
/* Function for Evaluating Polynomials */
void polyval (double p[], double xv[], double yv[], int n, int m) {
	int j;
	yv[0] = gsl_poly_eval(p, n, xv[0]);
	for (j = 1; j < m; j++) 
		yv[j] = gsl_poly_eval(p, n, xv[j]);			
	return;
}
