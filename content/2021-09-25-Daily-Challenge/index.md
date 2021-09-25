+++
title = "2021-09-25 Daily-Challenge"
path = "2021-09-25-Daily-Challenge"
date = 2021-09-25 15:15:15+08:00
updated = 2021-09-25 15:56:28+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/639/week-4-september-22nd-september-28th/3987/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 25

## Description

**Shortest Path in a Grid with Obstacles Elimination**

You are given an `m x n` integer matrix `grid` where each cell is either `0` (empty) or `1` (obstacle). You can move up, down, left, or right from and to an empty cell in **one step**.

Return *the minimum number of **steps** to walk from the upper left corner* `(0, 0)` *to the lower right corner* `(m - 1, n - 1)` *given that you can eliminate **at most*** `k` *obstacles*. If it is not possible to find such walk return `-1`.

 

**Example 1:**

```
Input: 
grid = 
[[0,0,0],
 [1,1,0],
 [0,0,0],
 [0,1,1],
 [0,0,0]], 
k = 1
Output: 6
Explanation: 
The shortest path without eliminating any obstacle is 10. 
The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).
```

**Example 2:**

```
Input: 
grid = 
[[0,1,1],
 [1,1,1],
 [1,0,0]], 
k = 1
Output: -1
Explanation: 
We need to eliminate at least two obstacles to find such a walk.
```

 

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 40`
- `1 <= k <= m * n`
- `grid[i][j] == 0 **or** 1`
- `grid[0][0] == grid[m - 1][n - 1] == 0`

## Solution

``` cpp
const int8_t moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool vis[80][40][40];
struct State {
  int16_t step;
  int8_t rest;
  int8_t row;
  int8_t column;
  State(int16_t step = 0, int8_t rest = 0, int8_t row = 0, int8_t column = 0) : 
    step(step), rest(rest), row(row), column(column) { }
  bool operator<(const State& other) const {
    return step > other.step || (step == other.step && rest < other.rest);
  }
};
class Solution {
public:
  int shortestPath(vector<vector<int>>& grid, int k) {
    int8_t rows = grid.size();
    int8_t cols = grid.front().size();
    if(k >= rows + cols - 3) return rows + cols - 2;
    memset(vis, 0, sizeof(vis[0]) * (k + 1));
    priority_queue<State> pq;
    pq.push(State(0, k, 0, 0));
    vis[k][0][0] = true;
    while(pq.size()) {
      auto [step, rest, row, col] = pq.top();
      // cout << step << " " << rest << " " << row << " " << col <<endl;
      pq.pop();
      if(row == rows - 1 && col == cols - 1) return step;
      for(int i = 0; i < 4; ++i) {
        int8_t newRow = row + moves[i][0];
        int8_t newCol = col + moves[i][1];
        int8_t newRest = rest;
        if(newRow >= rows || newCol >= cols || newRow < 0 || newCol < 0) continue;
        newRest -= grid[newRow][newCol];
        // cout << newRest << ' ' << newRow << ' ' << newCol <<endl;
        if(newRest < 0 || vis[newRest][newRow][newCol]) {
          continue;
        }
        pq.push(State(step + 1, newRest, newRow, newCol));
        vis[newRest][newRow][newCol] = true;
      }
    }
    return -1;
  }
};

// Accepted
// 47/47 cases passed (4 ms)
// Your runtime beats 99.62 % of cpp submissions
// Your memory usage beats 100 % of cpp submissions (7.7 MB)
```
