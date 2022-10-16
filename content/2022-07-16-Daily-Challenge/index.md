+++
updated = 2022-07-16 18:14:00+08:00
title = "2022-07-16 Daily-Challenge"
path = "2022-07-16-Daily-Challenge"
date = 2022-07-16 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/next-greater-element-iii/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 16

## Description

**Out of Boundary Paths**

There is an `m x n` grid with a ball. The ball is initially at the position `[startRow, startColumn]`. You are allowed to move the ball to one of the four adjacent cells in  the grid (possibly out of the grid crossing the grid boundary). You can  apply **at most** `maxMove` moves to the ball.

Given the five integers `m`, `n`, `maxMove`, `startRow`, `startColumn`, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it **modulo** `109 + 7`.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/04/28/out_of_boundary_paths_1.png)

```
Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
Output: 6
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/04/28/out_of_boundary_paths_2.png)

```
Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
Output: 12
```

 

**Constraints:**

- `1 <= m, n <= 50`
- `0 <= maxMove <= 50`
- `0 <= startRow < m`
- `0 <= startColumn < n`

## Solution

``` cpp
const int SZ = 50;
const int MOD = 1e9 + 7;
int path[2][SZ][SZ];
const int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
public:
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    memset(path[0], 0, sizeof(path[0]));
    path[0][startRow][startColumn] = 1;
    int result = 0;
    for(int cnt = 0; cnt < maxMove; cnt++) {
      int parity = cnt & 1;
      memset(path[!parity], 0, sizeof(path[0]));
      for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
          // cout << path[parity][i][j] << ' ' ;
          for(int c = 0; c < 4; ++c) {
            int newRow = i + moves[c][0];
            int newCol = j + moves[c][1];
            if(newRow < 0 || newCol < 0 || newRow >= m || newCol >= n) continue;
            path[!parity][newRow][newCol] += path[parity][i][j];
            path[!parity][newRow][newCol] %= MOD;
          }
        }
        // cout << endl;
      }
      // cout << endl;
      for(int i = 0; i < m; ++i) {
        result += path[parity][i][0];
        result %= MOD;
        result += path[parity][i][n - 1];
        result %= MOD;
      }
      for(int i = 0; i < n; ++i) {
        result += path[parity][0][i];
        result %= MOD;
        result += path[parity][m - 1][i];
        result %= MOD;
      }
    }
    return result;
  }
};

// Accepted
// 94/94 cases passed (8 ms)
// Your runtime beats 84.71 % of cpp submissions
// Your memory usage beats 100 % of cpp submissions (5.8 MB)
```
