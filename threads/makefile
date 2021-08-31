all: thread1 thread2 thread3 thread4 thread5

thread1: thread1.c
	gcc -g -O0 -o thread1 thread1.c -lpthread

thread2: thread2.c
	gcc -g -O0 -o thread2 thread2.c -lpthread

thread3: thread3.c
	gcc -g -O0 -o thread3 thread3.c -lpthread

thread4: thread4.c
	gcc -g -O0 -o thread4 thread4.c -lpthread

thread5: thread5.c
	gcc -g -O0 -o thread5 thread5.c -lpthread

clean:
	rm -rf *.o thread1 thread2 thread3 thread4 thread5

