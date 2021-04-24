+++
title = "2020-11-02 Daily-Challenge"
path = "2020-11-02-Daily-Challenge"
date = 2020-11-02 00:24:07+08:00
updated = 2020-11-02 18:57:19+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done *2 Keys Keyboard* on [leetcode](https://leetcode.com/problems/2-keys-keyboard/) and leetcode's [November LeetCoding Challenge](https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/564/week-1-november-1st-november-7th/3517/) with `cpp`.

<!-- more -->

# 2 Keys Keyboard

## Description

Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:

1. `Copy All`: You can copy all the characters present on the notepad (partial copy is not allowed).
2. `Paste`: You can paste the characters which are copied **last time**.

Given a number `n`. You have to get **exactly** `n` 'A' on the notepad by performing the minimum number of steps permitted. Output the minimum number of steps to get `n` 'A'.

**Example 1:**

```
Input: 3
Output: 3
Explanation:
Intitally, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.
```

**Note:**

1. The `n` will be in the range [1, 1000].

## Solution

it's obvious that final result comes from it's factor, so all we need do is factorize it and add all non-one factors,
if there are only one and itself are its factors, answer is n.

``` cpp
class Solution {
public:
    int minSteps(int n) {
        if(n == 1) return 0;
        int ans = 0;
        for(int i = 2; i <= n; ++i) {
            if(n % i == 0) {
                while(n % i == 0) {
                    n /= i;
                    ans += i;
                }
            }
        }
        return ans;
    }
};
```

# November LeetCoding Challenge2

## Description

**Insertion Sort List**

Sort a linked list using insertion sort.

![img](https://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif)
A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.
With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list

**Algorithm of Insertion Sort:**

1. Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
2. At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
3. It repeats until no input elements remain.
   **Example 1:**

```
Input: 4->2->1->3
Output: 1->2->3->4
```

**Example 2:**

```
Input: -1->5->3->4->0
Output: -1->0->3->4->5
```

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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *new_head = new ListNode(INT_MIN);
        ListNode *cur_head = head, *cur_node;
        while(cur_head) {
            cur_node = cur_head;
            cur_head = cur_head->next;
            ListNode *insert_pos = new_head->next, *prev_pos = new_head;
            while(insert_pos && insert_pos->val < cur_node->val) {
                prev_pos = insert_pos;
                insert_pos = insert_pos->next;
            }
            cur_node->next = insert_pos;
            prev_pos->next = cur_node;
        }
        return new_head->next;
    }
};
```
