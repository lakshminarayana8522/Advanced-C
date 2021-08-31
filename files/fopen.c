#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE *fp;
	fp = fopen("file1.c","w");
	if(fp==NULL){
		printf("Error in opening a file....\n");
		exit(1);
	}
	printf("File successfully opend in write mode....\n");
	fclose(fp);
}

