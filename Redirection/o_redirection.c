#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
int main()
{
	int fd,fd1;
	char arr[100];

	fd = open("data.text",O_WRONLY|O_CREAT,0777);
	if(fd==-1)
	{
		printf("file not opend...\n");
		exit(0);
	}

	close(1);

	gets(arr);
	
	fd1 = dup(fd);

	printf("fd1: %d\n",fd1);

	puts(arr);

	close(fd);

	return 0;
}


