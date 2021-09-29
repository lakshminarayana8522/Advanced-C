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
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/thumb1.PNG">
</p>
<h2>Conditional execution</h2>
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

<h2>Cache Memory</h2>
<p>Cache memory is a high-speed memory, which is small in size but faster than the main memory (RAM). The CPU can access it more quickly than the primary memory. So, it is used to synchronize with high-speed CPU and to improve its performance.</p>
<p>Cache memory can only be accessed by CPU. It can be a reserved part of the main memory or a storage device outside the CPU. It holds the data and programs which are frequently used by the CPU. So, it makes sure that the data is instantly available for CPU whenever the CPU needs this data. In other words, if the CPU finds the required data or instructions in the cache memory, it doesn't need to access the primary memory (RAM). Thus, by acting as a buffer between RAM and CPU, it speeds up the system performance.</p>
<h2>Types of Cache Memory:</h2>
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/cachetypes.jpg">
</p>
<p><b>L1:</b> It is the first level of cache memory, which is called Level 1 cache or L1 cache. In this type of cache memory, a small amount of memory is present inside the CPU itself. If a CPU has four cores (quad core cpu), then each core will have its own level 1 cache. As this memory is present in the CPU, it can work at the same speed as of the CPU. The size of this memory ranges from 2KB to 64 KB. The L1 cache further has two types of caches: Instruction cache, which stores instructions required by the CPU, and the data cache that stores the data required by the CPU.</p>
<p><b>L2:</b> This cache is known as Level 2 cache or L2 cache. This level 2 cache may be inside the CPU or outside the CPU. All the cores of a CPU can have their own separate level 2 cache, or they can share one L2 cache among themselves. In case it is outside the CPU, it is connected with the CPU with a very high-speed bus. The memory size of this cache is in the range of 256 KB to the512 KB. In terms of speed, they are slower than the L1 cache.</p>
<p><b>L3:</b> It is known as Level 3 cache or L3 cache. This cache is not present in all the processors; some high-end processors may have this type of cache. This cache is used to enhance the performance of Level 1 and Level 2 cache. It is located outside the CPU and is shared by all the cores of a CPU. Its memory size ranges from 1 MB to 8 MB. Although it is slower than L1 and L2 cache, it is faster than Random Access Memory (RAM).</p>
<h2>How does cache memory work with CPU?</h2>
<p>When CPU needs the data, first of all, it looks inside the L1 cache. If it does not find anything in L1, it looks inside the L2 cache. If again, it does not find the data in L2 cache, it looks into the L3 cache. If data is found in the cache memory, then it is known as a cache hit. On the contrary, if data is not found inside the cache, it is called a cache miss.

If data is not available in any of the cache memories, it looks inside the Random Access Memory (RAM). If RAM also does not have the data, then it will get that data from the Hard Disk Drive.

So, when a computer is started for the first time, or an application is opened for the first time, data is not available in cache memory or in RAM. In this case, the CPU gets the data directly from the hard disk drive. Thereafter, when you start your computer or open an application, CPU can get that data from cache memory or RAM.</p>

<h2> Cache Algorithms</h2>
<p>A Cache algorithm is an algorithm used to manage a cache or group of data. When the cache is full, it decides which item should be deleted from the cache.</p>

</h3>First in first out (FIFO)</h3>
<p>Using this algorithm the cache behaves in the same way as a FIFO queue. The cache evicts the blocks in the order they were added, without any regard to how often or how many times they were accessed before.</p>

<h3>Last in first out (LIFO) or First in last out (FILO)</h3>
<p>Using this algorithm the cache behaves in the same way as a stack and opposite way as a FIFO queue. The cache evicts the block added most recently first without any regard to how often or how many times it was accessed before.</p>
<h3>Most Recently Used (MRU):</h3> 
<p>This algorithm deletes the most recently used items first. This caching mechanism is commonly used for database memory caches.</p>
<p>The access sequence for the below example is A B C D E C D B.</p>

<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/MRU.png">
</p>

<p>Here, A B C D are placed in the cache as there is still space available. At the 5th access E, we see that the block which held D is now replaced with E as this block was used most recently. Another access to C and at the next access to D, C is replaced as it was the block accessed just before D and so on.</p>


<h3>Least Frequently Used (LFU):</h3>
<p> LFU counts how often an item is needed. Those that are used least often are discarded first.</p>
<p>The access sequence for the below example is A B C D E D F.</p>

<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/LRU.png">
</p>


<p>In the above example once A B C D gets installed in the blocks with sequence numbers (Increment 1 for each new Access) and when E is accessed, it is a miss and it needs to be installed in one of the blocks. According to the LRU Algorithm, since A has the lowest Rank(A(0)), E will replace A.

In the second last step D is accessed and therefore the sequence number is updated.

LRU, like many other replacement policies, can be characterized using a state transition field in a vector space, which decides the dynamic cache state changes similar to how an electromagnetic field determines the movement of a charged particle placed in it</p>

<h3>Random replacement (RR)</h3>
<p>Randomly selects a candidate item and discards it to make space when necessary. This algorithm does not require keeping any information about the access history. For its simplicity, it has been used in ARM processors.</p>

<h3>Least-frequently used (LFU)</h3>
<p>Counts how often an item is needed. Those that are used least often are discarded first. This works very similar to LRU except that instead of storing the value of how recently a block was accessed, we store the value of how many times it was accessed. So of course while running an access sequence we will replace a block which was used fewest times from our cache. E.g., if A was used (accessed) 5 times and B was used 3 times and others C and D were used 10 times each, we will replace B.</p>

