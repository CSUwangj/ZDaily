+++
updated = 2024-03-23T14:02:15+08:00
title = "2024-03-23 Daily Challenge"
path = "2024-03-23-Daily-Challenge"
date = 2024-03-23T14:02:15+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/reorder-list/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 23

## Description

**Reorder List**

<p>You are given the head of a singly linked-list. The list can be represented as:</p>

<pre>
L<sub>0</sub> &rarr; L<sub>1</sub> &rarr; &hellip; &rarr; L<sub>n - 1</sub> &rarr; L<sub>n</sub>
</pre>

<p><em>Reorder the list to be on the following form:</em></p>

<pre>
L<sub>0</sub> &rarr; L<sub>n</sub> &rarr; L<sub>1</sub> &rarr; L<sub>n - 1</sub> &rarr; L<sub>2</sub> &rarr; L<sub>n - 2</sub> &rarr; &hellip;
</pre>

<p>You may not modify the values in the list&#39;s nodes. Only nodes themselves may be changed.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/04/reorder1linked-list.jpg" style="width: 422px; height: 222px;" />
<pre>
<strong>Input:</strong> head = [1,2,3,4]
<strong>Output:</strong> [1,4,2,3]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/09/reorder2-linked-list.jpg" style="width: 542px; height: 222px;" />
<pre>
<strong>Input:</strong> head = [1,2,3,4,5]
<strong>Output:</strong> [1,5,2,4,3]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is in the range <code>[1, 5 * 10<sup>4</sup>]</code>.</li>
	<li><code>1 &lt;= Node.val &lt;= 1000</code></li>
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
  int length(ListNode *head) {
    int result = 0;
    while(head) {
      result += 1;
      head = head->next;
    }
    return result;
  }
  ListNode *advance(ListNode *head, int count) {
    while(--count) {
      head = head->next;
    }
    return head;
  }
  ListNode *reverse(ListNode *head) {
    ListNode *tail = nullptr;
    while(head) {
      ListNode *tmp = head->next;
      head->next = tail;
      tail = head;
      head = tmp;
    }
    return tail;
  }
  void merge(ListNode *head1, ListNode *head2) {
    while(head1 && head2) {
      ListNode *tmp2 = head2->next;
      head2->next = head1->next;
      head1->next = head2;
      head1 = head2->next;
      head2 = tmp2;
    }
  }
public:
  void reorderList(ListNode* head) {
    int len = length(head);
    ListNode *tail1 = advance(head, (len + 1) / 2);
    ListNode *head2 = tail1->next;
    tail1->next = nullptr;
    head2 = reverse(head2);
    merge(head, head2);
  }
};

// Accepted
// 12/12 cases passed (32 ms)
// Your runtime beats 95.77 % of cpp submissions
// Your memory usage beats 76.71 % of cpp submissions (17.8 MB)
```
