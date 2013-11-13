/*
 Generates .dat files, with a specified number of random values
 Features to add: custom dimension, custom range for values,etc.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*prototypes*/
double genRand(int range);

int main(void){         
		int n,m,x,y,z;    /*rows, columns, loop index, loop index, range*/
		char name[25], na[5], attr1[8], attr2[8], attr3[8];  /*file name, response, attribute names*/
		FILE *outp;     
		/*Seed random*/
		unsigned int iseed = (unsigned int)time(NULL);
		srand(iseed);
		/*Input name and size*/
		printf("Name the file (25 character limit): ");
		scanf("%s", name);
		printf("What is the number of rows(entries)?: ");
		scanf("%d", &n);
		printf("What is the number of columns(attributes)?: ");
		scanf("%d", &m);
		/* Handle Attributes */
		printf("Would you like to name your attributes?(yes or no): ");
                scanf("%s", na);
		if(strcmp(na, "yes")==0 || strcmp(na, "y")==0){
			printf("What is the name of attribute one?: ");
		    scanf("%s", attr1);
			printf("What is the name of attribute two?: ");
		    scanf("%s", attr2);
			printf("What is the name of attribute three?: ");
		    scanf("%s", attr3);
		}
		printf("What is the range for the random generator?: ");
        scanf("%d", &z);
        /*initialize array*/
        double matrix[n][m];
        /*Generate random values and populate array*/
		for (x=0; x<n; x++){
            for(y=0; y<m; y++){
                matrix[x][y] = genRand(z);
            }
        }
        printf("\nValues generated\n");
		/*open file*/
		outp = fopen(name,"w");
		if (outp == NULL){
			printf("Error opening file");
			exit(0);
		}
		/*write to file*/
		int q,w;
		for (q=0; q<n; q++){
			for (w=0; w<m; w++){
				if(q==0){
					if(w==0){
					fprintf(outp, "%7s", attr1);
					}
					else if(w==1){
					fprintf(outp, "%7s", attr2);
					}
					else{
					fprintf(outp, "%7s", attr3);
					}
				}
				else if(q!=0){
				fprintf(outp, "%7.1f", matrix[q][w]);
				}
				}
			fprintf (outp, "\n");
		}
		/*close file*/
		fclose (outp);
        printf("\nComplete!\n");
        return 0;
}
double genRand(int range){
		/*return random number*/		
		return rand()%range+1;
}
/*initArray(){
	eh?
}*/

		

