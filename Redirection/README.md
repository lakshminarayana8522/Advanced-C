<h1>dup()</h1>

The dup() system call creates a copy of a file descriptor. <br />

It uses the lowest-numbered unused descriptor for the new descriptor.<br />
If the copy is successfully created, then the original and copy file descriptors may be used interchangeably. <br />
They both refer to the same open file description and thus share file offset and file status flags.<br />

<h3>Syntax:</h3>

int dup(int oldfd); <br />
oldfd: old file descriptor whose copy is to be created.<br />

<h1>dup2()</h1>

The dup2() system call is similar to dup() but the basic difference between them is that instead of using the lowest-numbered unused file descriptor, it uses the descriptor number specified by the user.

<h3>Syntax:</h3>

int dup2(int oldfd, int newfd);

oldfd: old file descriptor <br />
newfd new file descriptor which is used by dup2() to create a copy.<br />


<h2>i_redirection.c</h2>
This file contains the program which performs the input redirection using dup() system call --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/Redirection/i_redirection.c">code</a>

<h2>o_redirection.c</h2>
This file contains the program which performs the output redirection using dup() system call --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/Redirection/o_redirection.c">code</a>

<h2>dup2.c</h2>
This file contains the program which performs the input redirection using dup2() system call --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/Redirection/dup2.c">code</a>
