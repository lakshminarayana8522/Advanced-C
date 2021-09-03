


<h1>Threads</h1>


 Threads are mechanism to do more than one job at a time.
 unlike processes, thread share same address space and other resources.
 Threads runs independently  from its main program.
 Threads increases the performence.
 if main program terminates all threads created by main will also terminates.

 the following function are used with threads
  pthread _create() :  to create thread.
  pthread _join()   : it is like wait system call in process it will wait untill the thread finshes
  pthread _exit()   : it will terminates the thread
  pthread _cancel() : it will terminate the calling thread.

 This Folder will contains the programming examples of threads.

<h2>thread1.c</h2>
This file contains the program to create thread.  --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/threads/thread1.c">code</a>

<h2>thread2.c</h2>
This file contains the program to undestand to create multiple threads in for loop. --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/threads/thread2.c">code</a>

<h2>thread3.c</h2>
This file contains the program to understand thread execution with main program. --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/threads/thread3.c">code</a>

<h2>thread4.c</h2>
This file contains the program to understand how thread _cancel() work. --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/threads/thread4.c">code</a>

<h2>thread5.c</h2>
This file contains the program to understand how threads access the shared resource. --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/threads/thread4.c">code</a>


