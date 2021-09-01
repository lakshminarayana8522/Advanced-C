
CC=gcc
CFLAGS=-g -O0
a.out: atexit1 atexit2 atexit3
%.o: %.c
	$(CC) $(CFLAGS) -o $^

clean: 
	rm -rf *.o atexit1 atexit2 atexit3
