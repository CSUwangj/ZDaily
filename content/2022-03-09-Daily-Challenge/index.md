+++
updated = 2022-03-09 18:26:00+08:00
title = "2022-03-09 Daily-Challenge"
path = "2022-03-09-Daily-Challenge"
date = 2022-03-09 18:25:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 9

## Description

**Remove Duplicates from Sorted List II**

Given the `head` of a sorted linked list, *delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list*. Return *the linked list **sorted** as well*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/01/04/linkedlist1.jpg)

```
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/01/04/linkedlist2.jpg)

```
Input: head = [1,1,1,2,3]
Output: [2,3]
```

 

**Constraints:**

- The number of nodes in the list is in the range `[0, 300]`.
- `-100 <= Node.val <= 100`
- The list is guaranteed to be **sorted** in ascending order.

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
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode *newHead = new ListNode();
    ListNode *newCur = newHead;
    while(head) {
      if(head->next && head->val == head->next->val) {
        int val = head->val;
        while(head && head->val == val) head = head->next;
        continue;
      }
      newCur->next = head;
      newCur = newCur->next;
      head = head->next;
    }
    newCur->next = nullptr;
    return newHead->next;
  }
};

// Accepted
// 166/166 cases passed (19 ms)
// Your runtime beats 16.25 % of cpp submissions
// Your memory usage beats 20.51 % of cpp submissions (11.2 MB)
```
