/* 
	Computational Model for Standard Deviation
	Modeling a matrirainfall and matric arithmetic
	
	Author: Andrew Bocz
*/  

#include <stdio.h>
#include <math.h>

int main(void) { 
	/*loop variables*/
	int j,k,l,m;
	/* variables */
	double totalSum = 0.0;
	double rowSum = 0.0;
	double totalAverage = 0.0;
	double rowAverage = 0.0;
	double max = 0.0;
	double min = 100.0;
	double yearMax = 0.0;
	double yearMin = 100.0;
	/* Rainfall over five years, 4 values for each quater of the year */	
	double rainfall[5][4]={{30.206,35.099,47.658,57.122},{60.476,34.042,53.201,50.462},{39.515,52.099,44.595,41.056},{45.091,39.430,40.857,54.988},{42.322,46.569,39.217,61.364}};
    
	/* Print the elements of the array */
	for(j = 0; j<5; j++){
		for(k = 0; k<4; k++){
			printf(" %f", rainfall[j][k]);
			totalSum+=rainfall[j][k];
			/* Looks for maximum */
			if(max<rainfall[j][k]){
				max=rainfall[j][k];
			}
			/* Looks for minimum */
			if(min>rainfall[j][k]){
				min=rainfall[j][k];
			}
		}
		printf("\n");
	}
	totalAverage = totalSum/20;
    printf("\nThe average of all rainfall is : %f \n", totalAverage);
	printf("The maximum of all rainfall is : %f \n", max);
	printf("The minimum of all rainfall is : %f \n", min);
	for(l = 0; l<5; l++){
		rowSum = 0;
		yearMax = 0.0;
		yearMin = 100.0;
		for(m = 0; m<4; m++){
			/* Looks for maximum */
			if(yearMax<rainfall[l][m]){
				yearMax=rainfall[l][m];
			}
			/* Looks for minimum */
			if(yearMin>rainfall[l][m]){
				yearMin=rainfall[l][m];
			}
			rowSum += rainfall[l][m];
       }
	   rowAverage = rowSum/5;
	   printf("\nThe average rainfall of year %d: %f \n",l+1, rowAverage);
	   printf("The maximum rainfall of year %d: %f \n",l+1, yearMax);
	   printf("The minimum rainfall of year %d: %f \n",l+1, yearMin);	   
    }
   
  return 0;
}