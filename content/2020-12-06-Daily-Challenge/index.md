+++
title = "2020-12-06 Daily-Challenge"
path = "2020-12-06-Daily-Challenge"
date = 2020-12-06 21:18:11+08:00
updated = 2020-12-06 21:43:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I've already finished review, so I just do today's leetcode's [November LeetCoding Challenge](https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/569/week-1-december-1st-december-7th/3556/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge6

**Populating Next Right Pointers in Each Node II**

## Description

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

**Follow up:**

- You may only use constant extra space.
- Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.

**Example 1:**

![img](https://assets.leetcode.com/uploads/2019/02/15/117_sample.png)

```
Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
```

**Constraints:**

- The number of nodes in the given tree is less than `6000`.
- `-100 <= node.val <= 100`

## Solution

use a order traversal is naive and easy

``` cpp
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> cur;
        queue<Node*> next;
        cur.push(root);
        while(cur.size()) {
            while(cur.size()) {
                Node* curNode = cur.front();
                cur.pop();
                curNode->next = cur.size() ? cur.front() : NULL;
                if(curNode->left) next.push(curNode->left);
                if(curNode->right) next.push(curNode->right);
            }
            cur = next;
            while(next.size()) next.pop();
        }
        return root;
    }
};
```

another solution is not so elegant

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
```