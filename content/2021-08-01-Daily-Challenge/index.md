+++
title = "2021-08-01 Daily-Challenge"
path = "2021-08-01-Daily-Challenge"
date = 2021-08-01 16:33:03+08:00
updated = 2021-08-01 17:15:24+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I gonna review the tasks I've done this week, and finish today's leetcode's [August LeetCoding Challenge](https://leetcode.com/explore/featured/card/august-leetcoding-challenge-2021/613/week-1-august-1st-august-7th/3835/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 1

## Description

**Making A Large Island**

You are given an `n x n` binary matrix `grid`. You are allowed to change **at most one** `0` to be `1`.

Return *the size of the largest **island** in* `grid` *after applying this operation*.

An **island** is a 4-directionally connected group of `1`s.

 

**Example 1:**

```
Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
```

**Example 2:**

```
Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
```

**Example 3:**

```
Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.
```

 

**Constraints:**

- `n == grid.length`
- `n == grid[i].length`
- `1 <= n <= 500`
- `grid[i][j]` is either `0` or `1`.

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
const int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int part[500][500];
bool vis[500][500];
class Solution {
  int n;
  vector<int> lands;
  void travelIsland(
    vector<vector<int>> &grid,
    int row,
    int col,
    int id
  ) {
    vis[row][col] = true;
    lands[id] += 1;
    part[row][col] = id;
    for(int i = 0; i < 4; ++i) {
      int newRow = row + moves[i][0];
      int newCol = col + moves[i][1];
      if(newRow < 0 || newCol < 0 || newRow >= n || newCol >= n) continue;
      if(vis[newRow][newCol]) continue;
      if(!grid[newRow][newCol]) continue;
      travelIsland(grid, newRow, newCol, id);
    }
  }
public:
  int largestIsland(vector<vector<int>>& grid) {
    n = grid.size();
    memset(vis, 0, sizeof(vis));
    memset(part, -1, sizeof(part));
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        if(!vis[i][j] && grid[i][j]) {
          lands.push_back(0);
          travelIsland(grid, i, j, cnt);
          cnt += 1;
        }
      }
    }
    if(!lands.size()) return 1;
    if(lands.size() == 1) return min(n * n, lands[0] + 1);

    int answer = 0;
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        if(grid[i][j]) continue;
        unordered_set<int> neighbors;
        int result = 1;
        for(int k = 0; k < 4; ++k) {
          int newRow = i + moves[k][0];
          int newCol = j + moves[k][1];
          if(newRow < 0 || newCol < 0 || newRow >= n || newCol >= n) continue;
          if(!grid[newRow][newCol]) continue;
          if(neighbors.count(part[newRow][newCol])) continue;
          result += lands[part[newRow][newCol]];
          neighbors.insert(part[newRow][newCol]);
        }
        answer = max(answer, result);
      }
    }

    return answer;
  }
};

// Accepted
// 75/75 cases passed (392 ms)
// Your runtime beats 91.75 % of cpp submissions
// Your memory usage beats 77.94 % of cpp submissions (143.7 MB)
```