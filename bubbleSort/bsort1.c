/**
 * This program is an example of bubble sort algorithm. it will sort the interger array
 *
 * filename  : bsort1.c
 * author    : Lakshmi Narayana S
 * email     : narayana8522@gmail.com
 * date      : 1 Sep 2021
 */

/*! includes */
#include<stdio.h>
/*! main program starts */
int main()
{ 
	/*! array containing 10 intergers */
	int arr[10] = {9,5,9,7,4,9,8,2,6,12};
	int i,j,temp;
	printf("before sorting: ");
	for(i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");

	/*! sorting  */
	for(i=1;i<10;i++)
	{
		for(j=0;j<10-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}

	printf("after sorting: ");
	for(i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

