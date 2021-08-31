/* This program will represents the how to write block of data to a file using fwrite function.
 *
 *
 *
 * author: Lakshmi Narayana S                                */





#include<stdio.h>
#include<stdlib.h>

struct st{                            //declaring a user defined structure.
	char name[20];
	int age;
};

int main(){
	FILE *fp;                     //Declaring a file handler
	int i,n;
	fp = fopen("file1.c","wb");      //opening a file in write binary mode.
	if(fp == NULL)                    //on error fopen will return NULL
	{
		printf("Error while opening a file...\n");
		exit(1);
	}
	printf("no of record: ");
	scanf("%d",&n);                                                    
	struct st person;
	for(i=0;i<n;i++)
	{
		printf("Enter the name: ");
		scanf("%s",person.name);
		printf("Enter the age: ");
		scanf("%d",&person.age);
		fwrite(&person,sizeof(person),1,fp);                //the fwrite() function will write the block of data to the file associated by file handler fp.
								    //the first argument will be pointer to a memory that contains the information to be written to the file.
								    //the second argument will be size of the each item to be written to file
								    //the third argument will be the number of items to be wtitten to the file.
	}
	fclose(fp);                              //closing the file.
}

	

