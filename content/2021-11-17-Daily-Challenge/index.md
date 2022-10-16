+++
title = "2021-11-17 Daily-Challenge"
path = "2021-11-17-Daily-Challenge"
date = 2021-11-17 20:30:03+08:00
updated = 2021-11-17 20:32:24+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/unique-paths/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 17

## Description

**Unique Paths**

A robot is located at the top-left corner of a `m x n` grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

 

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
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
```

**Example 3:**

```
Input: m = 7, n = 3
Output: 28
```

**Example 4:**

```
Input: m = 3, n = 3
Output: 6
```

 

**Constraints:**

- `1 <= m, n <= 100`
- It's guaranteed that the answer will be less than or equal to `2 * 10^9`.

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
// 62/62 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 88.67 % of cpp submissions (5.8 MB)
```
