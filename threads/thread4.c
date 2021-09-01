
/**
 *  This program will be the example for how to cancel a thread using pthread_cancel() function.
 * filename  : thread4.c
 * author    : Lakshmi Narayana S
 * email     : narayana8522@gmail.com
 * date      : 1 Sep 2021
 */

/*! includes */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

/*! routine for thread 1 */
void *fun1(void *args)     
{
	printf("sleeping for 200 secs....\n");
	/*! sleeping for 200 secs */
	sleep(200);
	/*! this will not be printed because thread 2 is terminates the thread 1 by calling pthread_cancel() */	
	printf("thread wokeup...\n");
	return NULL;
}

/*! routine for thread 2 */
void *fun2(void *args)     
{
	printf("waiting 3 seconds to cancel the thread..\n");
	/*! sleeping for 3 seconds */
	sleep(3);
	/*! calling the pthread_cancel to terminate thread 1 */	
	pthread_cancel((pthread_t)args);                       
	printf("killed....\n");
	return NULL;
}

/*! main program starts */
int main()
{
	/*! declaring thread variables to hold thread IDs */
	pthread_t t1,t2;                                    
	printf("creating threads...\n");
	/*! creating thread 1 */
	pthread_create(&t1,NULL,fun1,NULL); 
	/*! creating thread 2 and passing the thread 1 identifier as an argument */	
	pthread_create(&t2,NULL,fun2,(void *)t1);                    
	printf("threads created...\n");
	/*! waiting for thread 1 to finish */
	pthread_join(t2,NULL);               
	/*! waiting for thread 2 to finish */
	pthread_join(t1,NULL);               
}

