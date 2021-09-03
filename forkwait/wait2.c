/**
 * This program will demonstrate the wait system call 
 * filename : wait2.c
 * author   : Lakshmi narayana S
 * email    : narayana8522@gmail.com
 * date     : 3 Sep 2021
 */

/*! includes headers */
#include<stdio.h>      /*! required for printf() */
#include<unistd.h>     /*! required for fork() */
#include<sys/wait.h>   /*! required for wait() */

/*! main program starts */
int main()
{
	/*! creating child process */
	if(fork() == 0)
	{
		/*! in child process */
		printf("hello from child....\n");
	}
	else
	{
		/*! in parent process */
		printf("Hello from parent..\n");
		/* waiting for child to terminate */
		wait(NULL);
		printf("child process terminated..\n");
	}
	printf("bye..\n");

	return 0;
}

