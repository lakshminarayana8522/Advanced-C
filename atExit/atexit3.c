
/* this program represents the exit handlers are inherited to child process...
 * filename  : atexit3.c
 * author    : Lakshmi Narayana S    
 * email     : narayana8522@gmail.com
 * date      : 1 Sep 2021
 */
/*! Includes */
#include<stdio.h> /*! required for printf() */
#include<stdlib.h>  /*! required for atexit() */
#include<unistd.h>  /*! required for fork() */
/*! defining exit handler 1 */
void handler1(void)                             
{
	printf("in first exit handler...\n");
}
/*! defining exit handler 2 function */
void handler2(void)		
{
	printf("in second exit handler...\n");
}

/*! main program starts */
int main()
{
	/*! Registering the exit handler1 */
        atexit(handler1);                   
	/*! Registering the exit handler2 */
	atexit(handler2);                   
	printf("before fork...\n");
        /*!creating child procees using fork. this will cause each exit handler twice once on parent process
	 * termination once on child process termination
	 */
	fork();
	printf("After fork...\n");
}

