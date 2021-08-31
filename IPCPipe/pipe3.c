
/* this programs also explains the communication between parent and child process
 *
 *
 *
 * author: Lakshmi Narayana S      */





#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/wait.h>

void writer(FILE *stream)      //this is writer function which writes the data to the pipe.
{
	int count = 0;
	for(count=0;count<=5;count++)
	{
		fprintf(stream,"This is a message number %d\n",count);
		fflush(stream);                                   
		sleep(1);
	}
}

void reader(FILE *stream)       // this is a reader function which reads the data from pipe and print it on display.
{
	char buffer[100];
	while(!feof(stream) && !ferror(stream) && fgets(buffer,sizeof(buffer),stream)!=NULL)
	{
		fputs(buffer,stdout);
	}
}

int main()
{
	int fd[2];
	pid_t pid;
	FILE *stream;    //  declaring a file handler.

	pipe(fd);             //creating a pipe.

	pid = fork();  //creating child process using fork().

	if(pid == 0)
	{
		fprintf(stderr,"this is child process with pid: %d\n",getpid());
		close(fd[1]);                             //closes write end in child because we only read from pipe in this example
		stream = fdopen(fd[0],"r");               //it will return reference to stream associated with pipe in read mode.
		reader(stream);      // calling the reader function. it will read data from pipe.
		close(fd[0]);            // closing the read end of pipe in child
	}
	else
	{
		fprintf(stderr,"this is parent process with pid: %d\n",getpid());
		close(fd[0]);                         //closing write end 
		stream = fdopen(fd[1],"w");           //it will open in write mode.
		writer(stream);                       //calling the writer function. it will writes the data to the pipe.
		close(fd[1]);                          //closing the write end.
		wait(NULL);         //waiting for child to finsh.
	}
	return 0;
}

