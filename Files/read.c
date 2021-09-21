#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
int main()
{
	int fd;
	char buf[12];
	fd = open("hello.txt",O_RDONLY);
	if(fd == -1)
	{
		printf("failed...\n");
	}
	read(fd,buf,11);

	printf("data fetched successfully..\n");
	printf("data: %s\n",buf);
}


