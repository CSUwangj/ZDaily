+++
updated = 2022-12-12T12:08:37+08:00
title = "2022-12-12 Daily Challenge"
path = "2022-12-12-Daily-Challenge"
date = 2022-12-12T12:08:37+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/climbing-stairs/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 12

## Description

**Climbing Stairs**

<p>You are climbing a staircase. It takes <code>n</code> steps to reach the top.</p>

<p>Each time you can either climb <code>1</code> or <code>2</code> steps. In how many distinct ways can you climb to the top?</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 2
<strong>Output:</strong> 2
<strong>Explanation:</strong> There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 45</code></li>
</ul>


## Solution

``` cpp
constexpr auto table = []{
  array<int, 46> arr{1, 1};
  for(int i = 2; i < 46; ++i) arr[i] = arr[i - 1] + arr[i - 2];
  return arr;
}();
class Solution {
public:
  int climbStairs(int n) {
    return table[n];
  }
};

// Accepted
// 45/45 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 55.72 % of cpp submissions (6 MB)
```
