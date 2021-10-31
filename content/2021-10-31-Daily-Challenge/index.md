+++
title = "2021-10-31 Daily-Challenge"
path = "2021-10-31-Daily-Challenge"
date = 2021-10-31 14:33:22+08:00
updated = 2021-10-31 14:43:12+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 31

## Description

**Flatten a Multilevel Doubly Linked List**

You are given a doubly linked list which in addition to the next and previous pointers, it could have a child pointer, which may or may not point to a separate doubly linked list. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in the example below.

Flatten the list so that all the nodes appear in a single-level, doubly linked list. You are given the head of the first level of the list.

 

**Example 1:**

```
Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
Output: [1,2,3,7,8,11,12,9,10,4,5,6]
Explanation:

The multilevel linked list in the input is as follows:



After flattening the multilevel linked list it becomes:
```

**Example 2:**

```
Input: head = [1,2,null,3]
Output: [1,3,2]
Explanation:

The input multilevel linked list is as follows:

  1---2---NULL
  |
  3---NULL
```

**Example 3:**

```
Input: head = []
Output: []
```

 

**How multilevel linked list is represented in test case:**

We use the multilevel linked list from **Example 1** above:

```
 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL
```

The serialization of each level is as follows:

```
[1,2,3,4,5,6,null]
[7,8,9,10,null]
[11,12,null]
```

To serialize all levels together we will add nulls in each level to signify no node connects to the upper node of the previous level. The serialization becomes:

```
[1,2,3,4,5,6,null]
[null,null,7,8,9,10,null]
[null,11,12,null]
```

Merging the serialization of each level and removing trailing nulls we obtain:

```
[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
```

 

**Constraints:**

- The number of Nodes will not exceed `1000`.
- `1 <= Node.val <= 10^5`


## Solution

``` cpp
class Solution {
  pair<Node*, Node*> _flatten(Node *head) {
    if(!head) return {nullptr, nullptr};
    Node *resultHead = head;
    Node *resultTail = nullptr;
    Node *cur = head;
    while (cur) {
      if (cur->child) {
        auto [h, t] = _flatten(cur->child);
        t->next = cur->next;
        if(cur->next) {
          cur->next->prev = t;
        }
        cur->next = h;
        h->prev = cur;
        cur->child = nullptr;
        cur = t;
      }
      resultTail = cur;
      cur = cur->next;
    }
    return {resultHead, resultTail};
  }
public:
  Node* flatten(Node* head) {
    return _flatten(head).first;
  }
};

// Accepted
// 26/26 cases passed (4 ms)
// Your runtime beats 75.52 % of cpp submissions
// Your memory usage beats 20.82 % of cpp submissions (7.5 MB)
```
