/* This program  is the example to explain how multiple threads are accesing the shared resource
 *
 * here number variable is shared between all threads
 *
 * in this follwing program the thread which accesing number variable with value 0 will be terminated and the remaining two threads will be executed normally 
 *
 *
 *
 * author: LaKshmi Narayana S      */





#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int number = 14;              //declaring a global variable it will be shared between the all threads

void *fun(void *args)      //thread handler which will be excuted by the 3 threads concurrently
{
	while(number)                           //in this program for thread 1 while accssing the number will be zero after some looping. so, it will be terminated.
	{
		sleep(1);
		number--;
		printf("%d %d\n",(int)args,number);
	}
	return NULL;
}

int main()
{
	pthread_t t1,t2,t3;                          //declaring thread variables
	pthread_create(&t1,NULL,fun,(void *)111);      //creating thread1
	pthread_create(&t2,NULL,fun,(void *)222);     //creating thread 2
	pthread_create(&t3,NULL,fun,(void *)333);     //creating thread 3

	pthread_join(t1,NULL);                 //waits untill thread 1 finishes
	pthread_join(t2,NULL);                 //waits untill thread2 finishes
	pthread_join(t3,NULL);                //waits untill thread 3 finishes
}

