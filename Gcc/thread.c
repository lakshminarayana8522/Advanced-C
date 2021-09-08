#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void *routinue()
{
	printf("thread created successfully...\n");
}



int main()
{
	pthread_t t1;
	pthread_create(&t1,NULL,routinue,0);
	pthread_join(t1,NULL);
	return 0;
}


