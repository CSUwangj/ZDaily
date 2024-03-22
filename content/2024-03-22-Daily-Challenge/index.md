+++
updated = 2024-03-22T10:09:59+08:00
title = "2024-03-22 Daily Challenge"
path = "2024-03-22-Daily-Challenge"
date = 2024-03-22T10:09:59+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/palindrome-linked-list/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 22

## Description

**Palindrome Linked List**

<p>Given the <code>head</code> of a singly linked list, return <code>true</code><em> if it is a </em><span data-keyword="palindrome-sequence"><em>palindrome</em></span><em> or </em><code>false</code><em> otherwise</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/03/pal1linked-list.jpg" style="width: 422px; height: 62px;" />
<pre>
<strong>Input:</strong> head = [1,2,2,1]
<strong>Output:</strong> true
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/03/pal2linked-list.jpg" style="width: 182px; height: 62px;" />
<pre>
<strong>Input:</strong> head = [1,2]
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is in the range <code>[1, 10<sup>5</sup>]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 9</code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Could you do it in <code>O(n)</code> time and <code>O(1)</code> space?

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
