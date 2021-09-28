<h1>Problem</h1>
After getting her PhD, Christie has become a celebrity at her university, and her facebook profile is full of friend requests. Being the nice girl she is, Christie has accepted all the requests.

Now Kuldeep is jealous of all the attention she is getting from other guys, so he asks her to delete some of the guys from her friend list.

To avoid a 'scene', Christie decides to remove some friends from her friend list, since she knows the popularity of each of the friend she has, she uses the following algorithm to delete a friend.

Algorithm Delete(Friend):
    DeleteFriend=false
    for i = 1 to Friend.length-1
         if (Friend[i].popularity < Friend[i+1].popularity)
            delete i th friend
            DeleteFriend=true
            break
    if(DeleteFriend == false)
        delete the last friend

<h2>Input:</h2>
First line contains T number of test cases. First line of each test case contains N, the number of friends Christie currently has and K ,the number of friends Christie decides to delete. Next lines contains popularity of her friends separated by space.

<h2>Output:</h2>
For each test case print N-K numbers which represent popularity of Christie friend's after deleting K friends.

<h2>Constraints</h2>
1<=T<=1000
1<=N<=100000
0<=K< N
0<=popularity_of_friend<=100

<h2>NOTE:</h2>
Order of friends after deleting exactly K friends should be maintained as given in input.

<h3>Sample Input</h3>
3
3 1
3 100 1
5 2
19 12 3 4 17
5 3
23 45 11 77 18
<h3>Sample Output</h3>
100 1 
19 12 17 
77 18 

<b>solution</b> --<a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/HackerEarth/delete_friend.c">code</a>


<h1>Double Linked List </h1>

You are given a doubly linked list which in addition to the next and previous pointers, it could have a child pointer, which may or may not point to a separate doubly linked list. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in the example below.

Flatten the list so that all the nodes appear in a single-level, doubly linked list. You are given the head of the first level of the list.

 

Example 1:

Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
Output: [1,2,3,7,8,11,12,9,10,4,5,6]
Explanation:

The multilevel linked list in the input is as follows:

<p align ="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/multilevellinkedlist.png">
</p>

After flattening the multilevel linked list it becomes:
<p align ="center">
<img src="https://github.com/lakshminarayana8522/Advanced-C/blob/main/Gcc/figures/multilevellinkedlistflattened.png">
</p>


Example 2:

Input: head = [1,2,null,3]
Output: [1,3,2]
Explanation:

The input multilevel linked list is as follows:

  1---2---NULL
  |
  3---NULL
Example 3:

Input: head = []
Output: []
 

How multilevel linked list is represented in test case:

We use the multilevel linked list from Example 1 above:

 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL
The serialization of each level is as follows:

[1,2,3,4,5,6,null]
[7,8,9,10,null]
[11,12,null]
To serialize all levels together we will add nulls in each level to signify no node connects to the upper node of the previous level. The serialization becomes:

[1,2,3,4,5,6,null]
[null,null,7,8,9,10,null]
[null,11,12,null]
Merging the serialization of each level and removing trailing nulls we obtain:

[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
 

Constraints:

The number of Nodes will not exceed 1000.
1 <= Node.val <= 105


<h2>Solution </h2> -- <a href="https://github.com/lakshminarayana8522/Advanced-C/tree/main/HackerEarth/double1.c">code</a>
