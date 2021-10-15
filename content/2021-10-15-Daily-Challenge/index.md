+++
title = "2021-10-15 Daily-Challenge"
path = "2021-10-15-Daily-Challenge"
date = 2021-10-15 22:28:33+08:00
updated = 2021-10-15 22:30:13+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 15

## Description

**Best Time to Buy and Sell Stock with Cooldown**

You are given an array `prices` where `prices[i]` is the price of a given stock on the `ith` day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

- After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).

**Note:** You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

**Example 1:**

```
Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
```

**Example 2:**

```
Input: prices = [1]
Output: 0
```

 

**Constraints:**

- `1 <= prices.length <= 5000`
- `0 <= prices[i] <= 1000`

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if(len < 2) return 0;
    int buy[2] = {-prices[0], max(-prices[0], -prices[1])};
    int sell[2] = {0, max(0, buy[1] + prices[1])};
    for(int i = 2; i < len; ++i) {
      buy[0] = buy[1];
      buy[1] = max(buy[1], sell[0] - prices[i]);
      sell[0] = sell[1];
      sell[1] = max(sell[1], buy[0] + prices[i]);
    }
    return sell[1];
  }
};

// Accepted
// 210/210 cases passed (8 ms)
// Your runtime beats 32.2 % of cpp submissions
// Your memory usage beats 49.7 % of cpp submissions (11.3 MB)
```
