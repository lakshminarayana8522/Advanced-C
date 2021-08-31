/*This program will creates the 5 threads using pthread_create in for loop
 *
 *
 *
 *
 *
 *
 * author: Lakshmi Narayana              */





#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define NUM_THREADS 5               //defining Constant

void *printhello(void *ptr)          //handler for threads
{
	int tid;
	tid = (int)ptr;
	printf("Hello....%d\n",tid);
	pthread_exit(NULL);                         //terminating the thread.
}


int main(int argc,char **argv)
{
	pthread_t t[NUM_THREADS];                     //declaring array of 5 thread variables type of pthread_create
	int i,r;
	for(i=0;i<NUM_THREADS;i++)                   
	{
		printf("In mai...creating thread: %d\n",i);
	 	r = pthread_create(&t[i],NULL,printhello,(void *)i);  //creating thread and passing the value of i to the handler
		if(r)                                                  //on failure pthread_create will return errno 
		{
			printf("error occured while creating a thread...%d\n",i);
			exit(-1);
		}
	}
	pthread_exit(NULL);                               //terminating the main thread.....
}


