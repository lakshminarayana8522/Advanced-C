/**
 * this program demonistrates the how to transfer data between files
 * filename : transfer.c
 * author   : Lakshmi narayana S
 * email    : narayana8522@gmail.com
 * date     : 3 Sep 2021
 */

/*! includes headers */
#include<stdio.h>   /*! required for printf(),fopen(),fclose(),fputc(),fgetc() */
#include<stdlib.h>   /*! required for exit() */
/*! main program starts */
int main(){
	/*! hold the references to source and destination files */
	FILE *sfp,*dfp; 
	int ch;
	/*! opening source file in read mode */
	sfp = fopen("file1.c","r");
	/*! on failure fopen returns NULL */
	if(sfp == NULL)         
	{
		printf("Error in opening a source file....\n");
		exit(1);
	}
	/*! opening destination file in write mode */
	dfp = fopen("file2.c","w");
	/*! on failure fopen returns NULL */
	if(dfp == NULL)                 
	{
		printf("Error in openng a destination file....\n");
		exit(1);
	}
	/*! reading data from source file using fgetc untill EOF reached */
	while((ch=fgetc(sfp))!=EOF)         
	{
		/*! writing the data to destination file */
		fputc(ch,dfp);                
	}
	/*! closing source file */
	fclose(sfp);              
	/*! closing destination file */
	fclose(dfp);
	return 0;	
}

	
