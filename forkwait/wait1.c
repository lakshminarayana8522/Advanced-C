/**
 * This program will demonstrate the wait system call 
 * filename : wait1.c
 * author   : Lakshmi narayana S
 * email    : narayana8522@gmail.com
 * date     : 3 Sep 2021
 */

/*! includes headers */
#include<stdio.h>       /*! required for printf */
#include<stdlib.h>      /*! required for exit() */
#include<sys/wait.h>    /*! required for wait() */
#include<unistd.h>      /*! required for fork() */

/*! main program starts */
int main()
{
	/*! hold process ID */
	pid_t pid;
	/*! creating child process */
	if(fork() == 0)
	{
		exit(0);
	}
	else
		/*! waiting for child termination. wait() returns terminated child process ID */
		pid = wait(NULL);
	printf("parent process ID: %d\n",getpid());
	printf("child process ID: %d\n",pid);

	return 0;
}

