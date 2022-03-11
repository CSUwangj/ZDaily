+++
updated = 2022-03-11 18:00:00+08:00
title = "2022-03-11 Daily-Challenge"
path = "2022-03-11-Daily-Challenge"
date = 2022-03-11 18:01:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/rotate-list/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 11

## Description

**Rotate List**

Given the `head` of a linked list, rotate the list to the right by `k` places.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/11/13/rotate1.jpg)

```
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/11/13/roate2.jpg)

```
Input: head = [0,1,2], k = 4
Output: [2,0,1]
```

 

**Constraints:**

- The number of nodes in the list is in the range `[0, 500]`.
- `-100 <= Node.val <= 100`
- `0 <= k <= 2 * 10^9`

## Solution

``` cpp
class Solution {
  int length(ListNode* head) {
    ListNode *cur = head;
    int len = 0;
    while(cur) {
        cur = cur->next;
        len += 1;
    }
    return len;
  }
public:
  ListNode* rotateRight(ListNode* head, int k) {
    int len = length(head);
    if(!len || k%len == 0) return head;
    k = len - (k % len);
    ListNode *cur = head, *previous;
    while(k--) {
      previous = cur;
      cur = cur->next;
    }
    ListNode *new_head = cur;
    while(cur->next) cur = cur->next;
    cur->next = head;
    previous->next = NULL;
    return new_head;
  }
};

// Accepted
// 231/231 cases passed (16 ms)
// Your runtime beats 22.86 % of cpp submissions
// Your memory usage beats 55.87 % of cpp submissions (11.8 MB)
```
