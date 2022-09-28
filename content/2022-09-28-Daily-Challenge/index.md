+++
updated = 2022-09-28 18:14:00+08:00
title = "2022-09-28 Daily-Challenge"
path = "2022-09-28-Daily-Challenge"
date = 2022-09-28 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 28

## Description

**Remove Nth Node From End of List**

Given the `head` of a linked list, remove the `nth` node from the end of the list and return its head.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/10/03/remove_ex1.jpg)

```
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
```

**Example 2:**

```
Input: head = [1], n = 1
Output: []
```

**Example 3:**

```
Input: head = [1,2], n = 1
Output: [1]
```

 

**Constraints:**

- The number of nodes in the list is `sz`.
- `1 <= sz <= 30`
- `0 <= Node.val <= 100`
- `1 <= n <= sz`

 

**Follow up:** Could you do this in one pass?

## Solution

``` cpp
class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *newHead = new ListNode(-1, head);
    ListNode *tail = newHead;
    ListNode *del = newHead;
    while(n--) tail = tail->next;
    while(tail->next) {
      tail = tail->next;
      del = del->next;
    }
    del->next = del->next->next;
    return newHead->next;
  }
};

// Accepted
// 208/208 cases passed (11 ms)
// Your runtime beats 27.59 % of cpp submissions
// Your memory usage beats 32.26 % of cpp submissions (10.8 MB)
```
