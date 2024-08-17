+++
updated = 2024-08-17T16:40:57+08:00
title = "2024-08-17 Daily Challenge"
path = "2024-08-17-Daily-Challenge"
date = 2024-08-17T16:40:57+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/maximum-number-of-points-with-cost/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 17

## Description

**Maximum Number of Points with Cost**

<p>You are given an <code>m x n</code> integer matrix <code>points</code> (<strong>0-indexed</strong>). Starting with <code>0</code> points, you want to <strong>maximize</strong> the number of points you can get from the matrix.</p>

<p>To gain points, you must pick one cell in <strong>each row</strong>. Picking the cell at coordinates <code>(r, c)</code> will <strong>add</strong> <code>points[r][c]</code> to your score.</p>

<p>However, you will lose points if you pick a cell too far from the cell that you picked in the previous row. For every two adjacent rows <code>r</code> and <code>r + 1</code> (where <code>0 &lt;= r &lt; m - 1</code>), picking cells at coordinates <code>(r, c<sub>1</sub>)</code> and <code>(r + 1, c<sub>2</sub>)</code> will <strong>subtract</strong> <code>abs(c<sub>1</sub> - c<sub>2</sub>)</code> from your score.</p>

<p>Return <em>the <strong>maximum</strong> number of points you can achieve</em>.</p>

<p><code>abs(x)</code> is defined as:</p>

<ul>
	<li><code>x</code> for <code>x &gt;= 0</code>.</li>
	<li><code>-x</code> for <code>x &lt; 0</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong><strong> </strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/12/screenshot-2021-07-12-at-13-40-26-diagram-drawio-diagrams-net.png" style="width: 300px; height: 300px;" />
<pre>
<strong>Input:</strong> points = [[1,2,3],[1,5,1],[3,1,1]]
<strong>Output:</strong> 9
<strong>Explanation:</strong>
The blue cells denote the optimal cells to pick, which have coordinates (0, 2), (1, 1), and (2, 0).
You add 3 + 5 + 3 = 11 to your score.
However, you must subtract abs(2 - 1) + abs(1 - 0) = 2 from your score.
Your final score is 11 - 2 = 9.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/12/screenshot-2021-07-12-at-13-42-14-diagram-drawio-diagrams-net.png" style="width: 200px; height: 299px;" />
<pre>
<strong>Input:</strong> points = [[1,5],[2,3],[4,2]]
<strong>Output:</strong> 11
<strong>Explanation:</strong>
The blue cells denote the optimal cells to pick, which have coordinates (0, 1), (1, 1), and (2, 0).
You add 5 + 3 + 4 = 12 to your score.
However, you must subtract abs(1 - 1) + abs(1 - 0) = 1 from your score.
Your final score is 12 - 1 = 11.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == points.length</code></li>
	<li><code>n == points[r].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= points[r][c] &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  long long maxPoints(vector<vector<int>>& points) {
    int rows = points.size();
    int cols = points.front().size();
    vector<long long> dp(cols);
    for(int i = 0; i < cols; ++i) {
      dp[i] = points[0][i];
    }
    for(int i = 1; i < rows; ++i) {
      vector<long long> left(cols), right(cols), newDp(cols);

      left[0] = dp[0];
      for(int j = 1; j < cols; ++j) {
        left[j] = max(left[j - 1], dp[j] + j);
      }

      right[cols - 1] = dp[cols - 1] - (cols - 1);
      for(int j = cols - 2; j >= 0; --j) {
        right[j] = max(right[j + 1], dp[j] - j);
      }

      for(int j = 0; j < cols; ++j) {
        newDp[j] = max(left[j] - j, right[j] + j) + points[i][j];
      }

      swap(dp, newDp);
    }
    return *max_element(dp.begin(), dp.end());
  }
};
```
