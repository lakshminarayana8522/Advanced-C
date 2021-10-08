/**
  This program will implement the WC command.

Filename : wcCmd.c
Author   : Lakshmi Narayana S
Email    : narayana8522@gmail.com
Date	 : 5 Oct 2021
*/

/*! include headers */
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>
/*! main program starts */
int main(int argc, char *argv[])
{
	
	int cflag=0,wflag=0,lflag = 0;
	int fd,w=0,l=0,c=0,f=0,i;
	f = argc-1;
	char ch1,ch,*buf,buf2[1024];
	FILE *fptr;
	/*! if input file is not provided through command line it will read from stdin */ 
	if(argc<2)
	{
		cflag=wflag=lflag=1;
		while(fgets(buf2,sizeof(buf2),stdin))
		{
			l++;
			c += strlen(buf2);
			buf = buf2;
			while(*buf)
			{
				if(*buf == ' ' || *buf == '\n' || *buf == '\t')
					i=0;
				else if(i == 0)
				{
					i =1;
					w++;
				}
				++buf;
			}

			
		}
		
	

		
		
		


	}

	/*! if file is provided through command line */
	else
	{
		/*! if options does not provides it will print all word, line, and characters count */
		if(argc == 2)
		{
			wflag = 1;
		}

		/*! checking for options */
		while((ch1 = getopt(argc,argv,"wlc"))!=-1)
		{
			switch(ch1)
			{
				case 'w': wflag = 1;
					  break;
				case 'l': lflag = 1;
					  break;
				case 'c': cflag = 1;
					  break;
				case '?':
			     		 printf("InValid option -%c\n",ch1);
			     	 	 break;
			}
		}
	/*! opening file in read only mode */
	fd = open(argv[f],O_RDONLY);
	/*! calculating line and charcter count */
	while(read(fd,&ch,1))
	{
		if(ch == '\n')
		{
			l++;
			c++;
		
		}
		else
		{
			c++;
		}
	}
	/*! closing file */
	close(fd);
	/*! opening file in readonly mode */
	fptr = fopen(argv[f],"r");
	if(fptr == NULL)
	{
		printf("file not opened....\n");
		exit(0);
	}
	/*! calculating the word count using fscanf() */
	while(fscanf(fptr,"%s",buf)!=EOF)
	{
		w++;
	}
	/*! closing file */
	fclose(fptr);


	}
	
	if(cflag &&  lflag && wflag)
	{
		printf("\ncharacters: %d\n lines: %d\n words:  %d\n",c,l,w);
	}
	else if(cflag)
	{
		printf("characters: %d\n",c);
	}
	else if(lflag)
	{
		printf("lines: %d\n",l);
	}
	else if(wflag)
	{
		printf("words: %d\n",w-1);
	}
	return 0;
}

