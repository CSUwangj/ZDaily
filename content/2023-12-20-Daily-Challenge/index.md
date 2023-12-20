+++
updated = 2023-12-20T18:37:03+08:00
title = "2023-12-20 Daily Challenge"
path = "2023-12-20-Daily-Challenge"
date = 2023-12-20T18:37:03+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/buy-two-chocolates/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 20

## Description

**Buy Two Chocolates**

<p>You are given an integer array <code>prices</code> representing the prices of various chocolates in a store. You are also given a single integer <code>money</code>, which represents your initial amount of money.</p>

<p>You must buy <strong>exactly</strong> two chocolates in such a way that you still have some <strong>non-negative</strong> leftover money. You would like to minimize the sum of the prices of the two chocolates you buy.</p>

<p>Return <em>the amount of money you will have leftover after buying the two chocolates</em>. If there is no way for you to buy two chocolates without ending up in debt, return <code>money</code>. Note that the leftover must be non-negative.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> prices = [1,2,2], money = 3
<strong>Output:</strong> 0
<strong>Explanation:</strong> Purchase the chocolates priced at 1 and 2 units respectively. You will have 3 - 3 = 0 units of money afterwards. Thus, we return 0.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> prices = [3,2,3], money = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> You cannot buy 2 chocolates without going in debt, so we return 3.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= prices.length &lt;= 50</code></li>
	<li><code>1 &lt;= prices[i] &lt;= 100</code></li>
	<li><code>1 &lt;= money &lt;= 100</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int buyChoco(vector<int>& prices, int money) {
    sort(prices.begin(), prices.end());
    if(money < prices[0] + prices[1]) return money;
    return money - prices[0] - prices[1];
  }
};

// Accepted
// 2003/2003 cases passed (10 ms)
// Your runtime beats 74.66 % of cpp submissions
// Your memory usage beats 58.3 % of cpp submissions (47 MB)
```
