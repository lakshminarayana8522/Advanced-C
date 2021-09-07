<h1> IPC Mechanism...The Message Queue </h1>

Message queues are somewhat like pipes, but differ in two important aspects. First, message queue boundaries are preserved, so that readers and writers communicate in ubits of messages, rather than via undelimited  bye stream. second, each message includes an integer type field, and it is possible to select messages by type, rather than reading them in the order in which they were written.

<h2> msg1.c </h2>

This file contains the program to create message queue and perform communication between processes created by fork(). --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/MessageQueue/msg1.c">code</a>

<h2> msg2.c </h2>

This file contains the program to send message to the message queue. --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/MessageQueue/msg2.c">code</a>

<h2> msg3.c </h2>

This file contains the program to read message from the message queue. --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/MessageQueue/msg3.c">code</a>
