#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>
#include<semaphore.h>
#define true 1

char ptr[100];

sem_t sem;

void *thread1_handler()
{
	FILE *fptr = fopen("data.txt","r");
	if(fptr == NULL)
	{
		printf("file not opend...\n");
		exit(0);
	}
	char word[100];
	int cnt = 0;
	while((fscanf(fptr,"%s",word))!=EOF)
	{
		cnt++;
	}

	fseek(fptr,0,0);

	char arr[cnt][12];

	
	cnt =0;
	while((fscanf(fptr,"%s",word))!=EOF)
	{

		strcpy(arr[cnt],word);
		cnt++;
	}

	fclose(fptr);
	
	
	int i = 0;
	while(true)
	{
		
		while(i<cnt)
		{
			
			strcpy(ptr,arr[i]);
			sem_post(&sem);
			sleep(1);
			i++;
		}

	
	}

}


void *thread2_handler()
{

	while(true)
	{
		sem_wait(&sem);
		printf("%s\n",ptr);
		
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

