<h1>fork()...system call</h1>
The fork() system call allows one process, the parent, to create a new process called child. This is done by making the new child process an exact duplicate of the parent.
The child obtains copies of the parent's stack, data, heap, and text segments.

<h2>syntax: pid_t fork(void);</h2>

In parent it returns the process ID of child
In child it returns 0.
on error it returns -1

<h2>fork1.c</h2>
This file contains the program to create child process. --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/fork/fork1.c">code</a>

<h2>fork2.c</h2>
This file contains the program to understand duplication of parents file discriptor value to child by fork. --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/fork/fork2.c">code</a>
