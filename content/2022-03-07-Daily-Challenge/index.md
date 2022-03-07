+++
updated = 2022-03-07 18:58:00+08:00
title = "2022-03-07 Daily-Challenge"
path = "2022-03-07-Daily-Challenge"
date = 2022-03-07 18:57:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/merge-two-sorted-lists/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 7

## Description

**Merge Two Sorted Lists**

You are given the heads of two sorted linked lists `list1` and `list2`.

Merge the two lists in a one **sorted** list. The list should be made by splicing together the nodes of the first two lists.

Return *the head of the merged linked list*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/10/03/merge_ex1.jpg)

```
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
```

**Example 2:**

```
Input: list1 = [], list2 = []
Output: []
```

**Example 3:**

```
Input: list1 = [], list2 = [0]
Output: [0]
```

 

**Constraints:**

- The number of nodes in both lists is in the range `[0, 50]`.
- `-100 <= Node.val <= 100`
- Both `list1` and `list2` are sorted in **non-decreasing** order.

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
  ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
    ListNode *newHead = new ListNode(0);
    ListNode *cur = newHead;
    while(a && b) {
      if(a->val < b->val) {
        cur->next = a;
        a = a->next;
      } else {
        cur->next = b;
        b = b->next;
      }
      cur = cur->next;
    }
    if(a) cur->next = a;
    else cur->next = b;
    return newHead->next;
  }
};

// Accepted
// 208/208 cases passed (11 ms)
// Your runtime beats 55.46 % of cpp submissions
// Your memory usage beats 15.87 % of cpp submissions (15 MB)
```
