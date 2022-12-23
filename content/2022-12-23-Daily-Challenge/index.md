+++
updated = 2022-12-23T13:04:28+08:00
title = "2022-12-23 Daily Challenge"
path = "2022-12-23-Daily-Challenge"
date = 2022-12-23T13:04:28+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 23

## Description

**Best Time to Buy and Sell Stock with Cooldown**

<p>You are given an array <code>prices</code> where <code>prices[i]</code> is the price of a given stock on the <code>i<sup>th</sup></code> day.</p>

<p>Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:</p>

<ul>
	<li>After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).</li>
</ul>

<p><strong>Note:</strong> You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> prices = [1,2,3,0,2]
<strong>Output:</strong> 3
<strong>Explanation:</strong> transactions = [buy, sell, cooldown, buy, sell]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> prices = [1]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= prices.length &lt;= 5000</code></li>
	<li><code>0 &lt;= prices[i] &lt;= 1000</code></li>
</ul>


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
// 210/210 cases passed (10 ms)
// Your runtime beats 43.57 % of cpp submissions
// Your memory usage beats 74.16 % of cpp submissions (11.2 MB)
```
