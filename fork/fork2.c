/**
 *  when child process is created the all parent process variables are duplicated in to child process. this program will give basic understanding.
 *
 *  filename : fork1.c
 *  author   : Lakshmi narayana S
 *  email    : narayana8522@gmail.com
 *  date     : 2 Sep 2021
 */

/*! including header files */
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>

/*! main program starts*/
int main()
{
	/* ! To hold the return value of fork() */
	pid_t pid;
	/*! to hold the file discriptor value return by open() */
	int fd;
	/*! to hold the data that is read from the file */
	char buffer[40];
	/*! openting a file in read only mode */
	fd = open("testfile",O_RDONLY);
	/*! creating child process */
	pid = fork();
	/*! on failure fork will return -1 */
	if(pid <0)
	{
		printf("faild to fork...\n");
	}
	/*! on success fork will return 0 in child process */
	else if(pid == 0)
	{
		printf("In Child process...\n");
		/*! when child is created, all the parent process values are duplicated to child. 
		 * so the file discriptor value returned by open in parent process is also copied to child. */
		/*! reading data from testfile */
		read(fd,buffer,sizeof(buffer));
		printf("data: %s\n",buffer);
	}
	/*! fork will return child process ID in parent process*/
	else if(pid > 0)
	{
		printf("in parent process..\n");
	}
	sleep(2);
	return 0;
}

