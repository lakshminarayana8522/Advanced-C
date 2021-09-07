<h1>gcc - GNU project C and c++ compiler.</h1>

Compilation can invoke upto four stages: preprocessing, compilation, assembly and linking, always in the order.

<h2> options for controlling the preprocessor</h2>
These options control the C preprocessor, which is run on each C source file before actual compilation.
if we use the -E option, nothing is done except preprocessing.

<h3> -include file </h3>
process file as if #include "file" appeared as the first line of the primary source code..

<h3> -D name </h3>
 it will Predefine name as a macro, with definition 1.

<h3> -D name=definition </h3>
it will predefine name as macro and intialize with definition.

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
