#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *ptr = (int *)malloc(10*sizeof(int));
	free(ptr);

	printf("Enter the data: ");
	scanf("%d",ptr);

	printf("data: %d\n",*ptr);
	return 0;
}


