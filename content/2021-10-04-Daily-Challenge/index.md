+++
title = "2021-10-04 Daily-Challenge"
path = "2021-10-04-Daily-Challenge"
date = 2021-10-04 19:04:33+08:00
updated = 2021-10-04 19:14:28+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/island-perimeter/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 4

## Description

**Island Perimeter**

You are given `row x col` `grid` representing a map where `grid[i][j] = 1` represents land and `grid[i][j] = 0` represents water.

Grid cells are connected **horizontally/vertically** (not diagonally). The `grid` is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2018/10/12/island.png)

```
Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.
```

**Example 2:**

```
Input: grid = [[1]]
Output: 4
```

**Example 3:**

```
Input: grid = [[1,0]]
Output: 4
```

 

**Constraints:**

- `row == grid.length`
- `col == grid[i].length`
- `1 <= row, col <= 100`
- `grid[i][j]` is `0` or `1`.
- There is exactly one island in `grid`.

## Solution

``` cpp
// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int islandPerimeter(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid.front().size();

    int answer = 0;

    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        if(j != cols - 1 && grid[i][j] != grid[i][j + 1]) {
          answer += 1;
        }
        if(i != rows - 1 && grid[i][j] != grid[i + 1][j]) {
          answer += 1;
        }
      }
    }
    for(int i = 0; i < rows; ++i) {
      answer += grid[i][0];
      answer += grid[i][cols - 1];
    }
    for(int i = 0; i < cols; ++i) {
      answer += grid[0][i];
      answer += grid[rows - 1][i];
    }

    return answer;
  }
};

// Accepted
// 5833/5833 cases passed (119 ms)
// Your runtime beats 38.48 % of cpp submissions
// Your memory usage beats 58.06 % of cpp submissions (96.2 MB)
```
