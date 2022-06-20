// To find the tarnspose of a given matrix

#include<stdio.h>


int main(void)
{
	int i ,j , row=0 , col =0;
	printf("Enter Number Of Rows :- ");
	scanf("%d",&row);
	printf("Enter Number OF Columns ;- ");
	scanf("%d",&col);

	int arr[row][col];
	int tran[row][col];

	printf("Enter Matrix Elements :- ");
	for( i=0 ; i < row ; i++)
	{
		for(j=0 ; j< col ; j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}

	printf("The Matrix is :- \n");
	for(i=0 ; i < row ; i++)
	{
		for( j=0 ; j < col ; j++)
		{
			printf("%d ",arr[i][j]);
			if(j == row -1)
			{
				printf("\n");
			}
		}
	}

	// taking traspose of the entered matrix
	for(i=0 ; i< row ; i++)
	{
		for(j =0 ; j< col ; j++)
		{
			tran[j][i] = arr[i][j];
		}
	}

	printf("The Transposed Matrix is :- \n");
	for(i=0 ; i < row ; i++)
	{
		for( j=0 ; j < col ; j++)
		{
			printf("%d ",tran[i][j]);
			if(j == row -1)
			{
				printf("\n");
			}
		}
	}

	return 0;
}

