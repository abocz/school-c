#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/*---------------------------------------------------*/
/*  This function fills array a starting from low to high
    in increments of diff. It returns the number of elements   
    in the array.
*/

int arraycol( double  a[], double low, double high, double diff) { 
   int  i;     /* used as index of the array  */
   double val;
   // printf("computing element values \n");
   val = low;
   a[0] = low;
   // printf("Element value: %f \n", a[0]);
   i = 1;
   while (val < high) { 
       val = a[i-1] + diff;
       if ( val <= high) {
          a[i] = val;
	      // printf("Element value: %f \n", a[i]);
	      i++;
	   }  
   } // endwhile 
   return (i);  
}  // end arraycol

/*---------------------------------------------------*/
/*  This function computes the num element values    */
/*  in the array starting from low to high.          */

 void linspace( double  a[], double low, double high, int num) { 
   int  i; /* used as index of the array  */
   double diff;
   diff = (high - low)/(num-1);
   a[0] = low;
   for (i = 1; i < num; i++ ) { 
       a[i] = a[i-1] + diff;
   } // endfor 
   return; 
}  // end linspace

/** 
   description
        The following function computes the differences of
		consecutive elements in the argument array.
   */
 // 
double *  diff( double  a[], int  num_elements ) { 
 int  i;  // used as index of the array 
 int  n; 
 double   * barray ; 
 n = (num_elements) - (1);
 barray = malloc(n*sizeof(double));
 for (i = 0 ; i < n; i++) { 
    barray [i] = (a [i+1]) - (a [i]);
 } // endfor 
 return barray; 
}  // end diff 

/** 
   description
        The following function computes the ratios of
		consecutive elements in the argument array.
   */
 // 
 double *  factor( double  a[], int  num_elements ) { 
 int  i; // used as index of the array 
 int  n; 
 double   * barray ; 
 n = (num_elements) - (1);
 barray = malloc(n*sizeof(double)); /* Creat array */
 // cout << "computing factors" << endl;
 for (i = 0 ; i < n; i++) { 
    if (abs(a[i]) > 0.0)
        barray [i] = a[i+1]/a[i];
	else
	    barray [i] = a[i+1]/(a[i+1]*0.01);
 } // endfor 
 return barray; 
}  // end factor 

/*---------------------------------------------------*/
/*  This function returns the maximum                */
/*  value in the array x with n elements.            */

double max(double x[], int n)
{
   /*  Declare variables.  */
   int k;
   double max_x;

   /*  Determine maximum value in the array.  */
   max_x = x[0];
   for (k=1; k<=n-1; k++)
   {
      if (x[k] > max_x)
	 max_x = x[k];
   }

   /*  Return maximum value.  */
   return max_x;
}
/*---------------------------------------------------*/
/*  This function returns the minimum                */
/*  value in an array x with n elements.             */

double min(double x[], int n)
{
   /*  Declare variables.  */
   int k;
   double min_x;

   /*  Determine minimum value in the array.  */
   min_x = x[0];
   for (k=1; k<=n-1; k++)
   {
      if (x[k] < min_x)
	 min_x = x[k];
   }

   /*  Return minimum value.  */
   return min_x;
}
/*---------------------------------------------------*/
/*  This function returns the average or             */
/*  mean value in an array with n elements.          */

double mean(double x[], int n)
{
   /*  Declare and initialize variables.  */
   int k;
   double sum=0;

   /*  Determine mean values.  */
   for (k=0; k<=n-1; k++)
   {
      sum += x[k];
   }

   /*  Return mean value.  */
   return sum/n;
}
/*---------------------------------------------------*/
/*  This function returns the median                 */
/*  value in an array x with n elements.             */

double median(double x[], int n)
{
   /*  Declare variables.  */
   int k;
   double median_x;

   /*  Determine median value.  */
   k = floor(n/2);
   if (n%2 != 0)
      median_x = x[k];
   else
      median_x = (x[k-1] + x[k])/2;

   /*  Return median value.  */
   return median_x;
}
/*---------------------------------------------------*/
/*  This function returns the variance               */
/*  of an array with n elements.                     */

double variance(double x[], int n)
{
   /*  Declare variables and function prototypes.  */
   int k;
   double sum=0, mu;
   double mean(double x[], int n);

   /*  Determine variance.  */
   mu = mean(x,n);
   for (k=0; k<=n-1; k++)
   {
      sum += (x[k] - mu)*(x[k] - mu);
   }

   /*  Return variance.  */
   return sum/(n-1);
}
/*---------------------------------------------------*/
/*  This function returns the standard deviation     */
/*  of an array with n elements.                     */

double std_dev(double x[], int n)
{
   /*  Declare function prototypes.  */
   double variance(double x[], int n);

   /*  Return standard deviation.  */
   return sqrt(variance(x,n));
}
/*---------------------------------------------------*/
/*  This function returns the average power          */
/*  of an array x with n elements.                   */

double ave_power(double x[], int n)
{
   /*  Declare and initialize variables.  */
   int k;
   double sum=0;

   /*  Determine average power.  */
   for (k=0; k<=n-1; k++)
   {
      sum += x[k]*x[k];
   }

   /*  Return average power.  */
   return sum/n;
}
/*---------------------------------------------------*/
/*  This function returns the average magnitude      */
/*  of an array x with n values.                     */

double ave_magn(double x[], int n)
{
   /*  Declare and initialize variables.  */
   int k;
   double sum=0;

   /*  Determine average magnitude.  */
   for (k=0; k<=n-1; k++)
   {
      sum += fabs(x[k]);
   }

   /*  Return average magnitude.  */
   return sum/n;
}
/*---------------------------------------------------*/
/*  This function returns a count of the number      */
/*  of zero crossings in an array x with n values.   */

int crossings(double x[], int n)
{
   /*  Declare and initialize variables.  */
   int count=0, k;

   /*  Determine number of zero crossings.  */
   for (k=0; k<=n-2; k++)
   {
      if (x[k]*x[k+1] < 0)
	 count++;
   }

   /*  Return number of zero crossings.  */
   return count;
}