+++
updated = 2024-03-07T16:21:19+08:00
title = "2024-03-07 Daily Challenge"
path = "2024-03-07-Daily-Challenge"
date = 2024-03-07T16:21:19+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/middle-of-the-linked-list/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 7

## Description

**Middle of the Linked List**

<p>Given the <code>head</code> of a singly linked list, return <em>the middle node of the linked list</em>.</p>

<p>If there are two middle nodes, return <strong>the second middle</strong> node.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/23/lc-midlist1.jpg" style="width: 544px; height: 65px;" />
<pre>
<strong>Input:</strong> head = [1,2,3,4,5]
<strong>Output:</strong> [3,4,5]
<strong>Explanation:</strong> The middle node of the list is node 3.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/23/lc-midlist2.jpg" style="width: 664px; height: 65px;" />
<pre>
<strong>Input:</strong> head = [1,2,3,4,5,6]
<strong>Output:</strong> [4,5,6]
<strong>Explanation:</strong> Since the list has two middle nodes with values 3 and 4, we return the second one.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is in the range <code>[1, 100]</code>.</li>
	<li><code>1 &lt;= Node.val &lt;= 100</code></li>
</ul>

## Solution

``` cpp
class Solution {
  int length(ListNode *head) {
    int result = 0;
    while(head) {
      result += 1;
      head = head->next;
    }
    return result;
  }
  ListNode *advance(ListNode *head, int count) {
    while(count--) {
      head = head->next;
    }
    return head;
  }
public:
  ListNode* middleNode(ListNode* head) {
    return advance(head, length(head) / 2);
  }
};

```
