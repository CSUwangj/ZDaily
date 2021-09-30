+++
title = "2021-09-29 Daily-Challenge"
path = "2021-09-29-Daily-Challenge"
date = 2021-09-29 19:03:45+08:00
updated = 2021-09-29 19:38:22+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/639/week-4-september-22nd-september-28th/3992/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 29

## Description

**Split Linked List in Parts**

Given the `head` of a singly linked list and an integer `k`, split the linked list into `k` consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.

Return *an array of the* `k` *parts*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/06/13/split1-lc.jpg)

```
Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/06/13/split2-lc.jpg)

```
Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
Output: [[1,2,3,4],[5,6,7],[8,9,10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.
```

 

**Constraints:**

- The number of nodes in the list is in the range `[0, 1000]`.
- `0 <= Node.val <= 1000`
- `1 <= k <= 50`

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
