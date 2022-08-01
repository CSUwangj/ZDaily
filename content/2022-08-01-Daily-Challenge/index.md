+++
updated = 2022-08-01 18:14:00+08:00
title = "2022-08-01 Daily-Challenge"
path = "2022-08-01-Daily-Challenge"
date = 2022-08-01 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/unique-paths/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 1

## Description

**Unique Paths**

There is a robot on an `m x n` grid. The robot is initially located at the **top-left corner** (i.e., `grid[0][0]`). The robot tries to move to the **bottom-right corner** (i.e., `grid[m - 1][n - 1]`). The robot can only move either down or right at any point in time.

Given the two integers `m` and `n`, return *the number of possible unique paths that the robot can take to reach the bottom-right corner*.

The test cases are generated so that the answer will be less than or equal to `2 * 109`.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png)

```
Input: m = 3, n = 7
Output: 28
```

**Example 2:**

```
Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
```

 

**Constraints:**

- `1 <= m, n <= 100`

## Solution

``` cpp
constexpr int combination(int total, int pick) {
  long long result = 1;
  for(int i = 0; i < pick; ++i) {
    result *= (total - i);
    result /= (i + 1);
  }
  return result;
}

class Solution {
public:
  int uniquePaths(int m, int n) {
    return combination(m + n - 2, min(n - 1, m - 1));
  }
};

// Accepted
// 63/63 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 98.48 % of cpp submissions (5.8 MB)
```
