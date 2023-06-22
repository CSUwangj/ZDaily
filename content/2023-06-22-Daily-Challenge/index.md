+++
updated = 2023-06-22T08:03:07+08:00
title = "2023-06-22 Daily Challenge"
path = "2023-06-22-Daily-Challenge"
date = 2023-06-22T08:03:07+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 22

## Description

**Best Time to Buy and Sell Stock with Transaction Fee**

<p>You are given an array <code>prices</code> where <code>prices[i]</code> is the price of a given stock on the <code>i<sup>th</sup></code> day, and an integer <code>fee</code> representing a transaction fee.</p>

<p>Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.</p>

<p><strong>Note:</strong> You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> prices = [1,3,2,8,4,9], fee = 2
<strong>Output:</strong> 8
<strong>Explanation:</strong> The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> prices = [1,3,7,5,10,3], fee = 3
<strong>Output:</strong> 6
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= prices.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= prices[i] &lt; 5 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= fee &lt; 5 * 10<sup>4</sup></code></li>
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
  int maxProfit(vector<int>& prices, int fee) {
    int len = prices.size();
    if(len < 2) return 0;
    int sell = 0;
    int buy = INT_MIN;
    for(auto price : prices) {
      buy = max(buy, sell - fee - price);
      sell = max(sell, buy + price);
    }
    return sell;
  }
};

// Accepted
// 44/44 cases passed (83 ms)
// Your runtime beats 99.48 % of cpp submissions
// Your memory usage beats 99.75 % of cpp submissions (54.6 MB)
```
