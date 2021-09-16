#include<stdio.h>
#include<elf.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char *argv[])
{
	if(argc<2)
	{
		printf("file name is missing.\n");
		exit(1);
	}
        /*! hold the Elf header */
	Elf64_Ehdr header;
	/*! hold the elf section */
	Elf64_Shdr section;
	/*! hold the address of section */
	Elf32_Addr address;
	
	FILE *fptr;
	char *snames;
	int i,arr[5];
	
	/*! opening elf file in read mode */
	fptr = fopen(argv[1],"r");
	/*! first 64 bytes in elf represents the ELF header. reading the header data structure of elf file */
	fread(&header,1,sizeof(header),fptr);

	/*! moving the file pointer position to the last section .shstrtab. This section contains the section names present in ELF file */ 
	fseek(fptr,header.e_shoff+header.e_shstrndx*sizeof(section),SEEK_SET);
        /*! reading the .shstrtab section data structure */
	fread(&section,1,sizeof(section),fptr);
	
	/*! allocating the memeory of size .shstrtab section to hold the all the data present in .shstrtab section. */
	snames = (char *)malloc(section.sh_size);
	
	/*! moving the file pointer position to offset address of .shstrtab section */
	fseek(fptr,section.sh_offset,SEEK_SET);
	
	/*! read the all data in the .shstrtab section into memmory pointed by snames */
	fread(snames,1,section.sh_size,fptr);

	/*! reading the all section names of ELF file */
	for(i=0;i<header.e_shnum;i++)
	{
		/*! hold the name of section */
		char *name = "";
		/*! setting the file pointer position to each section using e_shoff address in the header */
		fseek(fptr,header.e_shoff+i*sizeof(section),SEEK_SET);
		/*! reading the data structure associated with section */
		fread(&section,1,sizeof(section),fptr);
		if(section.sh_name)
		{
			name = snames+ section.sh_name;
			if(strcmp(name,".data")==0)
			{
				fseek(fptr,section.sh_offset+0x10,SEEK_SET);
				fread(arr,5,4,fptr);
				
				
			}
			
		}
		/*! printing the sections name */
		printf("%2u %s\n",i,name);
	}
	printf("data in.data section: ");
	for(i=0;i<5;i++)
	{
	  printf("%d ",arr[i]);
	}

	printf("\n");

	return 0;
}

