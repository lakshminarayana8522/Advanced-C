/**
 * This program will get the process ID, and parent process ID.
 *
 * filename : pid_example1.c
 * author   : Lakshmi narayana S
 * email    : narayana8522@gmail.com
 * date     : 3 Sep 2021
 */

/*! including header files*/
#include<stdio.h>       /*! required for printf()  */
#include<unistd.h>      /*! required for getpid(), getppid() */

/*! main program starts */
int main()
{
	/*! printing process ID */
	printf("I am process %ld\n",(long)getpid());
	/*! printing parent process ID */
	printf("My parent id is %ld\n",(long)getppid());
	return 0;
}

