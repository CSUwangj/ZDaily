+++
updated = 2023-05-16T12:19:06+08:00
title = "2023-05-16 Daily Challenge"
path = "2023-05-16-Daily-Challenge"
date = 2023-05-16T12:19:06+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/swap-nodes-in-pairs/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 16

## Description

**Swap Nodes in Pairs**

<p>Given a&nbsp;linked list, swap every two adjacent nodes and return its head. You must solve the problem without&nbsp;modifying the values in the list&#39;s nodes (i.e., only nodes themselves may be changed.)</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/03/swap_ex1.jpg" style="width: 422px; height: 222px;" />
<pre>
<strong>Input:</strong> head = [1,2,3,4]
<strong>Output:</strong> [2,1,4,3]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> head = []
<strong>Output:</strong> []
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> head = [1]
<strong>Output:</strong> [1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the&nbsp;list&nbsp;is in the range <code>[0, 100]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 100</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  ListNode* swapPairs(ListNode* head) {
    ListNode *newHead = new ListNode(-1, head);
    ListNode *cur = newHead;
    while(head) {
      if(head->next) {
        ListNode *tmp = head->next->next;
        cur->next = head->next;
        head->next->next = head;
        head->next = tmp;
        cur = cur->next->next;
        head = tmp;
      } else {
        head = head->next;
      }
    }
    return newHead->next;
  }
};

// Accepted
// 55/55 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 55.41 % of cpp submissions (7.5 MB)
```
