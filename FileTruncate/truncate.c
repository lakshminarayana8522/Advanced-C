#include<stdio.h>
#include<unistd.h>

int main()
{
	int ret;

	ret = truncate("./data.text",3);

	if(ret == -1)
	{
		perror("truncate");

	}
	return 0;
}
