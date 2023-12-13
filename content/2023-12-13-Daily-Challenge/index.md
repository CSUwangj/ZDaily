+++
updated = 2023-12-13T23:09:52+08:00
title = "2023-12-13 Daily Challenge"
path = "2023-12-13-Daily-Challenge"
date = 2023-12-13T23:09:52+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/special-positions-in-a-binary-matrix/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 13

## Description

**Special Positions in a Binary Matrix**

<p>Given an <code>m x n</code> binary matrix <code>mat</code>, return <em>the number of special positions in </em><code>mat</code><em>.</em></p>

<p>A position <code>(i, j)</code> is called <strong>special</strong> if <code>mat[i][j] == 1</code> and all other elements in row <code>i</code> and column <code>j</code> are <code>0</code> (rows and columns are <strong>0-indexed</strong>).</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/12/23/special1.jpg" style="width: 244px; height: 245px;" />
<pre>
<strong>Input:</strong> mat = [[1,0,0],[0,0,1],[1,0,0]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/12/24/special-grid.jpg" style="width: 244px; height: 245px;" />
<pre>
<strong>Input:</strong> mat = [[1,0,0],[0,1,0],[0,0,1]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> (0, 0), (1, 1) and (2, 2) are special positions.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>mat[i][j]</code> is either <code>0</code> or <code>1</code>.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int numSpecial(vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat.front().size();
    vector<int> rowCount(rows);
    vector<int> colCount(cols);
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        if(mat[i][j]) {
          rowCount[i] += 1;
          colCount[j] += 1;
        }
      }
    }

    int answer = 0;
    for(int i = 0; i < rows; ++i) {
      if(rowCount[i] != 1) continue;
      for(int j = 0; j < cols; ++j) {
        if(!mat[i][j] || colCount[j] != 1) continue;
        answer += 1;
      }
    }

    return answer;
  }
};

// Accepted
// 95/95 cases passed (13 ms)
// Your runtime beats 83.42 % of cpp submissions
// Your memory usage beats 12.89 % of cpp submissions (13.4 MB)
```
