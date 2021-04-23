+++
title = "2021-04-06 Daily-Challenge"
path = "2021-04-06-Daily-Challenge"
date = 2021-04-06 15:00:02+08:00
updated = 2021-04-06 15:31:50+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Surrounded Regions](https://leetcode.com/problems/surrounded-regions/) and leetcode's [April LeetCoding Challenge](https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/593/week-1-april-1st-april-7th/3698/) with `cpp`.

<!-- more -->

# Surrounded Regions

## Description

Given an `m x n` matrix `board` containing `'X'` and `'O'`, *capture all regions surrounded by* `'X'`.

A region is **captured** by flipping all `'O'`s into `'X'`s in that surrounded region.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/02/19/xogrid.jpg)

```
Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Surrounded regions should not be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
```

**Example 2:**

```
Input: board = [["X"]]
Output: [["X"]]
```

 

**Constraints:**

- `m == board.length`
- `n == board[i].length`
- `1 <= m, n <= 200`
- `board[i][j]` is `'X'` or `'O'`.

## Solution

``` cpp
const int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
  int rows;
  int cols;
  vector<vector<bool>> vis;
  void dfs(int row, int col, vector<vector<char>>& board) {
    vis[row][col] = true;
    board[row][col] = 'A';
    for(int i = 0; i < 4; ++i) {
      int newRow = row + moves[i][0];
      int newCol = col + moves[i][1];
      if(newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols) continue;
      if(vis[newRow][newCol] || board[newRow][newCol] == 'X') continue;
      dfs(newRow, newCol, board);
    }
  }
public:
  void solve(vector<vector<char>>& board) {
    rows = board.size();
    cols = board.front().size();
    vis.resize(rows, vector<bool>(cols));
    for(int i = 0; i < cols; ++i) {
      if(!vis[0][i] && board[0][i] == 'O') dfs(0, i, board);
      if(!vis[rows - 1][i] && board[rows - 1][i] == 'O') dfs(rows - 1, i, board); 
    }
    for(int i = 0; i < rows; ++i) {
      if(!vis[i][0] && board[i][0] == 'O') dfs(i, 0, board);
      if(!vis[i][cols - 1] && board[i][cols - 1] == 'O') dfs(i, cols - 1, board);
    }
    for(auto &row : board) {
      for(auto &c : row) {
        c = (c == 'A' ? 'O' : 'X');
      }
    }
  }
};
```

# April LeetCoding challenge6

## Description

**Minimum Operations to Make Array Equal**

In one operation, you can select two indices `x` and `y` where `0 <= x, y < n` and subtract `1` from `arr[x]` and add `1` to `arr[y]` (i.e. perform `arr[x] -=1 `and `arr[y] += 1`). The goal is to make all the elements of the array **equal**. It is **guaranteed** that all the elements of the array can be made equal using some operations.

Given an integer `n`, the length of the array. Return *the minimum number of operations* needed to make all the elements of arr equal.

 

**Example 1:**

```
Input: n = 3
Output: 2
Explanation: arr = [1, 3, 5]
First operation choose x = 2 and y = 0, this leads arr to be [2, 3, 4]
In the second operation choose x = 2 and y = 0 again, thus arr = [3, 3, 3].
```

**Example 2:**

```
Input: n = 6
Output: 9
```

 

**Constraints:**

- `1 <= n <= 10^4`

## Solution

this problem can be solved with only one computing expression without `if` and `?`. check comment for explanation.

``` cpp
class Solution {
public:
  int minOperations(int n) {
    return (n / 2) * ((n + 1) / 2);
  }
};

// 1 3 => 1
// 1 3 5 7 => 4 4 4 4 => 1 + 3
// 1 3 5 7 9 11 => 1 + 3 + 5
// f(n) = 1 + 3 + ... + n - 1 = n * (n / 2) / 2 = n * n / 4 (n == 2 * k)

// 1 => 0
// 1 3 5 => 0 + 2
// 1 3 5 7 9 => 0 + 2 + 4
// f(n) = 0 + 2 + ... + n - 1 = (n - 1) * ((n + 1) / 2) / 2

// f(n) = (n / 2) * ((n + 1) / 2)
// because for odd number, (n - 1) / 2 == (n) / 2 in computing
// and we have (n + 1) / 2 == n / 2 for even number
// do not casually exchange order of computing because
// it will break the equality
```
