+++
updated = 2024-05-13T09:14:44+08:00
title = "2024-05-13 Daily Challenge"
path = "2024-05-13-Daily-Challenge"
date = 2024-05-13T09:14:44+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/score-after-flipping-matrix/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 13

## Description

**Score After Flipping Matrix**

<p>You are given an <code>m x n</code> binary matrix <code>grid</code>.</p>

<p>A <strong>move</strong> consists of choosing any row or column and toggling each value in that row or column (i.e., changing all <code>0</code>&#39;s to <code>1</code>&#39;s, and all <code>1</code>&#39;s to <code>0</code>&#39;s).</p>

<p>Every row of the matrix is interpreted as a binary number, and the <strong>score</strong> of the matrix is the sum of these numbers.</p>

<p>Return <em>the highest possible <strong>score</strong> after making any number of <strong>moves</strong> (including zero moves)</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/23/lc-toogle1.jpg" style="width: 500px; height: 299px;" />
<pre>
<strong>Input:</strong> grid = [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
<strong>Output:</strong> 39
<strong>Explanation:</strong> 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> grid = [[0]]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 20</code></li>
	<li><code>grid[i][j]</code> is either <code>0</code> or <code>1</code>.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int matrixScore(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid.front().size();
    int answer = (1 << (m - 1)) * n;

    for(int j = 1; j < m; ++j) {
      int value = 1 << (m - 1 - j);
      int same = 0;

      for(int i = 0; i < n; ++i) {
        same += (grid[i][j] == grid[i][0]);
      }

      answer += max(same, n - same) * value;
    }

    return answer;
  }
};
```
