CC=gcc
CFLAGS=-g -O0

all: i_redirection o_redirection dup2 test

%.o:%.c
	$(CC) $(CFLAGS) -o $^

clean:
	rm -rf *.o i_redirection o_redirection dup2 test


