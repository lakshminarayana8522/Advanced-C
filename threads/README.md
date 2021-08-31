


.....................Threads.................................


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
