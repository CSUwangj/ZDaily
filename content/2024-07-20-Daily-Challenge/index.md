+++
updated = 2024-07-20T23:56:47+08:00
title = "2024-07-20 Daily Challenge"
path = "2024-07-20-Daily-Challenge"
date = 2024-07-20T23:56:47+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 20

## Description

**Find Valid Matrix Given Row and Column Sums**

<p>You are given two arrays <code>rowSum</code> and <code>colSum</code> of non-negative integers where <code>rowSum[i]</code> is the sum of the elements in the <code>i<sup>th</sup></code> row and <code>colSum[j]</code> is the sum of the elements of the <code>j<sup>th</sup></code> column of a 2D matrix. In other words, you do not know the elements of the matrix, but you do know the sums of each row and column.</p>

<p>Find any matrix of <strong>non-negative</strong> integers of size <code>rowSum.length x colSum.length</code> that satisfies the <code>rowSum</code> and <code>colSum</code> requirements.</p>

<p>Return <em>a 2D array representing <strong>any</strong> matrix that fulfills the requirements</em>. It&#39;s guaranteed that <strong>at least one </strong>matrix that fulfills the requirements exists.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> rowSum = [3,8], colSum = [4,7]
<strong>Output:</strong> [[3,0],
         [1,7]]
<strong>Explanation:</strong> 
0<sup>th</sup> row: 3 + 0 = 3 == rowSum[0]
1<sup>st</sup> row: 1 + 7 = 8 == rowSum[1]
0<sup>th</sup> column: 3 + 1 = 4 == colSum[0]
1<sup>st</sup> column: 0 + 7 = 7 == colSum[1]
The row and column sums match, and all matrix elements are non-negative.
Another possible matrix is: [[1,2],
                             [3,5]]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> rowSum = [5,7,10], colSum = [8,6,8]
<strong>Output:</strong> [[0,5,0],
         [6,1,0],
         [2,0,8]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= rowSum.length, colSum.length &lt;= 500</code></li>
	<li><code>0 &lt;= rowSum[i], colSum[i] &lt;= 10<sup>8</sup></code></li>
	<li><code>sum(rowSum) == sum(colSum)</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
    int rows = rowSum.size();
    int cols = colSum.size();
    int curRow = 0;
    int curCol = 0;
    vector<vector<int>> answer(rows, vector<int>(cols, 0));

    while(curRow < rows || curCol < cols) {
      if(curRow >= rows) {
        answer[rows  - 1][curCol] = colSum[curCol];
        curCol += 1;
        continue;
      } else if(curCol >= cols) {
        answer[curRow][cols - 1] = rowSum[curRow];
        curRow += 1;
        continue;
      }

      int value = min(rowSum[curRow], colSum[curCol]);
      rowSum[curRow] -= value;
      colSum[curCol] -= value;
      answer[curRow][curCol] = value;

      if(!rowSum[curRow]) {
        curRow += 1;
      }
      if(!colSum[curCol]) {
        curCol += 1;
      }
    }

    return answer;
  }
};
```
