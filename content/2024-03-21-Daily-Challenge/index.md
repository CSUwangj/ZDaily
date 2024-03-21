+++
updated = 2024-03-21T21:24:49+08:00
title = "2024-03-21 Daily Challenge"
path = "2024-03-21-Daily-Challenge"
date = 2024-03-21T21:24:49+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/reverse-linked-list/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 21

## Description

**Reverse Linked List**

<p>Given the <code>head</code> of a singly linked list, reverse the list, and return <em>the reversed list</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/rev1ex1.jpg" style="width: 542px; height: 222px;" />
<pre>
<strong>Input:</strong> head = [1,2,3,4,5]
<strong>Output:</strong> [5,4,3,2,1]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/rev1ex2.jpg" style="width: 182px; height: 222px;" />
<pre>
<strong>Input:</strong> head = [1,2]
<strong>Output:</strong> [2,1]
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> head = []
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is the range <code>[0, 5000]</code>.</li>
	<li><code>-5000 &lt;= Node.val &lt;= 5000</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> A linked list can be reversed either iteratively or recursively. Could you implement both?</p>


## Solution

``` cpp
class Solution {
public:
  ListNode* reverseList(ListNode* head, ListNode* tail = nullptr) {
    if(!head) return tail;
    ListNode *next = head->next;
    head->next = tail;
    return reverseList(next, head);
  }
};

// Accepted
// 28/28 cases passed (4 ms)
// Your runtime beats 96.22 % of cpp submissions
// Your memory usage beats 97.51 % of cpp submissions (8.2 MB)
```
