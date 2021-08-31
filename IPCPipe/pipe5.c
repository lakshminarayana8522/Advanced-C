/* This program describes the how communication happend between processes.
 *
 * in this program popen function shall execute the command specified by the string command.
 * it shall create a pipe between the calling program and the executed command, and shall returns 
 * a pointer to stream that can be used to either read from or write to the pipe.
 *
 *
 *
 *
 * author: Lakshmi Narayana S               */




#include<stdio.h>
#include<unistd.h>


int main()
{
	FILE *stream = popen("cat","w"); //this will execute cat command and creates a pipe between the current program and the process executed the cat command
	fprintf(stream,"hi!\n");        //it will write the message to pipe and the cat command will read it and print it on dispaly.
	fflush(stream);
	sleep(10);
	fprintf(stream,"just testing :D\n");
	fflush(stream);
	pclose(stream);
	fprintf(stdout,"Finshed!\n");
	return 0;
}

