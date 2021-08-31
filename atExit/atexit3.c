
/* this program represents the exit handlers are inherited to child process...
 *
 *
 *
 *
 *
 * author: Lakshmi NArayana S     */




#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void handler1(void)                              //programmer defined exit handler1
{
	printf("in first exit handler...\n");
}


void handler2(void)				//programmer defined exit handler2
{
	printf("in second exit handler...\n");
}


int main()
{
        atexit(handler1);                       //Registering the exit handler1
	atexit(handler2);                       //Registering the exit handler2
	printf("before fork...\n");
	fork();                                 //creating child procees using fork. this will cause each exit handler twice once on parent process termination
					        //once on child process termination
	printf("After fork...\n");
}

