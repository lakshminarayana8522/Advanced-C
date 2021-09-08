<h1>gcc - GNU project C and c++ compiler.</h1>

Compilation can invoke upto four stages: preprocessing, compilation, assembly and linking, always in the order.

<h2> options for controlling the preprocessor</h2>
These options control the C preprocessor, which is run on each C source file before actual compilation.
if we use the -E option, nothing is done except preprocessing.

<h3> -include file </h3>
process file as if #include "file" appeared as the first line of the primary source code..
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/include3.PNG">
</p>

if above program is compiled it shows error because it does not contain header file.
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/include1.PNG">
</p>
we can solve the above problem by compiling the program using bellow command
<h2> gcc -include stdio.h prog.c -o prog </h2>
The above command include the header file to the program.
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/include2.PNG">
</p>

<h3> -D name </h3>
 it will Predefine name as a macro, with definition 1.
<div>
#include<stdio.h>

if above program is compiled it shows error because of MAX is undefined.
by using the follwing command we can define the macros
<h2> gcc -D MAX prog.c -o prog </h2>
by default -D name command initialize the macro with value 1.


<h3> -D name=definition </h3>
it will predefine name as macro and intialize with definition.
<div>

#include<stdio.h>

int main()
{
	printf("%d\n",MAX);
	return 0;
}
</div>

The above program will throw error because of undefined MAX;
the following command will resolve the issue by defining the MAX
<h2> gcc -D MAX=10 prog.c -o prog </h2>


<h3> -pthreads </h3>
Define additional macros required for using the POSIX threads library.

<h3> gcc -wall </h3>

gcc -wall enables all comipler's warnings messages. This option should always be used, inorder to generate better code.

Syntax:  gcc -wall filename.c -o filename


<h3>gcc -shared </h3>

gcc -shared generates the shared object file for shared library.

syntax: gcc -shared filename.c -o filename

<h3>-pipe </h3>
use pipes rather than temparary files for communication between the variour stages of compilation.
