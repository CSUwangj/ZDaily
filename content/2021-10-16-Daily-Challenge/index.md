+++
title = "2021-10-16 Daily-Challenge"
path = "2021-10-16-Daily-Challenge"
date = 2021-10-16 10:02:45+08:00
updated = 2021-10-16 10:34:33+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 16

## Description

**Best Time to Buy and Sell Stock III**

<p>You are given an array&nbsp;<code>coordinates</code>, <code>coordinates[i] = [x, y]</code>, where <code>[x, y]</code> represents the coordinate of a point. Check if these points&nbsp;make a straight line in the XY plane.</p>

<p>&nbsp;</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/10/15/untitled-diagram-2.jpg" style="width: 336px; height: 336px;" /></p>

<pre>
<strong>Input:</strong> coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/10/09/untitled-diagram-1.jpg" style="width: 348px; height: 336px;" /></strong></p>

<pre>
<strong>Input:</strong> coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;=&nbsp;coordinates.length &lt;= 1000</code></li>
	<li><code>coordinates[i].length == 2</code></li>
	<li><code>-10^4 &lt;=&nbsp;coordinates[i][0],&nbsp;coordinates[i][1] &lt;= 10^4</code></li>
	<li><code>coordinates</code>&nbsp;contains no duplicate point.</li>
</ul>

## Solution

``` cpp
class Solution {
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
    for(int i = 1; i <= k; ++i) {
      for(int j = 1; j < len; ++j) {
        sell[j] = max(sell[j], sell[j - 1]);
        sell[j] = max(sell[j], buy[j - 1] + prices[j]);
      }
      for(int j = 1; j < len; ++j) {
        buy[j] = max(buy[j - 1], sell[j - 1] - prices[j]);
      }
    }
    return sell[len - 1];
  }
public:
  int maxProfit(vector<int>& prices) {
    return maxProfit(2, prices);
  }
};

// Accepted
// 214/214 cases passed (124 ms)
// Your runtime beats 83.81 % of cpp submissions
// Your memory usage beats 61.08 % of cpp submissions (76 MB)
```
