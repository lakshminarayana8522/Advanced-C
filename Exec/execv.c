#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>


int main(int argc, char *argv[])
{
	int i;
	printf("in execv program...\n");
	char *args[] = {"hello","from","Execv",NULL};
	i=execv("./hello",args);
	printf("i: %d\n",i);
	printf("%d .... %s\n",errno,strerror(errno));
	printf("after execv...\n");
}

