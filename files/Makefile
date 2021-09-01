CC=gcc
CFLAGES=-g -O0

all: fgetc fputc fgets fputs fprintf fread fwrite transfer fseek

%.o:%.c
	$(CC) $(CFLAGS) -o $^
clean: 
	rm -rf *.o fgetc fputc fgets fputs fprintf fread fwrite fseek transfer
