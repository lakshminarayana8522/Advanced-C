/**
 * This program demonstrate the opening  files using fopen() and closing a file using fclose().
 *
 * filename : fopen.c
 * author   : Lakshmi narayana S
 * email    : narayana8522@gmail.com
 * date     : 3 Sep 2021
 */

/*! includes headers */
#include<stdio.h>     /*! required for printf,fopen(),fclose() */
#include<stdlib.h>    /*! required for exit() */
/*! main program starts */
int main(){
	/*! hold the fopen return value */
	FILE *fp;
	/*! opening file1.c file in write mode */
	fp = fopen("file1.c","w");
	/*! on failure fopen returns NULL*/
	if(fp==NULL){
		printf("Error in opening a file....\n");
		exit(1);
	}
	printf("File successfully opend in write mode....\n");
	/*! closing the file */
	fclose(fp);
}

