/**
 * This program will demonstrate the waitpid() system call to block the parent until particular child terminates.
 * filename : wait4.c
 * author   : Lakshmi narayana S
 * email    : narayana8522@gmail.com
 * date     : 3 Sep 2021
 */

/*! includes headers */
#include<stdio.h>     /*! required for printf */
#include<stdlib.h>    /*! required for exit() */
#include<unistd.h>    /*! required for fork() */
#include<sys/wait.h>  /*! required for wait() */

/*! main program starts */
int main()
{
	/*! hold the child terminated status */
	int status;
	int i;
	/*! hold the process IDs */
	pid_t pid[5];
	/*! creation 5 child processes using fork() */
	for(i=0;i<5;i++)
	{
		if((pid[i] = fork()) == 0)
		{
			/*in child process i */
			/*! sleep for 1 sec */
			sleep(1);
			/*! terminating child by exit() */
			exit(100+i);
		}
	}

	for(i=0;i<5;i++)
	{
		/*! parent process */
		/*! wait for child pid[i] termination */
		pid_t cpid = waitpid(pid[i], &status,0);
		if(WIFEXITED(status))
		{
			printf("child %d terminated with %d exit status\n",cpid,WEXITSTATUS(status));
		}
	}
	return 0;
}


