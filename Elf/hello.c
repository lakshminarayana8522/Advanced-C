#include<stdio.h>
int a,b,c=2;                     /*! global variables */
static int x,y=10,z=20; /*! gloal static variables */
const char str[] = "hello";
int main()
{
	             /*! local variables */
	static int i,j,k,n=8,m=9;       /*! local static variables */
	printf("hello world\n");
	return 0;
}

