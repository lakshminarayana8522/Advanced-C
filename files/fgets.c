/* this program will represents the how to read string from a file.
 *
 * fgets() function is used to read string.
 *
 *
 *
 *
 * author : Lakshmi Narayana S        */






#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE *fp;                  //declaring a file handler
	char str[20];              // declaring a character array to store the characters read from the file.
	fp = fopen("file2.c","r");      //opening a file in read mode.
	if(fp == NULL){                                                    //on failure fopen will return NULL.
		printf("Error while opening a file...\n");
		exit(1);
	}
	fgets(str,20,fp);               //fgets will read the 19 characters from the file pointed by fp. and store it in character array str. fgets function appends the NULL character at the end of                                        // the string. that why it reads the n-1 characters in this case 20-1 = 19 characters reads and puts the NULL (\0) character at the end of the string.
	printf("%s\n",str);             // printing the string on display.
	fclose(fp);                     //closeing the file
}
