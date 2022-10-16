+++
title = "2021-04-18 Daily-Challenge"
path = "2021-04-18-Daily-Challenge"
date = 2021-04-18 15:30:24+08:00
updated = 2021-04-18 15:47:23+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I gonna review the tasks I've done this week, and finish today's leetcode's [April LeetCoding Challenge](https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/595/week-3-april-15th-april-21st/3712/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 18

## Description

**Remove Nth Node From End of List**

Given the `head` of a linked list, remove the <code>n<sup>th</sup></code> node from the end of the list and return its head.

**Follow up:** Could you do this in one pass?

 

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
```
