+++
updated = 2023-06-24T15:07:14+08:00
title = "2023-06-24 Daily Challenge"
path = "2023-06-24-Daily-Challenge"
date = 2023-06-24T15:07:14+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/tallest-billboard/description/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 24

## Description

**Tallest Billboard**

<p>You are installing a billboard and want it to have the largest height. The billboard will have two steel supports, one on each side. Each steel support must be an equal height.</p>

<p>You are given a collection of <code>rods</code> that can be welded together. For example, if you have rods of lengths <code>1</code>, <code>2</code>, and <code>3</code>, you can weld them together to make a support of length <code>6</code>.</p>

<p>Return <em>the largest possible height of your billboard installation</em>. If you cannot support the billboard, return <code>0</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> rods = [1,2,3,6]
<strong>Output:</strong> 6
<strong>Explanation:</strong> We have two disjoint subsets {1,2,3} and {6}, which have the same sum = 6.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> rods = [1,2,3,4,5,6]
<strong>Output:</strong> 10
<strong>Explanation:</strong> We have two disjoint subsets {2,3,5} and {4,6}, which have the same sum = 10.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> rods = [1,2]
<strong>Output:</strong> 0
<strong>Explanation:</strong> The billboard cannot be supported, so we return 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= rods.length &lt;= 20</code></li>
	<li><code>1 &lt;= rods[i] &lt;= 1000</code></li>
	<li><code>sum(rods[i]) &lt;= 5000</code></li>
</ul>

## Solution

``` cpp
class Solution {
public:
  int tallestBillboard(vector<int>& rods) {
    int sum = 0;
    for(auto rod : rods) {
      sum += rod;
    }

    vector<int> dp(sum + 1, -1);
    dp[0] = 0;
    for(auto rod : rods) {
      vector<int> dpCopy(sum + 1);
      copy(dp.begin(), dp.end(), dpCopy.begin());

      for(int i = 0; i <= sum - rod; ++i) {
        if(dpCopy[i] < 0) continue;

        dp[i + rod] = max(dp[i + rod], dpCopy[i]);
        dp[abs(i - rod)] = max(dp[abs(i - rod)], dpCopy[i] + min(i, rod));
      }
    }

    return dp[0];
  }
};

// Accepted
// 80/80 cases passed (38 ms)
// Your runtime beats 95.24 % of cpp submissions
// Your memory usage beats 69.7 % of cpp submissions (26.6 MB)
```
