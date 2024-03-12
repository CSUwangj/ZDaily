+++
updated = 2024-03-12T13:38:11+08:00
title = "2024-03-12 Daily Challenge"
path = "2024-03-12-Daily-Challenge"
date = 2024-03-12T13:38:11+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 12

## Description

**Remove Zero Sum Consecutive Nodes from Linked List**

<p>Given the <code>head</code> of a linked list, we repeatedly delete consecutive sequences of nodes that sum to <code>0</code> until there are no such sequences.</p>

<p>After doing so, return the head of the final linked list.&nbsp; You may return any such answer.</p>

<p>&nbsp;</p>
<p>(Note that in the examples below, all sequences are serializations of <code>ListNode</code> objects.)</p>

<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> head = [1,2,-3,3,1]
<strong>Output:</strong> [3,1]
<strong>Note:</strong> The answer [1,2,1] would also be accepted.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> head = [1,2,3,-3,4]
<strong>Output:</strong> [1,2,4]
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> head = [1,2,3,-3,-2]
<strong>Output:</strong> [1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The given linked list will contain between <code>1</code> and <code>1000</code> nodes.</li>
	<li>Each node in the linked list has <code>-1000 &lt;= node.val &lt;= 1000</code>.</li>
</ul>


## Solution

``` cpp
class Solution {
  map<int, ListNode*> pos;
public:
  ListNode* removeZeroSumSublists(ListNode* head) {
    int sum = 0;
    ListNode *newHead = new ListNode(-1, head);
    pos[0] = newHead;
    while(head) {
      sum += head->val;
      if(pos.count(sum)) {
        ListNode* toDelete = pos[sum]->next;
        int deleteSum = sum + toDelete->val;
        while(toDelete != head) {
          pos.erase(deleteSum);
          toDelete = toDelete->next;
          deleteSum += toDelete->val;
        }
        pos[sum]->next = head->next;
      } else {
        pos[sum] = head;
      }
      head = head->next;
    }
    return newHead->next;
  }
};
```
