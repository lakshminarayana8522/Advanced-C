#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char name[20];
	int age;
}person;

unsigned int hash(char *ptr)
{
	int len = strlen(ptr);
	return(len % 8);
}

int main()
{
	printf("%d --- %s\n",hash("lakshmi"),"lakshmi");
	printf("%d --- %s\n",hash("venky"),"venky");
	printf("%d --- %s\n",hash("prasad"),"prasad");
	printf("%d --- %s\n",hash("vamsi"),"vamsi");
}

