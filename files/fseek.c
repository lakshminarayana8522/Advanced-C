/* This program will represents the how to change the position of file handler using fseek() Function
 *
 *
 * and also how to get the current position of file handler using ftell() function.
 *
 *
 * Syntax:  int fseek(FILE *fp,long displacement, int origin);
 *
 * orgin takes the three values they are ...
 *       Constant             value      position
	SEEK_SET		0	begining of a file
	SEEK_CURRENT		1	current position
	SEEK_END		2	End of the file
  we can use the value or constants in place of origin
  Displacement represrnt the offset value to move forward or backwork from origin. if positive value it moves forward or if negative it moves backward.


author: Lakshmi Narayana S    */


#include<stdio.h>
#include<stdlib.h>

struct st{                                      //declaring a user defined structure
	char name[20];
	int age;
};

int main(){
	FILE *fp;                          //declaring a file handler
	struct st person;
	fp = fopen("file1.c","rb");           //opening a file in binary read mode.
	if(fp == NULL)                       //fopen will return NULL on failure. 
	{
		printf("Error while opening file...\n");
		exit(1);
	}
	fseek(fp,sizeof(person),0);                  //moves the file handler position from begening of the file to length of the person variable.

	fread(&person,sizeof(person),1,fp);            //reading data from file.
	printf("name: %s\n",person.name);
	printf("age: %d\n",person.age);
	printf("position: %d\n",ftell(fp));       //ftell() function will return the current position of the file handler fp.
	rewind(fp);                                       //it will move the file handler fp position to the begening of the file.
	printf("position: %ld\n",ftell(fp));
	fread(&person,sizeof(person),1,fp);
	printf("name: %s\n",person.name);
	printf("age: %d\n",person.age);
	printf("position: %d\n",ftell(fp));
	fclose(fp);                                     //closing a file.
}
