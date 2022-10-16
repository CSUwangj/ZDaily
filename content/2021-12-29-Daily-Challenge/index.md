+++
title = "2021-12-29 Daily-Challenge"
path = "2021-12-29-Daily-Challenge"
date = 2021-12-29 19:35:00+08:00
updated = 2021-12-29 19:37:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 29

## Description

**Populating Next Right Pointers in Each Node**

You are given a **perfect binary tree** where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

```
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
```

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to `NULL`.

Initially, all next pointers are set to `NULL`.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2019/02/14/116_sample.png)

```
Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
```

**Example 2:**

```
Input: root = []
Output: []
```

 

**Constraints:**

<ul>
	<li>The number of nodes in the tree is in the range <code>[0, 2<sup>12</sup> - 1]</code>.</li>
	<li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
</ul>
 

**Follow-up:**

- You may only use constant extra space.
- The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.

## Solution

``` cpp
class Solution {
public:
  Node* connect(Node* root) {
    Node *curLevel = root;
    while(curLevel) {
      Node *nextLevel = curLevel->left;
      Node *cur = curLevel;
      while(cur) {
        if(!cur->left) break;
        cur->left->next = cur->right;
        if(cur->next) {
          cur->right->next = cur->next->left;
        }
        cur = cur->next;
      }
      curLevel = nextLevel;
    }
    return root;
  }
};

// Accepted
// 58/58 cases passed (20 ms)
// Your runtime beats 57.99 % of cpp submissions
// Your memory usage beats 65.94 % of cpp submissions (16.8 MB)
```
