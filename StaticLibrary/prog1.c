/**
 * This program will use the static library
 * filename : prog1.c
 * author   : Lakshmi narayana S
 * email    : narayana8522@gmail.com
 * date     : 8 Sep 2021
 */

/*! include headers */
#include<stdio.h>         /*! required for printf() */

/*! main program starts */
int main()
{
	/*! hold the return value from library functions */
	int r;
	/*! calling the library function print() */
	print("hello");

	/*! calling the library function sum() */
	r = sum(10,20);
	printf("Sum: %d\n",r);

	/*! calling the library function mul() */
	r = mul(10,2);
	printf("Mul: %d\n",r);

	return 0;
}


