/**
 * This program will demonstrate  to know which causes the child termination by using the exit  status.
 * filename : wait5.c
 * author   : Lakshmi narayana S
 * email    : narayana8522@gmail.com
 * date     : 3 Sep 2021
 */

/*! includes headers */
#include<stdio.h>    /*! required for printf */
#include<unistd.h>  /*! required for fork() */
#include<sys/wait.h> /*! required for wait() */

/*! main program starts */
int main()
{
	/*! hold the exit status of child */
	int status;
	/*! hold the process id */
	pid_t pid;

	/*! creating child process */
	if(!fork())
	{
		/*! in child process */
		return 1;
	}
	/*! waiting for child termination */
	pid = wait(&status);

	/*! on error wait returns -1 */
	if(pid == -1)
	{
		perror("wait");
	}

	printf("pid : %d\n",pid);
	/*! checking for normal termination */
	if(WIFEXITED(status))
	{
		printf("Normal termination with exit status : %d\n",WEXITSTATUS(status));
	}
	
	/*! checking for abnormal termination */
	if(WIFSIGNALED(status))
	{
		printf("killed by signal :%d%s\n",WTERMSIG(status), WCOREDUMP(status) ? "core dump" : " ");
	}
	
	/*! checking if process is stopped by any signal */
	if(WIFSTOPPED(status))
	{
		printf("stoped by signal : %d\n",WSTOPSIG(status));
	}

	/*! checking if stopped signal is resumed */
	if(WIFCONTINUED(status))
	{
		printf("continued...\n");
	}
	return 0;
}

		       
		
