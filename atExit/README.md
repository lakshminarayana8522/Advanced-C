

AtExit()


Sometimes, an application needs to automatically perform some operations on process termination such as garbage collection.
These taskes are performed by exit handlers. An exit handler is a programmer-supplied function that is registered at some point
during the life of the process and is then automatically called during normal process termination vio exit().
Exit handlers are not called if a program terminated abnormally by a signal.

By using the atexit() we can register the exit handlers.

IT is possible to register multiple exit handlers.

When the program terminates these exit handlers are called in reverse order of registration. 

A child process created via fork() inherits a copy of its parent's exit handler registrations.
