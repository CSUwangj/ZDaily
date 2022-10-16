+++
title = "2021-11-12 Daily-Challenge"
path = "2021-11-12-Daily-Challenge"
date = 2021-11-12 18:22:24+08:00
updated = 2021-11-12 18:45:11+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/remove-linked-list-elements/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 12

## Description

**Remove Linked List Elements**

Given the `head` of a linked list and an integer `val`, remove all the nodes of the linked list that has `Node.val == val`, and return *the new head*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/03/06/removelinked-list.jpg)

```
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
```

**Example 2:**

```
Input: head = [], val = 1
Output: []
```

**Example 3:**

```
Input: head = [7,7,7,7], val = 7
Output: []
```

 

**Constraints:**

- The number of nodes in the list is in the range `[0, 10^4]`.
- `1 <= Node.val <= 50`
- `0 <= val <= 50`

## Solution

``` cpp
class Solution {
public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode *newHead = new ListNode();
    ListNode *cur = newHead;
    while(head) {
      if(head->val != val) {
        cur->next = head;
        cur = cur->next;
      }
      head = head->next;
    }
    cur->next = nullptr;
    return newHead->next;
  }
};

// Accepted
// 66/66 cases passed (20 ms)
// Your runtime beats 84.92 % of cpp submissions
// Your memory usage beats 79.14 % of cpp submissions (15 MB)
```
