+++
updated = 2022-08-23 18:14:00+08:00
title = "2022-08-23 Daily-Challenge"
path = "2022-08-23-Daily-Challenge"
date = 2022-08-23 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/palindrome-linked-list/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 23

## Description

**Palindrome Linked List**

Given the `head` of a singly linked list, return `true` if it is a palindrome.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/03/03/pal1linked-list.jpg)

```
Input: head = [1,2,2,1]
Output: true
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/03/03/pal2linked-list.jpg)

```
Input: head = [1,2]
Output: false
```

 

**Constraints:**

- The number of nodes in the list is in the range `[1, 10^5]`.
- `0 <= Node.val <= 9`

 

**Follow up:** Could you do it in `O(n)` time and `O(1)` space?

## Solution

``` cpp
class Solution {
  ListNode* reverseList(ListNode* head) {
    ListNode* prev=nullptr;
    ListNode* curr=head;
    while(curr) {
      ListNode* next=curr->next;
      curr->next=prev;
      prev=curr;
      curr=next;
    }
    return prev;
  }
public:
  bool isPalindrome(ListNode* head) {
    int n=0;
    ListNode* iter=head;
    while(iter) iter=iter->next, n++;
    if(n<2) return true;
    // printf("-->%d\n", n);
    iter=head;
    for(int i=1;i<n/2;++i) iter=iter->next;
    ListNode* iter2 = (n%2) ? iter->next->next : iter->next;
    iter->next=nullptr;
    // printf("iter2->val=%d\n",xiter2->val);
    iter=reverseList(head);
    while(iter) {
      if(iter->val!=iter2->val) return false;
      iter=iter->next;
      iter2=iter2->next;
    }
    return true;
  }
};

// Accepted
// 87/87 cases passed (401 ms)
// Your runtime beats 41.44 % of cpp submissions
// Your memory usage beats 95.63 % of cpp submissions (110.3 MB)
```
