/* This program will demonistrates how to create threads using pthread_create
 *
 *
 *
 *
 * author: Lakshmi Narayana S     */






#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
void * routinue(void *ptr)                //definig a route while will be executed by threads.
{
	int type = (int )ptr;             //type casting to appropriate type.
	fprintf(stderr,"type: %d\n",type);   // printing the value on display.
	return ptr;
}

int main(int argc,char **argv)
{
	pthread_t t1,t2;                       //declaring  thread variables.

	int a = 2;                             //initializing varibles these are passed to handler as a arguments.
	int b = 3;

	pthread_create(&t1,NULL,routinue,a);  //it will create a thread.
					      //the first argument will be a pointer to thread varible, on successful creation of thread it will put thread ID in the variable
					      //the second argument is thread attributes if we specify NULL it will go with default attribute values
					      //the third argument is a functon or handler 
					      //the fourth argument will be pointer to array of arguments which is to be passed to handler.
	pthread_create(&t2,NULL,routinue,b);

	pthread_join(t1,NULL);                //the phread_join wait for thread to complete,we can also collect status of terminated thread.
	pthread_join(t2,NULL);

}



