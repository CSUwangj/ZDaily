+++
updated = 2022-04-04 19:59:00+08:00
title = "2022-04-04 Daily-Challenge"
path = "2022-04-04-Daily-Challenge"
date = 2022-04-04 19:57:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/swapping-nodes-in-a-linked-list/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 4

## Description

**Swapping Nodes in a Linked List**

You are given the `head` of a linked list, and an integer `k`.

Return *the head of the linked list after **swapping** the values of the* `kth` *node from the beginning and the* `kth` *node from the end (the list is **1-indexed**).*

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/09/21/linked1.jpg)

```
Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
```

**Example 2:**

```
Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]
```

 

**Constraints:**

- The number of nodes in the list is `n`.
- `1 <= k <= n <= 105`
- `0 <= Node.val <= 100`

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  int listLength(ListNode *head) {
    int len = 0;
    while(head) {
      len += 1;
      head = head->next;
    }
    return len;
  }
public:
  ListNode* swapNodes(ListNode* head, int k) {
    int len = listLength(head);
    int first = k - 1;
    int second = len - k;
    ListNode *nodeFirst = head;
    while(first--) nodeFirst = nodeFirst->next;
    ListNode *nodeSecond = head;
    while(second--) nodeSecond = nodeSecond->next;
    swap(nodeFirst->val, nodeSecond->val);
    return head;
  }
};

// Accepted
// 132/132 cases passed (548 ms)
// Your runtime beats 99.93 % of cpp submissions
// Your memory usage beats 15.97 % of cpp submissions (180.3 MB)
```
