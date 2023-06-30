+++
updated = 2023-06-30T20:20:51+08:00
title = "2023-06-30 Daily Challenge"
path = "2023-06-30-Daily-Challenge"
date = 2023-06-30T20:20:51+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/last-day-where-you-can-still-cross/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 30

## Description

**Last Day Where You Can Still Cross**

<p>There is a <strong>1-based</strong> binary matrix where <code>0</code> represents land and <code>1</code> represents water. You are given integers <code>row</code> and <code>col</code> representing the number of rows and columns in the matrix, respectively.</p>

<p>Initially on day <code>0</code>, the <strong>entire</strong> matrix is <strong>land</strong>. However, each day a new cell becomes flooded with <strong>water</strong>. You are given a <strong>1-based</strong> 2D array <code>cells</code>, where <code>cells[i] = [r<sub>i</sub>, c<sub>i</sub>]</code> represents that on the <code>i<sup>th</sup></code> day, the cell on the <code>r<sub>i</sub><sup>th</sup></code> row and <code>c<sub>i</sub><sup>th</sup></code> column (<strong>1-based</strong> coordinates) will be covered with <strong>water</strong> (i.e., changed to <code>1</code>).</p>

<p>You want to find the <strong>last</strong> day that it is possible to walk from the <strong>top</strong> to the <strong>bottom</strong> by only walking on land cells. You can start from <strong>any</strong> cell in the top row and end at <strong>any</strong> cell in the bottom row. You can only travel in the<strong> four</strong> cardinal directions (left, right, up, and down).</p>

<p>Return <em>the <strong>last</strong> day where it is possible to walk from the <strong>top</strong> to the <strong>bottom</strong> by only walking on land cells</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/27/1.png" style="width: 624px; height: 162px;" />
<pre>
<strong>Input:</strong> row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 2.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/27/2.png" style="width: 504px; height: 178px;" />
<pre>
<strong>Input:</strong> row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 1.
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/27/3.png" style="width: 666px; height: 167px;" />
<pre>
<strong>Input:</strong> row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 3.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= row, col &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>4 &lt;= row * col &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>cells.length == row * col</code></li>
	<li><code>1 &lt;= r<sub>i</sub> &lt;= row</code></li>
	<li><code>1 &lt;= c<sub>i</sub> &lt;= col</code></li>
	<li>All the values of <code>cells</code> are <strong>unique</strong>.</li>
</ul>


## Solution

``` cpp
struct UnionSet {
  vector<int> parent;
public:
  UnionSet(int size): parent(size) {
    for(int i = 0; i < size; ++i) {
      parent[i] = i;
    }
  }

  int find(int x) {
    if(parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
  }

  void merge(int x, int y) {
    x = find(x);
    y = find(y);
    parent[x] = y;
  }
};
const int MOVES[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
public:
  int latestDayToCross(int rows, int cols, vector<vector<int>>& cells) {
    UnionSet us(rows * cols + 2);
    vector<vector<bool>> land(rows, vector<bool>(cols, false));
    int top = 0;
    int bottom = rows * cols + 1;
    for(int i = cells.size() - 1; i >= 0; --i) {
      if(us.find(top) == us.find(bottom)) return i + 1;
      int row = cells[i][0] - 1;
      int col = cells[i][1] - 1;
      int position = row * cols + col + 1;
      if(row == 0) us.merge(top, position);
      if(row == rows - 1) us.merge(bottom, position);
      land[row][col] = true;
      for(int m = 0; m < 4; ++m) {
        int newRow = row + MOVES[m][0];
        int newCol = col + MOVES[m][1];
        if(newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols) continue;
        if(!land[newRow][newCol]) continue;
        us.merge(position, newRow * cols + newCol + 1);
      }
    }
    return 0;
  }
};

// Accepted
// 118/118 cases passed (366 ms)
// Your runtime beats 81.08 % of cpp submissions
// Your memory usage beats 85.13 % of cpp submissions (106.1 MB)
```
