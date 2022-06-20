// C program for finding the smallest integer
// among three numbers using command line arguments
#include <stdio.h>
#include <stdlib.h>

// Taking argument as command line
int main(int argc, char *argv[])
{
	int a, b, c;

	// Checking if number of argument is
	// equal to 4 or not.
	if (argc < 4 || argc > 5)
	{
		printf("enter 4 arguments only eg.\"filename arg1 arg2 arg3!!\"\n");
		return 0;
	}

	// Converting string type to integer type
	// using function "atoi( argument)"
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	c = atoi(argv[3]);

	// Checking if all the numbers are positive of not
	if (a < 0 || b < 0 || c < 0)
	{
		printf("enter only positive values in arguments !!\n");
		return 1;
	}

	// Checking if all the numbers are different or not
	if (!(a != b && b != c && a != c))
	{
		printf("please enter three different value\n");
		return 1;
	}
	else
	{
		// Checking condition for "a" to be smallest
		if (a < b && a < c)			
			printf("%d is smallest\n", a);

		// Checking condition for "b" to be smallest
		else if (b < c && b < a)
			printf ("%d is smallest\n", b);

		// Checking condition for "c" to be smallest.
		else if (c < a && c < b)
			printf("%d is smallest\n",c);
	}
	return 0;
}

