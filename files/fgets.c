/**
 * this program will represents the how to read string from a file.
 * filename : fgets.c
 * author   : Lakshmi narayana S
 * email    : narayana8522@gmail.com
 * date     : 3 Sep 2021
 */

/*! includes headers */
#include<stdio.h>    /*! required for printf(),fgets() */
#include<stdlib.h>   /*! required for exit() */
/*! main program starts */
int main(){
	/*! hold the reference to the file */
	FILE *fp; 
	/*! hold the data that is readed from the file */
	char str[20];
	/*! opening file2.c in read mode */
	fp = fopen("file2.c","r");
	/*! on failure fopen returns NULL */
	if(fp == NULL){                     
		printf("Error while opening a file...\n");
		exit(1);
	}
        /**
	 * fgets will read the 19 characters from the file pointed by fp. and store it in character array str. 
	 * fgets function appends the NULL character at the end of the string. 
	 * that why it reads the n-1 characters in this case 20-1 = 19 characters reads and puts the NULL (\0) character at the end of the string.
	 * */
	fgets(str,20,fp);
	/*! printing the readed date on stdout */
	printf("%s\n",str);
	/*! closing the file */
	fclose(fp);            
	return 0;
}
