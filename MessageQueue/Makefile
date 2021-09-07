CC=gcc
CFLAGS=-g -O0

all: msg1 msg2 msg3

%.o:%.c
	$(CC) $(CFLAGS) -o $^

clean:
	rm -rf *.o msg1 msg2 msg3
