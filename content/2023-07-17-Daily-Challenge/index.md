+++
updated = 2023-07-17T08:59:48+08:00
title = "2023-07-17 Daily Challenge"
path = "2023-07-17-Daily-Challenge"
date = 2023-07-17T08:59:48+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/add-two-numbers-ii/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 17

## Description

**Add Two Numbers II**

<p>You are given two <strong>non-empty</strong> linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.</p>

<p>You may assume the two numbers do not contain any leading zero, except the number 0 itself.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/09/sumii-linked-list.jpg" style="width: 523px; height: 342px;" />
<pre>
<strong>Input:</strong> l1 = [7,2,4,3], l2 = [5,6,4]
<strong>Output:</strong> [7,8,0,7]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> l1 = [2,4,3], l2 = [5,6,4]
<strong>Output:</strong> [8,0,7]
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> l1 = [0], l2 = [0]
<strong>Output:</strong> [0]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in each linked list is in the range <code>[1, 100]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 9</code></li>
	<li>It is guaranteed that the list represents a number that does not have leading zeros.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong>&nbsp;Could you solve it without reversing the input lists?</p>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  pair<ListNode*, int> addTwoNumber(ListNode* l1, int len1, ListNode* l2, int len2) {
    if(!len1 || !len2) return len1 ? make_pair(l1, 0) : make_pair(l2, 0);
    ListNode *nextNode;
    int carry, curVal;
    if(len1 > len2) {
      tie(nextNode, carry) = addTwoNumber(l1->next, len1-1, l2, len2);
      curVal = l1->val + carry;
    } else if(len1 < len2) {
      tie(nextNode, carry) = addTwoNumber(l1, len1, l2->next, len2-1);
      curVal = l2->val + carry;
    } else {
      tie(nextNode, carry) = addTwoNumber(l1->next, len1-1, l2->next, len2-1);
      curVal = l1->val +l2->val + carry;
    }
    ListNode *node = new ListNode(curVal%10, nextNode);
    return make_pair(node, curVal/10);
  }
  
  int length(ListNode* l) {
    int len = 0;
    while(l) {
      len += 1;
      l = l->next;
    }
    return len;
  }
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int len1 = length(l1);
    int len2 = length(l2);
    auto [head, carry] = addTwoNumber(l1, len1, l2, len2);
    if(!carry) return head;
    return new ListNode(carry, head);
  }
};

// Accepted
// 1563/1563 cases passed (36 ms)
// Your runtime beats 73.8 % of cpp submissions
// Your memory usage beats 32.62 % of cpp submissions (71.6 MB)
```
