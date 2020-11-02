+++
title = "2020-11-01 Daily-Challenge"
path = "2020-11-01-Daily-Challenge"
date = 2020-11-01 10:24:07+08:00
updated = 2020-11-01 15:27:19+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I gonna review the tasks I've done this week, and finish today's leetcode's [October LeetCoding Challenge](https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/564/week-1-november-1st-november-7th/3516/) with `cpp`.

BTW I decided to write solution directly on website rather than on VSCode when reviewing.

<!-- more -->

# LeetCode review

## Linked List Cycle II

use two pointers which one pointer step two node at each time. the amount which faster pointer is ahead of the slower pointer is number of step time.

if there is a cycle in list, we assume that the length before the cycle is `n`, then when the both pointers are in the cycle, the distance between them is `n`. and we assume that cycle length is `c`, when two pointers meet, there is `(c-n)%c` rounds gone. so we just use another pointer start from head, when it meets the slower pointer, meet point is where the cycle begins.

``` cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *quickPointer = head, *slowPointer = head;
        bool hasCycle = false;
        while(quickPointer && quickPointer->next && slowPointer) {
            slowPointer = slowPointer->next;
            quickPointer = quickPointer->next->next;
            if(slowPointer == quickPointer) {
                hasCycle = true;
                break;
            }
        }
        if(!hasCycle) return NULL;
        while(head != slowPointer) {
            head = head->next;
            slowPointer = slowPointer->next;
        }
        return head;
    }
};
```

## Recover Binary Search Tree

morris traversal

``` cpp
class Solution {
    vector<TreeNode*> wrongNodes;
    void check(TreeNode* cur, TreeNode* prev) {
        if(prev && prev->val >= cur->val) {
            wrongNodes.push_back(prev);
            wrongNodes.push_back(cur);
        }
    }
public:
    void recoverTree(TreeNode* root) {
        TreeNode *cur = root, *prev = nullptr;
        while(cur) {
            if(!(cur->left)) {
                check(cur, prev);
                prev = cur;
                cur = cur->right;
            } else {
                TreeNode *pred = cur->left;
                while(pred->right && pred->right != cur) pred = pred->right;
                if(pred->right) {
                    pred->right = nullptr;
                    check(cur, prev);
                    prev = cur;
                    cur = cur->right;
                } else {
                    pred->right = cur;
                    cur = cur->left;
                }
            }
        }
        swap(wrongNodes.front()->val, wrongNodes.back()->val);
    }
};
```

# November LeetCoding Challenge1

## Description

**Convert Binary Number in a Linked List to Integer**

Given `head` which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the *decimal value* of the number in the linked list.

**Example 1:**

![img](https://assets.leetcode.com/uploads/2019/12/05/graph-1.png)

```
Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
```

**Example 2:**

```
Input: head = [0]
Output: 0
```

**Example 3:**

```
Input: head = [1]
Output: 1
```

**Example 4:**

```
Input: head = [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
Output: 18880
```

**Example 5:**

```
Input: head = [0,0]
Output: 0
```

**Constraints:**

- The Linked List is not empty.
- Number of nodes will not exceed `30`.
- Each node's value is either `0` or `1`.

## Solution

nothing to say

``` cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        while(head) {
            ans <<= 1;
            ans |= head->val;
            head = head->next;
        }
        return ans;
    }
};
```