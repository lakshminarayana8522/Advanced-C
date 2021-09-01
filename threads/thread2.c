/**
 * This program will creates the 5 threads using pthread_create in for loop
 * filename  : thread2.c
 * author    : Lakshmi Narayana S
 * email     : narayana8522@gmail.com
 * date      : 1 Sep 2021
 */

/*! includes  */
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

/*! Defining constants */
#define NUM_THREADS 5    

/*! routine for threads */ 
void *printhello(void *ptr)     
{ 
	/*! to hod the value from main thred */
	int tid;
	tid = (int)ptr;
	/*! printing the value on the display */
	printf("Hello....%d\n",tid);
	/*! terminating the thread */
	pthread_exit(NULL);          
}

/*! main program starts  */
int main(int argc,char **argv)
{
	/*! declaring array of 5 thread variables to hold the thread IDs */
	pthread_t t[NUM_THREADS];                  
	int i,r;
	/*! creating 5 threads */
	for(i=0;i<NUM_THREADS;i++)                   
	{
		printf("In mai...creating thread: %d\n",i);
		/*! creating thread */
	 	r = pthread_create(&t[i],NULL,printhello,(void *)i);  
		/*! checking the return value of pthread_create is successful or not */
		if(r)                                                  
		{
			printf("error occured while creating a thread...%d\n",i);
			exit(-1);
		}
	}
	/*! terminating the main thread....*/
	pthread_exit(NULL);                  }


