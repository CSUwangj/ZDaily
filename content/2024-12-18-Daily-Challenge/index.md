+++
updated = 2024-12-18T15:40:32+08:00
title = "2024-12-18 Daily Challenge"
path = "2024-12-18-Daily-Challenge"
date = 2024-12-18T15:40:32+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 18

## Description

**Final Prices With a Special Discount in a Shop**

<p>You are given an integer array <code>prices</code> where <code>prices[i]</code> is the price of the <code>i<sup>th</sup></code> item in a shop.</p>

<p>There is a special discount for items in the shop. If you buy the <code>i<sup>th</sup></code> item, then you will receive a discount equivalent to <code>prices[j]</code> where <code>j</code> is the minimum index such that <code>j &gt; i</code> and <code>prices[j] &lt;= prices[i]</code>. Otherwise, you will not receive any discount at all.</p>

<p>Return an integer array <code>answer</code> where <code>answer[i]</code> is the final price you will pay for the <code>i<sup>th</sup></code> item of the shop, considering the special discount.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> prices = [8,4,6,2,3]
<strong>Output:</strong> [4,2,4,2,3]
<strong>Explanation:</strong> 
For item 0 with price[0]=8 you will receive a discount equivalent to prices[1]=4, therefore, the final price you will pay is 8 - 4 = 4.
For item 1 with price[1]=4 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 4 - 2 = 2.
For item 2 with price[2]=6 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 6 - 2 = 4.
For items 3 and 4 you will not receive any discount at all.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> prices = [1,2,3,4,5]
<strong>Output:</strong> [1,2,3,4,5]
<strong>Explanation:</strong> In this case, for all items, you will not receive any discount at all.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> prices = [10,1,1,6]
<strong>Output:</strong> [9,0,1,6]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= prices.length &lt;= 500</code></li>
	<li><code>1 &lt;= prices[i] &lt;= 1000</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  vector<int> finalPrices(vector<int>& prices) {
    for(int i = 0; i < prices.size() - 1; ++i) {
      for(int j = i + 1; j < prices.size(); ++j) {
        if(prices[j] > prices[i]) continue;
        prices[i] -= prices[j];
        break;
      }
    }
    return prices;
  }
};

// Accepted
// 103/103 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 29.91 % of cpp submissions (13.9 MB)
```
