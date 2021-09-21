CC=gcc
CFLAGS=-g -O0

all: sorted

%.o:%.c
	$(CC) $(CFLAGS) -o $^

clean:
	rm -rf *.o sorted
