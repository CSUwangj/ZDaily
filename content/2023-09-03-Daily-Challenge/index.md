+++
updated = 2023-09-03T13:15:56+08:00
title = "2023-09-03 Daily Challenge"
path = "2023-09-03-Daily-Challenge"
date = 2023-09-03T13:15:56+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/unique-paths/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 3

## Description

**Unique Paths**

<p>There is a robot on an <code>m x n</code> grid. The robot is initially located at the <strong>top-left corner</strong> (i.e., <code>grid[0][0]</code>). The robot tries to move to the <strong>bottom-right corner</strong> (i.e., <code>grid[m - 1][n - 1]</code>). The robot can only move either down or right at any point in time.</p>

<p>Given the two integers <code>m</code> and <code>n</code>, return <em>the number of possible unique paths that the robot can take to reach the bottom-right corner</em>.</p>

<p>The test cases are generated so that the answer will be less than or equal to <code>2 * 10<sup>9</sup></code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img src="https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png" style="width: 400px; height: 183px;" />
<pre>
<strong>Input:</strong> m = 3, n = 7
<strong>Output:</strong> 28
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> m = 3, n = 2
<strong>Output:</strong> 3
<strong>Explanation:</strong> From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -&gt; Down -&gt; Down
2. Down -&gt; Down -&gt; Right
3. Down -&gt; Right -&gt; Down
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
</ul>


## Solution

``` cpp
constexpr int combination(int total, int pick) {
  long long result = 1;
  for(int i = 0; i < pick; ++i) {
    result *= (total - i);
    result /= (i + 1);
  }
  return result;
}

class Solution {
public:
  int uniquePaths(int m, int n) {
    return combination(m + n - 2, min(n - 1, m - 1));
  }
};

// Accepted
// 63/63 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 98.48 % of cpp submissions (5.8 MB)
```
