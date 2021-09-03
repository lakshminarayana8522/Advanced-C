/**
 * This program will represents the how to write block of data to a file using fwrite function.
 * filename : fwrite.c
 * author   : Lakshmi narayana S
 * email    : narayana8522@gmail.com
 * date     : 3 Sep 2021
 *
 */

/*! includes headers */
#include<stdio.h>          /*! required for printf(), scanf(),fwrite() */
#include<stdlib.h>         /*! required for exit() */
/*! user defined structure to hold data that is written to file */
struct st{                         
	char name[20];
	int age;
};
/*! main program starts */
int main(){
	/*! hold the reference to file returned by fopen() */
	FILE *fp;                  
	int i,n;
	/*! opening file1.c in binary write mode */
	fp = fopen("file1.c","wb");
	/*! on failure fopen returns NULL */.
	if(fp == NULL)                   
	{
		printf("Error while opening a file...\n");
		exit(1);
	}
	/*! getting input from stdin to write how many records to write */
	printf("no of record: ");
	scanf("%d",&n);                                                    
	struct st person;
	for(i=0;i<n;i++)
	{
		printf("Enter the name: ");
		scanf("%s",person.name);
		printf("Enter the age: ");
		scanf("%d",&person.age);
		/*! writing data to the file */
		fwrite(&person,sizeof(person),1,fp);               
	}
	/*! closing the file */
	fclose(fp);           
	return 0;
}

	

