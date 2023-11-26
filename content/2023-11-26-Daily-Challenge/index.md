+++
updated = 2023-11-26T11:17:00+08:00
title = "2023-11-26 Daily Challenge"
path = "2023-11-26-Daily-Challenge"
date = 2023-11-26T11:17:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/largest-submatrix-with-rearrangements/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 26

## Description

**Largest Submatrix With Rearrangements**

<p>You are given a binary matrix <code>matrix</code> of size <code>m x n</code>, and you are allowed to rearrange the <strong>columns</strong> of the <code>matrix</code> in any order.</p>

<p>Return <em>the area of the largest submatrix within </em><code>matrix</code><em> where <strong>every</strong> element of the submatrix is </em><code>1</code><em> after reordering the columns optimally.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/29/screenshot-2020-12-30-at-40536-pm.png" style="width: 500px; height: 240px;" />
<pre>
<strong>Input:</strong> matrix = [[0,0,1],[1,1,1],[1,0,1]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> You can rearrange the columns as shown above.
The largest submatrix of 1s, in bold, has an area of 4.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/29/screenshot-2020-12-30-at-40852-pm.png" style="width: 500px; height: 62px;" />
<pre>
<strong>Input:</strong> matrix = [[1,0,1,0,1]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> You can rearrange the columns as shown above.
The largest submatrix of 1s, in bold, has an area of 3.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> matrix = [[1,1,0],[1,0,1]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> Notice that you must rearrange entire columns, and there is no way to make a submatrix of 1s larger than an area of 2.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>matrix[i][j]</code> is either <code>0</code> or <code>1</code>.</li>
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
  int largestSubmatrix(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix.front().size();

    int answer = 0;
    for(int row = 0; row < rows; ++row) {
      for(int col = 0; col < cols; ++col) {
        if(matrix[row][col] && row) {
          matrix[row][col] += matrix[row - 1][col];
        }
      }

      vector<int> currentRow = matrix[row];
      sort(currentRow.rbegin(), currentRow.rend());
      for(int i = 0; i < cols; ++i) {
        answer = max(answer, currentRow[i] * (i + 1));
      }
    }

    return answer;
  }
};

// Accepted
// 58/58 cases passed (168 ms)
// Your runtime beats 36.93 % of cpp submissions
// Your memory usage beats 60.8 % of cpp submissions (74.7 MB)
```
