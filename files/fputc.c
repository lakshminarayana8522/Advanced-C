
/* This  program will represents the how write single character to a file
 *
 *
 *
 *
 *
 *      author: Lakshmi Narayana S                */






#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE *fp;                          // declaring a file handler
	int ch;
	fp = fopen("file1.c","w");          // opening a file in write mode. if file not exists it will creates a new file with name specified in path name.
	if(fp==NULL){                                             // on failure fopen will return NULL
		printf("Error while opening a file...\n");
		exit(1);
	}
	printf("file opend successfully.....\n");
	printf("Enter the data: ");                                 
	while((ch=getchar())!=EOF){                  // through getchar() function read one character from user and stored it in ch variable
		                                    
		fputc(ch,fp);                       // the fputc function will put the data in ch variable to the file associated with file handler fp.
	}
	fclose(fp);                                  //closing a file
}
	


