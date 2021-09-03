<h1> Wait() system call </h1>

The wait system call waits for one of the children of the calling process to terminate and returns the termination status of that child in the buffer pointed by the status.
<h2> Syntax: pid_t wait(int *status) </h2>

Returns process id of terminated child, or -1 on error.
If no child of the calling process has yet terminated, the call blocks until one of the children terminates. if the child has already teminated by the time of the call, wait() returns immediatly.

<h1>waitpid() system call </h1>

if parent process has created multiple children, it is wait for particular child termination. In case of wait() call if no child has terminated it blocks. in waitpid() it do not blocks the parent.
<h2> Syntx: pid_t waitpid(pid_t pid,int *status,int options) </h2>


<h2>wait1.c</h2>
this file contains the program to understand wait() system call. --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/forkwait/wait1.c">code</a>

<h2>wait2.c</h2>
This file contains the program to understand wait() system call --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/forkwait/wait2.c">code</a>

<h2>wait3.c</h2>
This file contains the program to demonstrate collecting exit status from child on process termination. --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/forkwait/wait3.c">code</a>

<h2>wait4.c</h2>
This file contains the program to demonstrate waitpid() system call --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/forkwait/wait4.c">code</a>

<h2>wait5.c</h2>
This file contains the program to collect exit status from child and also tells the which signal causes the child to terminate. --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/forkwait/wait5.c">code</a>

