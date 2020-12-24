+++
title = "2020-12-24 Daily-Challenge"
path = "2020-12-24-Daily-Challenge"
date = 2020-12-24 18:00:42+08:00
updated = 2020-12-24 18:51:11+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Path Sum](https://leetcode.com/problems/path-sum/) on leetcode and leetcode's [December LeetCoding Challenge](https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/572/week-4-december-22nd-december-28th/3579/) with `cpp`.

<!-- more -->

# Path Sum

## Description

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

**Note:** A leaf is a node with no children.

**Example:**

Given the below binary tree and `sum = 22`,

```
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
```

return true, as there exist a root-to-leaf path `5->4->11->2` which sum is 22.

## Solution

nothing to say

``` cpp
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        if(root->left || root->right) return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
        return sum == root->val;
    }
};
```

# December LeetCoding Challenge24

**Swap Nodes in Pairs**

## Description

Given a linked list, swap every two adjacent nodes and return its head.

You may **not** modify the values in the list's nodes. Only nodes itself may be changed.

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/10/03/swap_ex1.jpg)

```
Input: head = [1,2,3,4]
Output: [2,1,4,3]
```

**Example 2:**

```
Input: head = []
Output: []
```

**Example 3:**

```
Input: head = [1]
Output: [1]
```

**Constraints:**

- The number of nodes in the list is in the range `[0, 100]`.
- `0 <= Node.val <= 100`

## Solution

nothing to say

``` cpp
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *newHead = new ListNode(-1, head);
        ListNode *cur = newHead;
        while(cur->next && cur->next->next) {
            ListNode *nxt = cur->next;
            cur->next = nxt->next;
            nxt->next = cur->next->next;
            cur->next->next = nxt;
            cur = cur->next->next;
        }
        return newHead->next;
    }
};
```