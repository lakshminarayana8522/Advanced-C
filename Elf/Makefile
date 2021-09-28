CC=gcc
CFLAGS =-g -O0

all:testElf decode elf1 dynamic variable hello

%.o:%.c
	$(CC) $(CFLAGS) -o $^

clean:
	rm -rf *.o testElf decode elf1 dynamic variable hello
