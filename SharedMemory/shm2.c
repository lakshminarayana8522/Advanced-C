/**
 * This program will attach the shared memory segment to procees and put data into shared memory
 * filename : shm2.c
 * author   : Lakshmi narayana S
 * email    : narayana8522@gmail.com
 * date     : 7 Sep 2021
 */

/*! include headers */
#include<stdio.h>   /*! required for printf() */
#include<sys/shm.h>   /*! required for shmat() shmdt() shmget() */
#include<sys/ipc.h>   /*! required for shared memory operations */
#include<errno.h>   /*! required for strerror() */
#include<sys/stat.h>  /*! required for permission flags */
/*! main program starts */
int main()
{
	/*! hold the shared memory segment refernce */
	char *shared_memory;
	/*! hold the shared memory segment ID */
	int id;
	/*! referning to shared memory */
	id = shmget(3434,0,IPC_CREAT|S_IRWXU);
	
	if(errno != 0)
	{
		printf("Error occured in shmget: %s\n",strerror(errno));
	}
	
	/*! attaching the shared memory segment */
	shared_memory = shmat(id,NULL,0);

	if(errno != 0)
	{
		printf("error occured at shmat: %s\n",strerror(errno));
	}
	/*! writing data into shared memory segment */
	sprintf(shared_memory,"%s","Hello...world...\n");
	printf("some information writes in shared memory...\n");

	/*! detaching the shared memory from process so it won't refer after*/
	shmdt(shared_memory);
	return 0;
}
