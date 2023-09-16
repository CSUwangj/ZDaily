+++
updated = 2023-09-16T02:25:58+08:00
title = "2023-09-16 Daily Challenge"
path = "2023-09-16-Daily-Challenge"
date = 2023-09-16T02:25:58+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/path-with-minimum-effort/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 16

## Description

**Path With Minimum Effort**

<p>You are a hiker preparing for an upcoming hike. You are given <code>heights</code>, a 2D array of size <code>rows x columns</code>, where <code>heights[row][col]</code> represents the height of cell <code>(row, col)</code>. You are situated in the top-left cell, <code>(0, 0)</code>, and you hope to travel to the bottom-right cell, <code>(rows-1, columns-1)</code> (i.e.,&nbsp;<strong>0-indexed</strong>). You can move <strong>up</strong>, <strong>down</strong>, <strong>left</strong>, or <strong>right</strong>, and you wish to find a route that requires the minimum <strong>effort</strong>.</p>

<p>A route&#39;s <strong>effort</strong> is the <strong>maximum absolute difference</strong><strong> </strong>in heights between two consecutive cells of the route.</p>

<p>Return <em>the minimum <strong>effort</strong> required to travel from the top-left cell to the bottom-right cell.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/10/04/ex1.png" style="width: 300px; height: 300px;" /></p>

<pre>
<strong>Input:</strong> heights = [[1,2,2],[3,8,2],[5,3,5]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
</pre>

<p><strong class="example">Example 2:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/10/04/ex2.png" style="width: 300px; height: 300px;" /></p>

<pre>
<strong>Input:</strong> heights = [[1,2,3],[3,8,4],[5,3,5]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/04/ex3.png" style="width: 300px; height: 300px;" />
<pre>
<strong>Input:</strong> heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
<strong>Output:</strong> 0
<strong>Explanation:</strong> This route does not require any effort.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>rows == heights.length</code></li>
	<li><code>columns == heights[i].length</code></li>
	<li><code>1 &lt;= rows, columns &lt;= 100</code></li>
	<li><code>1 &lt;= heights[i][j] &lt;= 10<sup>6</sup></code></li>
</ul>

## Solution

``` cpp
auto speedup = []() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();

using pi = pair<int, int>;
bool vis[100][100];
class Solution {
  int rows;
  int cols;
  int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  bool verify(vector<vector<int>>& heights, int effort) {
    memset(vis, 0, sizeof(vis));
    queue<pi> q;
    q.push({0, 0});
    vis[0][0] = true;
    while(q.size()) {
      auto [row, col] = q.front();
      q.pop();
      if(row == rows - 1 && col == cols - 1) return true;
      for(int i = 0; i < 4; ++i) {
        int newRow = row + moves[i][0];
        int newCol = col + moves[i][1];
        if(newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols) continue;
        if(vis[newRow][newCol]) continue;
        if(abs(heights[newRow][newCol] - heights[row][col]) > effort) continue;
        vis[newRow][newCol] = true;
        q.push({newRow, newCol});
      }
    }
    return false;
  }
public:
  int minimumEffortPath(vector<vector<int>>& heights) {
    rows = heights.size();
    cols = heights.front().size();
    int mmin = INT_MAX;
    int mmax = INT_MIN;
    for(auto &row :heights) {
      mmin = min(mmin, *min_element(row.begin(), row.end()));
      mmax = max(mmax, *max_element(row.begin(), row.end()));
    }
    int low = 0;
    int high = mmax - mmin;
    while(low < high) {
      int mid = (low + high) >> 1;
      if(!verify(heights, mid)) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return low;
  }
};

// Accepted
// 75/75 cases passed (294 ms)
// Your runtime beats 56.19 % of cpp submissions
// Your memory usage beats 43.06 % of cpp submissions (39.2 MB)
```
