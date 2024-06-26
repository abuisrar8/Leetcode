Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

 

Example 1:

![image](https://github.com/abuisrar8/Leetcode/assets/51960220/e124fcdb-d31f-4db5-87e1-49466fc2fc4b)

Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
Example 2:


Input: root = [2,1,3]
Output: [2,1,3]
 
![image](https://github.com/abuisrar8/Leetcode/assets/51960220/b2bdf835-f248-4568-8391-b8d54dcc625a)

Constraints:

The number of nodes in the tree is in the range [1, 104].
1 <= Node.val <= 105
