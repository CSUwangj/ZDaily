+++
title = "2021-11-02 Daily-Challenge"
path = "2021-11-02-Daily-Challenge"
date = 2021-11-02 17:43:23+08:00
updated = 2021-11-02 17:50:32+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/unique-paths-iii/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 2

## Description

**Unique Paths III**

You are given an `m x n` integer array `grid` where `grid[i][j]` could be:

- `1` representing the starting square. There is exactly one starting square.
- `2` representing the ending square. There is exactly one ending square.
- `0` representing empty squares we can walk over.
- `-1` representing obstacles that we cannot walk over.

Return *the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/08/02/lc-unique1.jpg)

```
Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/08/02/lc-unique2.jpg)

```
Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
```

**Example 3:**

![img](https://assets.leetcode.com/uploads/2021/08/02/lc-unique3-.jpg)

```
Input: grid = [[0,1],[2,0]]
Output: 0
Explanation: There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.
```

 

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 20`
- `1 <= m * n <= 20`
- `-1 <= grid[i][j] <= 2`
- There is exactly one starting cell and one ending cell.

## Solution

``` cpp
const char moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
  char rows;
  char cols;
  char start;
  char finish;
  char obstacles;
  char target;
  char answer;
  unordered_set<string> cache;
  vector<bool> visit;
  string path;
  void init(vector<vector<int>> &grid) {
    rows = grid.size();
    cols = grid.front().size();
    for(int i = 0; i < rows; ++i) {
      for(char j = 0; j < cols; ++j) {
        switch(grid[i][j]) {
          case 1:
            start = i * cols + j;
            break;
          case 2:
            finish = i * cols + j;
            break;
          case -1:
            obstacles += 1;
          default:
            ;
        }
      }
    }
    target = rows * cols - obstacles;
  }
  bool checkConnection(vector<vector<int>>& grid) {
    queue<pair<char, char>> q;
    bool vis[rows][cols];
    memset(vis, 0, sizeof(vis));
    vis[start / cols][start % cols] = true;
    q.push({start / cols, start % cols});

    while(q.size()) {
      auto [row, col] = q.front();
      if(row * cols + col == finish) return true;
      q.pop();
      for(char i = 0 ; i < 4; ++i) {
        char newRow = row + moves[i][0];
        char newCol = col + moves[i][1];
        if(newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols) continue;
        if(vis[newRow][newCol] || grid[newRow][newCol] == -1) continue;
        vis[newRow][newCol] = true;
        q.push({newRow, newCol});
      }
    }
    return false;
  }
  void solve(vector<vector<int>>& grid) {
    if(cache.count(path)) return;
    cache.insert(path);
    // cout << ToHex(path) << endl;

    char row = path.back() / cols;
    char col = path.back() % cols;
    if(path.back() == finish) {
      answer += path.length() == target;
      return;
    }

    for(char i = 0; i < 4; ++i) {
      char newRow = row + moves[i][0];
      char newCol = col + moves[i][1];
      if(newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols) continue;
      if(visit[newRow * cols + newCol] || grid[newRow][newCol] == -1) continue;
      visit[newRow * cols + newCol] = true;
      path.push_back(newRow * cols + newCol);
      solve(grid);
      path.pop_back();
      visit[newRow * cols + newCol] = false;
    }
  }
public:
  int uniquePathsIII(vector<vector<int>>& grid) {

    init(grid);
    if(!checkConnection(grid)) {
      return 0;
    }

    unordered_set<string> cache;
    visit.resize(rows * cols);
    path.push_back(start);
    visit[start] = true;
    solve(grid);

    return answer;
  }
};

// Accepted
// 39/39 cases passed (8 ms)
// Your runtime beats 32.66 % of cpp submissions
// Your memory usage beats 22.59 % of cpp submissions (10 MB)
```

and do some optimization

``` cpp
const char moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
  char rows;
  char cols;
  char start;
  char finish;
  char obstacles;
  char target;
  char answer;
  char count = 1;
  void init(vector<vector<int>> &grid) {
    rows = grid.size();
    cols = grid.front().size();
    for(int i = 0; i < rows; ++i) {
      for(char j = 0; j < cols; ++j) {
        switch(grid[i][j]) {
          case 1:
            start = i * cols + j;
            break;
          case 2:
            finish = i * cols + j;
            break;
          case -1:
            obstacles += 1;
          default:
            ;
        }
      }
    }
    target = rows * cols - obstacles;
  }
  void solve(vector<vector<int>>& grid, char pos) {
    // cout << ToHex(path) << endl;

    char row = pos / cols;
    char col = pos % cols;
    if(pos == finish) {
      answer += count == target;
      return;
    }
    grid[row][col] = -1;

    for(char i = 0; i < 4; ++i) {
      char newRow = row + moves[i][0];
      char newCol = col + moves[i][1];
      if(newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols) continue;
      if(grid[newRow][newCol] == -1) continue;
      count += 1;
      solve(grid, newRow * cols + newCol);
      count -= 1;
    }
    grid[row][col] = 0;
  }
public:
  int uniquePathsIII(vector<vector<int>>& grid) {

    init(grid);

    solve(grid, start);

    return answer;
  }
};

// Accepted
// 39/39 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 67.27 % of cpp submissions (7.1 MB)
```
