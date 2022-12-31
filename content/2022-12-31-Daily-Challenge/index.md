+++
updated = 2022-12-31T11:01:13+08:00
title = "2022-12-31 Daily Challenge"
path = "2022-12-31-Daily-Challenge"
date = 2022-12-31T11:01:13+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/unique-paths-iii/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 31

## Description

**Unique Paths III**

<p>You are given an <code>m x n</code> integer array <code>grid</code> where <code>grid[i][j]</code> could be:</p>

<ul>
	<li><code>1</code> representing the starting square. There is exactly one starting square.</li>
	<li><code>2</code> representing the ending square. There is exactly one ending square.</li>
	<li><code>0</code> representing empty squares we can walk over.</li>
	<li><code>-1</code> representing obstacles that we cannot walk over.</li>
</ul>

<p>Return <em>the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/02/lc-unique1.jpg" style="width: 324px; height: 245px;" />
<pre>
<strong>Input:</strong> grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/02/lc-unique2.jpg" style="width: 324px; height: 245px;" />
<pre>
<strong>Input:</strong> grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/02/lc-unique3-.jpg" style="width: 164px; height: 165px;" />
<pre>
<strong>Input:</strong> grid = [[0,1],[2,0]]
<strong>Output:</strong> 0
<strong>Explanation:</strong> There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 20</code></li>
	<li><code>1 &lt;= m * n &lt;= 20</code></li>
	<li><code>-1 &lt;= grid[i][j] &lt;= 2</code></li>
	<li>There is exactly one starting cell and one ending cell.</li>
</ul>


## Solution

``` cpp
const char moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
  char rows;
  char cols;
  char start;
  char finish;
  char obstacles;
  char target;
  char answer;
  unordered_set<string> cache;
  vector<bool> visit;
  string path;
  void init(vector<vector<int>> &grid) {
    rows = grid.size();
    cols = grid.front().size();
    for(int i = 0; i < rows; ++i) {
      for(char j = 0; j < cols; ++j) {
        switch(grid[i][j]) {
          case 1:
            start = i * cols + j;
            break;
          case 2:
            finish = i * cols + j;
            break;
          case -1:
            obstacles += 1;
          default:
            ;
        }
      }
    }
    target = rows * cols - obstacles;
  }
  bool checkConnection(vector<vector<int>>& grid) {
    queue<pair<char, char>> q;
    bool vis[rows][cols];
    memset(vis, 0, sizeof(vis));
    vis[start / cols][start % cols] = true;
    q.push({start / cols, start % cols});

    while(q.size()) {
      auto [row, col] = q.front();
      if(row * cols + col == finish) return true;
      q.pop();
      for(char i = 0 ; i < 4; ++i) {
        char newRow = row + moves[i][0];
        char newCol = col + moves[i][1];
        if(newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols) continue;
        if(vis[newRow][newCol] || grid[newRow][newCol] == -1) continue;
        vis[newRow][newCol] = true;
        q.push({newRow, newCol});
      }
    }
    return false;
  }
  void solve(vector<vector<int>>& grid) {
    if(cache.count(path)) return;
    cache.insert(path);
    // cout << ToHex(path) << endl;

    char row = path.back() / cols;
    char col = path.back() % cols;
    if(path.back() == finish) {
      answer += path.length() == target;
      return;
    }

    for(char i = 0; i < 4; ++i) {
      char newRow = row + moves[i][0];
      char newCol = col + moves[i][1];
      if(newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols) continue;
      if(visit[newRow * cols + newCol] || grid[newRow][newCol] == -1) continue;
      visit[newRow * cols + newCol] = true;
      path.push_back(newRow * cols + newCol);
      solve(grid);
      path.pop_back();
      visit[newRow * cols + newCol] = false;
    }
  }
public:
  int uniquePathsIII(vector<vector<int>>& grid) {

    init(grid);
    if(!checkConnection(grid)) {
      return 0;
    }

    unordered_set<string> cache;
    visit.resize(rows * cols);
    path.push_back(start);
    visit[start] = true;
    solve(grid);

    return answer;
  }
};

// Accepted
// 39/39 cases passed (8 ms)
// Your runtime beats 32.66 % of cpp submissions
// Your memory usage beats 22.59 % of cpp submissions (10 MB)
```
