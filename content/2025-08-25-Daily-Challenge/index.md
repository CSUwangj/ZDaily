+++
updated = 2025-08-25T23:08:41+02:00
title = "2025-08-25 Daily Challenge"
path = "2025-08-25-Daily-Challenge"
date = 2025-08-25T23:08:41+02:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/diagonal-traverse/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 25

## Description

**Diagonal Traverse**

<p>Given an <code>m x n</code> matrix <code>mat</code>, return <em>an array of all the elements of the array in a diagonal order</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/10/diag1-grid.jpg" style="width: 334px; height: 334px;" />
<pre>
<strong>Input:</strong> mat = [[1,2,3],[4,5,6],[7,8,9]]
<strong>Output:</strong> [1,2,4,7,5,3,6,8,9]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> mat = [[1,2],[3,4]]
<strong>Output:</strong> [1,2,3,4]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= mat[i][j] &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat.front().size();
    int row = 0;
    int col = 0;
    int direction = 1;
    vector<int> answer;
    while(row < rows && col < cols) {
      // cout << row << ' ' <<col << " -> ";
      answer.push_back(mat[row][col]);
      row -= direction;
      col += direction;
      // cout << row << ' ' <<col << endl;
      direction = -direction;
      if(col == cols) {
        row += 2;
        col -= 1;
      } else if(row == rows) {
        col += 2;
        row -= 1;
      } else if(row < 0) {
        row = 0;
      } else if(col < 0) {
        col = 0;
      } else {
        direction = -direction;
      }
    }
    return answer;
  }
};

// Accepted
// 32/32 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 83.49 % of cpp submissions (22.6 MB)
```
