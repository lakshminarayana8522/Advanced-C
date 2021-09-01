/**
 * This program will demonistrates how to create threads using pthread_create
 * filename  : thread1.c
 * author    : Lakshmi Narayana S 
 * email     : narayana8522@gmail.com
 * date      : 1 Sep 2021  
 */

/*! Includes  */
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
/*! routine function to handle by the threads */
void * routinue(void *ptr)                
{
	/*! type casting argument to integer type */
	int type = (int )ptr;             
	/*! printing the value of type on display */
	fprintf(stderr,"type: %d\n",type);   
	return ptr;
}

/*! main function starts */
int main(int argc,char **argv)
{
	/*! t1,t2 are used to hold the thread Id */
	pthread_t t1,t2;                       
        /*! these are the integer varible used to pass as an arguments to threads */
	int a = 2;                          
	int b = 3;
	/*! creating thread 1 */
	pthread_create(&t1,NULL,routinue,a);
	/*! creating another thread */
	pthread_create(&t2,NULL,routinue,b);
	/*! waiting for the thread 1 to finish */
	pthread_join(t1,NULL);               
	/*! waiting for the thread 2 to finish */
	pthread_join(t2,NULL);

}



