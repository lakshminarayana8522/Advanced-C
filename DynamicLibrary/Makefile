CC=gcc
CFLAGS=-c -fpic

all:sum mul print

%.o:%.c
	$(CC) $(CFLAGS) $^

clean:
	rm -rf *.o sum mul print
