+++
title = "2021-03-25 Daily-Challenge"
path = "2021-03-25-Daily-Challenge"
date = 2021-03-25 18:00:35+08:00
updated = 2021-03-25 18:52:52+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Defuse the Bomb](https://leetcode.com/problems/defuse-the-bomb/) and leetcode's [March LeetCoding Challenge](https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/591/week-4-march-22nd-march-28th/3684/) with `cpp`.

<!-- more -->

# Defuse the Bomb

## Description

You have a bomb to defuse, and your time is running out! Your informer will provide you with a **circular** array `code` of length of `n` and a key `k`.

To decrypt the code, you must replace every number. All the numbers are replaced **simultaneously**.

- If `k > 0`, replace the `ith` number with the sum of the **next** `k` numbers.
- If `k < 0`, replace the `ith` number with the sum of the **previous** `k` numbers.
- If `k == 0`, replace the `ith` number with `0`.

As `code` is circular, the next element of `code[n-1]` is `code[0]`, and the previous element of `code[0]` is `code[n-1]`.

Given the **circular** array `code` and an integer key `k`, return *the decrypted code to defuse the bomb*!

 

**Example 1:**

```
Input: code = [5,7,1,4], k = 3
Output: [12,10,16,13]
Explanation: Each number is replaced by the sum of the next 3 numbers. The decrypted code is [7+1+4, 1+4+5, 4+5+7, 5+7+1]. Notice that the numbers wrap around.
```

**Example 2:**

```
Input: code = [1,2,3,4], k = 0
Output: [0,0,0,0]
Explanation: When k is zero, the numbers are replaced by 0. 
```

**Example 3:**

```
Input: code = [2,4,9,3], k = -2
Output: [12,5,6,13]
Explanation: The decrypted code is [3+9, 2+3, 4+2, 9+4]. Notice that the numbers wrap around again. If k is negative, the sum is of the previous numbers.
```

 

**Constraints:**

- `n == code.length`
- `1 <= n <= 100`
- `1 <= code[i] <= 100`
- `-(n - 1) <= k <= n - 1`

## Solution

``` cpp
class Solution {
public:
  vector<int> decrypt(vector<int>& code, int k) {
    int len = code.size();
    vector<int> prefix(len);
    for(int i = 0; i < len; ++i) {
      prefix[i] = code[i];
      if(i) prefix[i] += prefix[i - 1];
    }
    vector<int> answer(len);
    if(!k) return answer;
    for(int i = 0; i < len; ++i) {
      int result = 0;
      if(k < 0) {
        if(i + k <= 0) {
          answer[i] = prefix[len - 1] - prefix[i + k + len - 1]  + prefix[i] - code[i];
        } else {
          answer[i] = prefix[i - 1] - prefix[i + k - 1];
        }
      } else {
        if(i + k >= len) {
          answer[i] = prefix[len - 1] - prefix[i] + prefix[i + k - len];
        } else {
          answer[i] = prefix[i + k] - prefix[i];
        }
      }
    }
    return answer;
  }
};
```

# March LeetCoding challenge 25

## Description

**Pacific Atlantic Water Flow**

You are given an `m x n` integer matrix `heights` representing the height of each unit cell in a continent. The **Pacific ocean** touches the continent's left and top edges, and the A**tlantic ocean** touches the continent's right and bottom edges.

Water can only flow in four directions: up, down, left, and right. Water flows from a cell to an adjacent one with an equal or lower height.

Return *a list of grid coordinates where water can flow to both the Pacific and Atlantic oceans*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/03/26/ocean-grid.jpg)

```
Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
```

**Example 2:**

```
Input: heights = [[2,1],[1,2]]
Output: [[0,0],[0,1],[1,0],[1,1]]
```

 

**Constraints:**

- `m == heights.length`
- `n == heights[i].length`
- `1 <= m, n <= 200`
- `1 <= heights[i][j] <= 105`

## Solution

``` cpp
const int NONE = 0;
const int PAC = 1;
const int ATL = 1 << 1;
const int HALF = 1;
const int ALL = 1 << 1;
const int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
  int rows;
  int cols;
  vector<vector<int>> matrix;
  vector<vector<uint8_t>> canReach;
  void dfs(int row, int col, int conti) {
    if((canReach[row][col] & conti) == conti) return;
    canReach[row][col] |= conti;
    for(int i = 0; i < 4; ++i) {
      int newRow = row + moves[i][0];
      int newCol = col + moves[i][1];
      if(newRow >= rows || newRow < 0 || newCol >= cols || newCol < 0) continue;
      if(matrix[newRow][newCol] < matrix[row][col]) continue;
      if((canReach[newRow][newCol] & conti) == conti) continue;
      dfs(newRow, newCol, conti);
    }
  }
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
    this->matrix = matrix;
    rows = matrix.size();
    if(!rows) return {};
    cols = matrix.front().size();
    if(!cols) return {};
    canReach.resize(rows, vector<uint8_t>(cols));
    for(int i = 0; i < rows; ++i) {
      dfs(i, 0, PAC);
      dfs(i, cols - 1, ATL);
    }
    for(int i = 0; i < cols; ++i) {
      dfs(0, i, PAC);
      dfs(rows - 1, i, ATL);
    }
    const int TARGET = PAC | ATL;
    vector<vector<int>> answer;
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        if(canReach[i][j] == TARGET) {
          answer.push_back({i, j});
        }
      }
    }
    return answer;
  }
};
```
