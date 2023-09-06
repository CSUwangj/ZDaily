+++
updated = 2023-09-06T01:29:15+08:00
title = "2023-09-06 Daily Challenge"
path = "2023-09-06-Daily-Challenge"
date = 2023-09-06T01:29:15+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/split-linked-list-in-parts/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 6

## Description

**Split Linked List in Parts**

<p>Given the <code>head</code> of a singly linked list and an integer <code>k</code>, split the linked list into <code>k</code> consecutive linked list parts.</p>

<p>The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.</p>

<p>The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.</p>

<p>Return <em>an array of the </em><code>k</code><em> parts</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/13/split1-lc.jpg" style="width: 400px; height: 134px;" />
<pre>
<strong>Input:</strong> head = [1,2,3], k = 5
<strong>Output:</strong> [[1],[2],[3],[],[]]
<strong>Explanation:</strong>
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/13/split2-lc.jpg" style="width: 600px; height: 60px;" />
<pre>
<strong>Input:</strong> head = [1,2,3,4,5,6,7,8,9,10], k = 3
<strong>Output:</strong> [[1,2,3,4],[5,6,7],[8,9,10]]
<strong>Explanation:</strong>
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is in the range <code>[0, 1000]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 1000</code></li>
	<li><code>1 &lt;= k &lt;= 50</code></li>
</ul>


## Solution

``` cpp
class Solution {
  int length(ListNode *head) {
    int len = 0;
    while(head) {
      len += 1;
      head = head->next;
    }
    return len;
  }
  ListNode *getNNode(ListNode *&head, int n) {
    if(!head || !n) return nullptr;
    ListNode *newHead = head;
    while(--n && head) {
      head = head->next;
    }
    if(head) {
      ListNode *newCur = head->next;
      head->next = nullptr;
      head = newCur;
    }
    return newHead;
  }
public:
  vector<ListNode*> splitListToParts(ListNode* head, int k) {
    int len = length(head);
    int lenOfPart = len / k;
    vector<ListNode*> answer;
    while(k) {
      int partLen = lenOfPart + (lenOfPart * k < len);
      answer.push_back(getNNode(head, partLen));
      len -= partLen;
      k -= 1;
    }
    return answer;
  }
};

// Accepted
// 43/43 cases passed (4 ms)
// Your runtime beats 96.39 % of cpp submissions
// Your memory usage beats 91.57 % of cpp submissions (8.8 MB)
```
