+++
updated = 2023-05-15T13:45:49+08:00
title = "2023-05-15 Daily Challenge"
path = "2023-05-15-Daily-Challenge"
date = 2023-05-15T13:45:49+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/swapping-nodes-in-a-linked-list/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 15

## Description

**Swapping Nodes in a Linked List**

<p>You are given the <code>head</code> of a linked list, and an integer <code>k</code>.</p>

<p>Return <em>the head of the linked list after <strong>swapping</strong> the values of the </em><code>k<sup>th</sup></code> <em>node from the beginning and the </em><code>k<sup>th</sup></code> <em>node from the end (the list is <strong>1-indexed</strong>).</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/21/linked1.jpg" style="width: 400px; height: 112px;" />
<pre>
<strong>Input:</strong> head = [1,2,3,4,5], k = 2
<strong>Output:</strong> [1,4,3,2,5]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> head = [7,9,6,6,7,8,3,0,9,5], k = 5
<strong>Output:</strong> [7,9,6,6,8,7,3,0,9,5]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is <code>n</code>.</li>
	<li><code>1 &lt;= k &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= Node.val &lt;= 100</code></li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  int listLength(ListNode *head) {
    int len = 0;
    while(head) {
      len += 1;
      head = head->next;
    }
    return len;
  }
public:
  ListNode* swapNodes(ListNode* head, int k) {
    int len = listLength(head);
    int first = k - 1;
    int second = len - k;
    ListNode *nodeFirst = head;
    while(first--) nodeFirst = nodeFirst->next;
    ListNode *nodeSecond = head;
    while(second--) nodeSecond = nodeSecond->next;
    swap(nodeFirst->val, nodeSecond->val);
    return head;
  }
};

// Accepted
// 132/132 cases passed (548 ms)
// Your runtime beats 99.93 % of cpp submissions
// Your memory usage beats 15.97 % of cpp submissions (180.3 MB)
```
