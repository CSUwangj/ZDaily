+++
updated = 2022-05-16 19:24:00+08:00
title = "2022-05-16 Daily-Challenge"
path = "2022-05-16-Daily-Challenge"
date = 2022-05-16 19:21:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/shortest-path-in-binary-matrix/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 16

## Description

**Shortest Path in Binary Matrix**

Given an `n x n` binary matrix `grid`, return *the length of the shortest **clear path** in the matrix*. If there is no clear path, return `-1`.

A **clear path** in a binary matrix is a path from the **top-left** cell (i.e., `(0, 0)`) to the **bottom-right** cell (i.e., `(n - 1, n - 1)`) such that:

- All the visited cells of the path are `0`.
- All the adjacent cells of the path are **8-directionally** connected (i.e., they are different and they share an edge or a corner).

The **length of a clear path** is the number of visited cells of this path.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/02/18/example1_1.png)

```
Input: grid = [[0,1],[1,0]]
Output: 2
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/02/18/example2_1.png)

```
Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4
```

**Example 3:**

```
Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1
```

 

**Constraints:**

- `n == grid.length`
- `n == grid[i].length`
- `1 <= n <= 100`
- `grid[i][j] is 0 or 1`

## Solution

``` cpp
class Solution {
  int move[8][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    if(grid.front().front() || grid.back().back()) return -1;
    int n = grid.size();
    vector<vector<int>> dis(n, vector<int>(n));
    dis[0][0] = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    while(!q.empty()) {
      auto [row, col] = q.front();
      q.pop();
      for(int i = 0; i < 8; ++i) {
        int newRow = row + move[i][0];
        int newCol = col + move[i][1];
        if(newRow < 0 || newRow >= n || newCol < 0 || newCol >= n || grid[newRow][newCol]) continue;
        if(dis[newRow][newCol]) continue;
        dis[newRow][newCol] = dis[row][col] + 1;
        q.push(make_pair(newRow, newCol));
      }
    }
    return dis.back().back() ? dis.back().back() : -1;
  }
};

// Accepted
// 88/88 cases passed (82 ms)
// Your runtime beats 65.2 % of cpp submissions
// Your memory usage beats 49.22 % of cpp submissions (20.8 MB)
```
