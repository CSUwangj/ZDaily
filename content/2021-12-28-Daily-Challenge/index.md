+++
title = "2021-12-28 Daily-Challenge"
path = "2021-12-28-Daily-Challenge"
date = 2021-12-28 14:15:00+08:00
updated = 2021-12-28 14:17:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/middle-of-the-linked-list/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 28

## Description

**Middle of the Linked List**

Given the `head` of a singly linked list, return *the middle node of the linked list*.

If there are two middle nodes, return **the second middle** node.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/07/23/lc-midlist1.jpg)

```
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/07/23/lc-midlist2.jpg)

```
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
```

 

**Constraints:**

- The number of nodes in the list is in the range `[1, 100]`.
- `1 <= Node.val <= 100`

## Solution

``` cpp
class Solution {
  int length(ListNode *head) {
    int result = 0;
    while(head) {
      result += 1;
      head = head->next;
    }
    return result;
  }
  ListNode *advance(ListNode *head, int count) {
    while(count--) {
      head = head->next;
    }
    return head;
  }
public:
  ListNode* middleNode(ListNode* head) {
    return advance(head, length(head) / 2);
  }
};

// Accepted
// 36/36 cases passed (4 ms)
// Your runtime beats 40.59 % of cpp submissions
// Your memory usage beats 96.09 % of cpp submissions (7 MB)
```
