+++
updated = 2026-01-18T22:46:24+01:00
title = "2026-01-18 Daily Challenge"
path = "2026-01-18-Daily-Challenge"
date = 2026-01-18T22:46:24+01:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/Largest Magic Square
/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 18

## Description

**Largest Magic Square**

<p>A <code>k x k</code> <strong>magic square</strong> is a <code>k x k</code> grid filled with integers such that every row sum, every column sum, and both diagonal sums are <strong>all equal</strong>. The integers in the magic square <strong>do not have to be distinct</strong>. Every <code>1 x 1</code> grid is trivially a <strong>magic square</strong>.</p>

<p>Given an <code>m x n</code> integer <code>grid</code>, return <em>the <strong>size</strong> (i.e., the side length </em><code>k</code><em>) of the <strong>largest magic square</strong> that can be found within this grid</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" style="width: 413px; height: 335px;" src="https://assets.leetcode.com/uploads/2021/05/29/magicsquare-grid.jpg">
<pre><strong>Input:</strong> grid = [[7,1,4,5,6],[2,5,1,6,4],[1,5,4,3,2],[1,2,7,3,4]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The largest magic square has a size of 3.
Every row sum, column sum, and diagonal sum of this magic square is equal to 12.
- Row sums: 5+1+6 = 5+4+3 = 2+7+3 = 12
- Column sums: 5+5+2 = 1+4+7 = 6+3+3 = 12
- Diagonal sums: 5+4+3 = 6+4+2 = 12
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" style="width: 333px; height: 255px;" src="https://assets.leetcode.com/uploads/2021/05/29/magicsquare2-grid.jpg">
<pre><strong>Input:</strong> grid = [[5,1,3,1],[9,3,3,1],[1,3,3,8]]
<strong>Output:</strong> 2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 50</code></li>
	<li><code>1 &lt;= grid[i][j] &lt;= 10<sup>6</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
  bool ok(const vector<vector<int>>& grid, int startCol, int startRow, int k) {
    int target = accumulate(grid[startRow].begin() + startCol, grid[startRow].begin() + startCol + k, 0);
    // cout << startRow << ' ' << startCol << ' ' << k << ' ' << target << endl;
    for(int i = 0; i < k; ++i) {
      int sum = 0;
      for(int j = 0; j < k; ++j) {
        sum += grid[startRow + i][startCol + j];
      }
      if(sum != target) return false;
      sum = 0;
      for(int j = 0; j < k; ++j) {
        sum += grid[startRow + j][startCol + i];
      }
      if(sum != target) return false;
    }
    int sum = 0;
    for(int i = 0; i < k; ++i) {
      sum += grid[startRow + i][startCol + i];
    }
    if(sum != target) return false;
    sum = 0;
    for(int i = 0; i < k; ++i) {
      sum += grid[startRow + k - 1 - i][startCol + i];
    }
    if(sum != target) return false;
    return true;
  }
public:
  int largestMagicSquare(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid.front().size();
    for(int k = min(rows, cols); k > 1; --k) {
      for(int row = 0; row + k <= rows; ++row) {
        for(int col = 0; col + k <= cols; ++col) {
          if(ok(grid, col, row, k)) return k;
        }
      }
    }
    return 1;
  }
};

// Accepted
// 80/80 cases passed (34 ms)
// Your runtime beats 49.43 % of cpp submissions
// Your memory usage beats 87.43 % of cpp submissions (12.9 MB)
```
