/* This program will represents the how to write formatted data into the file using fprintf library function.
 *
 *
 *
 * fprintf function is same as normal printf() function but it writes the formatted data into the file instead of the standard output.
 *
 *
 * author: Lakshmi Narayana S                  */




#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE *fp;                        //declaring file handler
	int age;                          
	char name[20];
	fp = fopen("file1.c","w");            //  opening a file in write mode.
	if(fp == NULL){                                           //on failure fopen will return NULL.
		printf("Error while opening a file...\n");
		exit(1);
	}
	printf("Enter the name: ");
	scanf("%s",name);                                 //taking the input from the user
	printf("Enter the age: ");
	scanf("%d",&age);
	fprintf(fp,"Mi name is %s and age is %d\n",name,age);   //it will write  formatted data name and age to the file associated with fp.
	fclose(fp);                                        //closing the file.


}

