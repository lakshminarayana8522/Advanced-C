/**
 * This program will demonstrate collectiong the exit status of child using wait() system call
 * filename : wait3.c
 * author   : Lakshmi narayana S
 * email    : narayana8522@gmail.com
 * date     : 3 Sep 2021
 */

/*! includes headers */
#include<stdio.h>    /*! required for printf */
#include<stdlib.h>   /*! required for exit() */
#include<unistd.h>   /*! required for fork() */
#include<sys/wait.h>  /*! required for wait() */

/*! main program starts */
int main()
{
	/*! hold the exit status of child */
	int status;
	/*! creating child process */
	if(fork() == 0)
	{
		/*! in chhild process. */
		/*! terminating the child by exit. */
		sleep(100);
		exit(1);
	}
	else
	{
		/*! waiting for child termination */
		wait(&status);
	}
	/*! WIFEXITED will return true if child terminated normally */
	if(WIFEXITED(status))
	{
		printf("child exit status: %d\n",WEXITSTATUS(status));
	}
	
	return 0;
}



