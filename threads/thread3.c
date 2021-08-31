/*this program will demonistates the thereads will share the global resources
 *
 *
 *
 *
 *
 * author: Lakshmi Narayana S    */






#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *Inc_x(void *ptr)             //defining a thread handler 
{
	int *x_ptr = (int *)ptr;
	while(++(*x_ptr)<100);                       //this will increments the c value to 100
	printf("x increment finshed......\n");
	return NULL;
}

int main()
{
	int x=0,y=0;                       //declaring variables and initilized them with 0 value
	printf("x: %d,y: %d\n",x,y);

	pthread_t t1;                             //declaring a thread variable type of pthread_t.

	if(pthread_create(&t1,NULL,Inc_x,&x))                 //creating a thread. this will excute the thread handler concurrently with main thread.
	{
		printf("Error while creating a thread...\n");
	}

	while(++y<100);                               //incermenting the y value in main thread
	printf("y increment finshed....\n");

	if(pthread_join(t1,NULL))                    //it will wait untill the thread is finshed.
	{
		printf("Error while joining a thread...\n");
	}

	printf("x: %d,y: %d\n",x,y);               
}
