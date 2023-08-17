+++
updated = 2023-08-17T09:24:43+08:00
title = "2023-08-17 Daily Challenge"
path = "2023-08-17-Daily-Challenge"
date = 2023-08-17T09:24:43+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/01-matrix/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 17

## Description

**01 Matrix**

<p>Given an <code>m x n</code> binary matrix <code>mat</code>, return <em>the distance of the nearest </em><code>0</code><em> for each cell</em>.</p>

<p>The distance between two adjacent cells is <code>1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/24/01-1-grid.jpg" style="width: 253px; height: 253px;" />
<pre>
<strong>Input:</strong> mat = [[0,0,0],[0,1,0],[0,0,0]]
<strong>Output:</strong> [[0,0,0],[0,1,0],[0,0,0]]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/24/01-2-grid.jpg" style="width: 253px; height: 253px;" />
<pre>
<strong>Input:</strong> mat = [[0,0,0],[0,1,0],[1,1,1]]
<strong>Output:</strong> [[0,0,0],[0,1,0],[1,2,1]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>4</sup></code></li>
	<li><code>mat[i][j]</code> is either <code>0</code> or <code>1</code>.</li>
	<li>There is at least one <code>0</code> in <code>mat</code>.</li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat.front().size();
    vector<vector<bool>> vis(rows, vector<bool>(cols));
    queue<pair<int, int>> q;
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        if(!mat[i][j]) {
          vis[i][j] = true;
          q.push({i, j});
        }
      }
    }
    int cnt = 1;
    while(q.size()) {
      int sz = q.size();
      for(int _ = 0; _ < sz; ++_) {
        auto [row, col] = q.front();
        q.pop();
        for(int i = 0; i < 4; ++i) {
          int newRow = row + moves[i][0];
          int newCol = col + moves[i][1];
          if(newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols) continue;
          if(vis[newRow][newCol]) continue;
          // cout << newRow << ' ' << newCol << ' ' << cnt << endl;
          vis[newRow][newCol] = true;
          mat[newRow][newCol] = cnt;
          q.push({newRow, newCol});
        }
      }
      cnt += 1;
    }
    return mat;
  }
};

// Accepted
// 50/50 cases passed (61 ms)
// Your runtime beats 92.14 % of cpp submissions
// Your memory usage beats 68.82 % of cpp submissions (32.1 MB)
```
