+++
title = "2021-03-14 Daily-Challenge"
path = "2021-03-14-Daily-Challenge"
date = 2021-03-14 19:50:45+08:00
updated = 2021-03-14 20:02:19+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I gonna review the tasks I've done this week, and finish today's leetcode's [March LeetCoding Challenge](https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/589/week-2-march-8th-march-14th/3671/) with `cpp`.


<!-- more -->

# March LeetCoding Challenge 14

## Description

**Swapping Nodes in a Linked List**

You are given the `head` of a linked list, and an integer `k`.

Return *the head of the linked list after **swapping** the values of the* `kth` *node from the beginning and the* `kth` *node from the end (the list is **1-indexed**).*

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/09/21/linked1.jpg)

```
Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
```

**Example 2:**

```
Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]
```

**Example 3:**

```
Input: head = [1], k = 1
Output: [1]
```

**Example 4:**

```
Input: head = [1,2], k = 1
Output: [2,1]
```

**Example 5:**

```
Input: head = [1,2,3], k = 2
Output: [1,2,3]
```

 

**Constraints:**

- The number of nodes in the list is `n`.
- $1 \le k \le n \le 10^5$
- `0 <= Node.val <= 100`

## Solution

``` cpp
int listLength(ListNode *head) {
  int len = 0;
  while(head) {
    len += 1;
    head = head->next;
  }
  return len;
}
class Solution {
public:
  ListNode* swapNodes(ListNode* head, int k) {
    int len = listLength(head);
    int first = k - 1;
    int second = len - k;
    ListNode *nodeFirst = head;
    while(first--) nodeFirst = nodeFirst->next;
    ListNode *nodeSecond = head;
    while(second--) nodeSecond = nodeSecond->next;
    swap(nodeFirst->val, nodeSecond->val);
    return head;
  }
};
```
