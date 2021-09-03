/**
 * This program represents the how to read single character from a file
 * filename  : fgetc.c
 * author    : Lakshmi Narayana S  
 * email     : narayana8522@gmail.com
 * date      : 1 Sep 2021
 */

/*! includes */
#include<stdio.h>  /* require for printf(),fopen(),fclose(),fgetc() */
#include<stdlib.h>   /* required for exit() */

/*! main program starts */
int main(){
	/*! declaring file pointer to handle with files */
	FILE *fp;
	/*! ch  varible to hold the data read through fgetc */
	int ch;
	/*! opening file1.c in read mode */
	fp = fopen("file1.c","r");
	/*! on failure fopen will return NULL */	
	if(fp == NULL){                    
		printf("Error while opening a file....\n");
		exit(1);
	}
	printf("File opend successfully...\n");
	/*! for each itaration fgetc reads single character from file1.c. This while loop will iterartes until it reaches EOF (End OF the File). */	
	while((ch=fgetc(fp))!=EOF){              
		printf("%c",ch);
	}
	/*! closing the file */
	fclose(fp);            
}

