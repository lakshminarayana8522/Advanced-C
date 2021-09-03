/**
 * This program represents how to register multiple exit handlers and how they are called on process termination
 * filename : atexit2.c
 * author   : Lakshmi Narayana S 
 * email    : narayana8522@gmail.com    
 * date     : 1 Sep 2021    
 */
/*! Includes */
#include<stdio.h>   /*! required for printf*/
#include<stdlib.h>  /*! reuired for atexit() */
#include<unistd.h>  /*! required for slepp() */
/*! Programmer defined Exit handler 1 */
void out1(void) 
{
	printf("In out1...\n");
}
/*! programmer defined Exit handler 2 */
void out2(void)                    
{
	printf("in out2...\n");
}
/*! Main program starts */
int main()
{
	/*! Registering out1 exit handler */
	atexit(out1);
	/*! registering out2 exit handler */	
	atexit(out2);              
	/*! sleep for 10 seconds */
	sleep(10);
	
}


/**
 *  after 10 seconds the program terminated and calls the exit handlers on reverse order  which means first registered exit handler are called last. 
 */
