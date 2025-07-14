+++
updated = 2025-07-15T03:19:10+08:00
title = "2025-07-14 Daily Challenge"
path = "2025-07-14-Daily-Challenge"
date = 2025-07-15T03:19:10+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 14

## Description

**Convert Binary Number in a Linked List to Integer**

<p>Given <code>head</code> which is a reference node to a singly-linked list. The value of each node in the linked list is either <code>0</code> or <code>1</code>. The linked list holds the binary representation of a number.</p>

<p>Return the <em>decimal value</em> of the number in the linked list.</p>

<p>The <strong>most significant bit</strong> is at the head of the linked list.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/12/05/graph-1.png" style="width: 426px; height: 108px;" />
<pre>
<strong>Input:</strong> head = [1,0,1]
<strong>Output:</strong> 5
<strong>Explanation:</strong> (101) in base 2 = (5) in base 10
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> head = [0]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The Linked List is not empty.</li>
	<li>Number of nodes will not exceed <code>30</code>.</li>
	<li>Each node&#39;s value is either <code>0</code> or <code>1</code>.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int getDecimalValue(ListNode* head) {
    int ans = 0;
    while(head) {
      ans <<= 1;
      ans |= head->val;
      head = head->next;
    }
    return ans;
  }
};

// Accepted
// 102/102 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 93.93 % of cpp submissions (8.1 MB)class Solution {
public:
  int getDecimalValue(ListNode* head) {
    int ans = 0;
    while(head) {
      ans <<= 1;
      ans |= head->val;
      head = head->next;
    }
    return ans;
  }
};

// Accepted
// 102/102 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 93.93 % of cpp submissions (8.1 MB)class Solution {
public:
  int getDecimalValue(ListNode* head) {
    int ans = 0;
    while(head) {
      ans <<= 1;
      ans |= head->val;
      head = head->next;
    }
    return ans;
  }
};

// Accepted
// 102/102 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 93.93 % of cpp submissions (8.1 MB)
```
