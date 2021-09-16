CC=gcc
CFLAGS=-c -fpic

all: display sum

%.o:%.c
	$(CC) $(CFLAGS) $^

clean:
	rm -rf *.o display sum
