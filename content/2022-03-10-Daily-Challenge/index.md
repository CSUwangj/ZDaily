+++
updated = 2022-03-10 18:00:00+08:00
title = "2022-03-10 Daily-Challenge"
path = "2022-03-10-Daily-Challenge"
date = 2022-03-10 18:01:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/add-two-numbers/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 10

## Description

**Add Two Numbers**

You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order**, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/10/02/addtwonumber1.jpg)

```
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
```

**Example 2:**

```
Input: l1 = [0], l2 = [0]
Output: [0]
```

**Example 3:**

```
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
```

 

**Constraints:**

- The number of nodes in each linked list is in the range `[1, 100]`.
- `0 <= Node.val <= 9`
- It is guaranteed that the list represents a number that does not have leading zeros.

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *newHead = new ListNode();
    ListNode *cur = newHead;
    int carry = 0;
    while(l1 && l2) {
      int val = l1->val + l2->val + carry;
      carry = val / 10;
      cur->next = new ListNode(val%10);
      cur = cur->next;
      l1 = l1->next;
      l2 = l2->next;
    }
    ListNode *rest = l1 ? l1 : l2;
    while(rest) {
      int val = rest->val + carry;
      carry = val / 10;
      cur->next = new ListNode(val%10);
      cur = cur->next;
      rest = rest->next;
    }
    if(carry) cur->next = new ListNode(carry);
    return newHead->next;
  }
};

// Accepted
// 1568/1568 cases passed (40 ms)
// Your runtime beats 71.08 % of cpp submissions
// Your memory usage beats 11.57 % of cpp submissions (71.6 MB)

```
