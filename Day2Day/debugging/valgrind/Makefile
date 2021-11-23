all:mem_leak_valgrind mem_double_free write_after_free

%.o:%.c
	$(CC) $(CFLAGS) -o $^

clean:
	rm -rf *.o mem_leak_valgrind mem_double_free write_after_free
