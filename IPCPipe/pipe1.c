/* This program demonistrates how to create a pipe using pipe() system call
 * filename  : pipe1.c
 * author    : Lakshmi Narayana S
 * email     : narayana8522@gmail.com
 * date      : 1 Sep 2021   */

/*! Includes */
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>

/*! main program starts */
int main()
{
	/*! declaring integer array to hold the file discriptor values of pipe */
	int fd[2];
	/*! declared integer variable to hold the return value of pipe. */
	int status;   
	/**creating the pipe. it takes the integer array of two elements.
	 * first element used for read end and secondelement used for write end of the pipe.
	 */
	status = pipe(fd);
        /*! checking status to know pipe created or not*/
        if(status < 0)
        {	
		perror("pipe failed:");
 		exit(-1);
        }
	else
	{
		printf("pipe is created successfully...\n");
	}
	/*! closing the read end of the pipe*/
	close(fd[0]);  
        /* closing the write end of the file */	
	close(fd[1]);  
	return 0;
}	
