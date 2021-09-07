/**
 * This program will create the shared memomry segment 
 * filename : shm1.c
 * author   : Lakshmi narayana S
 * email    : narayana8522@gmail.com
 * date     : 7 Sep 2021
 */

/*! include headers */
#include<stdio.h>   /*! required for printf */
#include<sys/ipc.h>  /*! required for shmget() */
#include<sys/shm.h>  /*! required for shmget() */
#include<sys/stat.h>  /*! reuired for Permission flag constants */
#include<errno.h>   /*! required for strerror() */
/*! main program starts */
int main()
{
	/*! defining size of shared memory */
	size_t shm_size = 0x80;
	/*! hold the shared memory segment ID */
	int id;
	/*! creationg shared memory segment */
	id = shmget(3434,shm_size,IPC_CREAT|S_IRWXU);

	if(errno !=0)
	{
		printf("An error is occured: %s\n",strerror(errno));
	}
	printf("shared memory segment created successfully.....\n");
	return 0;
}
