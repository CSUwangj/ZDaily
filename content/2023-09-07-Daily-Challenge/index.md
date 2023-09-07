+++
updated = 2023-09-07T09:48:40+08:00
title = "2023-09-07 Daily Challenge"
path = "2023-09-07-Daily-Challenge"
date = 2023-09-07T09:48:40+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/reverse-linked-list-ii/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 7

## Description

**Reverse Linked List II**

<p>Given the <code>head</code> of a singly linked list and two integers <code>left</code> and <code>right</code> where <code>left &lt;= right</code>, reverse the nodes of the list from position <code>left</code> to position <code>right</code>, and return <em>the reversed list</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/rev2ex2.jpg" style="width: 542px; height: 222px;" />
<pre>
<strong>Input:</strong> head = [1,2,3,4,5], left = 2, right = 4
<strong>Output:</strong> [1,4,3,2,5]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> head = [5], left = 1, right = 1
<strong>Output:</strong> [5]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is <code>n</code>.</li>
	<li><code>1 &lt;= n &lt;= 500</code></li>
	<li><code>-500 &lt;= Node.val &lt;= 500</code></li>
	<li><code>1 &lt;= left &lt;= right &lt;= n</code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Could you do it in one pass?

## Solution

``` cpp
class Solution {
public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode *newHead = new ListNode();
    ListNode *newCur = newHead;
    ListNode *cur = head;
    int pos = 1;
    while(pos < left) {
      newCur->next = cur;
      cur = cur->next;
      newCur = newCur->next;
      pos += 1;
    }
    ListNode *midTail = cur;
    ListNode *midCur = nullptr;
    ListNode *next;
    while(pos <= right) {
      next = cur->next;
      cur->next = midCur;
      midCur = cur;
      cur = next;
      pos += 1;
    }
    newCur->next = midCur;
    newCur = midTail;
    newCur->next = next;
    return newHead->next;
  }
};

// Accepted
// 44/44 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 17.76 % of cpp submissions (7.5 MB)
```
