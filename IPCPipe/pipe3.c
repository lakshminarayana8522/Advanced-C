
/* this programs also explains the communication between parent and child process
 * filename  : pipe3.c
 * author    : Lakshmi Narayana S
 * email     : narayana8522@gmail.com
 * date      : 1 Sep 2021      */

/*! Includes */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/wait.h>

/*! this is writer function, which writes the data to the pipe */
void writer(FILE *stream)
{
	int count = 0;
	for(count=0;count<=5;count++)
	{
		/*! writing data to the pipe. */
		fprintf(stream,"This is a message number %d\n",count);
		/*! flushing the data in stream so data is immediatly writes to pipe */
		fflush(stream);
		/*! for every iteration slepping for one second */		
		sleep(1);
	}
}
/*! This is function to read data from the pipe */
void reader(FILE *stream)      
{
	/*! used to hold the data to be read from pipe */
	char buffer[100];
	/*! readig the data from the pipe */
	while(!feof(stream) && !ferror(stream) && fgets(buffer,sizeof(buffer),stream)!=NULL)
	{
		/*! printing the readed data from the pipe */
		fputs(buffer,stdout);
	}
}

/*! Main program starts */
int main()
{
	/*! used to hold the file discriptors of pipe */
	int fd[2];
	/* used to hold the process ID returned by fork */
	pid_t pid;
	/*! file handler */
	FILE *stream;    
	/*! creating pipe */
	pipe(fd);           
	/*! creating child process using fork */
	pid = fork(); 

	if(pid == 0)
	{	/*! in child process */
		/*! printing the child process ID */
		fprintf(stderr,"this is child process with pid: %d\n",getpid());
		/*! closing the write end of the pipe */
		close(fd[1]);
		/*! fdopen function associates a stream with the read file discriptor of pipe */		
		stream = fdopen(fd[0],"r");
		/*! calling the reader function */
		reader(stream);
		/*! closing the read end of pipe */
		close(fd[0]);            
	}
	else
	{
		/*! in parent process */
		/*! printing the parent process ID */
		fprintf(stderr,"this is parent process with pid: %d\n",getpid());
		/*! closing the write end to the pipe */
		close(fd[0]);                         
	        /*! fdopen returns a stream associated with the write file discriptor of pipe */	
		stream = fdopen(fd[1],"w");
		/*! calling the writer function to write date to the pipe */
		writer(stream);                      
		/*! closing the write end of pipe */
		close(fd[1]);                       
		/*! waiting for child to terminate */
		wait(NULL);        
	}
	return 0;
}

