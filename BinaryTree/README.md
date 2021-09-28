<h1>Binary Tree</h1>
<p>The Binary tree means that the node can have maximum two children. Here, binary name itself suggests that 'two'; therefore, each node can have either 0, 1 or 2 children.</p>
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/binary-tree.png">
</p>

<p>The above tree is a binary tree because each node contains the utmost two children. The logical representation of the above tree is given below:</p>
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/binary-tree2.png">
</p>
<p>In the above tree, node 1 contains two pointers, i.e., left and a right pointer pointing to the left and right node respectively. The node 2 contains both the nodes (left and right node); therefore, it has two pointers (left and right). The nodes 3, 5 and 6 are the leaf nodes, so all these nodes contain NULL pointer on both left and right parts.</p>

<h2>Properties of binary tree</h2>
<p>At each level of i, the maximum number of nodes is 2^i<br />
The height of the tree is defined as the longest path from the root node to the leaf node. The tree which is shown above has a height equal to 3. Therefore, the maximum number of nodes at height 3 is equal to (1+2+4+8) = 15. In general, the maximum number of nodes possible at height h is (20 + 21 + 22+….2h) = 2h+1 -1.<br />
The minimum number of nodes possible at height h is equal to h+1.</p>


<h2>tree.c</h2>
This file contains the program to execute the binary tree. --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/BinaryTree/tree.c">code</a>
