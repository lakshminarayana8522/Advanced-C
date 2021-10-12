#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<wait.h>
#include<string.h>
int main()
{
	/*! to hold the data readed  from the stdin */
	char buf[256];
	int n;
	pid_t cpid;
	

	while(1)
	{
		printf("myShell: ");
		fflush(stdout);
		n = read(0,buf,sizeof(buf));
		buf[n-1] = 0;

		if(strcmp(buf,"quit")==0)
		{
			exit(0);
			
		}
		
		/*! creating child process */
		cpid = fork();
		if(cpid ==0)
		{
	
			system(buf);
			exit(0);
		}

		waitpid(cpid,NULL,WUNTRACED);

	}


	



}

		

