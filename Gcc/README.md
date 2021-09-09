<h1>gcc - GNU project C and c++ compiler.</h1>

Compilation can invoke upto four stages: preprocessing, compilation, assembly and linking, always in the order.


<h1> -include file </h1>
process file as if #include "file" appeared as the first line of the primary source code..
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/include3.PNG">
</p>

if above program is compiled it shows error because it does not contain header file.
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/include1.PNG">
</p>
we can solve the above problem by compiling the program using bellow command
<h3> gcc -include stdio.h prog.c -o prog </h3>
The above command include the header file to the program.
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/include2.PNG">
</p>

<h1> -D name </h1>
 it will Predefine name as a macro, with definition 1.
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/d1.PNG">
</p>

if above program is compiled it shows error because of MAX is undefined.
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/d2.PNG">
</p>
by using the follwing command we can define the macros
<h3> gcc -D MAX prog.c -o prog </h3>
by default -D name command initialize the macro with value 1.
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/d3.PNG">
</p>


<h1> -D name=definition </h1>
it will predefine name as macro and intialize with definition.
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/d1.PNG">
</p>
The above program will throw error because of undefined MAX;
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/d2.PNG">
</p>
the following command will resolve the issue by defining the MAX
<b> gcc -D MAX=10 prog.c -o prog </b>
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/d4.PNG">
</p>


<h1> -pthreads </h1>
Define additional macros required for using the POSIX threads library.
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/thread1.PNG">
</p>
the above code produces errors because it usees thread related libraries
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/thread2.PNG">
</p>
the follwing command will solve the error
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/thread3.PNG">
</p>

<h1> gcc -wall </h1>

gcc -wall enables all comipler's warnings messages. This option should always be used, inorder to generate better code.
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/wall1.PNG">
</p>
Syntax:  gcc -wall filename.c -o filename
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/wall2.PNG">
</p>


<h1>gcc -shared </h1>

gcc -shared generates the shared object file for shared library.

syntax: gcc -shared filename.c -o filename
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/shared.PNG">
</p>

<h1> -ggdb3 </h1>
This command give us permission to debug the program using gdb. -g option for debugging.
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/gdb.PNG">
</p>

<h1> -Wunused-macros </h1>
Warn about the macros defined in the main file that are unused
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/macro1.PNG">
</p>
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/macro2.PNG">
</p>
<h1> -save-temps </h1>
This commmand produces the differnt files for each compilation stage.
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/save.PNG">
</p>


<h1> -lm </h1>
This command link math.h library to our source file, -l option is used for linking particular library, for math.h we use -lm

<h1> -c </h1>
This command compile the program and give the object file as output, which is used to make libraries.

