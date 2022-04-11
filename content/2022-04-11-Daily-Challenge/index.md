+++
updated = 2022-04-11 20:51:00+08:00
title = "2022-04-11 Daily-Challenge"
path = "2022-04-11-Daily-Challenge"
date = 2022-04-11 20:37:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/shift-2d-grid/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 11

## Description

**Shift 2D Grid**

Given a 2D `grid` of size `m x n` and an integer `k`. You need to shift the `grid` `k` times.

In one shift operation:

- Element at `grid[i][j]` moves to `grid[i][j + 1]`.
- Element at `grid[i][n - 1]` moves to `grid[i + 1][0]`.
- Element at `grid[m - 1][n - 1]` moves to `grid[0][0]`.

Return the *2D grid* after applying shift operation `k` times.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2019/11/05/e1.png)

```
Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
Output: [[9,1,2],[3,4,5],[6,7,8]]
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2019/11/05/e2.png)

```
Input: grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
Output: [[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]
```

**Example 3:**

```
Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 9
Output: [[1,2,3],[4,5,6],[7,8,9]]
```

 

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m <= 50`
- `1 <= n <= 50`
- `-1000 <= grid[i][j] <= 1000`
- `0 <= k <= 100`

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    int rows = grid.size();
    int cols = grid.front().size();
    k %= (rows * cols);
    if(!k) return move(grid);
    vector<int> temp;
    temp.reserve(k);
    for(int row = 0; temp.size() != k && row < rows; ++row) {
      for(int col = 0; temp.size() != k && col < cols; ++col) {
        temp.push_back(grid[row][col]);
      }
    }
    for(int row = rows - 1; row >= 0; --row) {
      for(int col = cols - 1; row * cols + col >= k && col >= 0; --col) {
        cout << row << ' '<< col << endl;
        int targetPos = (row * cols + col + k) % (rows * cols);
        grid[targetPos / cols][targetPos % cols] = grid[row][col];
      }
    }
    for(int i = 0; i < k; ++i) {
      int targetPos = (i + k) % (rows * cols);
      grid[targetPos / cols][targetPos % cols] = temp[i];
    }
    return move(grid);
  }
};

// Accepted
// 107/107 cases passed (46 ms)
// Your runtime beats 47.01 % of cpp submissions
// Your memory usage beats 100 % of cpp submissions (13.6 MB)
```
