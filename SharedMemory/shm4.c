/**
 * This program will delete the shared memory segment and get the data structure associated with the shared memory
 * filename : shm4.c
 * author   : Lakshmi narayana S
 * email    : narayana8522@gmail.com
 * date     : 7 Sep 2021
 */

/*! include headers */
#include<stdio.h>           /*! required for printf() */
#include<sys/shm.h>         /*! required for shared memory operations */
#include<sys/ipc.h>        /*! required for shared memory operations */
#include<sys/stat.h>      /*! required for permission flag constants */
#include<errno.h>          /*! required for strerror() */
#include<time.h>           /*! required for ctime() */
/*! main program starts */
int main()
{
	/*! hold the shared memory ID */
	int id;
	/*! hold the shared memory data strusture */
	struct shmid_ds info;
	/*! obtain the shared memory ID */
	id = shmget(3434,0,IPC_CREAT|S_IRWXU);

	/*! copying the shared memory data structure into info variable */
	shmctl(id,IPC_STAT,&info);

	printf("Here some information about the shared memory:  \n");
	printf("size of segment : %ld\n PID of creator: %d\n Last attach time: %s\n",info.shm_segsz,info.shm_cpid,ctime(&info.shm_atime));

	/*! deleting the shared memory segment */
	shmctl(id,IPC_RMID,0);

	return 0;
}
