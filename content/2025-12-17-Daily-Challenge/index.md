+++
updated = 2025-12-17T18:49:48+01:00
title = "2025-12-17 Daily Challenge"
path = "2025-12-17-Daily-Challenge"
date = 2025-12-17T18:49:48+01:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 17

## Description

**Best Time to Buy and Sell Stock V**

<p>You are given an integer array <code>prices</code> where <code>prices[i]</code> is the price of a stock in dollars on the <code>i<sup>th</sup></code> day, and an integer <code>k</code>.</p>

<p>You are allowed to make at most <code>k</code> transactions, where each transaction can be either of the following:</p>

<ul>
	<li>
	<p><strong>Normal transaction</strong>: Buy on day <code>i</code>, then sell on a later day <code>j</code> where <code>i &lt; j</code>. You profit <code>prices[j] - prices[i]</code>.</p>
	</li>
	<li>
	<p><strong>Short selling transaction</strong>: Sell on day <code>i</code>, then buy back on a later day <code>j</code> where <code>i &lt; j</code>. You profit <code>prices[i] - prices[j]</code>.</p>
	</li>
</ul>

<p><strong>Note</strong> that you must complete each transaction before starting another. Additionally, you can't buy or sell on the same day you are selling or buying back as part of a previous transaction.</p>

<p>Return the <strong>maximum</strong> total profit you can earn by making <strong>at most</strong> <code>k</code> transactions.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">prices = [1,7,9,8,2], k = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">14</span></p>

<p><strong>Explanation:</strong></p>
We can make $14 of profit through 2 transactions:

<ul>
	<li>A normal transaction: buy the stock on day 0 for $1 then sell it on day 2 for $9.</li>
	<li>A short selling transaction: sell the stock on day 3 for $8 then buy back on day 4 for $2.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">prices = [12,16,19,19,8,1,19,13,9], k = 3</span></p>

<p><strong>Output:</strong> <span class="example-io">36</span></p>

<p><strong>Explanation:</strong></p>
We can make $36 of profit through 3 transactions:

<ul>
	<li>A normal transaction: buy the stock on day 0 for $12 then sell it on day 2 for $19.</li>
	<li>A short selling transaction: sell the stock on day 3 for $19 then buy back on day 4 for $8.</li>
	<li>A normal transaction: buy the stock on day 5 for $1 then sell it on day 6 for $19.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= prices.length &lt;= 10<sup>3</sup></code></li>
	<li><code>1 &lt;= prices[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= prices.length / 2</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  long long maximumProfit(vector<int>& prices, int k) {
    int len = prices.size();
    vector<vector<vector<long long>>> dp(len, vector<vector<long long>>(k + 1, vector<long long>({0, -prices[0], prices[0]})));
    for(int i = 1; i < len; ++i) {
      int x = prices[i];
      for(int t = 1; t <= k; ++t) {
        long long profit = dp[i - 1][t][0];
        long long buy = dp[i - 1][t][1];
        long long sell = dp[i - 1][t][2];
        long long prevProfit = dp[i - 1][t - 1][0];
        profit = max({profit, buy + x, sell - x});
        buy = max(buy, prevProfit - x);
        sell = max(sell, prevProfit + x);
        dp[i][t][0] = profit;
        dp[i][t][1] = buy;
        dp[i][t][2] = sell;
      }
    }
    return dp[len - 1][k][0];
  }
};

// Accepted
// 776/776 cases passed (703 ms)
// Your runtime beats 37.53 % of cpp submissions
// Your memory usage beats 21.77 % of cpp submissions (344.9 MB)
```
