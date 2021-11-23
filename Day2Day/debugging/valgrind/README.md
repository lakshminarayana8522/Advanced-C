<h1>Valgrind tool </h1>

<p>Valgrind is a memory mismanagement detector. It shows you memory leaks, deallocation errors, etc. Actually, Valgrind is a wrapper around a collection of tools that do many other things (e.g., cache profiling); however, here we focus
on the default tool, memcheck. Memcheck can detect:  </p>

<p>
	Use of uninitialised memory

	Reading/writing memory after it has been free'd

	Reading/writing off the end of malloc'd blocks

	Reading/writing inappropriate areas on the stack
	
	Memory leaks -- where pointers to malloc'd blocks are lost forever

	Mismatched use of malloc/new/new [] vs free/delete/delete []

	Overlapping src and dst pointers in memcpy() and related functions

	Some misuses of the POSIX pthreads API 
</p>


<h2> to check for memory leaks run your code using valgrind as shown in follwing </h2>

<p>
	valgrind --leak-check=full ./a.out 
</p>
<h1>Memory leak </h1>
<p>I have created a program which causes the memory leak </p>
<p>mem_leak_valgrind.c <a href="https://github.com/lakshminarayana1516/Advanced-C-1/tree/main/Day2Day/debugging/valgrind/mem_leak_valgrind.c">----code</a></p>
<h3>run the above program using valgrind tool</h3>
<p>
	valgrind --tool=memcheck --leak-check=yes ./mem_leak_valgrind 
</p>
<h1>Reasult</h1>
<p align="center">
<img src="https://github.com/lakshminarayana1516/Advanced-C-1/blob/main/figures/valgrind.png">
</p>


<h1>Double free </h1>
<p>This program will free the dynamically allocated memory twice. we can detect this using valgrind</p>
<p>mem_double_free.c <a href="https://github.com/lakshminarayana1516/Advanced-C-1/tree/main/Day2Day/debugging/valgrind/double_free.c">---code</a></p>

<h3>Run the above program using valgrind tool </h3>
<p>
	valgrind --tool=memcheck --leak-check=yes ./mem_double_free
</p>
<h1>Result</h1>
<p align="center">
<img src="https://github.com/lakshminarayana1516/Advanced-C-1/blob/main/figures/double_free.png">
</p>
