/**
 * this program will demonistates the thereads will share the global resources
 * filename  : thread3.c
 * author    : Lakshmi Narayana S 
 * email     : narayana8522@gmail.com
 * date      : 1 Sep 2021
 */

/*! Includes  */
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

/*! thread routine  */
void *Inc_x(void *ptr)              
{
	/*!declared a pointer to int to hold the value received as a parameter from main thread */
	int *x_ptr = (int *)ptr;
	/*! incrementing the value to 100 */
	while(++(*x_ptr)<100);                       
	printf("x increment finshed......\n");
	return NULL;
}

/*! main program starts */
int main()
{
	/*! declaring variables one is passed to thread and another is used by main thread */
	int x=0,y=0;                      
	printf("x: %d,y: %d\n",x,y);
        /*! declaring thread variable to hold thread ID */
	pthread_t t1;                             
        /*! creating thread  */
	if(pthread_create(&t1,NULL,Inc_x,&x))                
	{
		printf("Error while creating a thread...\n");
	}
	/*! incrementing the y value to 100 */
	while(++y<100);                       
	printf("y increment finshed....\n");
        /*! waitng for thread to finish */
	if(pthread_join(t1,NULL))         
	{
		printf("Error while joining a thread...\n");
	}
        /*! printing the values on display  */
	printf("x: %d,y: %d\n",x,y);               
}
