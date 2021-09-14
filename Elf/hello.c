#include<stdio.h>
int a,b,c=2;                     /*! global variables */
static int x,y=10,z=20;         /*! gloal static variables */
int main()
{
	int i,j=5;                 /*! local variables */
	static int i,j,k,n,m;       /*! local static variables */
	printf("hello world\n");
	return 0;
}

