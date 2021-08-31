#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/wait.h>


int main()
{
	int fd[2];
	pid_t pid;

	pipe(fd);

	if(pid == 0)
	{
		char string[10];
		close(fd[1]);
		dup2(fd[0],STDIN_FILENO);
		scanf("%s",string);
		fprintf(stdout,"the messahe is: %s\n",string);
	}
	else
	{
		FILE *stream;
		close(fd[0]);
		stream = fdopen(fd[1],"w");
		fprintf(stream,"%s","Hello..!");
		fflush(stream);
		fprintf(stdout,"A message has been written to pipe.\n");
		close(fd[1]);
		waitpid(pid,NULL,0);
	}
	return 0;
}

