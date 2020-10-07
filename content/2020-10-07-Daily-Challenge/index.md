+++
title = "2020-10-07 Daily-Challenge"
path = "2020-10-07-Daily-Challenge"
date = 2020-10-07 02:36:36+08:00
updated = 2020-10-07 16:38:02+08:00
in_search_index = true

[taxonomies]
tags = ["Design", "Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is an example of *The non-Designer's Design Book* on bottom of Page 74 and *Data Stream as Disjoint Intervals* on [leetcode](https://leetcode.com/problems/data-stream-as-disjoint-intervals/) and leetcode's [October LeetCoding Challenge](https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/559/week-1-october-1st-october-7th/3486/) with `cpp`.

<!-- more -->

# The non-Designer's Design Book

my answer:

- [F] use repeat rule in the contact information
- [T] change the font of the title
- [T] use white background instead of lavender
- [T] change font of main text
- [F] use lavender as quotes background
- [T] reduce image size so it looks less crowded
- [T] add dark purple banner

# Data Stream as Disjoint Intervals

## Description

Given a data stream input of non-negative integers a1, a2, ..., an, ..., summarize the numbers seen so far as a list of disjoint intervals.

For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be:

```
[1, 1]
[1, 1], [3, 3]
[1, 1], [3, 3], [7, 7]
[1, 3], [7, 7]
[1, 3], [6, 7]
```

**Follow up:**

What if there are lots of merges and the number of disjoint intervals are small compared to the data stream's size?

## Solution

what a shitty description...

I use binary search and vector to solve it.

``` cpp
class SummaryRanges {
  vector<vector<int>> intervals = {{-2, -2}};
public:
  void addNum(int val) {
    auto end = intervals.end(), begin = intervals.begin();
    while(begin < end) {
      auto mid = begin;
      advance(mid, distance(begin, end)/2);
      if((*mid)[0] <= val && (*mid)[1] >= val) {
        return;
      } else if((*mid)[0] > val) {
        end = mid;
      } else if((*mid)[1] < val) {
        begin = mid + 1;
      }
    }
    if(begin != intervals.end() && ((*(begin))[0] == val+1) && ((*(begin-1))[1] == val-1)) {
      (*(begin-1))[1] = (*(begin))[1];
      intervals.erase(begin);
    } else if(begin != intervals.end() && (*(begin))[0] == val+1) {
      (*(begin))[0] = val;
    } else if((*(begin-1))[1] == val-1){
      (*(begin-1))[1] = val;
    } else {
      intervals.insert(begin, {val, val});
    }
  }
  
  vector<vector<int>> getIntervals() {
    return vector<vector<int>> {intervals.begin()+1, intervals.end()};
  }
};
```

# October LeetCoding Challenge7

## Description

**Rotate List**

Given a linked list, rotate the list to the right by *k* places, where *k* is non-negative.

**Example 1:**

```
Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
```

**Example 2:**

```
Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
```

## Solution

my code is somewhat ugly, rewrite it later.

``` cpp
class Solution {
public:
    int length(ListNode* head) {
        ListNode* cur = head;
        int len = 0;
        while(cur) {
            cur = cur->next;
            len += 1;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* cur = head, *pre;
        ListNode* newHead;
        int l = length(head);
        if(!l) return head;
        k = (l - k%l)%l;
        if(!k) return head;
        while(k) {
            pre = cur;
            cur = cur->next;
            k -= 1;
        }
        newHead = cur;
        pre->next = nullptr;
        while(cur->next) {
            cur = cur->next;
        }
        cur->next = head;
        return newHead;
    }
};
```