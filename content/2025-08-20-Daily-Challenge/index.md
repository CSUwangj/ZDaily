+++
updated = 2025-08-21T01:09:18+02:00
title = "2025-08-20 Daily Challenge"
path = "2025-08-20-Daily-Challenge"
date = 2025-08-21T01:09:18+02:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/count-square-submatrices-with-all-ones/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 20

## Description

**Count Square Submatrices with All Ones**

<p>Given a <code>m * n</code> matrix of ones and zeros, return how many <strong>square</strong> submatrices have all ones.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> matrix =
[
&nbsp; [0,1,1,1],
&nbsp; [1,1,1,1],
&nbsp; [0,1,1,1]
]
<strong>Output:</strong> 15
<strong>Explanation:</strong> 
There are <strong>10</strong> squares of side 1.
There are <strong>4</strong> squares of side 2.
There is  <strong>1</strong> square of side 3.
Total number of squares = 10 + 4 + 1 = <strong>15</strong>.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
<strong>Output:</strong> 7
<strong>Explanation:</strong> 
There are <b>6</b> squares of side 1.  
There is <strong>1</strong> square of side 2. 
Total number of squares = 6 + 1 = <b>7</b>.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length&nbsp;&lt;= 300</code></li>
	<li><code>1 &lt;= arr[0].length&nbsp;&lt;= 300</code></li>
	<li><code>0 &lt;= arr[i][j] &lt;= 1</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int countSquares(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix.front().size();
    int answer = 0;
    vector<vector<int>> dp(rows, vector<int>(cols));

    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        if(!i || !j) {
          dp[i][j] = matrix[i][j];
        } else {
          if(matrix[i][j]) {
            dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
          }
        }
        answer += dp[i][j];
      }
    }
    return answer;
  }
};

// Accepted
// 32/32 cases passed (11 ms)
// Your runtime beats 28.49 % of cpp submissions
// Your memory usage beats 70.19 % of cpp submissions (30.2 MB)
```
