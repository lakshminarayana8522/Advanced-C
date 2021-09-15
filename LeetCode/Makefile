CC=gcc
CFLAGS=-g -O0

all: prog1 prog2 prog3

%.o:%.c
	$(CC) $(CFLAGS) -o $^

clean:
	rm -rf *.o prog1 prog2 prog3
