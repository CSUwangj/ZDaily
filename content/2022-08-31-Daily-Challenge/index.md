+++
updated = 2022-08-31 18:14:00+08:00
title = "2022-08-31 Daily-Challenge"
path = "2022-08-31-Daily-Challenge"
date = 2022-08-31 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/pacific-atlantic-water-flow/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 31

## Description

**Pacific Atlantic Water Flow**

There is an `m x n` rectangular island that borders both the **Pacific Ocean** and **Atlantic Ocean**. The **Pacific Ocean** touches the island's left and top edges, and the **Atlantic Ocean** touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an `m x n` integer matrix `heights` where `heights[r][c]` represents the **height above sea level** of the cell at coordinate `(r, c)`.

The island receives a lot of rain, and the rain water can flow to  neighboring cells directly north, south, east, and west if the  neighboring cell's height is **less than or equal to** the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return *a **2D list** of grid coordinates* `result` *where* `result[i] = [ri, ci]` *denotes that rain water can flow from cell* `(ri, ci)` *to **both** the Pacific and Atlantic oceans*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/06/08/waterflow-grid.jpg)

```
Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
[0,4]: [0,4] -> Pacific Ocean 
       [0,4] -> Atlantic Ocean
[1,3]: [1,3] -> [0,3] -> Pacific Ocean 
       [1,3] -> [1,4] -> Atlantic Ocean
[1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean 
       [1,4] -> Atlantic Ocean
[2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean 
       [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
[3,0]: [3,0] -> Pacific Ocean 
       [3,0] -> [4,0] -> Atlantic Ocean
[3,1]: [3,1] -> [3,0] -> Pacific Ocean 
       [3,1] -> [4,1] -> Atlantic Ocean
[4,0]: [4,0] -> Pacific Ocean 
       [4,0] -> Atlantic Ocean
Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.
```

**Example 2:**

```
Input: heights = [[1]]
Output: [[0,0]]
Explanation: The water can flow from the only cell to the Pacific and Atlantic oceans.
```

 

**Constraints:**

- `m == heights.length`
- `n == heights[r].length`
- `1 <= m, n <= 200`
- `0 <= heights[r][c] <= 10^5`

## Solution

``` cpp
const int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

class Solution {
  int rows;
  int cols;
  void dfs(vector<vector<int>>& heights, vector<vector<bool>>& vis, int row, int col) {
    if(vis[row][col]) return;
    vis[row][col] = true;
    for(int i = 0; i < 4; ++i) {
      int newRow = row + moves[i][0];
      int newCol = col + moves[i][1];
      if(newRow >= rows || newRow < 0 || newCol >= cols || newCol < 0) continue;
      if(heights[row][col] > heights[newRow][newCol]) continue;
      dfs(heights, vis, newRow, newCol);
    }
  }
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    vector<vector<int>> answer;
    if(heights.empty() || heights.front().empty()) return answer;
    rows = heights.size();
    cols = heights.front().size();
    vector<vector<bool>> visPac(rows, vector<bool>(cols));
    vector<vector<bool>> visAtl(rows, vector<bool>(cols));
    
    for(int i = 0; i < cols; ++i) {
      dfs(heights, visPac, 0, i);
      dfs(heights, visAtl, rows - 1, i);
    }
    for(int i = 0; i < rows; ++i) {
      dfs(heights, visPac, i, 0);
      dfs(heights, visAtl, i, cols - 1);
    }
    
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        if(visPac[i][j] && visAtl[i][j]) answer.push_back({i, j});
      }
    }
    
    return answer;
  }
};

// Accepted
// 113/113 cases passed (54 ms)
// Your runtime beats 79.37 % of cpp submissions
// Your memory usage beats 77.12 % of cpp submissions (17.5 MB)
```
