/* 
	ComplexNumNum Arithmetic
	Performing addition, subtraction, multiplication, and division	
	
	Author: Andrew Bocz
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/* ComplexNum struct */
typedef struct{
        double real;
        double imag;
}ComplexNum;
/* ComplexNum Addition Function */
ComplexNum addition(ComplexNum a, ComplexNum b){
	ComplexNum ans;
	ans.real = a.real + b.real;
	ans.imag = a.imag + b.imag;
	return ans;
}
 /* ComplexNum Multiplication Function */
ComplexNum multiplication(ComplexNum a, ComplexNum b){
	ComplexNum ans;
	ans.real = a.real * b.real - a.imag * b.imag;
	ans.imag = a.real * b.imag + a.imag * b.real;
	return ans;
}
 
/* ComplexNum Subtraction Function */
ComplexNum subtraction(ComplexNum a, ComplexNum b){
	ComplexNum ans;
	ans.real = a.real- b.real;
	ans.imag = a.imag-b.imag;
	return ans;
}
/* ComplexNum Division Function */
ComplexNum division(ComplexNum a, ComplexNum b){
	ComplexNum ans;
	ans.real = a.real/b.real;
	ans.imag = a.imag/b.imag;
	return ans;
}
/* Function that prints the ComplexNum */
void printComplexNum(ComplexNum c)
{ 
	printf("{%f+I",c.real);
	printf("%f}",c.imag);
} 
int main(void){
	/* loop variables */
	int g,h,i,j,k;
	/* Two arrays of ComplexNums */ 
	ComplexNum x[] = {{1.26599,1.84479},{2.06624,2.25282},{3.07594,3.08994},{4.36796,4.44147},{5.74627,5.29287}};
	ComplexNum y[] = {{1.4,1.4},{3.2,3.2},{4.4,4.4},{1.1,1.1},{2.9,2.9}};
	ComplexNum results[5];
	/* Complete Required Tasks */
	printf("The complex numbers are: \n");
	for(g=0;g<5;g++){
		/* Print ComplexNums x*/
		printf("x%d:",g+1);
		printComplexNum(x[g]);
		printf(", y%d:",g+1);
		printComplexNum(y[g]);
		printf("\n");
	}
	printf("\nAddition: \n");
	for(i=0;i<5;i++){
		/* Perform addition */
		results[i] = addition(x[i],y[i]);
		printf("x%d+y%d=",i+1,i+1);
		printComplexNum(results[i]);
		printf("\n");
	}
	printf("\nMultiplication: \n");
	for(h=0;h<5;h++){
		/* Perform multiplication */
		results[h] = multiplication(x[h],y[h]);
		printf("x%d*y%d=",h+1,h+1);
		printComplexNum(results[h]);
		printf("\n");
	}
	printf("\nSubtraction: \n");
	for(j=0;j<5;j++){
		/* Perform subtraction */
		results[j] = subtraction(x[j],y[j]);
		printf("x%d-y%d=",j+1,j+1);
		printComplexNum(results[j]);
		printf("\n");
	}
	printf("\nDivision: \n");
	for(k=0;k<5;k++){
		/* Perform division */
		results[k] = division(x[k],y[k]);
		printf("x%d/y%d=",k+1,k+1);
		printComplexNum(results[k]);
		printf("\n");
	}
	return 0;
}
