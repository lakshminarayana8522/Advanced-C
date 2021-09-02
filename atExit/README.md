

<h1>AtExit()</h1>


Sometimes, an application needs to automatically perform some operations on process termination such as garbage collection.
These taskes are performed by exit handlers. An exit handler is a programmer-supplied function that is registered at some point
during the life of the process and is then automatically called during normal process termination vio exit().
Exit handlers are not called if a program terminated abnormally by a signal.

By using the atexit() we can register the exit handlers.

IT is possible to register multiple exit handlers.

When the program terminates these exit handlers are called in reverse order of registration. 

A child process created via fork() inherits a copy of its parent's exit handler registrations.

this folder contains the programming examples of exit handlers.

<h2>atexit1.c</h2>
This file contains program to  create exit handler and registering exit handler. --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/atExit/atexit1.c">code</a>

<h2>atexit2.c</h2>
This file contains program to create multiple exit handlers and registering them, shows in which order they called when program terminates. --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/atExit/atexit2.c">code</a>

<h2>atexit3.c</h2>
This file contains program to understand how the register handlers are inherited when we create a child process using fork. --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/atExit/atexit3.c">code</a>
