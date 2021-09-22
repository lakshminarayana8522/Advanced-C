/**
 * This program will redirects the stdin. So instead of reading from stdin this program will read from a file. using dup2() system call we can achive this.
 *
 * filename : dup2.c
 * author   : Lakshmi narayana S
 * email    : narayana8522@gmail.com
 * date     : 22 Sep 2021
 */

/*! include headers */
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>

/*! main program starts */
int main()
{
	int fd,fd1;
	char arr[100];
	/*! opening data.text file in readonly mode */
	fd = open("data.text",O_RDONLY);
	if(fd==-1)
	{
		printf("file not opened...\n");
		exit(0);
	}

	/*! redirecting stdin. it will points to the file */
	fd1 = dup2(fd,0);
	
	printf("fd1: %d\n",fd1);
	
	/*! it will read from file instead of stdin */
	gets(arr);

	puts(arr);

	close(fd);

}

