/**
 * This program will read the data from shared memory segment
 * filename : shm3.c
 * author   : Lakshmi narayana S
 * email    : narayana8522@gmail.com
 * date     : 7 Sep 2021
 */

/*! include headers */
#include<stdio.h>   /*! required for printf() */
#include<sys/ipc.h>  /*! required for shared memory operations */
#include<sys/shm.h>  /*! required for shared memory operations */
#include<errno.h>    /*required for strerror() */
#include<sys/stat.h>  /*! required for permission flag constants */

/*! main program starts */
int main()
{
	/*! hold the shared memory ID */
	int id;
	/*! hold the shared memory reference */
	char *shared_memory;

	/*! obtaining the shared memory ID */
	id = shmget(3434,0,IPC_CREAT|S_IRWXU);
	if(errno != 0)
	{
		printf("error occured at shmget: %s\n",strerror(errno));
	}
	/*! attaching shared memory to program */
	shared_memory = shmat(id,NULL,0);

	if(errno != 0)
	{
		printf("error occured at shmat: %s\n",strerror(errno));
	}
	printf("data: %s\n",shared_memory);

	/*! detaching shared memory */
	shmdt(shared_memory);
	return 0;
}
