+++
updated = 2023-08-15T13:18:45+08:00
title = "2023-08-15 Daily Challenge"
path = "2023-08-15-Daily-Challenge"
date = 2023-08-15T13:18:45+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/partition-list/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 15

## Description

**Partition List**

<p>Given the <code>head</code> of a linked list and a value <code>x</code>, partition it such that all nodes <strong>less than</strong> <code>x</code> come before nodes <strong>greater than or equal</strong> to <code>x</code>.</p>

<p>You should <strong>preserve</strong> the original relative order of the nodes in each of the two partitions.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/04/partition.jpg" style="width: 662px; height: 222px;" />
<pre>
<strong>Input:</strong> head = [1,4,3,2,5,2], x = 3
<strong>Output:</strong> [1,2,2,4,3,5]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> head = [2,1], x = 2
<strong>Output:</strong> [1,2]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is in the range <code>[0, 200]</code>.</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
	<li><code>-200 &lt;= x &lt;= 200</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  ListNode* partition(ListNode* head, int x) {
    ListNode *newFront = new ListNode(-1);
    ListNode *frontTail = newFront;
    ListNode *newBack = new ListNode(-1);
    ListNode *backTail = newBack;
    while(head) {
      if(head->val < x) {
        frontTail->next = head;
        frontTail = frontTail->next;
      } else {
        backTail->next = head;
        backTail = backTail->next;
      }
      head = head->next;
    } 
    backTail->next = nullptr;
    frontTail->next = newBack->next;
    ListNode* answer = newFront->next;
    delete newFront;
    delete newBack;
    return answer;
  }
};

// Accepted
// 168/168 cases passed (7 ms)
// Your runtime beats 73.71 % of cpp submissions
// Your memory usage beats 32.53 % of cpp submissions (10.3 MB)
```
