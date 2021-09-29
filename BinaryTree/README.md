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
<h2>Key Words</h2>
<p><b>Root</b> It is first  node of the tree. or Root is the only node which doesn't have parent.</p>
<p><b>Branch/Edge/Arc</b> Connectivity between the nodes. If we have N number of nodes then we will have N-1 branches.</p>
<p><b>Internal Nodes</b> A node which has parent as well as child is called Internal nodes</p>
<p><b>Leaf Node</b> A node without childrens are called leaf nodes.</p>

<h2>Height Of Node</h2>
<p>Number of edges or branches present in the longest path from the given node to leaf node. Height of tree is the height of root node.</p>
<h2>Depth Of Node</h2>
<p>Number of edges present in the path from the node to the root. Maximum depth and height of tree is same</p>
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/height.png">
</p>
 
<h2>Properties of binary tree</h2>
<p>At each level of i, the maximum number of nodes is 2^i<br />
The height of the tree is defined as the longest path from the root node to the leaf node. The tree which is shown above has a height equal to 3. Therefore, the maximum number of nodes at height 3 is equal to (1+2+4+8) = 15. In general, the maximum number of nodes possible at height h is (20 + 21 + 22+….2h) = 2h+1 -1.<br />
The minimum number of nodes possible at height h is equal to h+1.</p>

<h2>Types of Binary Tree</h2>
<p>Full/ proper/ strict Binary tree</p>
<p>Complete Binary tree</p>
<p>Perfect Binary tre</p>
<p>Degenerate Binary tree</p>
<p>Balanced Binary tree</p>

<h2>Strict Binary Tree</h2>
<p>The full binary tree is also known as a strict binary tree. The tree can only be considered as the full binary tree if each node must contain either 0 or 2 children. The full binary tree can also be defined as the tree in which each node must contain 2 children except the leaf nodes.</p>

<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/strict.png">
</p>

<h2>Complete Binary Tree</h2>
<p>The complete binary tree is a tree in which all the nodes are completely filled except the last level. In the last level, all the nodes must be as left as possible. In a complete binary tree, the nodes should be added from the left.</p>
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/complete.png">
</p>
<p>The above tree is a complete binary tree because all the nodes are completely filled, and all the nodes in the last level are added at the left first.</p>

<h2>Perfect Binary Tree</h2>
<p>A tree is a perfect binary tree if all the internal nodes have 2 children, and all the leaf nodes are at the same level.</p>
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/perfect.png">
</p>

<h2>Degenerate Binary Tree</h2>
<p>The degenerate binary tree is a tree in which all the internal nodes have only one children.</p>
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/degenerate.png">
</p>

<h2>Balanced Binary Tree</h2>
<p>The balanced binary tree is a tree in which both the left and right trees differ by atmost 1. For example, AVL and Red-Black trees are balanced binary tree.</p>
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/balanced.png">
</p>
<p>The above tree is a balanced binary tree because the difference between the left subtree and right subtree is zero.</p>
<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/balanced.png">
</p>
<p>The above tree is not a balanced binary tree because the difference between the left subtree and the right subtree is greater than 1.</p>


<h2>tree.c</h2>
This file contains the program to execute the binary tree. --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/BinaryTree/tree.c">code</a>
