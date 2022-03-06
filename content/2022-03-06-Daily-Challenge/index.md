+++
title = "2022-03-06 Daily-Challenge"
path = "2022-03-06-Daily-Challenge"
date = 2022-03-06 14:20:00+08:00
updated = 2022-03-06 14:28:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 6

## Description

**Count All Valid Pickup and Delivery Options**

Given `n` orders, each order consist in pickup and delivery services. 

Count all valid pickup/delivery possible sequences such that delivery(i) is always after of pickup(i). 

Since the answer may be too large, return it modulo 10^9 + 7.

 

**Example 1:**

```
Input: n = 1
Output: 1
Explanation: Unique order (P1, D1), Delivery 1 always is after of Pickup 1.
```

**Example 2:**

```
Input: n = 2
Output: 6
Explanation: All possible orders: 
(P1,P2,D1,D2), (P1,P2,D2,D1), (P1,D1,P2,D2), (P2,P1,D1,D2), (P2,P1,D2,D1) and (P2,D2,P1,D1).
This is an invalid order (P1,D2,P2,D1) because Pickup 2 is after of Delivery 2.
```

**Example 3:**

```
Input: n = 3
Output: 90
```

 

**Constraints:**

- `1 <= n <= 500`

## Solution

``` cpp
const int MOD = 1e9 + 7;
constexpr auto table = []{
  array<int, 501> answer{0, 1};
  for(int i = 2; i <= 500; ++i) {
    answer[i] = 1LL * answer[i - 1] * i * (i * 2 - 1) % MOD;
  }
  return answer;
}();
class Solution {
public:
  int countOrders(int n) {
    return table[n];
  }
};

// Accepted
// 36/36 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 31.45 % of cpp submissions (6 MB)
```
