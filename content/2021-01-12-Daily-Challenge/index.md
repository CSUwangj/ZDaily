+++
title = "2021-01-12 Daily-Challenge"
path = "2021-01-12-Daily-Challenge"
date = 2021-01-12 21:07:32+08:00
updated = 2021-01-12 21:38:56+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) and leetcode's [January LeetCoding Challenge](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/580/week-2-january-8th-january-14th/3600/) with `cpp`.

<!-- more -->

# Best Time to Buy and Sell Stock

## Description

Say you have an array for which the *i*th element is the price of a given stock on day *i*.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

**Example 1:**

```
Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
```

**Example 2:**

```
Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
```

## Solution

``` cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int mmin = prices.front();
        int answer = 0;
        int len = prices.size();
        for(int i : prices) {
            mmin = min(mmin, i);
            answer = max(answer, i-mmin);
        }
        return answer;
    }
};
```

# January LeetCoding Challenge12

## Description

**Add Two Numbers**

## Description

You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order**, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/10/02/addtwonumber1.jpg)

```
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
```

**Example 2:**

```
Input: l1 = [0], l2 = [0]
Output: [0]
```

**Example 3:**

```
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
```

**Constraints:**

- The number of nodes in each linked list is in the range `[1, 100]`.
- `0 <= Node.val <= 9`
- It is guaranteed that the list represents a number that does not have leading zeros.

## Solution

``` cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *newHead = new ListNode();
        ListNode *cur = newHead;
        int carry = 0;
        while(l1 && l2) {
            int val = l1->val + l2->val + carry;
            carry = val / 10;
            cur->next = new ListNode(val%10);
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode *rest = l1 ? l1 : l2;
        while(rest) {
            int val = rest->val + carry;
            carry = val / 10;
            cur->next = new ListNode(val%10);
            cur = cur->next;
            rest = rest->next;
        }
        if(carry) cur->next = new ListNode(carry);
        return newHead->next;
    }
};
```
