+++
updated = 2025-06-01T23:30:33+08:00
title = "2025-06-01 Daily Challenge"
path = "2025-06-01-Daily-Challenge"
date = 2025-06-01T23:30:33+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/distribute-candies-among-children-ii/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 1

## Description

**Distribute Candies Among Children II**

<p>You are given two positive integers <code>n</code> and <code>limit</code>.</p>

<p>Return <em>the <strong>total number</strong> of ways to distribute </em><code>n</code> <em>candies among </em><code>3</code><em> children such that no child gets more than </em><code>limit</code><em> candies.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 5, limit = 2
<strong>Output:</strong> 3
<strong>Explanation:</strong> There are 3 ways to distribute 5 candies such that no child gets more than 2 candies: (1, 2, 2), (2, 1, 2) and (2, 2, 1).
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 3, limit = 3
<strong>Output:</strong> 10
<strong>Explanation:</strong> There are 10 ways to distribute 3 candies such that no child gets more than 3 candies: (0, 0, 3), (0, 1, 2), (0, 2, 1), (0, 3, 0), (1, 0, 2), (1, 1, 1), (1, 2, 0), (2, 0, 1), (2, 1, 0) and (3, 0, 0).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= limit &lt;= 10<sup>6</sup></code></li>
</ul>


## Solution

``` cpp
constexpr long long combinationOfTwo(int total) {
  if(total < 0) return 0;
  return 1LL * total * (total - 1) / 2;
}
class Solution {
public:
  long long distributeCandies(int n, int limit) {
    return combinationOfTwo(n + 2)  
      - 3 * combinationOfTwo(n - limit + 1) 
      + 3 * combinationOfTwo(n - 2 * limit)
      - combinationOfTwo(n - 3 * limit - 1);
  }
};

// Accepted
// 958/958 cases passed (5 ms)
// Your runtime beats 77.06 % of cpp submissions
// Your memory usage beats 18.82 % of cpp submissions (9 MB)
```
