+++
updated = 2025-01-19T21:40:09+08:00
title = "2025-01-19 Daily Challenge"
path = "2025-01-19-Daily-Challenge"
date = 2025-01-19T21:40:09+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/trapping-rain-water-ii/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 19

## Description

**Trapping Rain Water II**

<p>Given an <code>m x n</code> integer matrix <code>heightMap</code> representing the height of each unit cell in a 2D elevation map, return <em>the volume of water it can trap after raining</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/08/trap1-3d.jpg" style="width: 361px; height: 321px;" />
<pre>
<strong>Input:</strong> heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> After the rain, water is trapped between the blocks.
We have two small ponds 1 and 3 units trapped.
The total volume of water trapped is 4.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/08/trap2-3d.jpg" style="width: 401px; height: 321px;" />
<pre>
<strong>Input:</strong> heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
<strong>Output:</strong> 10
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == heightMap.length</code></li>
	<li><code>n == heightMap[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>0 &lt;= heightMap[i][j] &lt;= 2 * 10<sup>4</sup></code></li>
</ul>


## Solution

``` cpp
const int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
  int rows;
  int cols;
  int answer = 0;
  using pi_heap = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
  void dfs(
    vector<vector<bool>> &visited,
    pi_heap &pq,
    vector<vector<int>>& heightMap,
    int row,
    int col,
    int height
  ) {
    // cout << row << ' ' << col << ' ' << height << endl;
    answer += height - heightMap[row][col];
    heightMap[row][col] = height;
    visited[row][col] = true;
    for(int i = 0; i < 4; ++i) {
      int newRow = row + moves[i][0];
      int newCol = col + moves[i][1];
      if(newRow < 0 || newRow >= rows || newCol >= cols || newCol < 0) continue;
      if(visited[newRow][newCol]) continue;
      if(heightMap[newRow][newCol] < height) {
        dfs(visited, pq, heightMap, newRow, newCol, height);
      } else {
        pq.push({heightMap[newRow][newCol], newRow * cols + newCol});
      }
    }
  }
public:
  int trapRainWater(vector<vector<int>>& heightMap) {
    rows = heightMap.size();
    cols = heightMap.front().size();
    vector<vector<bool>> visited(rows, vector<bool>(cols));
    pi_heap pq;
    for(int i = 0; i < rows; ++i) {
      pq.push({heightMap[i][0], i * cols});
      pq.push({heightMap[i][cols - 1], i * cols + cols - 1});
    }
    for(int j = 0; j < cols; ++j) {
      pq.push({heightMap[0][j], j});
      pq.push({heightMap[rows - 1][j], (rows - 1) * cols + j});

    }
    while(pq.size()) {
      auto [height, position] = pq.top();
      pq.pop();
      dfs(visited, pq, heightMap, position / cols, position % cols, height);
    }
    return answer;
  }
};

// Accepted
// 42/42 cases passed (109 ms)
// Your runtime beats 25.9 % of cpp submissions
// Your memory usage beats 35.12 % of cpp submissions (25.3 MB)
```
