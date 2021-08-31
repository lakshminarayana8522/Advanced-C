/* This program will represents the how to insert string into a file using  fputs function
 *
 *
 *
 *
 *   author: Lakshmi Narayana S            */



#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE *fp;                    //declaring a file handler
	char str[20];                // declaring a character array of 20 elements
	fp = fopen("file2.c","a");        //opening a file in append mode. append mode also creates new file if it not exists. if file exists it will append the data at the end of existing data. 
	if(fp == NULL){                    //fopen will return NULL on failure
		printf("Error in opening a file....\n");
		exit(1);
	}
	printf("Enter the String:  ");
	while((gets(str))!=NULL){                //through gets() function take the string from user and store it in chracter array str.
	fputs(str,fp);                           // using fputs function insert the data into a file pointed by fp.

	}
	fclose(fp);                //closing the file.
}

