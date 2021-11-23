/* Write a multiple concurrent process program that does the following
   1. Displays the contents of a file to STDOUT

   The program should perform this task in the following way:
   1. Report an error message if no file was specified
   2. Open a pipe to allow for communication between the parent and child

   3. Create a child process that:
      a. Dups the write side of the pipe to STDIN
      b. Executes the cat function on the file specified in the 
         command line arguments

   4. Create a parent process that:
      a. Reads character data from the read side of the pipe
      b. Outputs the data to STDOUT
   -- Make certain to continue reading from the pipe until all of the
      data has been read and sent to STDOUT
*/


/* Problem 1 -- List the include files you need for this program */

#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>

/* Problem 2 -- write one or more functions necessary to make the 
   program work. At minimum, you will need function main */

int main(int argc, char *argv[])
{
	if(argc<2)
	{
		printf("file is missing....\n");
		exit(0);
	}

	int pipe_fd[2];

	pipe(pipe_fd);

	pid_t pid;

	pid = fork();

	if(pid == 0)
	{
		close(pipe_fd[0]);

		dup2(pipe_fd[1],0);

		FILE *fptr;

		fptr = fopen(argv[1],"r");
		if(fptr == NULL)
		{
			printf("file is not opened...\n");
			exit(0);
		}

		char ch;

		while((ch = fgetc(fptr))!=EOF)
		{
			write(0,&ch,1);
		}

	

	}
	else
	{
		close(pipe_fd[1]);
		char ch;

		while(read(pipe_fd[0],&ch,1))
		{
			printf("%c",ch);
		}

		close(pipe_fd[0]);
	}

	return 0;
}
