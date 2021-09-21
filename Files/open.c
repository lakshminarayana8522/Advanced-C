#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>

int main()
{
	int fd;

	fd = open("hello.txt",O_RDONLY|O_CREAT);

	if(fd == -1)
	{
		printf("file not opened...\n");
		return;
	}
	printf("fd: %d\n",fd);
}
