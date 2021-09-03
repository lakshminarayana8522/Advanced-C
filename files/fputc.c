/**
 * This  program will represents the how write single character to a file
 * filename : fputc.c
 * author   : Lakshmi Narayana S 
 * email    : narayana8522@gmail.com
 * date     : 1 Sep 2021
 */

/*! includes */
#include<stdio.h>  /*! required for printf(),fopen(),fclose(),fputc() */
#include<stdlib.h>  /*! required for exit() */

/*! main program starts */
int main(){
	/*! declaring a file pointer to handle with files */
	FILE *fp;                         
	/*! to hold the data to write to file */
	int ch;
	/*! opening file1.c in write mode */
	fp = fopen("file1.c","w");
	/*! on failure fopen will return NULL */	
	if(fp==NULL){                          
		printf("Error while opening a file...\n");
		exit(1);
	}
	printf("file opend successfully.....\n");
	printf("Enter the data: ");
	/*! data is read from user through getchar function */	
	while((ch=getchar())!=EOF){             
		/*! writing character into file1.c */                                    
		fputc(ch,fp);                      .
	}
	/*! closing the file */
	fclose(fp);    
}
	


