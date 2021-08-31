/*  This program represents the how to read single character from a file
 *
 *
 *
 *
 *  Author: Lakshmi Narayana S              */




#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE *fp;                           //Declaring a File handler
	int ch;
	fp = fopen("file1.c","r");          // opening a file  in read mode. It will return the reference to the file that will be stored in file handler fp.
	if(fp == NULL){                     // On failure fopen will return NULL.
		printf("Error while opening a file....\n");
		exit(1);
	}
	printf("File opend successfully...\n");                     
	while((ch=fgetc(fp))!=EOF){                 // fgetc function takes one argument that is file handler fp. on sucsess it will return character from file and increment the fp by one
		                                    // the wile loop will be executed untill EOF(end of the file) reached. the EOF is integer constant it's value is -1. it will be placed 
						    // in the file at last.
		printf("%c",ch);
	}
	fclose(fp);                         //closing a file. it flushes the buffer associated with file and closes the file.
}

