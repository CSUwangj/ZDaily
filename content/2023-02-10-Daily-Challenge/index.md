+++
updated = 2023-02-10T15:46:06+08:00
title = "2023-02-10 Daily Challenge"
path = "2023-02-10-Daily-Challenge"
date = 2023-02-10T15:46:06+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/as-far-from-land-as-possible/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 10

## Description

**As Far from Land as Possible**

<p>Given an <code>n x n</code> <code>grid</code>&nbsp;containing only values <code>0</code> and <code>1</code>, where&nbsp;<code>0</code> represents water&nbsp;and <code>1</code> represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance.&nbsp;If no land or water exists in the grid, return <code>-1</code>.</p>

<p>The distance used in this problem is the Manhattan distance:&nbsp;the distance between two cells <code>(x0, y0)</code> and <code>(x1, y1)</code> is <code>|x0 - x1| + |y0 - y1|</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/05/03/1336_ex1.JPG" style="width: 185px; height: 87px;" />
<pre>
<strong>Input:</strong> grid = [[1,0,1],[0,0,0],[1,0,1]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The cell (1, 1) is as far as possible from all the land with distance 2.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/05/03/1336_ex2.JPG" style="width: 184px; height: 87px;" />
<pre>
<strong>Input:</strong> grid = [[1,0,0],[0,0,0],[0,0,0]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The cell (2, 2) is as far as possible from all the land with distance 4.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= n&nbsp;&lt;= 100</code></li>
	<li><code>grid[i][j]</code>&nbsp;is <code>0</code> or <code>1</code></li>
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
  int length;
  int move[4][2] = {
    {-1,0}, 
    {0, 1},
    {1, 0},
    {0,-1}
  };
  bool isValid(int first, int second) {
    return first >= 0 && second >= 0 && first < length && second < length;
  }
  int bfs(vector<vector<int>>& grid, queue<tuple<int, int, int>>& q) {
    int ans = 0;
    while(q.size()) {
      auto [ x, y, cnt ] = q.front();
      // int x = get<0>(q.front());
      // int y = get<1>(q.front());
      // int cnt = get<2>(q.front());
      q.pop();
      if(cnt > ans) ans = cnt;
      for(int i = 0; i < 4; ++i) {
        if(isValid(x+move[i][0], y+move[i][1]) && !grid[x+move[i][0]][y+move[i][1]]) {
          q.push(make_tuple(x+move[i][0], y+move[i][1], cnt+1));
          grid[x+move[i][0]][y+move[i][1]] = 1;
        }
      }
    }
    return ans;
  }
public:
  int maxDistance(vector<vector<int>>& grid) {
    queue<tuple<int, int, int>> q;
    length = grid.size();
    for(int i = 0; i < length; i++) {
      for(int j = 0; j < length; j++) {
        if(grid[i][j] == 1) {
          q.push(make_tuple(i, j, 0));
        }
      }
    }
    if (q.size() == length * length || q.empty()) {
      return -1;
    }
    return bfs(grid, q);
  }
};

// Accepted
// 37/37 cases passed (77 ms)
// Your runtime beats 58.09 % of cpp submissions
// Your memory usage beats 43 % of cpp submissions (21.5 MB)
```
