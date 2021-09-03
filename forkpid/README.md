<h1> getpipd() </h1>

Each process has a process ID (PID), a positive integer that uniquely identifies the process on the system.
syntax: pid _t getpid(void);

Always successfully returns proces ID of caller.
The pid_t data type used for the return value of getpid() is an integer type specified for the purpose of storing process IDs.

<h1> getppid() </h1>
Each process has a parent- the process that created it. A process can find out the process ID of its parent using the getppid() system call.

Syntax: pid _t getppid(void);

it always successfully returns process ID of parent of caller.

<h2>pid_example1.c</h2>
This file contains the program to get the process id and parent process id. --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/forkpid/pid_example1.c">code</a>

<h2>pid_exmaple2.c</h2>
This file contains the program to get the process IDs of child process created by fork. --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/forkpid/pid_example2.c">code</a>