<h2>Types of memory</h2>
<p>There are many different types of memory.

<h3>RAM (Random Access Memory)</h3>
<p>RAM, which stands for Random Access Memory, is a hardware device generally located on the motherboard of a computer and acts as an internal memory of the CPU. It allows CPU store data, program, and program results when you switch on the computer. It is the read and write memory of a computer, which means the information can be written to it as well as read from it.</p>
<p>RAM is a volatile memory, which means it does not store data or instructions permanently. When you switch on the computer the data and instructions from the hard disk are stored in the RAM, e.g., when the computer is rebooted, and when you open a program, the operating system (OS), and the program are loaded into RAM, generally from an HDD or SSD. CPU utilizes this data to perform the required tasks. As soon as you shut down the computer, the RAM loses the data. So, the data remains in the RAM as long as the computer is on and lost when the computer is turned off. The benefit of loading data into RAM is that reading data from the RAM is much faster than reading from the hard drive.</p>

<h3>SRAM (Static Random Access Memory </h3>
<p>Static RAM (SRAM) is a type of random access memory that retains its state for data bits or holds data as long as it receives the power. It is made up of memory cells and is called a static RAM as it does not need to be refreshed on a regular basis because it does not need the power to prevent leakage, unlike dynamic RAM. So, it is faster than DRAM.</p>
<p>The drawback with Static RAM is that its memory cells occupy more space on a chip than the DRAM memory cells for the same amount of storage space (memory) as it has more parts than a DRAM. So, it offers less memory per chip.</p>

<h3>Dynamic RAM</h3>
<p>Dynamic Ram (DRAM) is also made up of memory cells. It is an integrated circuit (IC) made of millions of transistors and capacitors which are extremely small in size and each transistor is lined up with a capacitor to create a very compact memory cell so that millions of them can fit on a single memory chip. So, a memory cell of a DRAM has one transistor and one capacitor and each cell represents or stores a single bit of data in its capacitor within an integrated circuit.

The capacitor holds this bit of information or data, either as 0 or as 1. The transistor, which is also present in the cell, acts as a switch that allows the electric circuit on the memory chip to read the capacitor and change its state.

The capacitor needs to be refreshed after regular intervals to maintain the charge in the capacitor. This is the reason it is called dynamic RAM as it needs to be refreshed continuously to maintain its data or it would forget what it is holding. </p>

<h3>Synchronous DRAM</h3>
<p>SDRAM (Synchronous DRAM) began to appear in late 1996. In SDRAM, the RAM was synchronized with the CPU clock. It allowed the CPU or to be precise the memory controller to know the exact clock cycle or timing or the number of cycles after which the data will be available on the bus. So, the CPU does not need for the memory accesses and thus the memory read and write speed can be increased. The SDRAM is also known as the single data rate SDRAM (SDR SDRAM) as data is transferred only at each rising edge of the clock cycle. </p>

<h3>DDR SDRAM</h3>
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/ram6.png">
</p>
<p>The next generation of the synchronous DRAM is known as the DDR RAM. It was developed to overcome the limitations of SDRAM and was used in PC memory at the beginning of the year 2000. In DDR SDRAM (DDR RAM), the data is transferred twice during each clock cycle; during the positive edge (rising edge) and the negative edge (falling edge) of the cycle. So, it is known as the double data rate SDRAM.

There are different generations of DDR SDRAM which include DDR1, DDR2, DDR3, and DDR4.</p>

<h3>Read Only Memory(ROM)</h3>
<p>ROM stands for Read Only Memory. The memory from which we can only read but cannot write on it. This type of memory is non-volatile. The information is stored permanently in such memories during manufacture. A ROM stores such instructions that are required to start a computer. This operation is referred to as bootstrap. ROM chips are not only used in the computer but also in other electronic items like washing machine and microwave oven.</p>

<h3>Flash ROM </h3>
<p> special type of memory that works like both RAM and ROM. You can write information to flash memory, like you can with RAM, but that information isn’t erased when the power is off, like it is with ROM. The erasing and writing of flash ROM are completely software controlled with no additional hardware circutary required, Which reduces the manufacturing costs.It stores information in an arrangement or array of memory cells made from floating-gate transistors. The advantage of using this memory is that you can delete or write blocks of data around 512 bytes at a particular time. Whereas, in EEPROM, you can delete or write only 1 byte of data at a time. So, this memory is faster than EEPROM.</p> 


<h2>Peripherals</h2>
Embedded System that interact with the outside world need some form of peripheral device. A peripheral device performs input and output functions for the chip by connecting to other devices or sensors that aree off-chip.

<h3>Interrupt controllers </h3>
<p>When a peripheral or device requires attention, it raises an interrupt to the processor. There are two types of interrupt controllers avaiable for the ARM processor. The standard interrupt controller and the Vector interrupt controller(VIC).

<b>The standard interrupt controller</b> sends an interrupt signal to the processor core when an external device request servicing.


<b>Nested vector interrupt control (NVIC)</b> is a method of prioritizing interrupts, improving the MCU’s performance and reducing interrupt latency. NVIC also provides implementation schemes for handling interrupts that occur when other interrupts are being executed or when the CPU is in the process of restoring its previous state and resuming its suspended process.</p>
