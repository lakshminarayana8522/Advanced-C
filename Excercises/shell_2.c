/**
  This program will implement the shell to execute all commands 

filename : shell_2.c
author   : Lakshmi Narayana S
email    : narayana8522@gmail.com
date     : 11 Oct 2021

*/



/*! includes headers */
#include<stdio.h> 		/*! required for printf() */
#include<stdlib.h>		/*! required for exit() */
#include<unistd.h>		/*! required for execv() */
#include<fcntl.h>		/*! required for read() */
#include<string.h>		/*! required for strcmp(), strtok() */
#include<wait.h>		/*! required for wait() */

/*! main program starts */
int main()
{
	char buf[1024];
	char path[1024];
	char cmd[1024] = {"/bin/"};
	int n,i,background;
	char *token;
	/*! hold the process id */
	pid_t cpid;
	char *args[10];

	while(1)
	{	/*! printing prompt as myShell */
		printf("myShell: ");
		/*! flushing stdout  */
		fflush(stdout);
		/*! reading input from stdin */
		n = read(0,buf,sizeof(buf));
		/*! assigning null character inplace of new line */
		buf[n-1] = 0;
		/*! if user enetrs quit it exit from the program */
		if(strcmp("quit",buf)==0)
		{
			exit(EXIT_SUCCESS);
		}
		/*! extracting the user entered commands through stdin and storing it in characer array */
		i=0;
		token = strtok(buf," ");

		/*! if user enters wc it will execute the user defined wcCmd program instead of standard wc */
		if(strcmp(token,"wc")==0)
		{
			args[i] = "wcCmd";
			i++;
			strcpy(path,"./wcCmd");

		}
		
		/*! for standared commands */
		else
		{
			
		
			while(token!=NULL)
			{
				args[i] = token;
				token = strtok(NULL," ");
				i++;
			}
			strcpy(path,cmd);
			strcat(path,args[0]);
		}
		args[i] = 0;

		
		/*! check process weather it is run in background */
		i=0;
		while(args[i] != NULL)
		{
			if(strcmp(args[i],"&")==0)
			{
				background = 1;
				args[i] = NULL;
				break;
			}
			i++;
		}

		
	/*! creating process */
		cpid = fork();
		
		if(cpid == 0)
		{
			/*! executing commands in child process */
			execv(path,args);
			exit(EXIT_SUCCESS);
		}
		else
		{
			/*! if process required to in background then the parent will not wait for child */
			if(!background)
			{
				/*! waiting for child to finish its execution */
				wait(NULL);
			}

			background = 0;

		}



		

		
	}

	return 0;






}

		


		
		
