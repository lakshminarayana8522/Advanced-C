
/* This program will be the example for hiow to cancel a thread using pthread_cancel() function.
 *
 *
 * in this program i have created 2 threads and each executes different  handlers
 *
 * the second thread handler terminates the first thread  by calling the pthread_cancel.
 *
 *
 * author: Lakshmi Narayana S                      */





#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *fun1(void *args)                       //first thread handler
{
	printf("sleeping for 200 secs....\n");
	sleep(200);                                        //sleeping for 200 secs 
	printf("thread wokeup...\n");
	return NULL;
}

void *fun2(void *args)                            //second thread handler
{
	printf("waiting 3 seconds to cancel the thread..\n");
	sleep(3);                                                      //  sleeping for 3 seconds 
	pthread_cancel((pthread_t)args);                              //after completing the sleep it will call pthread_cancel() to terminate the thread1 immediatly...
	printf("killed....\n");
	return NULL;
}

int main()
{
	pthread_t t1,t2;                                                 //   declaring thread variables
	printf("creating threads...\n");
	pthread_create(&t1,NULL,fun1,NULL);                            //creating thread 1
	pthread_create(&t2,NULL,fun2,(void *)t1);                    //creating thread 2 and pass the thread 1 ID as an parameter to the handler
	printf("threads created...\n");
	pthread_join(t2,NULL);                            //waiting for thread1 to finsh
	pthread_join(t1,NULL);                           //waiting for thread2 to finsh
}

