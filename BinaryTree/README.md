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

<h2>Tree Traversal</h2>
<p>Traversal is a process to visit all the nodes of a tree and may print their values too. Because, all nodes are connected via edges (links) we always start from the root (head) node. That is, we cannot randomly access a node in a tree. There are three ways which we use to traverse a tree </p>
In-order Traversal<br />
Pre-order Traversal<br />
Post-order Traversal<br />

<h2>In-Order Traversal </h2>
<p>In this traversal method, the left subtree is visited first, then the root and later the right sub-tree. We should always remember that every node may represent a subtree itself.

If a binary tree is traversed in-order, the output will produce sorted key values in an ascending order.</p>

<h3>Algorithm</h3>
Until all nodes are traversed −<br />
<b>Step 1</b> − Recursively traverse left subtree.<br />
<b>Step 2</b> − Visit root node.<br />
<b>Step 3</b> − Recursively traverse right subtree.<br />

<h2>Pret Order Traversal </h2>
<p>In this traversal method, the root node is visited first, then the left subtree and finally the right subtree</p>

<h3>Algorithm</h3>
Until all nodes are traversed −<br />
Step 1 − Visit root node.<br />
Step 2 − Recursively traverse left subtree.<br />
Step 3 − Recursively traverse right subtree.<br />

<h2>Post-Order Traversal </h2>
<p>In this traversal method, the root node is visited last, hence the name. First we traverse the left subtree, then the right subtree and finally the root node.</p>

<h3>Algorithm</h3>
Until all nodes are traversed −<br />
Step 1 − Recursively traverse left subtree.<br />
Step 2 − Recursively traverse right subtree.<br />
Step 3 − Visit root node.<br />

<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/traversal.jpg">
</p>

<h1>Balenced Tree</h1>
<p>A balanced binary tree is also known as height balanced tree. It is defined as binary tree in when the difference between the height of the left subtree and right subtree is not more than m, where m is usually equal to 1. The height of a tree is the number of edges on the longest path between the root node and the leaf node.</p>

<p align="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/balancedtree.png">
</p>

<h2>Rotate Right </h2>

</p>T1, T2, T3 and T4 are subtrees.
         z                                      y 
        / \                                   /   \
       y   T4      Right Rotate (z)          x      z
      / \          - - - - - - - - ->      /  \    /  \ 
     x   T3                               T1  T2  T3  T4
    / \
  T1   T2  </p>
<h2>tree.c</h2>
This file contains the program to execute the binary tree. --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/BinaryTree/tree.c">code</a>
