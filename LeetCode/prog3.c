/**
 * Given an integer array nums and an integer value val. remove all occurrencess of val in nums in-place. The relative of the elements may be changed.
 *
 * Since it is impossible to change the length of the array in some languages, You must instead have the result  be placed in the firat part of the array nums.
 * More formally, if there are K elements after removing the duplicates.then the first K elements of nums should hold the final result. it does not matter what you leave beyond the first K elements.
 *
 * Return K after placing the final result in the first K slots of nums.
 *
 * Test case1: 
 *	Input: nums = [3,2,2,3], val = 3
 *	Output: nums = [2,2,_,_]
 *
 * filename : prog3.c
 * author   : Lakshmi narayana S
 * email    : narayana8522@gmail.com
 * date     : 15 Sep 2021
 */

/*! include headers */
#include<stdio.h>

/*! removeElement function */
int removeElement(int *nums, int numsSize, int val)
{
	int i,j;
	for(i=0;i<numsSize;i++)
	{
		if(nums[i] == val)
		{
			for(j=i;j<numsSize-1;j++)
			{
				nums[j] = nums[j+1];
			}
			numsSize--;
			i = i-1;
		}
	}
	return numsSize;
	
}
/*! main program starts */
int main()
{
	int K,i,val=3;
	int nums[] = {3,2,2,3};
	int numsSize = sizeof(nums)/4;
	printf("Input : nums = ");
	for(i=0;i<numsSize;i++)
	{
		printf("%d ",nums[i]);
	}
	printf("\n");

	K = removeElement(nums,numsSize,val);

	printf("Output: nums = ");
	for(i=0;i<K;i++)
	{
		printf("%d ",nums[i]);
	}
	printf("\n");


	return 0;
}




