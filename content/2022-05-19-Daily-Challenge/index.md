+++
updated = 2022-05-19 18:14:00+08:00
title = "2022-05-19 Daily-Challenge"
path = "2022-05-19-Daily-Challenge"
date = 2022-05-19 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 19

## Description

**Longest Increasing Path in a Matrix**

Given an `m x n` integers `matrix`, return *the length of the longest increasing path in* `matrix`.

From each cell, you can either move in four directions: left, right, up, or down. You **may not** move **diagonally** or move **outside the boundary** (i.e., wrap-around is not allowed).

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/01/05/grid1.jpg)

```
Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/01/27/tmp-grid.jpg)

```
Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
```

**Example 3:**

```
Input: matrix = [[1]]
Output: 1
```

 

**Constraints:**

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 200`
- <code>0 &lt;= matrix[i][j] &lt;= 2<sup>31</sup> - 1</code>

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
const int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
  int rows;
  int cols;
  bool check(vector<vector<int>>& matrix, int row, int col) {
    int ok = 0;
    for(int i = 0; i < 4; ++i) {
      int newRow = row + moves[i][0];
      int newCol = col + moves[i][1];
      if(newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols ||
         matrix[row][col] <= matrix[newRow][newCol]) {
        ok += 1;
      }
    }
    // cout << row << ' ' << col << ' ' << ok << endl;
    return ok == 4;
  }
  void dfs(vector<vector<int>>& matrix,
           vector<vector<int>> &LIP,
           int row,
           int col,
           int cur
  ) {
    if(cur <= LIP[row][col]) return;
    LIP[row][col] = cur;
    for(int i = 0; i < 4; ++i) {
      int newRow = row + moves[i][0];
      int newCol = col + moves[i][1];
      if(newRow >= rows || newRow < 0 || newCol >= cols || newCol < 0) continue;
      if(matrix[row][col] >= matrix[newRow][newCol]) continue;
      dfs(matrix, LIP, newRow, newCol, cur + 1);
    }
  }
public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    rows = matrix.size();
    cols = matrix.front().size();
    vector<vector<int>> LIP(rows, vector<int>(cols));
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        if(check(matrix, i, j)) dfs(matrix, LIP, i, j, 1);
      }
    }
    int answer = 0;
    for(auto &row : LIP) {
      for(auto n : row) {
        // cout << n << ' ' ;
        answer = max(answer, n);
      }
      // cout << endl;
    }
    return answer;
  }
};

// Accepted
// 138/138 cases passed (185 ms)
// Your runtime beats 16.48 % of cpp submissions
// Your memory usage beats 41.9 % of cpp submissions (16.3 MB)
```
