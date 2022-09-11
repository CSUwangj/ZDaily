+++
updated = 2022-09-10 18:14:00+08:00
title = "2022-09-10 Daily-Challenge"
path = "2022-09-10-Daily-Challenge"
date = 2022-09-10 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 10

## Description

**Best Time to Buy and Sell Stock IV**

You are given an integer array `prices` where `prices[i]` is the price of a given stock on the `ith` day, and an integer `k`.

Find the maximum profit you can achieve. You may complete at most `k` transactions.

**Note:** You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

**Example 1:**

```
Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
```

**Example 2:**

```
Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
```

 

**Constraints:**

- `0 <= k <= 100`
- `0 <= prices.length <= 1000`
- `0 <= prices[i] <= 1000`

## Solution

``` cpp
class Solution {
public:
  int maxProfit(int k, vector<int>& prices) {
    int len = prices.size();
    if(len < 2) return 0;
    int buy[len];
    int sell[len];
    buy[0] = -prices[0];
    sell[0] = 0;
    for(int i = 1; i < len; ++i) {
      buy[i] = max(buy[i - 1], -prices[i]);
      sell[i] = 0;
    }
    // cout << "$$$$$$$$$$$$$$$" << endl;
    for(int i = 1; i <= k; ++i) {
      for(int j = 1; j < len; ++j) {
        sell[j] = max(sell[j], sell[j - 1]);
        sell[j] = max(sell[j], buy[j - 1] + prices[j]);
      }
      for(int j = 1; j < len; ++j) {
        buy[j] = max(buy[j - 1], sell[j - 1] - prices[j]);
      }
      // for(int j = 0; j < len; ++j) {
      //   cout << i << ' ' << j << ' ' << buy[j] << ' ' << sell[j] << endl;
      // }
    }
    return sell[len - 1];
  }
};

// Accepted
// 211/211 cases passed (3 ms)
// Your runtime beats 99.03 % of cpp submissions
// Your memory usage beats 98.77 % of cpp submissions (10.6 MB)
```
