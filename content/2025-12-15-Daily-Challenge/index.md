+++
updated = 2025-12-15T16:41:45+01:00
title = "2025-12-15 Daily Challenge"
path = "2025-12-15-Daily-Challenge"
date = 2025-12-15T16:41:45+01:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 15

## Description

**Number of Smooth Descent Periods of a Stock**

<p>You are given an integer array <code>prices</code> representing the daily price history of a stock, where <code>prices[i]</code> is the stock price on the <code>i<sup>th</sup></code> day.</p>

<p>A <strong>smooth descent period</strong> of a stock consists of <strong>one or more contiguous</strong> days such that the price on each day is <strong>lower</strong> than the price on the <strong>preceding day</strong> by <strong>exactly</strong> <code>1</code>. The first day of the period is exempted from this rule.</p>

<p>Return <em>the number of <strong>smooth descent periods</strong></em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> prices = [3,2,1,4]
<strong>Output:</strong> 7
<strong>Explanation:</strong> There are 7 smooth descent periods:
[3], [2], [1], [4], [3,2], [2,1], and [3,2,1]
Note that a period with one day is a smooth descent period by the definition.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> prices = [8,6,7,7]
<strong>Output:</strong> 4
<strong>Explanation:</strong> There are 4 smooth descent periods: [8], [6], [7], and [7]
Note that [8,6] is not a smooth descent period as 8 - 6 &ne; 1.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> prices = [1]
<strong>Output:</strong> 1
<strong>Explanation:</strong> There is 1 smooth descent period: [1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= prices.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= prices[i] &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  long long getDescentPeriods(vector<int>& prices) {
    long long answer = 0;
    int current = 0;
    int prev = -1;
    for(auto p : prices) {
      if(p == prev - 1) current += 1;
      else {
        answer += 1LL * current * (current + 1) / 2;
        current = 1;
      }
      prev = p;
    }
    answer += 1LL * current * (current + 1) / 2;
    return answer;
  }
};

// Accepted
// 168/168 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 24.91 % of cpp submissions (107.1 MB)
```
