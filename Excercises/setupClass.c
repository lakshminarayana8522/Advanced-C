/**
  This program creates a directory structure for all of your files associated with the excercises, assignments, and tests.
  This program has one optional command line argument which represents the name of the root directory to setup.
  If the argument is omitted then the root directory should default to "sysProg".

  The directory structure should be constructed as follws:

  					<root>

  	test			program					excercise
 test1 test2 test3	 prog1 prog2 prog3 prog4 prog 5		exce1 exer2 exer3 exer4 exer5 exer6 exer7 exer8 exer9 exer10

Filename : setupClass.c
Author   : Lakshmi Narayana S
Email    : narayana8522@gmail.com
Date	 : 1 Oct 2021
*/

/*! include headers */
#include<stdio.h>   		/*! required for printf() */
#include<stdlib.h>		/*!			 */
#include <sys/stat.h>		/*! required for mkdir(),chdir() */
#include <sys/types.h>         /*! required for chdir(), getcwd() */
#include<unistd.h>		/*! required for system() */
#include<string.h>		/*! required for strcmp() */
#include<errno.h>		/*! required for errno, strerror() */


/**
  This function creates sub-directories for each directory
  @param[in] directory name
  */
void create(char *ptr)
{
	if(strcmp(ptr,"test")==0)
	{
		system("mkdir test1 test2 test3");
	}
	else if(strcmp(ptr,"Excercise")==0)
	{
		system("mkdir exer1 exer2 exer3 exer4 exer5 exer6 exer7 exer8 exer9 exer10");
	}
	else
	{
		system("mkdir prog1 prog2 prog3 prog4 prog5");
	}
}

/*! main program starts */
int main(int argc, char *argv[])
{
	/*! to hold the path returend by getcwd() system call */
	char *buf1=NULL,*buf=NULL;
	/*! store the current working directory path */

	if((buf = getcwd(buf,100))==NULL)
	{
		printf("%s\n",strerror(errno));
		exit(0);
	}

	if(argc == 2)
	{
		/*! check if the directory exists os not */
		if((access(argv[1],F_OK))==0)
		{
			printf("Directory already exists..\n");
			exit(0);
		}
		/*! creating root directory specified in command line input */
		if(mkdir(argv[1],0777)==-1)
		{
			printf("%s\n",strerror(errno));
			exit(0);
		}
		/*! move to the root directory */
		if(chdir(argv[1])==-1)
		{
			printf("%s\n",strerror(errno));
			exit(0);
		}
	}
	else
	{
		/*! checking for directory existance */
		if(access("sysProg",F_OK)==0)
		{
			printf("Directory already exists..\n");
			exit(0);
		}
		/*! if not exists and command line input is not supplied creates root directory with name "sysProg"*/
		if(mkdir("sysProg",0777)==-1)
		{
			printf("%s\n",strerror(errno));
			exit(0);
		}
		/*! move to the root directory */
		if(chdir("sysProg")==-1)
		{
			printf("%s\n",strerror(errno));
			exit(0);
		}
	}
	/*! hold the sub-directories name */
	char *dire[] = {"test","Excercise","program"};
	/*! variables for looping */
	int i,j;
	/*! loop will execute for all 3 sub-directories */
	for(i=0;i<3;i++)
	{
		/*! creating sub-directory */
		if(mkdir(dire[i],0777)==-1)
		{
			printf("%s\n",strerror(errno));
			exit(0);
		}
		/*! hold the sub-directory path */
		if((buf1 = getcwd(buf1,100)) == NULL)
		{
			printf("%s\n",strerror(errno));
			exit(0);
		}
		
		/*! move to the sub-directiory */
		if(chdir(dire[i])==-1)
		{
			printf("%s\n",strerror(errno));
			exit(0);
		}
		/*! calling create() function to create folders in side the sub-directory */
		create(dire[i]);
		/*! after creating folders in each sub-directory get back to root directory */
		if(chdir(buf1)==-1)
		{
			printf("%s\n",strerror(errno));
			exit(0);
		}

	}
	if(chdir(buf)==-1)
	{
		printf("%s\n",strerror(errno));
		exit(0);
	}
	return 0;
}

