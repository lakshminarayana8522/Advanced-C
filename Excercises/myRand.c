/** 
  This program will create a new file name dataX.dat where X is a random number between 0 and 255.
  Generstes 60 values between 0 and 100 and store them in the file.
  Exit with an exist status of x.

Filename : myRand.c
Author   : Lakshmi Narayana S
Email    : narayana8522@gmail.com
Date     : 3 Oct 2021

*/

/*! include headers */
#include<stdio.h>          /*! required for printf() */
#include<stdlib.h> 	  /*! required for exit() */
#include<unistd.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
/*! main Program starts */
int main()
{
	/*! hold the reference to the file dataX.dat */
	FILE *fptr;
	
	int x,i,num;
	srand(time(0));
	/*! generating random integer between the range from 0 to 255 */
	x = rand()%256;
	/*! hold the filename */
	char filename[256];
	/*! concatinating random number with the filename */
	sprintf(filename,"data%d.dat",x);
	
	/*! creating file with write mode */
	fptr = fopen(filename,"w");
	if(fptr == NULL)
	{
		printf("File not created..\n");
		exit(0);
	}
	
	/*! generates the random numbers and store them in file */
	for(i=0;i<60;i++)
	{
		num = rand()%101;
		fprintf(fptr,"%d ",num);
	}
	
	/*! closing the file */
	fclose(fptr);
	
	printf("%d\n",x);
	/*! exiting with status X */
	exit(x);
}

	
