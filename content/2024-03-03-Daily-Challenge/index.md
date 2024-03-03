+++
updated = 2024-03-03T14:34:54+08:00
title = "2024-03-03 Daily Challenge"
path = "2024-03-03-Daily-Challenge"
date = 2024-03-03T14:34:54+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 3

## Description

**Remove Nth Node From End of List**

<p>Given the <code>head</code> of a linked list, remove the <code>n<sup>th</sup></code> node from the end of the list and return its head.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/03/remove_ex1.jpg" style="width: 542px; height: 222px;" />
<pre>
<strong>Input:</strong> head = [1,2,3,4,5], n = 2
<strong>Output:</strong> [1,2,3,5]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> head = [1], n = 1
<strong>Output:</strong> []
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> head = [1,2], n = 1
<strong>Output:</strong> [1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is <code>sz</code>.</li>
	<li><code>1 &lt;= sz &lt;= 30</code></li>
	<li><code>0 &lt;= Node.val &lt;= 100</code></li>
	<li><code>1 &lt;= n &lt;= sz</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Could you do this in one pass?</p>


## Solution

``` cpp
class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *newHead = new ListNode(-1, head);
    ListNode *tail = newHead;
    ListNode *del = newHead;
    while(n--) tail = tail->next;
    while(tail->next) {
      tail = tail->next;
      del = del->next;
    }
    del->next = del->next->next;
    return newHead->next;
  }
};

// Accepted
// 208/208 cases passed (3 ms)
// Your runtime beats 64.94 % of cpp submissions
// Your memory usage beats 45.9 % of cpp submissions (13.3 MB)
```
