/**
 * This  program will get the process id and parent process id of child process created by fork
 *
 * filename : pid_example2.c
 * author   : Lakshmi narayana S
 * email    : narayana8522@gmail.com
 * date     : 3 Sep 2021
 */

/*! includes header files */
#include<stdio.h>       /*! required for printf() */
#include<unistd.h>      /*! required for getpid(), getppid() */

/*! main program starts */
int main()
{
	/*! hold the process id returned by fork */
	pid_t pid;

	/*! creating child process */
	pid = fork();
	/*! on failure fork() returns -1 */
	if(pid<0)
	{
		printf("failed to fork..\n");
	}
	/*! In child fork return 0 */
	else if(pid == 0)
	{
		printf("in child....process ID: %d, parent process ID: %d\n",getpid(),getppid());
	}
	/*! in parent fork() returns child process id */
	else if(pid >0)
	{
		printf("in parent....process ID: %d, parent process ID: %d\n",getpid(),getppid());
	}
	sleep(2);
	return 0;
}

