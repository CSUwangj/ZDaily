+++
title = "2021-01-11 Daily-Challenge"
path = "2021-01-11-Daily-Challenge"
date = 2021-01-11 21:07:32+08:00
updated = 2021-01-11 21:40:51+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/) and leetcode's [January LeetCoding Challenge](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/580/week-2-january-8th-january-14th/3600/) with `cpp`.

<!-- more -->

# Reverse Nodes in k-Group

## Description

Given a linked list, reverse the nodes of a linked list *k* at a time and return its modified list.

*k* is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of *k* then left-out nodes, in the end, should remain as it is.

**Follow up:**

- Could you solve the problem in `O(1)` extra memory space?
- You may not alter the values in the list's nodes, only nodes itself may be changed.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/10/03/reverse_ex1.jpg)

```
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/10/03/reverse_ex2.jpg)

```
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
```

**Example 3:**

```
Input: head = [1,2,3,4,5], k = 1
Output: [1,2,3,4,5]
```

**Example 4:**

```
Input: head = [1], k = 1
Output: [1]
```

 

**Constraints:**

- The number of nodes in the list is in the range `sz`.
- `1 <= sz <= 5000`
- `0 <= Node.val <= 1000`
- `1 <= k <= sz`

## Solution

why this problem is a hard?

maybe I should continue to improve solution?

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
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *newHead = new ListNode();
        ListNode *cur = head, *tail = newHead;
        int len = length(head);
        if(k == 1 || len < k) return head;
        while(len >= k) {
            int cnt = k;
            ListNode *partHead = nullptr;
            ListNode *next;
            while(cnt--) {
                next = cur->next;
                tail->next = cur;
                cur->next = partHead;
                partHead = cur;
                cur = next;
            }
            while(tail->next) tail = tail->next;
            len -= k;
        }
        tail->next = cur;
        return newHead->next;
    }
};
```

# January LeetCoding Challenge11

**Merge Sorted Array**

## Description

Given two sorted integer arrays `nums1` and `nums2`, merge `nums2` into `nums1` as one sorted array.

The number of elements initialized in `nums1` and `nums2` are `m` and `n` respectively. You may assume that `nums1` has enough space (size that is equal to `m + n`) to hold additional elements from `nums2`.

 

**Example 1:**

```
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
```

**Example 2:**

```
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
```

 

**Constraints:**

- `0 <= n, m <= 200`
- `1 <= n + m <= 200`
- `nums1.length == m + n`
- `nums2.length == n`
- `-109 <= nums1[i], nums2[i] <= 109`

## Solution

``` cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while(n && m) {
            if(nums1[m-1] > nums2[n-1]) {
                nums1[n+m-1] = nums1[m-1];
                --m;
            } else {
                nums1[n+m-1] = nums2[n-1];
                --n;
            }
        }
        while(n) {
            nums1[n-1] = nums2[n-1];
            --n;
        }
    }
};
```
