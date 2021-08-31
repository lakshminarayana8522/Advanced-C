/* This program discribes the hoe communicate between the processes.
 *  
 *
 *  i have created child process using fork()
 *
 *  child process is read from the pipe
 *
 *  parent process will write the pipe
 *
 *
 *  author: Lakshmi Narayana S       */

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/wait.h>


int main()
{
	int status;
	int fd[2];
	int result = pipe(fd);  //creating pipe
	if(result != 0)
	{
		perror("pipe create failed:");
		exit(0);
	}
	pid_t childid;
	childid = fork();  // creating child process using fork
	if( childid == -1)
	{
		perror("Falied to fork:");
		exit(0);
	}

	if(childid == 0)
	{
		// In Child process
		close(fd[1]); //closing the write end of pipe in child
		char buffer[50];
		read(fd[0],buffer,sizeof(buffer));// This will block until
		 				//parent process writes to pipe.
 		printf("message from the parent: %s\n",buffer);
		close(fd[0]);// closing the read end in the child.
	}
	else
	{
		// In parent process
		close(fd[0]);// closing the read end in parent.
		char toWrite[] = "Hello from parent..";
		write(fd[1],toWrite,strlen(toWrite)+1);
		pid_t cpid = waitpid(childid,&status,0);//this will blocks 
						//parent until child finshes.
		if(WIFEXITED(status))      // it will true if child is terminated normally
		{
			printf("child %d terminated with status: %d\n",cpid,WEXITSTATUS(status)); 
			}
		close(fd[1]);// closing the write end in the parent
	}
	return 0;
}

