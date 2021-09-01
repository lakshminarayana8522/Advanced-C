/* This program describes the how communication happend between processes.
 * filename  : pipe4.c
 * author    : Lakshmi Narayana S    
 * email     : narayana8522@gmail.com
 * date      : 1 Sep 2021
 */

/*! Includes */
#include<stdio.h>
#include<unistd.h>

/*! main function starts */
int main()
{
	/*! the popen system call executes cat command and creates a pipe between current process and process executes the cat command in write mode */
	FILE *stream = popen("cat","w"); 
	/*! the fprintf function write the data to the stream associated with write end of pipe */
	fprintf(stream,"hi!\n");      
	/*! the fflush function immediatly writes the data to the pipe */
	fflush(stream);
	/*! sleeping for 10 seconds */
	sleep(10);
	/* this will again writes the data to the stream */
	fprintf(stream,"just testing :D\n");
	/* the data poointed by the stream will be pushed to pipe */ 
	fflush(stream);
	/*! closing the stream */
	pclose(stream);
	fprintf(stdout,"Finshed!\n");
	return 0;
}

