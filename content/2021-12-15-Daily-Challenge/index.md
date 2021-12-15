+++
title = "2021-12-15 Daily-Challenge"
path = "2021-12-15-Daily-Challenge"
date = 2021-12-15 18:37:00+08:00
updated = 2021-12-15 18:41:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/insertion-sort-list/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 15

## Description

**Insertion Sort List**

Given the `head` of a singly linked list, sort the list using **insertion sort**, and return *the sorted list's head*.

The steps of the **insertion sort** algorithm:

1. Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
2. At each iteration, insertion sort removes one element from the  input data, finds the location it belongs within the sorted list and  inserts it there.
3. It repeats until no input elements remain.

The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first  element in the list. One element (red) is removed from the input data  and inserted in-place into the sorted list with each iteration.

![img](https://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif)

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/03/04/sort1linked-list.jpg)

```
Input: head = [4,2,1,3]
Output: [1,2,3,4]
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/03/04/sort2linked-list.jpg)

```
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
```

 

**Constraints:**

- The number of nodes in the list is in the range `[1, 5000]`.
- `-5000 <= Node.val <= 5000`

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
  ListNode* insertionSortList(ListNode* head) {
    ListNode *newHead = new ListNode();
    ListNode *cur = head;
    while(cur) {
      ListNode *newCur = newHead;
      ListNode *newPrev = nullptr;
      while(newCur->next && newCur->next->val < cur->val) {
        newCur = newCur->next;
      }
      ListNode *tmp = cur->next;
      cur->next = newCur ->next;
      newCur->next = cur;
      cur = tmp;
    }
    return newHead->next;
  }
};

// Accepted
// 19/19 cases passed (47 ms)
// Your runtime beats 44.67 % of cpp submissions
// Your memory usage beats 14.7 % of cpp submissions (9.8 MB)
```
