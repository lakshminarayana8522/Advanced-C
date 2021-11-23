#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>

#define true 1

void *thread1_handler()
{
	int i =0;
	char *str = "ping";

	while(true)
	{
		printf("%c\n",str[i]);
		i = (i+1)%strlen(str);
		sleep(1);
	}
}

void *thread2_handler()
{
	int i =0;
	char *str = "pong";

	while(true)
	{
		printf("%c\n",str[i]);
		i = (i+1)% strlen(str);
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


