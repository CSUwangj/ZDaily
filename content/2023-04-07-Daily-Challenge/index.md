+++
updated = 2023-04-07T14:44:18+08:00
title = "2023-04-07 Daily Challenge"
path = "2023-04-07-Daily-Challenge"
date = 2023-04-07T14:44:18+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/number-of-enclaves/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 7

## Description

**Number of Enclaves**

<p>You are given an <code>m x n</code> binary matrix <code>grid</code>, where <code>0</code> represents a sea cell and <code>1</code> represents a land cell.</p>

<p>A <strong>move</strong> consists of walking from one land cell to another adjacent (<strong>4-directionally</strong>) land cell or walking off the boundary of the <code>grid</code>.</p>

<p>Return <em>the number of land cells in</em> <code>grid</code> <em>for which we cannot walk off the boundary of the grid in any number of <strong>moves</strong></em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/18/enclaves1.jpg" style="width: 333px; height: 333px;" />
<pre>
<strong>Input:</strong> grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/18/enclaves2.jpg" style="width: 333px; height: 333px;" />
<pre>
<strong>Input:</strong> grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
<strong>Output:</strong> 0
<strong>Explanation:</strong> All 1s are either on the boundary or can reach the boundary.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 500</code></li>
	<li><code>grid[i][j]</code> is either <code>0</code> or <code>1</code>.</li>
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
  const int MOVES[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
  int numEnclaves(vector<vector<int>>& grid) {
    queue<pair<int, int>> q;
    int rows = grid.size();
    int cols = grid.front().size();
    vector<vector<bool>> visit(rows, vector<bool>(cols));

    int answer = 0;
    for(int r = 0; r < rows; ++r) {
      for(int c = 0; c < cols; ++c) {
        if(!grid[r][c] || visit[r][c]) {
          visit[r][c] = true;
          continue;
        }
        q.push({r, c});
        visit[r][c] = true;
        bool border = false;
        int count = 0;
        while(q.size()) {
          auto [row, col] = q.front();
          q.pop();
          count += 1;
          if(!row || !col || row == rows - 1 || col == cols - 1) {
            border = true;
          }
          for(int m = 0; m < 4; ++m) {
            int newRow = row + MOVES[m][0];
            int newCol = col + MOVES[m][1];
            if(newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols) continue;
            if(!grid[newRow][newCol] || visit[newRow][newCol]) continue;
            visit[newRow][newCol] = true;
            q.push({newRow, newCol});
          }
        }
        if(!border) {
          answer += count;
        }
      }
    }

    return answer;
  }
};

// Accepted
// 58/58 cases passed (84 ms)
// Your runtime beats 39.64 % of cpp submissions
// Your memory usage beats 91.97 % of cpp submissions (27.2 MB)
```
