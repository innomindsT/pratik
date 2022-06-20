#include <stdio.h>

// A simple atoi() function
int myAtoi(char* str)
{
	// Initialize result
	int res = 0;
	int sign = 1;
	int i;
	if(str[0] == '-')
	{
		sign =-1 ;
		i++;
	}

	// Iterate through all characters of input string and update result
	// take ASCII character of corresponding digit, subtract the exp
	// from '0' to get numerical value and multiply res by 10 
	// to shuffle digits left to update running total
	for (; str[i] != '\0'; ++i)
	{
		res = res * 10 + str[i] - '0';
	}
	// return result.
	return sign * res;
}

// Driver Code
int main()
{
	char str[80];
	printf("Enter String:- ");
	scanf("%[^\n]s",str);

	// Function call
	int val = myAtoi(str);
	printf("%d ", val);
	return 0;
}

