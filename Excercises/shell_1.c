#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char *path;
	char *token;
	char *pathname;
	char *args[10] = {"pwd",NULL};

	path = getenv("PATH");
	
	token = strtok(path,":");

	while(token != NULL)
	{
		sprintf(pathname,"%s/%s",token,args[0]);

		if(access(pathname,F_OK)==0)
		{
			break;
		}
		token = strtok(NULL,":");

	}
	
	execv(pathname,args);


	return 0;
}



