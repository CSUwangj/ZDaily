+++
updated = 2022-05-13 17:10:00+08:00
title = "2022-05-13 Daily-Challenge"
path = "2022-05-13-Daily-Challenge"
date = 2022-05-13 17:09:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 13

## Description

**Populating Next Right Pointers in Each Node II**

Given a binary tree

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

![img](https://assets.leetcode.com/uploads/2019/02/15/117_sample.png)

```
Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
```

**Example 2:**

```
Input: root = []
Output: []
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[0, 6000]`.
- `-100 <= Node.val <= 100`

 

**Follow-up:**

- You may only use constant extra space.
- The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.

## Solution

``` cpp
class Solution {
public:
  Node* connect(Node* root) {
    Node *parent = root;
    Node *cur;
    Node *first;
    while(parent) {
      first = NULL;
      while(parent && !(parent->left || parent->right)) parent = parent->next;
      if(!parent) break;
      if(parent->left) {
        cur = parent->left;
        first = cur;
        if(parent->right) {
          cur->next = parent->right;
          cur = cur->next;
        }
      } else {
        cur = parent->right;
        first = cur;
      }
      parent = parent->next;
      while(cur) {
        while(parent && !(parent->left || parent->right)) parent = parent->next;
        if(!parent) break;
        if(parent->left) {
          cur->next = parent->left;
          if(parent->right) {
            cur = cur->next;
            cur->next = parent->right;
          }
        } else {
          cur->next = parent->right;
        }
        parent = parent->next;
        cur = cur->next;
      }
      parent = first;
    }
    return root;
  }
};

// Accepted
// 55/55 cases passed (18 ms)
// Your runtime beats 54.04 % of cpp submissions
// Your memory usage beats 94.51 % of cpp submissions (17.2 MB)
```
