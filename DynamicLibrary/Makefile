CC=gcc
CFLAGS=-c -fpic

all:display

%.o:%.c
	$(CC) $(CFLAGS) $^

clean:
	rm -rf *.o display
