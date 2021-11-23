#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

#define true 1

void *thread_handler()
{
	while(true)
	{
		printf("hello world\n");
		sleep(1);
	}
}


int main()
{
	pthread_t t1;

	pthread_create(&t1,NULL,thread_handler,NULL);
	
	
	pthread_join(t1,NULL);


	return 0;
}
