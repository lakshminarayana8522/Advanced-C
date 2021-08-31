/* This program demonistrates how to create a pipe using pipe() 
 * System call
 *
 *
 *
 *
 * author: Lakshmi Narayana S       */

#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>

int main()
{
	int fd[2];  //declaring a integer arry of two elements
	int status;   

	status = pipe(fd);//creating the pipe. it takes the integer array of two		       	// elements.first element used for read end an second
                //	element used for write end of the pipe.
		
       if(status < 0)
       {
		perror("pipe failed:");
 		exit(-1);
       }
	else
	{
		printf("pipe is created successfully...\n");
	}
	close(fd[0]);  //closing the read end of pipe
	close(fd[1]);  //closing the write end of pipe
	return 0;
}	
