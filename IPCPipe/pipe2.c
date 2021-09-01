/* This program discribes the how to communicate between the processes.
 * filename  : pipe2.c  
 * author    : Lakshmi Narayana S   
 * email     : narayana8522@gmail.com
 * date      : 1 Sep 2021    */

/*! Includes */
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/wait.h>

/*! main program starts */
int main()
{
	/*! used to store the exit status of child. */
	int status;
	/*! used to hold the pipe read and write file discriptor values.*/
	int fd[2];
	/*! creating a pipe. */
	int result = pipe(fd); 
	/*! checking the return value of pipe to know pipe is created or not. */
	if(result != 0)
	{
		perror("pipe create failed:");
		exit(0);
	}
	/*! to hold the process ID of child. */
	pid_t childid;
	/*! creating child process using fork. */
	childid = fork(); 
	/*! checking the return value of fork to know child process created or not. */
	if( childid == -1)
	{
		perror("Falied to fork:");
		exit(0);
	}
	if(childid == 0)
	{
		/*! In Child process. */
		/*! closing the write end of pipe. */
		close(fd[1]);
		/*buffer is to hold the data read from the file */
		char buffer[50];
		/*! reading the data from the pipe*/
		read(fd[0],buffer,sizeof(buffer));
		/*! printing the data readed from the pipe*/
 		printf("message from the parent: %s\n",buffer);
		/*! closing the read end of pipe */
		close(fd[0]);
	}
	else
	{
		/*! In parent process */
		/*! closing the read end of pipe */
		close(fd[0]);
		/*! this data to be write into pipe */
		char toWrite[] = "Hello from parent..";
		/*! writing data to the pipe */
		write(fd[1],toWrite,strlen(toWrite)+1);
		/*! this will blocks the parent untill the child finishes. */
		pid_t cpid = waitpid(childid,&status,0);
	        /*! the WIFEXITED is true if the child terminated normally */
		if(WIFEXITED(status))      
		{
			printf("child %d terminated with status: %d\n",cpid,WEXITSTATUS(status)); 
		}
		/*! closing the write end of the pipe */
		close(fd[1]);
	}
	return 0;
}

