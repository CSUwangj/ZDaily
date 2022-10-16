+++
updated = 2022-07-21 18:14:00+08:00
title = "2022-07-21 Daily-Challenge"
path = "2022-07-21-Daily-Challenge"
date = 2022-07-21 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/number-of-matching-subsequences/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 21

## Description

**Reverse Linked List II**

Given the `head` of a singly linked list and two integers `left` and `right` where `left <= right`, reverse the nodes of the list from position `left` to position `right`, and return *the reversed list*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/02/19/rev2ex2.jpg)

```
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
```

**Example 2:**

```
Input: head = [5], left = 1, right = 1
Output: [5]
```

 

**Constraints:**

- The number of nodes in the list is `n`.
- `1 <= n <= 500`
- `-500 <= Node.val <= 500`
- `1 <= left <= right <= n`

 

**Follow up:** Could you do it in one pass?

## Solution

``` cpp
class Solution {
public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode *newHead = new ListNode();
    ListNode *newCur = newHead;
    ListNode *cur = head;
    int pos = 1;
    while(pos < left) {
      newCur->next = cur;
      cur = cur->next;
      newCur = newCur->next;
      pos += 1;
    }
    ListNode *midTail = cur;
    ListNode *midCur = nullptr;
    ListNode *next;
    while(pos <= right) {
      next = cur->next;
      cur->next = midCur;
      midCur = cur;
      cur = next;
      pos += 1;
    }
    newCur->next = midCur;
    newCur = midTail;
    newCur->next = next;
    return newHead->next;
  }
};

// Accepted
// 44/44 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 17.76 % of cpp submissions (7.5 MB)
```
