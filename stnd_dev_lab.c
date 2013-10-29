/* 
	Computational Model for Standard Deviation
	Modeling standard deviation of Stocks
	
	Author: Andrew Bocz
*/  
#include <stdio.h>
#include "basic_lib_compc.h"

int main(void) {
	/*simulated stock values*/
	double stocks[] = {14850.0,14700.0,14680.0,14720.0,14800.0};
	/*variable to hold the standard deviation*/
	double stnd_devi = 0.0; 
	int i;
	printf("Values: \n");
    for(i = 0; i < 5; i++){
		/*Print each element of the array*/
		printf("%f \n", stocks[i]);
    }
    /*Using the basic library provided, compute the standard deviation*/
    stnd_devi = std_dev(stocks, 5);
    /*print standard deviation*/
    printf("The standard Deviation is: %lf \n", stnd_devi);
    return 0;  
}
