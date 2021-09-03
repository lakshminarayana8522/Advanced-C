/**
 * This program wiil demonstrate  the communication between the process created by fork through namedpipe ipc mechanism 
 * 
 * filename : npipe3.c
 * author   : Lakshmi narayana S
 * email    : narayana8522@gmail.com
 * date     : 3 Sep 2021
 */

/*! includes headers */
#include<stdio.h>     /*! required for printf */
#include<unistd.h>    /*! required for file handling and fork() */
#include<sys/types.h>  /*! required for file I/O */
#include<fcntl.h>      /*! required for file operations */
#include<sys/stat.h>   /*! required for named pipe */
#include<string.h>    /*! required for strlen() */

/*! main program starts */
int main()
{
	/*! hold the descriptor values return by open() */
	int fd1;

	/*! creating named pipe (FIFO) */
	mkfifo("myfifo",0666);
	/*! hold the data which is to write to pipe and read from pipe */
	char s1[30],s2[30];
	/*! creating child process */
	if(fork() == 0)
	{
		/*! in child process */
		/*! opening FIFO in write onlu mode */
		fd1 = open("myfifo",O_WRONLY);
		/*! taking input from stdin */
		fgets(s1,30,stdin);
		/*! writing data in s1 to FIFO */
		write(fd1,s1,strlen(s1)+1);
		/*! closing write to pipe */
		close(fd1);
	}
	else
	{
		/*! in parent process */
		/*! opening FIFO in read only mode */
		fd1 = open("myfifo",O_RDONLY);
		/*reading data to s2 from FIFO which is written by child process */
		read(fd1,s2,20);
		/*! printing readed data from FIFO on stdout */
		printf("data from child: %s\n",s2);
		/*! closing the read end of pipe */
		close(fd1);
	}
	return 0;
}






