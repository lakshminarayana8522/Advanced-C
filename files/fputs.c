/**
 * This program will represents the how to insert string into a file using  fputs function
 * filename : fputs.c
 * author   : Lakshmi narayana S
 * email    : narayana8522@gmail.com
 * date     : 3 Sep 2021
 */

/*! includes headers */
#include<stdio.h>  /*! required for printf(),fgets() */
#include<stdlib.h>  /*! required for exit() */

/*! main program starts */
int main(){
	/* hold the reference returned by fopen() */
	FILE *fp;
	/*! hold the data which will be write to file using fputs */	
       	char str[20];
	/*! opening file2.c in append mode */
	fp = fopen("file2.c","a");
	/*! on failure fopen returns NULL */. 
	if(fp == NULL){                   
		printf("Error in opening a file....\n");
		exit(1);
	}
	/*! getting input from stdin */
	printf("Enter the String:  ");
	while((gets(str))!=NULL){      
		/*! wring data to the file2.c uing fputs */
	fputs(str,fp);                           

	}
	/*! colsing file */
	fclose(fp);        
	return 0;
}

