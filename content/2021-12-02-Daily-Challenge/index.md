+++
title = "2021-12-02 Daily-Challenge"
path = "2021-12-02-Daily-Challenge"
date = 2021-12-02 18:00:00+08:00
updated = 2021-12-02 18:02:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/odd-even-linked-list/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 2

## Description

**Odd Even Linked List**

Given the `head` of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return *the reordered list*.

The **first** node is considered **odd**, and the **second** node is **even**, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in `O(1)` extra space complexity and `O(n)` time complexity.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/03/10/oddeven-linked-list.jpg)

```
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/03/10/oddeven2-linked-list.jpg)

```
Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
```

 

**Constraints:**

<ul>
	<li><code>n ==&nbsp;</code>number of nodes in the linked list</li>
	<li><code>0 &lt;= n &lt;= 10<sup>4</sup></code></li>
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
// Your memory usage beats 5.68 % of cpp submissions (10.8 MB)
```
