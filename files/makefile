all: fgetc fputc fgets fputs fprintf fread fwrite transfer fseek

fgetc: fgetc.c
	gcc -g -O0 -o fgetc fgetc.c

fputc: fputc.c
	gcc -g -O0 -o fputc fputc.c

fgets: fgets.c
	gcc -g -O0 -o fgets fgets.c

fputs: fputs.c
	gcc -g -O0 -o fputs fputs.c

fprintf: fprintf.c
	gcc -g -O0 -o fprintf fprintf.c

fread: fread.c
	gcc -g -O0 -o fread fread.c

fwrite: fwrite.c
	gcc -g -O0 -o fwrite fwrite.c

fseek: fseek.c
	gcc -g -O0 -o fseek fseek.c

transfer: transfer.c
	gcc -g -O0 -o transfer transfer.c

clean: 
	rm -rf *.o fgetc fputc fgets fputs fprintf fread fwrite fseek transfer
