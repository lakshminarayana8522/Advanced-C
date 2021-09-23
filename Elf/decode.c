#include<stdio.h>
#include<stdlib.h>
#include<elf.h>
#include<string.h>
int main(int argc, char *argv[])
{

	if(argc<2)
	{
		printf("Elf file is missing...\n");
		exit(0);
	}

	FILE *fp_elf;
	Elf64_Ehdr header;
	Elf64_Shdr section;
	int i,arr[5];
	char *snames;
	char data[22];

	fp_elf = fopen(argv[1],"r");
	if(fp_elf == NULL)
	{
		printf("Error occuured while opening a file...\n");
		exit(0);
	}
	
	fread(&header,1,sizeof(header),fp_elf);
	

	fseek(fp_elf,header.e_shoff+(header.e_shstrndx * header.e_shentsize),SEEK_SET);

	fread(&section,1,sizeof(section),fp_elf);

	snames = (char *)malloc(section.sh_size);

	fseek(fp_elf,section.sh_offset,SEEK_SET);

	fread(snames,1,section.sh_size,fp_elf);

	for(i=0;i<header.e_shnum;i++)
	{
		char *name;
		fseek(fp_elf,header.e_shoff+i*header.e_shentsize,SEEK_SET);
		fread(&section,1,sizeof(section),fp_elf);
		if(section.sh_name)
		{
			name = snames+section.sh_name;
			if(strcmp(name,".rodata")==0)
			{
				
				fseek(fp_elf,section.sh_offset+4,SEEK_SET);
				fread(data,1,section.sh_size,fp_elf);
			}
			else if(strcmp(name,".data")==0)
			{
				fseek(fp_elf,section.sh_offset+16,SEEK_SET);
				fread(arr,5,4,fp_elf);
			}

	
		}
		printf("%d %s\n",i,name);
	}
	printf("\n");
	printf("Data present in .rodata section: ");
	printf("%s\n",data);
	printf("\n");
	printf("data present in .data section: ");
	for(i=0;arr[i];i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");			
	return 0;
}




