+++
title = "2021-09-26 Daily-Challenge"
path = "2021-09-26-Daily-Challenge"
date = 2021-09-26 15:23:44+08:00
updated = 2021-09-26 16:09:29+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/639/week-4-september-22nd-september-28th/3988/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 26

## Description

**Transform to Chessboard**

You are given an `n x n` binary grid `board`. In each move, you can swap any two rows with each other, or any two columns with each other.

Return *the minimum number of moves to transform the board into a **chessboard board***. If the task is impossible, return `-1`.

A **chessboard board** is a board where no `0`'s and no `1`'s are 4-directionally adjacent.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/06/29/chessboard1-grid.jpg)

```
Input: board = [[0,1,1,0],[0,1,1,0],[1,0,0,1],[1,0,0,1]]
Output: 2
Explanation: One potential sequence of moves is shown.
The first move swaps the first and second column.
The second move swaps the second and third row.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/06/29/chessboard2-grid.jpg)

```
Input: board = [[0,1],[1,0]]
Output: 0
Explanation: Also note that the board with 0 in the top left corner, is also a valid chessboard.
```

**Example 3:**

![img](https://assets.leetcode.com/uploads/2021/06/29/chessboard3-grid.jpg)

```
Input: board = [[1,0],[1,0]]
Output: -1
Explanation: No matter what sequence of moves you make, you cannot end with a valid chessboard.
```

 

**Constraints:**

- `n == board.length`
- `n == board[i].length`
- `2 <= n <= 30`
- `board[i][j]` is either `0` or `1`.

## Solution

``` cpp
class Solution {
public:
  int movesToChessboard(vector<vector<int>>& board) {
    int n = board.size();
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        if(board[0][0] ^ board[0][j] ^ board[i][0] ^ board[i][j]) return - 1;
      }
    }
    int rowSum = 0;
    int colSum = 0;
    int rowSwap = 0;
    int colSwap = 0;
    for(int i = 0; i < n; ++i) {
      rowSum += board[0][i];
      colSum += board[i][0];
      rowSwap += board[i][0] == (i & 1);
      colSwap += board[0][i] == (i & 1);
    }
    if(rowSum != n / 2 && rowSum != (n + 1) / 2) return -1;
    if(colSum != n / 2 && colSum != (n + 1) / 2) return -1;
    if(n & 1) {
      if(colSwap & 1) colSwap = n - colSwap;
      if(rowSwap & 1) rowSwap = n - rowSwap;
    } else {
      if(colSwap * 2 > n) colSwap = n - colSwap;
      if(rowSwap * 2 > n) rowSwap = n - rowSwap;
    }
    return (colSwap + rowSwap) / 2;
  }
};

// Accepted
// 124/124 cases passed (4 ms)
// Your runtime beats 96.43 % of cpp submissions
// Your memory usage beats 98.21 % of cpp submissions (10 MB)
```
