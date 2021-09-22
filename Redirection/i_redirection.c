#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd;
	char arr[100];

	fd = open("data.text",O_RDONLY);
	if(fd == -1)
	{
		printf("file not opened..\n");
		exit(0);
	}

	close(0);
	
	printf("fd: %d\n",fd);

	dup(fd);

	printf("fd: %d\n",fd);

	gets(arr);

	puts(arr);

	return 0;
}




	
