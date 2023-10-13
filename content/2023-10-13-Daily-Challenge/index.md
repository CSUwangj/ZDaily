+++
updated = 2023-10-13T12:38:30+08:00
title = "2023-10-13 Daily Challenge"
path = "2023-10-13-Daily-Challenge"
date = 2023-10-13T12:38:30+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/min-cost-climbing-stairs/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 13

## Description

**Min Cost Climbing Stairs**

<p>You are given an integer array <code>cost</code> where <code>cost[i]</code> is the cost of <code>i<sup>th</sup></code> step on a staircase. Once you pay the cost, you can either climb one or two steps.</p>

<p>You can either start from the step with index <code>0</code>, or the step with index <code>1</code>.</p>

<p>Return <em>the minimum cost to reach the top of the floor</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> cost = [10,<u>15</u>,20]
<strong>Output:</strong> 15
<strong>Explanation:</strong> You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> cost = [<u>1</u>,100,<u>1</u>,1,<u>1</u>,100,<u>1</u>,<u>1</u>,100,<u>1</u>]
<strong>Output:</strong> 6
<strong>Explanation:</strong> You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= cost.length &lt;= 1000</code></li>
	<li><code>0 &lt;= cost[i] &lt;= 999</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int minCostClimbingStairs(vector<int>& cost) {
    int dp[3];
    int len = cost.size();
    for(int i = 2; i <= len; ++i) {
      dp[i % 3] = min(dp[(i + 1) % 3] + cost[i - 2], dp[(i + 2) % 3] + cost[i - 1]);
    }
    return dp[len % 3];
  }
};

// Accepted
// 283/283 cases passed (3 ms)
// Your runtime beats 84.96 % of cpp submissions
// Your memory usage beats 52.88 % of cpp submissions (13.9 MB)
```
