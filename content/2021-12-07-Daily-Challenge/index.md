+++
title = "2021-12-07 Daily-Challenge"
path = "2021-12-07-Daily-Challenge"
date = 2021-12-07 18:36:00+08:00
updated = 2021-12-07 18:38:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 7

## Description

**Convert Binary Number in a Linked List to Integer**

Given `head` which is a reference node to a singly-linked list. The value of each  node in the linked list is either 0 or 1. The linked list holds the  binary representation of a number.

Return the *decimal value* of the number in the linked list.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2019/12/05/graph-1.png)

```
Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
```

**Example 2:**

```
Input: head = [0]
Output: 0
```

**Example 3:**

```
Input: head = [1]
Output: 1
```

**Example 4:**

```
Input: head = [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
Output: 18880
```

**Example 5:**

```
Input: head = [0,0]
Output: 0
```

 

**Constraints:**

- The Linked List is not empty.
- Number of nodes will not exceed `30`.
- Each node's value is either `0` or `1`.

## Solution

``` cpp
class Solution {
public:
  int getDecimalValue(ListNode* head) {
    int ans = 0;
    while(head) {
      ans <<= 1;
      ans |= head->val;
      head = head->next;
    }
    return ans;
  }
};

// Accepted
// 102/102 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 93.93 % of cpp submissions (8.1 MB)
```
