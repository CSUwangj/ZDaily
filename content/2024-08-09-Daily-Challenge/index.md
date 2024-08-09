+++
updated = 2024-08-09T09:44:56+08:00
title = "2024-08-09 Daily Challenge"
path = "2024-08-09-Daily-Challenge"
date = 2024-08-09T09:44:56+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/magic-squares-in-grid/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 9

## Description

**Magic Squares In Grid**

<p>A <code>3 x 3</code> <strong>magic square</strong> is a <code>3 x 3</code> grid filled with distinct numbers <strong>from </strong>1<strong> to </strong>9 such that each row, column, and both diagonals all have the same sum.</p>

<p>Given a <code>row x col</code> <code>grid</code> of integers, how many <code>3 x 3</code> contiguous magic square subgrids are there?</p>

<p>Note: while a magic square can only contain numbers from 1 to 9, <code>grid</code> may contain numbers up to 15.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/11/magic_main.jpg" style="width: 322px; height: 242px;" />
<pre>
<strong>Input:</strong> grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
<strong>Output:</strong> 1
<strong>Explanation: </strong>
The following subgrid is a 3 x 3 magic square:
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/11/magic_valid.jpg" style="width: 242px; height: 242px;" />
while this one is not:
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/11/magic_invalid.jpg" style="width: 242px; height: 242px;" />
In total, there is only one magic square inside the given grid.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> grid = [[8]]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>row == grid.length</code></li>
	<li><code>col == grid[i].length</code></li>
	<li><code>1 &lt;= row, col &lt;= 10</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 15</code></li>
</ul>


## Solution

``` cpp
class Solution {
  const int target = (1 << 10) - 2;
public:
  int numMagicSquaresInside(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid.front().size();
    int answer = 0;
    for(int i = 0; i <= rows - 3; ++i) {
      for(int j = 0; j <= cols - 3; ++j) {
        int result = 0;
        for(int ii = 0; ii < 3; ++ii) {
          for(int jj = 0; jj < 3; ++jj) {
            result |= (1 << grid[i + ii][j + jj]);
          }
        }
        if(result != target) continue;
        bool ok = true;
        int sum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
        for(int ii = 0; ii < 3; ++ii) {
          if(grid[i + ii][j] + grid[i + ii][j + 1] + grid[i + ii][j + 2] != sum) ok = false;
          if(grid[i][j + ii] + grid[i + 1][j + ii] + grid[i + 2][j + ii] != sum) ok = false;
        }
        if(grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] != sum) ok = false;
        if(grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j] != sum) ok = false;
        answer += ok;
      }
    }
    return answer;
  }
};
```
