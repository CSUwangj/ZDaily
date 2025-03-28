+++
updated = 2025-03-28T11:45:57+08:00
title = "2025-03-28 Daily Challenge"
path = "2025-03-28-Daily-Challenge"
date = 2025-03-28T11:45:57+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 28

## Description

**Maximum Number of Points From Grid Queries**

<p>You are given an <code>m x n</code> integer matrix <code>grid</code> and an array <code>queries</code> of size <code>k</code>.</p>

<p>Find an array <code>answer</code> of size <code>k</code> such that for each integer <code>queries[i]</code> you start in the <strong>top left</strong> cell of the matrix and repeat the following process:</p>

<ul>
	<li>If <code>queries[i]</code> is <strong>strictly</strong> greater than the value of the current cell that you are in, then you get one point if it is your first time visiting this cell, and you can move to any <strong>adjacent</strong> cell in all <code>4</code> directions: up, down, left, and right.</li>
	<li>Otherwise, you do not get any points, and you end this process.</li>
</ul>

<p>After the process, <code>answer[i]</code> is the <strong>maximum</strong> number of points you can get. <strong>Note</strong> that for each query you are allowed to visit the same cell <strong>multiple</strong> times.</p>

<p>Return <em>the resulting array</em> <code>answer</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2025/03/15/image1.png" style="width: 571px; height: 152px;" />
<pre>
<strong>Input:</strong> grid = [[1,2,3],[2,5,7],[3,5,1]], queries = [5,6,2]
<strong>Output:</strong> [5,8,1]
<strong>Explanation:</strong> The diagrams above show which cells we visit to get points for each query.</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/10/20/yetgriddrawio-2.png" />
<pre>
<strong>Input:</strong> grid = [[5,2,1],[1,1,2]], queries = [3]
<strong>Output:</strong> [0]
<strong>Explanation:</strong> We can not get any points because the value of the top left cell is already greater than or equal to 3.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>2 &lt;= m, n &lt;= 1000</code></li>
	<li><code>4 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>k == queries.length</code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= grid[i][j], queries[i] &lt;= 10<sup>6</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
  const int MOVES[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  using pi = pair<int, int>;
  using pii = pair<int, pi>;
public:
  vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
    int len = queries.size();
    int rows = grid.size();
    int cols = grid.front().size();
    vector<int> indice(len);
    iota(indice.begin(), indice.end(), 0);
    sort(indice.begin(), indice.end(), [&](int a, int b){ return queries[a] < queries[b]; });

    priority_queue<pii, vector<pii>, greater<pii>> candidates;
    int current = 0;
    vector<int> answer(len);
    vector<vector<bool>> added(rows, vector<bool>(cols));
    candidates.push({grid[0][0], {0, 0}});
    added[0][0] = true;
    for(auto index : indice) {
      int q = queries[index];
      
      while(candidates.size() && q > candidates.top().first) {
        auto [val, coordinates] = candidates.top();
        candidates.pop();
        auto [row, col] = coordinates;
        current += 1;

        for(int m = 0; m < 4; ++m) {
          int newRow = row + MOVES[m][0];
          int newCol = col + MOVES[m][1];
          if(newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols) continue;
          if(added[newRow][newCol]) continue;

          added[newRow][newCol] = true;
          candidates.push({grid[newRow][newCol], {newRow, newCol}});
        }
      }

      answer[index] = current;
    }

    return answer;
  }
};

// Accepted
// 21/21 cases passed (91 ms)
// Your runtime beats 75.36 % of cpp submissions
// Your memory usage beats 94.2 % of cpp submissions (39 MB)
```
