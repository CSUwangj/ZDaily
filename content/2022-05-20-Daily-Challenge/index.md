+++
updated = 2022-05-20 18:14:00+08:00
title = "2022-05-20 Daily-Challenge"
path = "2022-05-20-Daily-Challenge"
date = 2022-05-20 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/unique-paths-ii/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 20

## Description

**Unique Paths II**

You are given an `m x n` integer array `grid`. There is a robot initially located at the **top-left corner** (i.e., `grid[0][0]`). The robot tries to move to the **bottom-right corner** (i.e., `grid[m-1][n-1]`). The robot can only move either down or right at any point in time.

An obstacle and space are marked as `1` or `0` respectively in `grid`. A path that the robot takes cannot include **any** square that is an obstacle.

Return *the number of possible unique paths that the robot can take to reach the bottom-right corner*.

The testcases are generated so that the answer will be less than or equal to `2 * 109`.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/11/04/robot1.jpg)

```
Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/11/04/robot2.jpg)

```
Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
```

 

**Constraints:**

- `m == obstacleGrid.length`
- `n == obstacleGrid[i].length`
- `1 <= m, n <= 100`
- `obstacleGrid[i][j]` is `0` or `1`.

## Solution

``` cpp
class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    if(obstacleGrid[0][0] || obstacleGrid[m-1][n-1]) return 0;
    vector<int> dp(m*n);
    dp[0] = 1;
    for(int i = 1; i < m*n; ++i) {
      if(obstacleGrid[i/n][i%n] == 1) continue;
      if(i >= n) dp[i] += dp[i-n];
      if(i % n != 0) dp[i] += dp[i-1];
    }
    return dp.back();
  }
};

// Accepted
// 41/41 cases passed (11 ms)
// Your runtime beats 10.13 % of cpp submissions
// Your memory usage beats 73.85 % of cpp submissions (7.7 MB)
```
