+++
title = "2021-04-14 Daily-Challenge"
path = "2021-04-14-Daily-Challenge"
date = 2021-04-14 19:59:29+08:00
updated = 2021-04-14 20:38:57+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/) and leetcode's [April LeetCoding Challenge](https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/594/week-2-april-8th-april-14th/3706/) with `cpp`.

<!-- more -->

# Reverse Linked List

## Description

Given the `head` of a singly linked list, reverse the list, and return *the reversed list*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/02/19/rev1ex1.jpg)

```
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/02/19/rev1ex2.jpg)

```
Input: head = [1,2]
Output: [2,1]
```

**Example 3:**

```
Input: head = []
Output: []
```

 

**Constraints:**

- The number of nodes in the list is the range `[0, 5000]`.
- `-5000 <= Node.val <= 5000`

 

**Follow up:** A linked list can be reversed either iteratively or recursively. Could you implement both?

## Solution

reverse iteratively

``` cpp
class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    ListNode *newHead = nullptr;
    ListNode *prev;
    ListNode *cur = head;
    while(cur) {
      prev = cur;
      cur = cur->next;
      prev->next = newHead;
      newHead = prev;
    }
    return newHead;
  }
};
```

reverse recursively

``` cpp
class Solution {
public:
  ListNode* reverseList(ListNode* head, ListNode* tail = nullptr) {
    if(!head) return tail;
    ListNode *next = head->next;
    head->next = tail;
    return reverseList(next, head);
  }
};
```

# April LeetCoding challenge14

**Partition List**

Given the `head` of a linked list and a value `x`, partition it such that all nodes **less than** `x` come before nodes **greater than or equal** to `x`.

You should **preserve** the original relative order of the nodes in each of the two partitions.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/01/04/partition.jpg)

```
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
```

**Example 2:**

```
Input: head = [2,1], x = 2
Output: [1,2]
```

 

**Constraints:**

- The number of nodes in the list is in the range `[0, 200]`.
- `-100 <= Node.val <= 100`
- `-200 <= x <= 200`

## Solution

``` cpp
class Solution {
public:
  ListNode* partition(ListNode* head, int x) {
    ListNode *newFront = new ListNode(-1);
    ListNode *frontTail = newFront;
    ListNode *newBack = new ListNode(-1);
    ListNode *backTail = newBack;
    while(head) {
      if(head->val < x) {
        frontTail->next = head;
        frontTail = frontTail->next;
      } else {
        backTail->next = head;
        backTail = backTail->next;
      }
      head = head->next;
    } 
    backTail->next = nullptr;
    frontTail->next = newBack->next;
    ListNode* answer = newFront->next;
    delete newFront;
    delete newBack;
    return answer;
  }
};
```
