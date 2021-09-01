/**
 * This program  is the example to explain how multiple threads are accesing the shared resource
 * filename  : thread3.c
 * author    : LaKshmi Narayana S
 * email     : narayana8522@gmail.com
 * date      : 1 Sep 2021
 */

/*! includes */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
/*! global variable shared between all threads */
int number = 14;             
/*! thread routine */
void *fun(void *args)     
{
	/*! it executes infinate times by thread 2 & 3. the while loop will be failed only when the number is 0. 
	 * in this program when the value of number becomes zero that value will be read by thethread 1 and it terminates. */
	while(number)          
	{
		sleep(1);
		number--;
		printf("%d %d\n",(int)args,number);
	}
	return NULL;
}
/*! main programs starts */
int main()
{
	/*! declaring thread varibles to hold the thread ID's */
	pthread_t t1,t2,t3;                          
	/*! creating thread 1 */
	pthread_create(&t1,NULL,fun,(void *)111);     
	/*! creating thread 2 */
	pthread_create(&t2,NULL,fun,(void *)222);     
	/*! creating thread 3 */
	pthread_create(&t3,NULL,fun,(void *)333);    
        /* waiting for thread1 to finish */
	pthread_join(t1,NULL);             
	/*! waiting for thread 2 to finish */
	pthread_join(t2,NULL);               
	/*! waiting for thread 3 to finish */
	pthread_join(t3,NULL);               
	return 0;
}
