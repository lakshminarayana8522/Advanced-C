/**
 * This program will represents the how to read block of data from a file using fread() library function.
 * filename : fread.c
 * author   : Lakshmi narayana S
 * email    : narayana8522@gmail.com
 * date     : 3 Sep 2021
 */

/*! includes headers */
#include<stdio.h>     /*! required for printf,fopen(),fclose(),fread() */
#include<stdlib.h>    /*! required for exit() */
/*! this structured data will be read  from file1.c */
struct st{                      .
	char name[20];
	int age;
};
/*! main program starts */
int main(){
	/*! hold the reference to the file return by fopen() */
	FILE *fp;  
	/*! opening a file in binary read mode */
	fp = fopen("file1.c","rb");
	/*! on error fopen() returns NULL */
	if(fp == NULL)                 
	{
		printf("Error while opening a file....\n");
		exit(1);
	}
	/*! structure variable to hold the data readed from the file */
	struct st person;
	/*! reading 1 structure record from file */
	fread(&person,sizeof(person),1,fp);
	/*! printing readed data to stdout */
	printf("name: %s\n",person.name);     
	printf("age: %d\n",person.age);      
	/*! again reading next record from file */
	fread(&person,sizeof(person),1,fp);
	/*! printing data to the stdout */
	printf("name: %s\n",person.name);
	printf("age: %d\n",person.age);
	/*! closing the file */
	fclose(fp);            
	return 0;
}

