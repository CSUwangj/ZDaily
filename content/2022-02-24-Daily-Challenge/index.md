+++
title = "2022-02-24 Daily-Challenge"
path = "2022-02-24-Daily-Challenge"
date = 2022-02-24 19:34:00+08:00
updated = 2022-02-24 19:34:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/sort-list/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 24

## Description

**Sort List**

Given the `head` of a linked list, return *the list after sorting it in **ascending order***.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/09/14/sort_list_1.jpg)

```
Input: head = [4,2,1,3]
Output: [1,2,3,4]
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/09/14/sort_list_2.jpg)

```
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
```

**Example 3:**

```
Input: head = []
Output: []
```

 

**Constraints:**

- The number of nodes in the list is in the range `[0, 5 * 10^4]`.
- `-10^5 <= Node.val <= 10^5`

 

**Follow up:** Can you sort the linked list in `O(n logn)` time and `O(1)` memory (i.e. constant space)?

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  int length(ListNode* head){
    int len = 0;
    while(head) {
      len += 1;
      head = head->next;
    }
    return len;
  }
public:
  ListNode* sortList(ListNode* head) {
    int interval = 1, len = length(head);
    if(len < 2) return head;
    ListNode *new_head = new ListNode(-1, head);
    while(interval < len) {
      ListNode *pre = new_head, *h = pre->next;
      while(h) {
        ListNode *h1 = h;
        int cnt = interval;
        while(h && cnt) {
          h = h->next;
          cnt -= 1;
        }
        if(cnt) break;
        ListNode *h2 = h;
        cnt = interval;
        while(h && cnt) {
          h = h->next;
          cnt -= 1;
        }
        int len1 = interval, len2 = interval - cnt;
        while(len1 && len2) {
          if(h1->val < h2->val) {
            pre->next = h1;
            h1 = h1->next;
            len1 -= 1;
          } else {
            pre->next = h2;
            h2 = h2->next;
            len2 -= 1;
          }
          pre = pre->next;
        }
        pre->next = len1 ? h1 : h2;
        while(len1 > 0 || len2 > 0) {
          pre = pre->next;
          len1 -= 1;
          len2 -= 1;
        }
        pre->next = h;
      }
      interval *= 2;
    }
    return new_head->next;
  }
};

// Accepted
// 28/28 cases passed (76 ms)
// Your runtime beats 99.22 % of cpp submissions
// Your memory usage beats 97.96 % of cpp submissions (28.9 MB)
```
