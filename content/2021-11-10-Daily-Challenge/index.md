+++
title = "2021-11-10 Daily-Challenge"
path = "2021-11-10-Daily-Challenge"
date = 2021-11-10 19:53:35+08:00
updated = 2021-11-10 20:03:38+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 10

## Description

**Best Time to Buy and Sell Stock II**

You are given an integer array `prices` where `prices[i]` is the price of a given stock on the `ith` day.

On each day, you may decide to buy and/or sell the stock. You can only hold **at most one** share of the stock at any time. However, you can buy it then immediately sell it on the **same day**.

Find and return *the **maximum** profit you can achieve*.

 

**Example 1:**

```
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
```

**Example 2:**

```
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
```

**Example 3:**

```
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
```

 

**Constraints:**

- `1 <= prices.length <= 3 * 10^4`
- `0 <= prices[i] <= 10^4`

## Solution

``` cpp
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if(len < 2) return 0;
    int answer = 0;
    for(int i = 1; i < len; ++i) {
      if(prices[i] > prices[i - 1]) answer += prices[i] - prices[i - 1];
    }
    return answer;
  }
};

// Accepted
// 200/200 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 8.25 % of cpp submissions (13.1 MB)
```
