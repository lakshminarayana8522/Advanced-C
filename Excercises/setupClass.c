#include<stdio.h>
#include<stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include<unistd.h>


int main(int argc, char *argv[])
{
	char *buf,*buf1;
	FILE *fptr;
	buf = getcwd(buf,30);
	if(argc == 2)
	{
		mkdir(argv[1],0777);
		chdir(argv[1]);
	}
	else
	{
		mkdir("sysProg",0777);
		chdir("sysProg");
	}
	char *dire[] = {"test","Excercise","program"};
	char *arr[][3] = {{"test1","test2","test3"},
			{"excer1","excer2","excer3"},
			{"prog1","prog2","prog3"}};
	int i,j;
	for(i=0;i<3;i++)
	{
		mkdir(dire[i],0777);
		buf1 = getcwd(buf1,100);
		chdir(dire[i]);
		for(j=0;j<3;j++)
		{
			mkdir(arr[i][j],0777);
		}
		chdir(buf1);

	}

	chdir(buf);
	return 0;
}

