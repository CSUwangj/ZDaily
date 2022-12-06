+++
updated = 2022-12-06T12:05:20+08:00
title = "2022-12-06 Daily Challenge"
path = "2022-12-06-Daily-Challenge"
date = 2022-12-06T12:05:20+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/odd-even-linked-list/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 6

## Description

**Odd Even Linked List**

<p>Given the <code>head</code> of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return <em>the reordered list</em>.</p>

<p>The <strong>first</strong> node is considered <strong>odd</strong>, and the <strong>second</strong> node is <strong>even</strong>, and so on.</p>

<p>Note that the relative order inside both the even and odd groups should remain as it was in the input.</p>

<p>You must solve the problem&nbsp;in <code>O(1)</code>&nbsp;extra space complexity and <code>O(n)</code> time complexity.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/10/oddeven-linked-list.jpg" style="width: 300px; height: 123px;" />
<pre>
<strong>Input:</strong> head = [1,2,3,4,5]
<strong>Output:</strong> [1,3,5,2,4]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/10/oddeven2-linked-list.jpg" style="width: 500px; height: 142px;" />
<pre>
<strong>Input:</strong> head = [2,1,3,5,6,4,7]
<strong>Output:</strong> [2,3,6,7,1,5,4]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the linked list is in the range <code>[0, 10<sup>4</sup>]</code>.</li>
	<li><code>-10<sup>6</sup> &lt;= Node.val &lt;= 10<sup>6</sup></code></li>
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
public:
  ListNode* oddEvenList(ListNode* head) {
    ListNode *oddHead = new ListNode();
    ListNode *evenHead = new ListNode();
    ListNode *oddCur = oddHead;
    ListNode *evenCur = evenHead;
    while(head) {
      oddCur->next = head;
      oddCur = oddCur->next;
      head = head->next;
      evenCur->next = head;
      evenCur = evenCur->next;
      if(head) head = head->next;
    }
    oddCur->next = evenHead->next;
    return oddHead->next;
  }
};

// Accepted
// 70/70 cases passed (8 ms)
// Your runtime beats 92.49 % of cpp submissions
// Your memory usage beats 29.12 % of cpp submissions (10.6 MB)
```
