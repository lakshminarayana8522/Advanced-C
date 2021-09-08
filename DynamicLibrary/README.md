<h1>Dynamic Library</h1>

Dynamic libraries help in dynamic linking. Another name for dynamic lirary is "shared object" or "DLL files" in windows.
The extension for dynamic library filrs is .so

When linker is dynamically linking with dynamic libraries, required function definitions are not copied to executable file. Thus executable file size is less.

Shared libraries serve a great advantange of sharing a single copy of library amoung multiple programs, hence they are called shared libraries

<h2> steps to create dynamic libraries </h2>

 source files for library functions
     sum.c --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/DynamicLibrary/sum.c">code</a>
     mul.c --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/DynamicLibrary/mul.c">code</a>
     print.c --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/DynamicLibrary/print.c">code</a>

 1. Compile the source files using -fpic option.

 2. The command to create dynamic library is
     <h3> gcc -shared -o libxyz.so sum.o mul.o print.o </h3>
     libxyz.so is a shared object.

<h2>prog1.c</h2>

This file contains the program which uses the dynamic library functions. --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/DynamicLibrary/prog1.c">code</a>

<h2> To link dynamic library with program: gcc filename.c ./libxyz.so -o filename </h2>
