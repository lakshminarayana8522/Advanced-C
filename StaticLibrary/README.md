<h1>Library</h1>

Library is a collection of predefined functions. Library cosists of precompiled code in the form of object files

<h1> Static Library </h1>

Static libraries is the result of the linker making the copy of all used library function definitions to the executable file.
static linking creates larger size executable files, and need more space on disk and main memeory. Another name for static library iis "archive files". 
The extension of static library is .a .'
One major advntage of static libraries is speed.

<h2>static Linking: gcc -static filename.c -o filename </h2>

<h3>steps to create static library </h3>

1. you should create object files for libray functions 
 	source code of object files
            sum.o -- <a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/StaticLibrary/sum.c">code</a>
	    mul.o -- <a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/StaticLibrary/mul.c">code</a>
            print.o -- <a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/StaticLibrary/print.c">code</a>

2. the follwing command will create static library with name libabc.a using sum.o, mul.o, print.o object files
    
    ar -rcsv libabc.a sum.o mul.o print.o 
      
      r: it replaces the objects in the library with new ones in command line. if library doesn't contain any objects, this will add them to the library.
      c: do not warn if library is newly created.
      v: means verbose, which tells ar to keep you informed about what it's doing.
      s: it tells ar to create a symbol table, which is somthing extra that gcc needs when using a library.

<h3> To list out the object files in given library the follwing command is used </h3>

 ar -t libabc.a

 <h3> The follwing code will use the functions from library. </h3>
 
   prog1.c --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/StaticLibrary/prog1.c">code<a>

   To compile the above code with static library use the -static command --> gcc -static prog1.c libabd.a -o prog:1
