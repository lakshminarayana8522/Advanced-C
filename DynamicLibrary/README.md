<h1> Dynamic Library </h1>

<p>Dynamic libraries help in dynamic linking. Another name for dynamic library is "shared object" or "DLL files" in windows. The extension for dynamic library files is .so</p>
<p> When linker is dynamically linking with dynamic libraries, required function definitions are not copied into executable file. Thus executable size is less.</p>
<p> Shared libraries serve a great advantage of sharing a single copy of library amoung multiple programs, hence they are called shared libraries </p>

<h1> Steps to create dynamic libraries </h1>

<b>step 1: </b> Compile the source files using -fpic option <br />
 	<b> gcc -c -fpic filename.c </b><br />

<b>step2: </b> create shared library using follwing command <br />
      <b> gcc -shared -o libxyz.so filename.o </b><br />

<b> step3: </b> link the shared library to program <br />
	<b> gcc filename.c ./library.so -o filename </b> <br />

<h1> LD_LIBRARY_PATH </h1>

By default the linker search for libraries in standard path.if our libraries present in non standard path. the environment variable <b> LD_LIBRARY_PATH</b> tells the linker to search for libraries in path initilized to <b>LD_LIBRARY_PATH</b>.

<b> step1: </b> telling Gcc where to find the shared library <br />
	<b> gcc -L/home/lakshmi -o prog prog.c -ldisplay </b>

<b> step2: </b> Making library available at runtime using <b>LD_LIBRARY_PATH</b> <br />
	<b>export LD_LIBRARY_PATH=/home/lakshmi </b>

<b> step3: </b> run the program <br />
         <b> ./prog </b>


<h1>display.c </h1>
This file contains the source file of library function.  --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/DynamicLibrary/display.c">code</a>

<h1>prog.c</h1>
This file contains the program that uses the shared library --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/DynamicLibrary/prog.c">code</a>
         
	 
