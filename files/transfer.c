/* this program demonistrates the how to transfer data between files
 *
 *
 *
 *
 *
 * author : Lakshmi Narayana S        */







#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE *sfp,*dfp;  //declaring two file handlers 
	int ch;
	sfp = fopen("file1.c","r");    //opening a source file from the data to be read in read mode.
	if(sfp == NULL)          //on failure fopen will return NULL
	{
		printf("Error in opening a source file....\n");
		exit(1);
	}
	dfp = fopen("file2.c","w");      //opening a destination file where data to be writen in write mode.
	if(dfp == NULL)                 //on failure fopen will return NULL
	{
		printf("Error in openng a destination file....\n");
		exit(1);
	}
	while((ch=fgetc(sfp))!=EOF)          //using fgec() function data is read from source file untill EOF (End Of the File) reached.
	{
		fputc(ch,dfp);                //using fputc() function data is written to the destination file.
	}
	fclose(sfp);                            //closing the sourece file.
	fclose(dfp);			 //closing the destination file
}

	
