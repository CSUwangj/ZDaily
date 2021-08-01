+++
title = "2021-01-05 Daily-Challenge"
path = "2021-01-05-Daily-Challenge"
date = 2021-01-05 18:09:45+08:00
updated = 2021-01-05 18:54:10+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Minimum Swaps To Make Sequences Increasing](https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/) on leetcode and leetcode's [January LeetCoding Challenge](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/579/week-1-january-1st-january-7th/3593/) with `cpp`.

<!-- more -->

# Minimum Swaps To Make Sequences Increasing

## Description

We have two integer sequences `A` and `B` of the same non-zero length.

We are allowed to swap elements `A[i]` and `B[i]`. Note that both elements are in the same index position in their respective sequences.

At the end of some number of swaps, `A` and `B` are both strictly increasing. (A sequence is *strictly increasing* if and only if `A[0] < A[1] < A[2] < ... < A[A.length - 1]`.)

Given A and B, return the minimum number of swaps to make both sequences strictly increasing. It is guaranteed that the given input always makes it possible.

```
Example:
Input: A = [1,3,5,4], B = [1,2,3,7]
Output: 1
Explanation: 
Swap A[3] and B[3].  Then the sequences are:
A = [1, 3, 5, 7] and B = [1, 2, 3, 4]
which are both strictly increasing.
```

**Note:**

- `A, B` are arrays with the same length, and that length will be in the range `[1, 1000]`.
- `A[i], B[i]` are integer values in the range `[0, 2000]`.

## Solution

note that `It is guaranteed that the given input always makes it possible.`

``` cpp
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int len = A.size();
        int pos = 1;
        int answer = 0;
        while(pos < len) {
            while(pos < len && min(A[pos], B[pos]) > max(A[pos-1], B[pos-1])) {
                pos += 1;
            }
            int cnt = 1, swap = 0;
            while(pos < len && min(A[pos], B[pos]) <= max(A[pos-1], B[pos-1])) {
                if(A[pos-1] > B[pos-1]) swap += 1;
                cnt += 1;
                pos += 1;
            }
            if(A[pos-1] > B[pos-1]) swap += 1;
            answer += min(swap, cnt-swap);
        }
        return answer;
    }
};
```

# January LeetCoding Challenge 5

## Description

**Remove Duplicates from Sorted List II**

Given the `head` of a sorted linked list, *delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list*. Return *the linked list **sorted** as well*.

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/01/04/linkedlist1.jpg)

```
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/01/04/linkedlist2.jpg)

```
Input: head = [1,1,1,2,3]
Output: [2,3]
```

**Constraints:**

- The number of nodes in the list is in the range `[0, 300]`.
- `-100 <= Node.val <= 100`
- The list is guaranteed to be **sorted** in ascending order.

## Solution

``` cpp
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *newHead = new ListNode(-111, head);
        ListNode *cur = newHead;
        while(cur) {
            if(cur->next && cur->next->next && cur->next->val == cur->next->next->val) {
                int dupVal = cur->next->val;
                while(cur->next && cur->next->val == dupVal) cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return newHead->next;
    }
};
```