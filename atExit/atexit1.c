/**
 * this bellow program represents the how exit handlers are registerd 
 * filename: atexit1.c
 * email   : narayana8522@gmail.com
 * date    : 1 Sep 2021
 * author  : Lakshmi Narayana S
 */

/*! Includes*/
#include<stdio.h>
#include<stdlib.h>

/*!programmer defined exit handler....... it is called when program terminated normally.
 * it does not accept and does not return anything...*/
void out(void)
{
	printf("atexit out success...\n");
}
/**
 *  Main entry point of the program.
 */
int main()
{     
        /*!Registering the exit handle using atexit().  on failure it will return negative value */
	if(atexit(out))
	{
		printf("atExit failed...\n");
	}
}
