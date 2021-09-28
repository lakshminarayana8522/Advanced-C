<h1> ARM  Embedded Systems </h1>

<h2> The RISC Design Pholosophy </h2>
<p> The ARM core uses a RISC architecture. RISC is a design philosophy aimed at delivering simple instructions that can execute in single clock cycle at high clock speed. </p>

<h2>The RISC Philosophy is implemented with four major design rules </h2>

<h2>1. Instructions</h2>
<b> RISC processors have a reduced number of instruction classes. These clases provide simple operations that can each execute in single cycle. The compiler or programmer synthesizes complicated operations by combining several simple instructions.Each instruction is a fixed length to allow the pipeline to fetch future instructions before decoding the current instruction.
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/risc.jpg">
</p>

<h2>2. Pipelines </h2>
<p>Pipelining organizes the execution of the multiple instructions simultaneously. Pipelining improves the throughput of the system. In pipelining the instruction is divided into the subtasks. Each subtask performs the dedicated task.</p>

<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/pipeline.jpg">
</p>

<h2>3. Registers </h2>
<p> RISC machines have a large general-purpose register set. Any register can contain either data or an address. Registers act as the fast memory store for all data processing operations.</p>

<h2>4. Load-store Architecture</h2>
<p>ARM uses a load-store model for memory access which means that only load/store (LDR and STR) instructions can access memory. While on x86 most instructions are allowed to directly operate on data in memory, on ARM data must be moved from memory into registers before being operated on. This means that incrementing a 32-bit value at a particular memory address on ARM would require three types of instructions (load, increment, and store) to first load the value at a particular address into a register, increment it within the register, and store it back to the memory from the register.</p>

<p>LDR R2, [R0]   @ [R0] - origin address is the value found in R0.
STR R2, [R1]   @ [R1] - destination address is the value found in R1.</p>
<p>LDR operation: loads the value at the address found in R0 to the destination register R2.</p>

<p>STR operation: stores the value found in R2 to the memory address found in R1.</p>

<h1>ARM Instruction Set For Embedded Systems</h1>
The ARM instruction set differs from the pure RISC definition in several ways that make the ARM instruction set suitable for embedded applications.

<h2>Variable cycle execution for certain instructions </h2>
<p>Not every ARM instruction executes in a single cycle. For example, load-store-multiple instructions vary in the number of execution cycles depending upon the number of registers being transferred.</p>

<h2>Inline barrel shifter </h2>
<p>The ARM arithmetic logic unit has a 32-bit barrel shifter that is capable of shift and rotate operations. The second operand to many ARM and Thumb data-processing and single register data-transfer instructions can be shifted, before the data-processing or data-transfer is executed, as part of the instruction.</p>
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/barrelshifter.jpg">
 </p>

<h2>Thumb 16-bit instruction set</h2>
<p>The Thumb instruction set consists of 16-bit instructions that act as a compact shorthand for a subset of the 32-bit instructions of the standard ARM. Every Thumb instruction could instead be executed via the equivalent 32-bit ARM instruction.</p>

<h2>Conditional ececution</h2>
<p>An instruction is only executed when a specific condition has been satisfied. This feature improves performence and code density by reducing branch instructions.</p>

<h2>Memory</h2>
<p>An embededde system has to have some form of memory to store and excute code. You have to compare price, performance, and power consumption when deciding upon specific memory characteristics, such as hierarchy, width, and type.</p>

<h3>Hierarchy</h3>
<p>All computer systems have memory arranged in some form of hierarchy.The fastest memory cache is physically located nearer the ARM processor core and the slowest secondary memory is set further away. Generally the closer memory is to the processor core, the more it costs and smaller its capacity.
	The cache is place between main memory and the core. It is used to speed up data transfer between the processor and main memory. A cache provides an overall increase in performence but with loss of predictble execution time. The main memory is large around 256kb to 256mb depending on the application and is generally stored in separate chips. Load and store instructions access the main memory unless the values have been stored in the cache for fast access. Secondary is the largest and slowest form of memory. Hard disk drives and CD-ROM drives are examples of secondary storage.</p>

 <p align="center">
 <img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/memory.jpg">
 </p>
<h3>Width</h3>
<p>The memory width is the number of biits the memory returns on each access. Typecally 8, 16, 32, or 64 bits. The memory width has a direct effect on the overall performence and cost ratio.
		If you have an unchached system using 32-bit ARM instructions and 16-bit wide memory chips, then the processor will have to meake two memory fetches per instruction. Each fetch requires two 16-bit loads. This has the effect of reducing the system performence.</p>

<h3>Types of memory</h3>
<p>There are many different types of memory.

<h3>Read Only Memory(ROM)</h3>
<p>ROM stands for Read Only Memory. The memory from which we can only read but cannot write on it. This type of memory is non-volatile. The information is stored permanently in such memories during manufacture. A ROM stores such instructions that are required to start a computer. This operation is referred to as bootstrap. ROM chips are not only used in the computer but also in other electronic items like washing machine and microwave oven.</p>

<h3>Flash ROM </h3>
<p> special type of memory that works like both RAM and ROM. You can write information to flash memory, like you can with RAM, but that information isn’t erased when the power is off, like it is with ROM. The erasing and writing of flash ROM are completely software controlled with no additional hardware circutary required, Which reduces the manufacturing costs.</p> 

<h3>DRAM</h3>
<p>As the name DRAM, or dynamic random access memory, implies, this form of memory technology is a type of random access memory. It stores each bit of data on a small capacitor within the memory cell. The capacitor can be either charged or discharged and this provides the two states, "1" or "0" for the cell.

Since the charge within the capacitor leaks, it is necessary to refresh each memory cell periodically. This refresh requirement gives rise to the term dynamic - static memories do not have a need to be refreshed.</p>

<h3>SRAM</h3>
<p>Static random access memory (SRAM) is faster than the DRAM, but requires more silicon area. SRAM does not require refreshing. The access time for SRAM is shorter than the DRAM because SRAM does not require a pause between data accesses. It is mostly used as caches.</p>

<h3>SDRAM</h3>
<p>Synchronous dynamic random access memory (SDRAM) is dynamic random access memory (DRAM) with an interface synchronous with the system bus carrying data between the CPU and the memory controller hub. SDRAM has a rapidly responding synchronous interface, which is in sync with the system bus. SDRAM waits for the clock signal before it responds to control inputs.</p>

<h2>Peripherals</h2>
Embedded System that interact with the outside world need some form of peripheral device. A peripheral device performs input and output functions for the chip by connecting to other devices or sensors that aree off-chip.

<h3>Interrupt controllers </h3>
<p>When a peripheral or device requires attention, it raises an interrupt to the processor. There are two types of interrupt controllers avaiable for the ARM processor. The standard interrupt controller and the Vector interrupt controller(VIC).

<b>The standard interrupt controller</b> sends an interrupt signal to the processor core when an external device request servicing.


<b>Nested vector interrupt control (NVIC)</b> is a method of prioritizing interrupts, improving the MCU’s performance and reducing interrupt latency. NVIC also provides implementation schemes for handling interrupts that occur when other interrupts are being executed or when the CPU is in the process of restoring its previous state and resuming its suspended process.</p>
