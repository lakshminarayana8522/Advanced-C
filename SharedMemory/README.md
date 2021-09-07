<h1>IPC Mechanism....Shared Memory </h1>
Shared memory allows two or more processes to share the same region of physical memory. Since shared memory segment becomes part of a process's user space memory, no kernel intervention is required for IPC. All that is required is that one process copies data into the shared memory, That data is immediatly available to all othet processers sharing the same segment

<h2> shm1.c </h2>

This file contains the program to create shared memory segment. --<a href="https://github.com/lakshminarayan8522/Advanced-C/tree/main/SharedMemory/shm1.c">code</a>

<h2> shm2.c </h2>

This file contains the program to copy the data into shared memory segment. --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/SharedMemory/shm2.c">code</a>

<h2> shm3.c </h2>

This file contains the program to read data from shared memory segment. --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/SharedMemory/shm3.c">code</a>

<h2> shm4.c </h2>

This file contains the  program to delete shared memory and get the details of shrared memory segment. --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/SharedMemory/shm4.c">code</a>


