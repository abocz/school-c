/* 
	Computational Model for Temperatures
	Use C and GNUPLOT to model differences in temperatures	
	
	Author: Andrew Bocz
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "basic_lib_compc.h" 
int main(void){
	/* variables */
	double time[] = {7, 8, 9, 10, 11, 12, 1, 2, 3, 4, 5, 6};
	double temp[]= {51, 56, 60, 65, 73,78, 85, 86, 84, 81, 80, 70};
	double *firstTime;
	double *firstTemp;
	double *secondTemp;
	/* Calculations using basic library */
	firstTime = diff(time, 12);
	firstTemp = diff(temp, 12);
	secondTemp = diff(firstTemp, 11);
	printf("\n");
	int i;
	for(i =0; i<10; i++){
		printf("%g %g %g\n", time[i], firstTemp[i], secondTemp[i]);
	}
	printf("%g %g\n", time[10], firstTemp[10]);
	printf("%g\n", time[11]);

	return 0;
}
