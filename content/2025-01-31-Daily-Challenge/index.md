+++
updated = 2025-01-31T16:07:20+08:00
title = "2025-01-31 Daily Challenge"
path = "2025-01-31-Daily-Challenge"
date = 2025-01-31T16:07:20+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/making-a-large-island/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 31

## Description

**Making A Large Island**

<p>You are given an <code>n x n</code> binary matrix <code>grid</code>. You are allowed to change <strong>at most one</strong> <code>0</code> to be <code>1</code>.</p>

<p>Return <em>the size of the largest <strong>island</strong> in</em> <code>grid</code> <em>after applying this operation</em>.</p>

<p>An <strong>island</strong> is a 4-directionally connected group of <code>1</code>s.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> grid = [[1,0],[0,1]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> grid = [[1,1],[1,0]]
<strong>Output:</strong> 4
<strong>Explanation: </strong>Change the 0 to 1 and make the island bigger, only one island with area = 4.</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> grid = [[1,1],[1,1]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> Can&#39;t change any 0 to 1, only one island with area = 4.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 500</code></li>
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
const int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int part[500][500];
bool vis[500][500];
class Solution {
  int n;
  vector<int> lands;
  void travelIsland(
    vector<vector<int>> &grid,
    int row,
    int col,
    int id
  ) {
    vis[row][col] = true;
    lands[id] += 1;
    part[row][col] = id;
    for(int i = 0; i < 4; ++i) {
      int newRow = row + moves[i][0];
      int newCol = col + moves[i][1];
      if(newRow < 0 || newCol < 0 || newRow >= n || newCol >= n) continue;
      if(vis[newRow][newCol]) continue;
      if(!grid[newRow][newCol]) continue;
      travelIsland(grid, newRow, newCol, id);
    }
  }
public:
  int largestIsland(vector<vector<int>>& grid) {
    n = grid.size();
    memset(vis, 0, sizeof(vis));
    memset(part, -1, sizeof(part));
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        if(!vis[i][j] && grid[i][j]) {
          lands.push_back(0);
          travelIsland(grid, i, j, cnt);
          cnt += 1;
        }
      }
    }
    if(!lands.size()) return 1;
    if(lands.size() == 1) return min(n * n, lands[0] + 1);

    int answer = 0;
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        if(grid[i][j]) continue;
        unordered_set<int> neighbors;
        int result = 1;
        for(int k = 0; k < 4; ++k) {
          int newRow = i + moves[k][0];
          int newCol = j + moves[k][1];
          if(newRow < 0 || newCol < 0 || newRow >= n || newCol >= n) continue;
          if(!grid[newRow][newCol]) continue;
          if(neighbors.count(part[newRow][newCol])) continue;
          result += lands[part[newRow][newCol]];
          neighbors.insert(part[newRow][newCol]);
        }
        answer = max(answer, result);
      }
    }

    return answer;
  }
};

// Accepted
// 75/75 cases passed (392 ms)
// Your runtime beats 91.75 % of cpp submissions
// Your memory usage beats 77.94 % of cpp submissions (143.7 MB)
```
