#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd;
	char buf1[10] = "abcdefghi";
	char buf2[10];

	fd = open("data.txt",O_RDWR|O_CREAT,0666);
	if(fd == -1)
	{
		printf("failed to open file..\n");
		return;
	}

	write(fd,buf1,9);
	//lseek(fd,0,SEEK_SET);
	read(fd,buf2,9);

	printf("buf1: %s\n",buf1);
	printf("buf2: %s\n",buf2);

	return 0;
}


	
