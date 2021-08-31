

/* this bellow program represents the how exit handlers are registerd 
 * .
 * .
 * .
 * author : Lakshmi NArayana S        */






#include<stdio.h>
#include<stdlib.h>

void out(void)      // programmer defined exit handler....... it is called when program terminated normally.
{
	printf("atexit out success...\n");
}

int main()
{
	if(atexit(out))                                    //Registering the exit handle using atexit().  on failure it will return negative value 
	{
		printf("atExit failed...\n");
	}
}
