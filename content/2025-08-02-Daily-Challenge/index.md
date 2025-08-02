+++
updated = 2025-08-03T02:15:05+08:00
title = "2025-08-02 Daily Challenge"
path = "2025-08-02-Daily-Challenge"
date = 2025-08-03T02:15:05+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/rearranging-fruits/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 2

## Description

**Rearranging Fruits**

<p>You have two fruit baskets containing <code>n</code> fruits each. You are given two <strong>0-indexed</strong> integer arrays <code>basket1</code> and <code>basket2</code> representing the cost of fruit in each basket. You want to make both baskets <strong>equal</strong>. To do so, you can use the following operation as many times as you want:</p>

<ul>
	<li>Chose two indices <code>i</code> and <code>j</code>, and swap the <code>i<font size="1">th</font>&nbsp;</code>fruit of <code>basket1</code> with the <code>j<font size="1">th</font></code>&nbsp;fruit of <code>basket2</code>.</li>
	<li>The cost of the swap is <code>min(basket1[i],basket2[j])</code>.</li>
</ul>

<p>Two baskets are considered equal if sorting them according to the fruit cost makes them exactly the same baskets.</p>

<p>Return <em>the minimum cost to make both the baskets equal or </em><code>-1</code><em> if impossible.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> basket1 = [4,2,2,2], basket2 = [1,4,1,2]
<strong>Output:</strong> 1
<strong>Explanation:</strong> Swap index 1 of basket1 with index 0 of basket2, which has cost 1. Now basket1 = [4,1,2,2] and basket2 = [2,4,1,2]. Rearranging both the arrays makes them equal.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> basket1 = [2,3,4,1], basket2 = [3,2,5,1]
<strong>Output:</strong> -1
<strong>Explanation:</strong> It can be shown that it is impossible to make both the baskets equal.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>basket1.length == basket2.length</code></li>
	<li><code>1 &lt;= basket1.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= basket1[i],basket2[i]&nbsp;&lt;= 10<sup>9</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  long long minCost(vector<int>& basket1, vector<int>& basket2) {
    int m = INT_MAX;
    unordered_map<int, int> freq;
    for(auto b : basket1) {
      freq[b] += 1;
      m = min(m, b);
    }
    for(auto b : basket2) {
      freq[b] -= 1;
      m = min(m, b);
    }

    vector<int> merge;
    for(auto [v, f] : freq) {
      if(f % 2) return -1;
      merge.resize(merge.size() + abs(f) / 2, v);
    }


    int mergeSize = merge.size();
    nth_element(merge.begin(), merge.begin() + mergeSize / 2, merge.end());

    return accumulate(merge.begin(), merge.begin() + mergeSize / 2, 0LL, [&](long long res, int x) {
      return res + min(2 * m, x);
    });
  }
};

// Accepted
// 40/40 cases passed (32 ms)
// Your runtime beats 89.65 % of cpp submissions
// Your memory usage beats 83.45 % of cpp submissions (89.8 MB)
```
