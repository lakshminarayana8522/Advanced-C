/**
 * This program uses the dynamic library functions
 * filename: prog1.c
 * author  : Lakshmi narayana S
 * email   : narayana8522@gmail.com
 * date    : 8 Sep 2021
 */

/*! include headers */
#include<stdio.h>          /*! required for printf() */


/*! main progarm starts */
int main()
{
	int r;
	print("hello");

	r = sum(10,20);
	printf("r= %d\n",r);

	r = mul(10,2);
	printf("r= %d\n",r);

	return 0;
}

