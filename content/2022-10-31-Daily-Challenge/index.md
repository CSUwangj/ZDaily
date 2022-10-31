+++
updated = 2022-10-31T12:38:25+08:00
title = "2022-10-31 Daily Challenge"
path = "2022-10-31-Daily-Challenge"
date = 2022-10-31T12:38:25+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/toeplitz-matrix/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 31

## Description

**Toeplitz Matrix**

<p>Given an <code>m x n</code> <code>matrix</code>, return&nbsp;<em><code>true</code>&nbsp;if the matrix is Toeplitz. Otherwise, return <code>false</code>.</em></p>

<p>A matrix is <strong>Toeplitz</strong> if every diagonal from top-left to bottom-right has the same elements.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/ex1.jpg" style="width: 322px; height: 242px;" />
<pre>
<strong>Input:</strong> matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
<strong>Output:</strong> true
<strong>Explanation:</strong>
In the above grid, the&nbsp;diagonals are:
&quot;[9]&quot;, &quot;[5, 5]&quot;, &quot;[1, 1, 1]&quot;, &quot;[2, 2, 2]&quot;, &quot;[3, 3]&quot;, &quot;[4]&quot;.
In each diagonal all elements are the same, so the answer is True.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/ex2.jpg" style="width: 162px; height: 162px;" />
<pre>
<strong>Input:</strong> matrix = [[1,2],[2,2]]
<strong>Output:</strong> false
<strong>Explanation:</strong>
The diagonal &quot;[1, 2]&quot; has different elements.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 20</code></li>
	<li><code>0 &lt;= matrix[i][j] &lt;= 99</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong></p>

<ul>
	<li>What if the <code>matrix</code> is stored on disk, and the memory is limited such that you can only load at most one row of the matrix into the memory at once?</li>
	<li>What if the <code>matrix</code> is so large that you can only load up a partial row into the memory at once?</li>
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
  bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix.front().size();
    for(int i = 0; i < cols - 1; ++i) {
      int element = matrix[0][i];
      for(int j = 1; j + i < cols && j < rows; ++j) {
        if(matrix[j][i + j] != element) return false;
      }
    }
    for(int i = 1; i < rows - 1; ++i) {
      int element = matrix[i][0];
      for(int j = 1; i + j < rows && j < cols; ++j) {
        if(matrix[i + j][j] != element) return false;
      }
    }
    return true;
  }
};

// Accepted
// 483/483 cases passed (17 ms)
// Your runtime beats 88.89 % of cpp submissions
// Your memory usage beats 15.16 % of cpp submissions (17.5 MB)
```
