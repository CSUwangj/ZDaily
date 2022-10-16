+++
updated = 2022-03-12 08:09:00+08:00
title = "2022-03-12 Daily-Challenge"
path = "2022-03-12-Daily-Challenge"
date = 2022-03-12 08:10:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/copy-list-with-random-pointer/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 12

## Description

**Copy List with Random Pointer**

A linked list of length `n` is given such that each node contains an additional random pointer, which could point to any node in the list, or `null`.

Construct a [**deep copy**](https://en.wikipedia.org/wiki/Object_copying#Deep_copy) of the list. The deep copy should consist of exactly `n` **brand new** nodes, where each new node has its value set to the value of its corresponding original node. Both the `next` and `random` pointer of the new nodes should point to new nodes in the copied list  such that the pointers in the original list and copied list represent  the same list state. **None of the pointers in the new list should point to nodes in the original list**.

For example, if there are two nodes `X` and `Y` in the original list, where `X.random --> Y`, then for the corresponding two nodes `x` and `y` in the copied list, `x.random --> y`.

Return *the head of the copied linked list*.

The linked list is represented in the input/output as a list of `n` nodes. Each node is represented as a pair of `[val, random_index]` where:

- `val`: an integer representing `Node.val`
- `random_index`: the index of the node (range from `0` to `n-1`) that the `random` pointer points to, or `null` if it does not point to any node.

Your code will **only** be given the `head` of the original linked list.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2019/12/18/e1.png)

```
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2019/12/18/e2.png)

```
Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
```

**Example 3:**

**![img](https://assets.leetcode.com/uploads/2019/12/18/e3.png)**

```
Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
```

 

**Constraints:**

- `0 <= n <= 1000`
- `-104 <= Node.val <= 10^4`
- `Node.random` is `null` or is pointing to some node in the linked list.

## Solution

``` cpp
class Solution {
public:
  Node* copyRandomList(Node* head) {
    if(!head) return nullptr;
    // copy nodes
    Node *cur = head;
    while(cur) {
      Node *newNode = new Node(cur->val);
      newNode->next = cur->next;
      newNode->random = cur->random;
      cur->next = newNode;
      cur = newNode->next;
    }

    // fix random
    cur = head;
    while(cur) {
      cur = cur->next;
      if(cur->random) cur->random = cur->random->next;
      cur = cur->next;
    }
    
    // separate two list
    Node *newHead = head->next;
    cur = head;
    Node *newCur = newHead;
    while(cur) {
      cur->next = newCur->next;
      cur = cur->next;
      newCur->next = cur ? cur->next : nullptr;
      newCur = newCur->next;
    }
    
    return newHead;
  }
};

// Accepted
// 19/19 cases passed (8 ms)
// Your runtime beats 84.2 % of cpp submissions
// Your memory usage beats 98.36 % of cpp submissions (11.1 MB)
```
