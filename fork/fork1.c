/**
 * This programs creates a child process using fork.
 *
 * filename : fork1.c
 * author   : Lakshmi narayana S
 * email    : narayana8522@gmail.com
 * date     : 2 Sep 2021
 */

/*! Includes header files */

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
/*! main program starts */
int main()
{
	/*! to hold the return value of fork */
	pid_t pid;
	/*! creating child process */
	pid = fork();
	/*! fork returns -1 on failure*/
	if(pid<0)
	{
<<<<<<< HEAD
		printf("child process is not created.....\n");
=======
		printf("failed to fork.......\n");
>>>>>>> test
	}
	/*! fork returns 0 in child process */
	else if(pid == 0)
	{
		printf("in child process..\n");
	}
	/*! fork returns child process ID in parent process */
	else if(pid>0)
	{
		printf("in parent process..\n");
	}
	sleep(2);
	return 0;
}


