/**
 *This program will open the named pipe (FIFO) for reading and writing.
 *
 * filename : npipe2.c
 * author   : Lakshmi narayana S
 * email    : narayana8522@gmail.com
 * date     : 3 Sep 2021
 */

/*! includes headers */
#include<stdio.h>  /*! required for printf */
#include<string.h>  /*! required for strlen() */
#include<fcntl.h>   /*! for open(),read(), write() */
#include<sys/stat.h>  /*! required for mkfifo() */
#include<sys/types.h>  /* required for file operation */
#include<unistd.h>    /*! required for file operations */

/*! main function starts */
int main()
{
	/*! hold the descriptor for file return by open() */
	int fd;
	/*! creating or refer to the existing FIFO */
	mkfifo("myfifo",0666);
	/*! hold the data which is to be write to FIFO or read from FIFO */
	char s1[50],s2[50];
	while(1)
	{
		/*! opening the FIFO in read only mode */
		fd = open("myfifo",O_RDONLY);
		/*! reading data from FIFO */
		read(fd,s1,50);
		/*! printing the data readed from FIFO */
		printf("user1: %s\n",s1);
		/*! closing the FIFO */
		close(fd);


		/*! opening the FIFO in wrire mode */
		fd = open("myfifo",O_WRONLY);
		/*! taking data from stdin */
		fgets(s2,50,stdin);
		/*! writing data in s2 to FIFO */
		write(fd,s2,50);
		/*! closing the file */
		close(fd);

	}
	return 0;
}


		
		

