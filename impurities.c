/*
	Assignment 6
	Impurties
	
	Author: Andrew Bocz
*/
#include <stdio.h>
#include <math.h>

int main(){
   const int N =8; 
   double x[N];
   double y[N];
   double impurityleft = 0.35; 
   int i;
   int j;
   double ximpurityleft;
   x[0] = 405.0;
   printf("Program to compute growth of impurities in water\n\n");
   ximpurityleft = N;
   
   printf("Initial impurity in water: %f\n", x[0]);
   printf("Number of applications: %d\n", N);
   printf("\n\nFactor: %f \n", impurityleft);
   for (j=0; j < N-1; j++)
     x[j+1] = impurityleft * x[j];
    printf("Impurities after each application \n");
  for ( j = 0;  j < N; j++)
    printf("%f %f %f \n", y[j], x[j]);
return 0;
}

