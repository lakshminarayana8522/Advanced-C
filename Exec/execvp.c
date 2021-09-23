#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("before execvp...\n");
	execvp("./hello",NULL);
	printf("after execvp..\n");
	return 0;
}

