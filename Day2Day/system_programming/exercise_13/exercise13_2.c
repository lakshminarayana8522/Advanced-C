#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

#define true 1

void *thread1_handler()
{
	while(true)
	{
		printf("ping\n");
		sleep(1);
	}
}


void *thread2_handler()
{
	while(true)
	{
		printf("pong\n");
		sleep(1);
	}
}

int main()
{
	pthread_t t1,t2;

	pthread_create(&t1,NULL,thread1_handler,NULL);
	pthread_create(&t2,NULL,thread2_handler,NULL);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	
	return 0;
}

