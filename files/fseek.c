/**
 * This program will represents the how to change the position of file handler using fseek() Function
 *
 *
 * and also how to get the current position of file handler using ftell() function.
 *
 *
 * Syntax:  int fseek(FILE *fp,long displacement, int origin);
 *
 * orgin takes the three values they are ...
 *       Constant             value      position
 *	SEEK_SET		0	begining of a file
 *	SEEK_CURRENT		1	current position
 * 	SEEK_END		2	End of the file
 * we can use the value or constants in place of origin
 * Displacement represrnt the offset value to move forward or backwork from origin. if positive value it moves forward or if negative it moves backward.
 *
 * filename : fseek.c
 * author   : Lakshmi narayana S
 * email    : narayana8522@gmail.com
 * date     : 3 Sep 2021
 */

/*! includes header files */
#include<stdio.h>   /*! required for printf(),ftell(),fseek(),fopen(),fclose(),fread() */
#include<stdlib.h>  /*! required for exit() */
/*! declared a user defined structure to hold the data readed from file */
struct st{                                     
	char name[20];
	int age;
};
/*! main program starts */
int main(){      
	/*! hold the reference to the file returned by a fopen() */	
	FILE *fp;
	struct st person;
	/*! opening afile1.c in binary read mode */
	fp = fopen("file1.c","rb");          
	/*! on failure fopen will return NULL */
	if(fp == NULL)                        
	{
		printf("Error while opening file...\n");
		exit(1);
	}
	/*! increase the file pointer(fp) value to the size of the person variable from starting position */
	fseek(fp,sizeof(person),0);
	/*! reading the record pointed by fp from the file */
	fread(&person,sizeof(person),1,fp);
	/*! printing the readed data to stdout */
	printf("name: %s\n",person.name);
	printf("age: %d\n",person.age);
	/*! getting the current position of fp */
	printf("position: %d\n",ftell(fp));      
	/*! setting the fp position to beginning  of the file */
	rewind(fp);
	/*! printing fp position to stdout */	
	printf("position: %ld\n",ftell(fp));
	/*! reading the first record from the file */
	fread(&person,sizeof(person),1,fp);
	/*! printing the readed data on stdout */
	printf("name: %s\n",person.name);
	printf("age: %d\n",person.age);
	printf("position: %d\n",ftell(fp));
	/*! closing the file */
	fclose(fp);            
	return 0;
}
