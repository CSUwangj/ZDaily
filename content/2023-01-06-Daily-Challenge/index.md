+++
updated = 2023-01-06T11:37:15+08:00
title = "2023-01-06 Daily Challenge"
path = "2023-01-06-Daily-Challenge"
date = 2023-01-06T11:37:15+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/maximum-ice-cream-bars/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 6

## Description

**Maximum Ice Cream Bars**

<p>It is a sweltering summer day, and a boy wants to buy some ice cream bars.</p>

<p>At the store, there are <code>n</code> ice cream bars. You are given an array <code>costs</code> of length <code>n</code>, where <code>costs[i]</code> is the price of the <code>i<sup>th</sup></code> ice cream bar in coins. The boy initially has <code>coins</code> coins to spend, and he wants to buy as many ice cream bars as possible.&nbsp;</p>

<p>Return <em>the <strong>maximum</strong> number of ice cream bars the boy can buy with </em><code>coins</code><em> coins.</em></p>

<p><strong>Note:</strong> The boy can buy the ice cream bars in any order.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> costs = [1,3,2,4,1], coins = 7
<strong>Output:</strong> 4
<strong>Explanation: </strong>The boy can buy ice cream bars at indices 0,1,2,4 for a total price of 1 + 3 + 2 + 1 = 7.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> costs = [10,6,8,7,7,8], coins = 5
<strong>Output:</strong> 0
<strong>Explanation: </strong>The boy cannot afford any of the ice cream bars.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> costs = [1,6,3,1,2,5], coins = 20
<strong>Output:</strong> 6
<strong>Explanation: </strong>The boy can buy all the ice cream bars for a total price of 1 + 6 + 3 + 1 + 2 + 5 = 18.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>costs.length == n</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= costs[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= coins &lt;= 10<sup>8</sup></code></li>
</ul>

## Solution

``` cpp
class Solution {
public:
  int maxIceCream(vector<int>& costs, int coins) {
    sort(costs.begin(), costs.end());
    if(coins < costs.front()) {
      return 0;
    }
    int answer = 0;
    for(int i = 1; i < costs.size(); ++i) {
      costs[i] += costs[i - 1];
      if(coins < costs[i]) {
        return i;
      }
    }
    return costs.size();
  }
};

// Accepted
// 63/63 cases passed (193 ms)
// Your runtime beats 91.54 % of cpp submissions
// Your memory usage beats 76.68 % of cpp submissions (76.5 MB)
```
