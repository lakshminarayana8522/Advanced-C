/**
 * This program sorts an array using selection sort algorithm
 *
 * filename  : selSort1.c
 * author    : Lakshmi Narayana S
 * email     : narayana8522@gmail.com
 * date      : 2 Sep 2021
 */

/*!Includes header files */
#include<stdio.h>

/*! main program starts */
int main()
{
	/*! declaring an array of 10 integers to sort */
	int arr[10] = {6,9,1,4,0,3,8,2,5,7};
	/*! to use in for loops */
	int i,j;
	/*! to hold data while swapping the values in sorting */
	int temp;

	printf("Before sorting: ");
	for(i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");

	/*! performing selection sort */

	for(i=0;i<10-1;i++)
	{
		for(j=i+1;j<10;j++)
		{
			if(arr[i]>arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	printf("After sorting : ");
	for(i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}

