+++
updated = 2023-06-13T08:59:04+08:00
title = "2023-06-13 Daily Challenge"
path = "2023-06-13-Daily-Challenge"
date = 2023-06-13T08:59:04+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/equal-row-and-column-pairs/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 13

## Description

**Equal Row and Column Pairs**

<p>Given a <strong>0-indexed</strong> <code>n x n</code> integer matrix <code>grid</code>, <em>return the number of pairs </em><code>(r<sub>i</sub>, c<sub>j</sub>)</code><em> such that row </em><code>r<sub>i</sub></code><em> and column </em><code>c<sub>j</sub></code><em> are equal</em>.</p>

<p>A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/06/01/ex1.jpg" style="width: 150px; height: 153px;" />
<pre>
<strong>Input:</strong> grid = [[3,2,1],[1,7,6],[2,7,7]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> There is 1 equal row and column pair:
- (Row 2, Column 1): [2,7,7]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/06/01/ex2.jpg" style="width: 200px; height: 209px;" />
<pre>
<strong>Input:</strong> grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> There are 3 equal row and column pairs:
- (Row 0, Column 0): [3,1,2,2]
- (Row 2, Column 2): [2,4,2,2]
- (Row 3, Column 2): [2,4,2,2]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == grid.length == grid[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 200</code></li>
	<li><code>1 &lt;= grid[i][j] &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int equalPairs(vector<vector<int>>& grid) {
    map<string, int> rows;
    map<string, int> cols;
    int n = grid.size();
    for(int i = 0; i < n; ++i) {
      string row;
      string col;
      for(int j = 0; j < n; ++j) {
        row.push_back('-');
        col.push_back('-');
        row += to_string(grid[i][j]);
        col += to_string(grid[j][i]);
      }
      rows[row] += 1;
      cols[col] += 1;
    }
    int answer = 0;
    for(const auto &[s, c] : rows) {
      answer += cols[s] * c;
    }

    return answer;
  }
};

// Accepted
// 72/72 cases passed (227 ms)
// Your runtime beats 42.93 % of cpp submissions
// Your memory usage beats 13.65 % of cpp submissions (45.7 MB)
```
