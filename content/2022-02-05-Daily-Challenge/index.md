+++
title = "2022-02-05 Daily-Challenge"
path = "2022-02-05-Daily-Challenge"
date = 2022-02-05 20:24:00+08:00
updated = 2022-02-05 20:29:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/merge-k-sorted-lists/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 5

## Description

**Merge k Sorted Lists**

You are given an array of `k` linked-lists `lists`, each linked-list is sorted in ascending order.

*Merge all the linked-lists into one sorted linked-list and return it.*

 

**Example 1:**

```
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
```

**Example 2:**

```
Input: lists = []
Output: []
```

**Example 3:**

```
Input: lists = [[]]
Output: []
```

 

**Constraints:**

- `k == lists.length`
- `0 <= k <= 10^4`
- `0 <= lists[i].length <= 500`
- `-10^4 <= lists[i][j] <= 10^4`
- `lists[i]` is sorted in **ascending order**.
- The sum of `lists[i].length` won't exceed `10^4`.

## Solution

``` cpp
struct cmp {
  bool operator()(const ListNode *a, const ListNode *b) const {
    return a->val > b->val;
  }
};
class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
    for(auto list : lists) {
      if(list) pq.push(list);
    }
    ListNode *newHead = new ListNode();
    ListNode *cur = newHead;
    while(pq.size()) {
      auto nxt = pq.top();
      pq.pop();
      if(nxt->next) {
        pq.push(nxt->next);
      }
      cur->next = nxt;
      cur = cur->next;
    }
    return newHead->next;
  }
};

// Accepted
// 133/133 cases passed (23 ms)
// Your runtime beats 78.38 % of cpp submissions
// Your memory usage beats 74.95 % of cpp submissions (13.3 MB)
```

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
