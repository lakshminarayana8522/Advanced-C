/**
  This program uses fork to create a child process and use one of the exec functions to run the myRand program
  This program uses wait() to collect the exit status of myRand program and uses WEXITSTATUS to convert the status returned by wait() to the actual value.
  opens the file dataX.dat where X is the number returned from system.
  Reads the values from dataX.dat file, display them, compute their average, and output the average.
  unlink the file


Filename : exec.c
Author   : Lakshmi narayana S
Email    : narayana8522@gmail.com
Date     : 3 Oct 2021
*/


/*! include headers */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>

/*! main program starts */
int main()
{
	/*! hold the  process id */
	pid_t cpid;
	int status,i,num,average=0,k;
	char filename[256];
	FILE *fptr;
	/*! creating child process */
	cpid = fork();
	/*! child process */
	if(cpid == 0)
	{
		char *arg[] = {"myRand",NULL};
		/*! replacing child process with myRand process */
		execl("./myRand",arg);
	}
	/*! parent process */
	else
	{
		/*! waiting child process to finish */
		wait(&status);
		/*! converting the status returned by child process*/
		k = WEXITSTATUS(status);
	}
	
	/*! concatinating exit status returned by myRand program with the filename */ 
	sprintf(filename,"data%d.dat",k);

 	/*! opening dataX.dat file in read mode */
	fptr = fopen(filename,"r");
	if(fptr == NULL)
	{
		printf("File Not opend..\n");
		exit(0);
	}
	/*! reading data from dataX.dat file */	
	for(i=0;i<60;i++)
	{
		fscanf(fptr,"%d",&num);
		printf("%d ",num);
		average += num;
	}
	printf("\n");
	/*! printing average */
	printf("Average: %d\n",average/60);
	/*! closing the file */
	fclose(fptr);
	return 0;
		







}

		

