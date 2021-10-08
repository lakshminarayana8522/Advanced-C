/**
Input: The input consist of three space seperated integers- input1,input2, input3 representing the three four-digit numbers.

Output: print an integer representing the concatenation of four digits where 
				
					-- first digit represents the smallest digit in the thousands place of all three numbers,
					
   					-- second digit represents the largest digit in the hundreds place of all three numbers,

					-- third digit represents the largest digit in the tens place of all three numbers,

					-- fourth digit represents the largest digit in the units place of all three numbers.

Example:

input: 3521 2452 1352

Output: 1522

Filename : prog1.c
author   : Lakshmi Narayana S
email    : narayana8522@gmail.com
Date     : 30 Sep 2021

*/



/*! include header files*/
#include<stdio.h>   /*! required for printf() scanf()  */

/**
  This function will reverse the number
  @param[in] a
  @param[out] num
  */

int reverse(int a)
{
	int num = 0;
	while(a)
	{
		num = num * 10 + (a%10);
		a = a/10;
	}
	return num;
}

/*! main program starts */
int main()
{
	int input[3],result=0,i,j,a;
	printf("Enter the input numbers: ");
	
	for(i=0;i<3;i++)
	{
		scanf("%d",&input[i]);
	}


	for(i=0;i<4;i++)
	{
		a = input[0]%10;
		input[0] = input[0]/10;
		
		for(j=1;j<3;j++)
		{
			if(i%2 == 0)
			{
				if(a<(input[j]%10))
				{
					a = input[j]%10;
				}
			}
			else
			{
				if(a>input[j]%10)
				{
					a = input[j]%10;
				}
			}

			input[j] = input[j]/10;
		}
		
		 result = result*10 + a;
	}

	result = reverse(result);

	printf("result: %d\n",result);

	return 0;
}

			

