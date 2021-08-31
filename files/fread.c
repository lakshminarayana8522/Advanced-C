/*  This program will represents the how to read block of data from a file using fread() library function.
 *
 *
 *
 *  author: Lakshmi Narayana S               */





#include<stdio.h>
#include<stdlib.h>

struct st{                       //declaring a  user defined structure with  two members name and age.
	char name[20];
	int age;
};

int main(){
	FILE *fp;                //declaring a file handler.
	fp = fopen("file1.c","rb");   //opening a file in binary read mode.
	if(fp == NULL)                 //on error fopen will return NULL
	{
		printf("Error while opening a file....\n");
		exit(1);
	}
	struct st person;                    //declaring a structure variable person.
	fread(&person,sizeof(person),1,fp);   //reading the data from the file associated by fp. the first argument is a pointer to a block of memory which recives the data read from the file.
	                                      //the second argument specifies the  length of each item to be read.
					      //the third argument specifies the  number of items to be read from the file.
	printf("name: %s\n",person.name);     
	printf("age: %d\n",person.age);       //printing the data be read from the file to display.
	fread(&person,sizeof(person),1,fp);
	printf("name: %s\n",person.name);
	printf("age: %d\n",person.age);
	fclose(fp);                                 //closing the file.
}

