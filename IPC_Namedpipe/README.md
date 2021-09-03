<h1> IPC mechanism..The FIFO </h1>
A FIFO is similar to a pipe. The principal difference is that a FIFO has a name within the file system and is opened in the same way as a regular file. The FIFO is also called as named pipe.
This allows a FIFO to be used for communication between unrelated processes.The FIFO must be opened at both ends simultaneously before you can proceed to do any input or output operations on in.
Opening a FIFO for reading normally blocks the until some other process open the same FIFO for writing and vice versa.

<h2> Syntax: int mkfifo(const char *pathname,mode_t mode); </h2>

Returns 0 on success, -1 on failure.

mkfifo() creates a FIFO special file with name pathname. 
The mode specifies the FIFOs permissions.

<h2>npipe1.c</h2>
This file contains the program to crate a FIFO file using mkfifo. --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/IPC_Namedpipe/npipe1.c">code</a>

<h2>npipe2.c</h2>
This file contains the program to create a FIFO and perform read and write on FIFO. --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/IPC_Namedpipe/npipe2.c">code</a>

<h2>npipe3.c</h2>
This file contains the program to create a FIFO and performm the communication between process/ -- <a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/IPC_Namedpipe/npipe3.c">code</a>
