/**
 * This program will represents the how to write formatted data into the file using fprintf library function.
 * filename : fprintf.c
 * author   : Lakshmi narayana S
 * email    : narayana8522@gmail.com
 * date     : 3 Sep 2021
 */

/*! includes header files */
#include<stdio.h>      /*! required for printf(), scanf(),fprintf() */
#include<stdlib.h>     /*! required for exit() */
/*! main program starts */
int main(){
	/*! hold the return value of fopen */
	FILE *fp;               
	/*! used to hold the values which is used to write into file1.c */
	int age;                          
	char name[20];
	/*! opening file1.c in write mode */
	fp = fopen("file1.c","w");
	/*! on failure fopen returns NULL */.
	if(fp == NULL){                                          
		printf("Error while opening a file...\n");
		exit(1);
	}
	/*! taking input from stdin */
	printf("Enter the name: ");
	scanf("%s",name);                               
	printf("Enter the age: ");
	scanf("%d",&age);
	/*! writing formatted data to the file1.c file */
	fprintf(fp,"Mi name is %s and age is %d\n",name,age);   
	/*! closing the file */
	fclose(fp);            


}

