+++
title = "2022-02-01 Daily-Challenge"
path = "2022-02-01-Daily-Challenge"
date = 2022-02-01 10:13:00+08:00
updated = 2022-02-01 10:14:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Happy new year!

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 1

## Description

**Best Time to Buy and Sell Stock**

<p>You are given an array <code>prices</code> where <code>prices[i]</code> is the price of a given stock on the <code>i<sup>th</sup></code> day.</p>

<p>You want to maximize your profit by choosing a <strong>single day</strong> to buy one stock and choosing a <strong>different day in the future</strong> to sell that stock.</p>

<p>Return <em>the maximum profit you can achieve from this transaction</em>. If you cannot achieve any profit, return <code>0</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong> prices = [7,1,5,3,6,4]
<strong>Output:</strong> 5
<strong>Explanation:</strong> Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong> prices = [7,6,4,3,1]
<strong>Output:</strong> 0
<strong>Explanation:</strong> In this case, no transactions are done and the max profit = 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= prices.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= prices[i] &lt;= 10<sup>4</sup></code></li>
</ul>

## Solution

``` cpp
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int mmin;
    int answer = 0;
    for(auto price : prices) {
      mmin = min(mmin, price);
      answer = max(answer, price - mmin);
    }
    return answer;
  }
};

// Accepted
// 211/211 cases passed (163 ms)
// Your runtime beats 48.73 % of cpp submissions
// Your memory usage beats 90.32 % of cpp submissions (93.3 MB)
```
