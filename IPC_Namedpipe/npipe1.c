/**
 * This program demonstrates creation of named pipe and writing data to it.
 * filename : npipe1.c
 * author   : Lakshmi narayana S
 * email    : narayana8522@gmail.com
 * date     : 3 Sep 2021
 */

/*! includes headers */
#include<stdio.h>    /*! required for printf */
#include<sys/stat.h>   /*! required for file permission constants */
#include<sys/types.h>
/*! main program starts */
int main()
{
	/*! hold the reference to namedpipe */
	FILE *fp;
	/*! creating namedpipe with only read permission to others */
	mkfifo("myfifo",S_IRWXU|S_IROTH);
	/*! opening named pipe in write mode. This process will be blocked until other process open myfifo for reading*/
	fp = fopen("myfifo","w");
	/*! writing data to FIFO */
	fprintf(fp,"%s\n","Hello..");
	/*! flushing the buffer pointed by fp so immediatly the data is written to named pipe myfifo */
	fflush(fp);
	/*! closing reference to file */
	fclose(fp);
	return 0;
}


