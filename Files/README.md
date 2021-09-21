<h1> File I/O (Handling Files using System Calls) </h1>

There are various system calls available for file I/O such as <b>open()</b> <br />
							      <b>read()</b> <br />
							      <b>write()</b> <br />
							      <b>lseek()</b> <br />
							      <b>close()</b> <br />


<h2>open() </h2>

open() system call possibly creates a file or device and returns a file descriptor

int open(const char *pathname,int flags);
int open(const char *pathname,int flags,mode_t mode);

Returns file descriptor on success, or -1 on error.  <br />
The file to be opend is identified by the pathname argument <br />

The flags argument is a bit mask that specifies the access mode for the file, using one of the constants below<br />

<b>O_RDONLY:</b> Open the file for reading only. <br />
<b>O_WRONLY:</b> Open the file for writing only. <br />
<b>O_RDWR  :</b> Open the file for both reading and writing. <br />
<b>O_CREAT :</b> Create file if it doesn't exist <br />
<b>O_APPEND:</b> Writes are always appended to end of the file <br />


<h2>read() </h2>

read() system call reads data from the open file refered by the desctiptor fd. <br />

size_t read(int fd, void *buffer, size_t count);

Returns number of bytes read, 0 on EOF, or -1 on error. <br />

The count argument specifies the maximum number of bytes to read. <br />
The buffer argument supplies the address of the memory buffer into which the input data is to e placed. <br />

<h2>write() </h2>

The write() system call writes data to an open file <br />

size_t write(int fd, void *buffer, size_t count); <br />

Returns number of bytes written, or -1 on error. <br />

The buffer is the address of the data to be written.<br />
Count is the number of bytes to write from buffer. <br />

<h2>lseek() </h2>

lseek() system call used to set the file pointer position in a file.

int lseek(int fd,size_t offset,wherence);

Returns the number of bytes shifted on success, or -1 on failure.<br />

The first parameter is the file descriptor of the file, which you can get using open() system call. the second parameter specifies how much you want the pointer to move and the third parameter is the reference point of the movement i.e., beginning of file(SEEK_SET), current position(SEEK_CUR) of pointer or end of file(SEEK_END).

<h2>close()</h2>

The close system call closes an open file descriptor, freeing it for subsequent reuse by the process. when a process terminates, all of its open file descriptors are automatically closed.

int close(int fd);

Returns 0 on success, or -1 on error.

<h2>open.c</h2>
This file contains the program to create and open a file using open() system call. --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/Files/open.c">code</a>

<h2>write.c</h2>
This file contains the program to write data into a file using write() system call. --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/Files/write.c">code</a>

<h2>read.c</h2>
This file contains the program to read data from a file using read() system call. --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/Files/read.c">code</a>

<h2>lseek.c</h2>
This file contains the program to reposition the file pointer in a file using lseek() system call. --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/Files/lseek.c">code</a>


