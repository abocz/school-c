/* 
	Polynomial of Degree 5
	curve fitting
	
	Author: Andrew Bocz
*/
#include <stdio.h>
#include <gsl/gsl_poly.h>
#include "basic_lib.h"
#include "polyfitgsl.h"
#define NC 6  

void polyval(double p[], double xv[], double yv[], int n, int m); 
int main(){
	const int NP = 8;      
	const int M = 30;      
	double x[] = {5500, 8500, 13500, 20500, 29500, 40500, 53500, 68500};
	double y[] = {0, 3000, 5000, 7000, 9000, 11000, 13000, 15000};
	double coeff[NC];  
	int i;
	double xc[M]; 
	double yc[M];  
	printf("Program finds best fit polynomial of degree %d \n", NC-1);
	printf("Data points (x,y): \n");
	for (i = 0; i < NP; i++)
		printf(" %f %f \n", x[i], y[i]);
	polynomialfit(NP, NC, x, y, coeff); 
	printf("\n\nCoefficients of polynomial found\n");
	for(i=0; i < NC; i++) {
		printf("%lf\n", coeff[i]);
	}
	linspace(xc, 0.0, 7.0, M);
	polyval(coeff, xc, yc, NC, M);
	printf("\nData points calculated with the polynomial \n");
	for(i=0; i < M; i++)
		printf("%d  %+.18f  %+.18f \n", i, xc[i], yc[i]);	 
	return 0;
}
void polyval (double p[], double xv[], double yv[], int n, int m) {
	int j;
	yv[0] = gsl_poly_eval(p, n, xv[0]);
	for (j = 1; j < m; j++) 
		yv[j] = gsl_poly_eval(p, n, xv[j]);			
	return;
}
