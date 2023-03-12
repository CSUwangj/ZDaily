+++
updated = 2023-03-12T21:05:10+08:00
title = "2023-03-12 Daily Challenge"
path = "2023-03-12-Daily-Challenge"
date = 2023-03-12T21:05:10+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/merge-k-sorted-lists/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 12

## Description

**Merge k Sorted Lists**

<p>You are given an array of <code>k</code> linked-lists <code>lists</code>, each linked-list is sorted in ascending order.</p>

<p><em>Merge all the linked-lists into one sorted linked-list and return it.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> lists = [[1,4,5],[1,3,4],[2,6]]
<strong>Output:</strong> [1,1,2,3,4,4,5,6]
<strong>Explanation:</strong> The linked-lists are:
[
  1-&gt;4-&gt;5,
  1-&gt;3-&gt;4,
  2-&gt;6
]
merging them into one sorted list:
1-&gt;1-&gt;2-&gt;3-&gt;4-&gt;4-&gt;5-&gt;6
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> lists = []
<strong>Output:</strong> []
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> lists = [[]]
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>k == lists.length</code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= lists[i].length &lt;= 500</code></li>
	<li><code>-10<sup>4</sup> &lt;= lists[i][j] &lt;= 10<sup>4</sup></code></li>
	<li><code>lists[i]</code> is sorted in <strong>ascending order</strong>.</li>
	<li>The sum of <code>lists[i].length</code> will not exceed <code>10<sup>4</sup></code>.</li>
</ul>


## Solution

``` cpp
class Solution {
  ListNode *merge2Lists(ListNode *a, ListNode *b) {
    ListNode *newHead = new ListNode(0);
    ListNode *cur = newHead;
    while(a && b) {
      if(a->val < b->val) {
        cur->next = a;
        a = a->next;
      } else {
        cur->next = b;
        b = b->next;
      }
      cur = cur->next;
    }
    if(a) cur->next = a;
    else cur->next = b;
    return newHead->next;
  }
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.empty()) return nullptr;
    int len = lists.size();
    for(int step = 1; step < len; step <<= 1) {
      for(int first = 0; first + step < len; first += 2 * step) {
        lists[first] = merge2Lists(lists[first], lists[first + step]);
      }
    }
    return lists.front();
  }
};

// Accepted
// 133/133 cases passed (12 ms)
// Your runtime beats 99.77 % of cpp submissions
// Your memory usage beats 58.51 % of cpp submissions (13.3 MB)
```
