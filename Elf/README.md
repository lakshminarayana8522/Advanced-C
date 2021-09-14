<h1> ELF (Executable and Linkable Format) </h1>

ELF is a common standard file format for executable files, object code  and shared libraries

<h1>Structure of ELF file </h1>

An ELF consists of two sections<br>
 -- ELF Header <br>
 -- file data <br>

<p><b>File data sections</b> consists of a program header table describing zero or more segments</p>
<p> and a section header table describing zero or more sections</p>



Each segment contains information that is necessary for run time execution of the file<br>
Sections contains the important data for linking and relocation.

<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/elfs.png">
</p>

<h1> The ELF Header </h1>
The ELF header is 32 bytes long, and identifies the format of the file. It satrts with a sequence of four unique bytes called magic bytes.
The header also indicates whether it is an ELF file for 32-bit or 64-bit format, uses littele or big endianness, shows the ELF version etc..,
 the command used to get ELF header of an application is <b> readelf -h prog </b>
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/elfh.PNG">
</p>

<h1>Program Header </h1>
The program header shows the segments used at run-time, and tells the system how to create process image. The header from above figure shows that ELF file consists of 13 program headers that have a size of 56 bytes each, and the first header starts at byte 64.
The command used to get ELF program header of an application is <b> readelf -l prog </b>
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/elfph.PNG">
</p>

<h1> Section Header </h1>
The section headers define all the sections in the file. This is used for linking and relocation. a segment can have 0 or more sections. for executable files there are four main sections.
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/elfsh.PNG">
</p>
<b>.text:-></b> contains executable code. it will be packed into segment with read write access rights.It only loades once, as the contents will not change.. This can be seen with the <b>objdump</b> utility.<br>

<b>.data:-></b> contains initialized data, with read/write access rights <br>

<b>.rodata:-></b> contains initialized data, with read access rights only <br>

<b>.bss:-></b> contains uninitialized data, with read/write access rights <br

<b>.init :-> </b> This section holds executable instructions tha contributes to the process initialization code. when a program starts to run, the system executes the code in this section.<br />

<b>.fini: -> </b> This section holds the executable instructions that contribute to the process termination code. when program exists normally, the system executes the code in this section. <br />

<b> .dynamic: -> </b> This section holds the dynamic linking information. <br />

<b> .dynsym: -> </b> This section holds the dynamic linking symbol table.  <br />

<h3> consider The following program as an example. and observe the elf file of the program </h3>
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/prog.PNG">
</p>
<h3>The local variable stored in the statck.</h3>

<h3> The initialized global static,local static and global variables stored in data section </h3>
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/global.PNG">
</p>
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/localstatic.PNG">
</p>
