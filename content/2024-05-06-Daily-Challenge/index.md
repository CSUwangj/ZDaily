+++
updated = 2024-05-06T12:02:34+08:00
title = "2024-05-06 Daily Challenge"
path = "2024-05-06-Daily-Challenge"
date = 2024-05-06T12:02:34+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/remove-nodes-from-linked-list/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 6

## Description

**Remove Nodes From Linked List**

<p>You are given the <code>head</code> of a linked list.</p>

<p>Remove every node which has a node with a greater value anywhere to the right side of it.</p>

<p>Return <em>the </em><code>head</code><em> of the modified linked list.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/10/02/drawio.png" style="width: 631px; height: 51px;" />
<pre>
<strong>Input:</strong> head = [5,2,13,3,8]
<strong>Output:</strong> [13,8]
<strong>Explanation:</strong> The nodes that should be removed are 5, 2 and 3.
- Node 13 is to the right of node 5.
- Node 13 is to the right of node 2.
- Node 8 is to the right of node 3.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> head = [1,1,1,1]
<strong>Output:</strong> [1,1,1,1]
<strong>Explanation:</strong> Every node has value 1, so no nodes are removed.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of the nodes in the given list is in the range <code>[1, 10<sup>5</sup>]</code>.</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  ListNode* removeNodes(ListNode* head) {
    stack<ListNode*> st;
    while(head) {
      while(st.size() && st.top()->val < head->val) {
        st.pop();
      }
      st.push(head);
      head = head->next;
    }
    ListNode *current = st.top();
    current->next = nullptr;
    st.pop();
    while(st.size()) {
      st.top()->next = current;
      current = st.top();
      st.pop();
      
    }
    return current;
  }
};
```
