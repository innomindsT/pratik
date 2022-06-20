// to find min and max from given array
#include<stdio.h>

int main(void)
{
	int i,size,min,max;
	printf("Enter size of the array : ");
    	scanf("%d", &size);
	int arr[size];

    	printf("Enter elements in array : \n");
    	for(i=0 ; i<size; i++)
    	{
        	scanf("%d",&arr[i]);
    	}
 
    	min=max=arr[0];
    	for(i=1; i<size; i++)
   	{
		if(min>arr[i])
		{
			min = arr[i];
		}
		if(max<arr[i])
		{
		    	max=arr[i];       
		}
	}
	printf("minimum of array is : %d\n",min);
	printf("maximum of array is : %d\n",max);
	return 0;
}
