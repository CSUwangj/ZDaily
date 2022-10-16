+++
updated = 2022-07-22 18:14:00+08:00
title = "2022-07-22 Daily-Challenge"
path = "2022-07-22-Daily-Challenge"
date = 2022-07-22 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/partition-list/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 22

## Description

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

// Accepted
// 168/168 cases passed (7 ms)
// Your runtime beats 73.71 % of cpp submissions
// Your memory usage beats 32.53 % of cpp submissions (10.3 MB)
```
