
<h1> IPC Mechanism</h1>
<h2>PIPE</h2>

Pipes can be used to transfer data between the related processes (Processes created using fork()).
Pipe is a byte stream, means that process reading from a pipe can read blocks of data oy any size, regardless of the size of the block written by writting process.
The data passes through the pipe sequentially, bytes are read from a pipe in exactly the order they were written.
Pipes are unidirectional ,data can travel only in one direction through pipe. One end of pipe is used for writting, and other end of the pipe is used for reading.
Pipes have a limited capacity. A pipe is simply a buffer maintained in kernel memory.If pipe is full, further writes to the pipe block until the reader removes some data from the pipe

the pipe() system call creates a new pipe

int pipe(int pipefd[2]);

Returns 0 on success, or -1 on failure

This folder contains the programming examples of pipe
 
