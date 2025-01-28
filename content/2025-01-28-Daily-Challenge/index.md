+++
updated = 2025-01-28T13:47:46+08:00
title = "2025-01-28 Daily Challenge"
path = "2025-01-28-Daily-Challenge"
date = 2025-01-28T13:47:46+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 28

## Description

**Maximum Number of Fish in a Grid**

<p>You are given a <strong>0-indexed</strong> 2D matrix <code>grid</code> of size <code>m x n</code>, where <code>(r, c)</code> represents:</p>

<ul>
	<li>A <strong>land</strong> cell if <code>grid[r][c] = 0</code>, or</li>
	<li>A <strong>water</strong> cell containing <code>grid[r][c]</code> fish, if <code>grid[r][c] &gt; 0</code>.</li>
</ul>

<p>A fisher can start at any <strong>water</strong> cell <code>(r, c)</code> and can do the following operations any number of times:</p>

<ul>
	<li>Catch all the fish at cell <code>(r, c)</code>, or</li>
	<li>Move to any adjacent <strong>water</strong> cell.</li>
</ul>

<p>Return <em>the <strong>maximum</strong> number of fish the fisher can catch if he chooses his starting cell optimally, or </em><code>0</code> if no water cell exists.</p>

<p>An <strong>adjacent</strong> cell of the cell <code>(r, c)</code>, is one of the cells <code>(r, c + 1)</code>, <code>(r, c - 1)</code>, <code>(r + 1, c)</code> or <code>(r - 1, c)</code> if it exists.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/03/29/example.png" style="width: 241px; height: 161px;" />
<pre>
<strong>Input:</strong> grid = [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]
<strong>Output:</strong> 7
<strong>Explanation:</strong> The fisher can start at cell <code>(1,3)</code> and collect 3 fish, then move to cell <code>(2,3)</code>&nbsp;and collect 4 fish.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/03/29/example2.png" />
<pre>
<strong>Input:</strong> grid = [[1,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,1]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The fisher can start at cells (0,0) or (3,3) and collect a single fish. 
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 10</code></li>
</ul>


## Solution

``` cpp
struct UnionSet {
  vector<int> parent;
  vector<int> count;
public:
  UnionSet(int size): parent(size), count(size) {
    iota(parent.begin(), parent.end(), 0);
  }

  void setCount(int key, int val) {
    count[key] = val;
  }

  int getCount(int key) {
    return count[key];
  }

  int find(int x) {
    if(parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
  }

  void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(y != parent[x]) count[y] += count[x];
    parent[x] = y;
  }
};
class Solution {
public:
  int findMaxFish(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid.front().size();
    UnionSet us(rows * cols);
    for(int r = 0; r < rows; ++r) {
      for(int c = 0; c < cols; ++c) {
        us.setCount(r * cols + c, grid[r][c]);
      }
    }
    for(int r = 0; r < rows; ++r) {
      for(int c = 0; c < cols; ++c) {
        if(!grid[r][c]) continue;
        if(r != rows - 1 && grid[r + 1][c]) us.merge(r * cols + c, r * cols + c + cols);
        if(c != cols - 1 && grid[r][c + 1]) us.merge(r * cols + c, r * cols + c + 1);
      }
    }
    int answer = 0;
    for(int i = 0; i < rows * cols; ++i) {
      answer = max(answer, us.getCount(i));
    }
    return answer;
  }
};

// Accepted
// 3842/3842 cases passed (11 ms)
// Your runtime beats 51.14 % of cpp submissions
// Your memory usage beats 68.65 % of cpp submissions (96.1 MB)
```
