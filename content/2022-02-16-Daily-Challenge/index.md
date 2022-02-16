+++
title = "2022-02-16 Daily-Challenge"
path = "2022-02-16-Daily-Challenge"
date = 2022-02-16 18:13:00+08:00
updated = 2022-02-16 18:14:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/swap-nodes-in-pairs/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 16

## Description

**Swap Nodes in Pairs**

Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e.,  only nodes themselves may be changed.)

 

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

``` cpp
class Solution {
public:
  ListNode* swapPairs(ListNode* head) {
    ListNode *newHead = new ListNode(-1, head);
    ListNode *cur = newHead;
    while(head) {
      if(head->next) {
        ListNode *tmp = head->next->next;
        cur->next = head->next;
        head->next->next = head;
        head->next = tmp;
        cur = cur->next->next;
        head = tmp;
      } else {
        head = head->next;
      }
    }
    return newHead->next;
  }
};

// Accepted
// 55/55 cases passed (3 ms)
// Your runtime beats 70.43 % of cpp submissions
// Your memory usage beats 55.41 % of cpp submissions (7.5 MB)
```
