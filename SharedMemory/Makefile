CC=gcc
CFLAGS=-g -O0

all: shm1 shm2 shm3 shm4

%.o:%.c
	$(CC) $(CFLAGS) -o $^

clean:
	rm -rf *.o shm1 shm2 shm3 shm4

