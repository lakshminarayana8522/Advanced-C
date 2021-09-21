#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main()
{
	int fd;
	char *arr = "Hello world";
	int size;
	fd = open("hello.txt",O_WRONLY|O_APPEND);

	size = write(fd,arr,strlen(arr));
	
	printf("data written successfully\n");
	printf("size: %d\n",size);
	return 0;
}


