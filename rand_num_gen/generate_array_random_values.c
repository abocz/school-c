/*
Generates .dat files, with a specified number of random values
+memory allocation for multi-dimensional array
Features to add: custom dimension, custom range for values,etc, rework input section
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*prototypes*/
double genRand(int range);
/* char *readText(); */
char* create1dArray(int m);
char** create2dArray(int m, int n);
void destroyArray(float** arr);


int main(void){
		int o,n,m,x,y,z; /* loop index, rows, columns, loop index, loop index, range */
		char name[25], na[5]; /* file name, value holder */
		char *attributes;	/* attribute name array pointer */
		FILE *outp; /* file pointer */
		/* Seed random */
		unsigned int iseed = (unsigned int)time(NULL);
		srand(iseed);
		/* Input name and size */
		printf("Name the generated file (25 character limit): ");
		scanf("%s", name);
		printf("What is the number of rows (entries)?: ");
		scanf("%d", &n);
		printf("What is the number of columns (attributes)?: ");
		scanf("%d", &m);	
		/*
		Begin attribute section
		*/
		printf("Would you like to name your attributes?(y/n) ");
		scanf("%s", na);
		if(strcmp(na, "Y")==0 || strcmp(na, "y")==0){
			attributes = create1dArray(m);	
			for(o=0;o<=m;o++){
				printf("What is the name of attribute %d?: ", &o);	
			}
			printf("What is the name of attribute one?: ");
			scanf("%s", attributes[][]);
			printf("What is the name of attribute two?: ");
			scanf("%s", attr2);
			printf("What is the name of attribute three?: ");
			scanf("%s", attr3);
		}
		else{
			attr1="one";
			attr2="two";
			attr3="three";
		}
		/*
		End attribute section
		*/
		printf("What is the range for the random generator?: ");
		scanf("%d", &z);
		/* initialize array */
		double matrix[n][m];
		/* Generate random values and populate array */
		for (x=0; x<n; x++){
			for(y=0; y<m; y++){
				matrix[x][y] = genRand(z);
			}
		}
		printf("\nValues generated\n");
		/* open file */
		outp = fopen(name,"w");
		if (outp == NULL){
			printf("Error opening file");
			exit(0);
		}
		/* write to file */
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
		/* close file */
		fclose (outp);
        printf("\nComplete!\n");
        return 0;
}
/* 
Returns random number
*/
double genRand(int range){
	return rand()%range+1;
}
/*
char *readText(){
	char *line = NULL, *t = NULL;
	size_t size = 0, index = 0;
	int letter = EOF;

	while (letter) {
	letter = getc(stdin);
	if (letter == EOF || letter == '\n')
		letter = 0;
		if (size <= index) {
			size += CHUNK;
			t = realloc(line, size);
			if (!t) {
			free(line);
			line = NULL;
			break;
			}
		line = t;
		}
	line[index++] = letter;
	}
	return line;
}
*/
char* create1dArray(int m){
	char *arr = malloc(m*sizeof(int));
	if (ptr == NULL) {
	fprintf(stderr, "Couldn't allocate memory!\n");
	exit(EXIT_FAILURE);
	}
	return arr;
}
char** create2dArray(int m, int n){
	int i;	
	char* values = calloc(m*n, sizeof(float));
	char** rows = malloc(n*sizeof(float*));
	if (values == NULL || rows == NULL) {
		fprintf(stderr, "Couldn't allocate memory!\n");
		exit(EXIT_FAILURE);
	}
	for (i=0; i<n; ++i){
		rows[i] = values + i*m;
	}
	return rows;
}
void destroyArray(char** arr){
    free(*arr);
    free(arr);
}

		

