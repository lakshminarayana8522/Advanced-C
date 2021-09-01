CC=gcc
CFLAGS=-g -O0 -pthread

all: thread1 thread2 thread3 thread4 thread5

%.o:%.c
	$(CC) $(CFLAGS) -o $^
clean:
	rm -rf *.o thread1 thread2 thread3 thread4 thread5

