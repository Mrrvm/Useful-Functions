#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>


/* Assigns vector[] values to any other important values 
 * Usage: assign_values(vector, &a, &b, &c, ..., NULL);
*/
void assign_values(int* vector, int* n_args, ...)
{
   va_list ap;

   va_start(ap, n_args);

   int* n_arg = n_args;
   int i = 0;

   while(n_arg)
   {
     *n_arg = vector[i];
     n_arg = va_arg(ap, int*);
     ++i;
   }

   va_end(ap);
}

/* testing, can erase */
int main()
{
	int vector[3];
	int a = 0, b = 0, c = 0;
	vector[0] = 3;
	vector[1] = 1;
	vector[2] = 2;
	assign_values(vector, &a, &b, &c, NULL);

	printf("%d %d %d\n", a, b, c);

	return 0;
}