+++
title = "2021-04-10 Daily-Challenge"
path = "2021-04-10-Daily-Challenge"
date = 2021-04-10 10:34:24+08:00
updated = 2021-04-10 19:15:10+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [April LeetCoding Challenge](https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/594/week-2-april-8th-april-14th/3703/) with `cpp`.

<!-- more -->

# LeetCode Review

## Maximum Number of Occurrences of a Substring

too easy to review

## Surrounded Regions

too easy to review

## Number of Students Unable to Eat Lunch

too easy to review

## Letter Combinations of a Phone Number

too easy to review

## Verifying an Alien Dictionary

too easy to review

## Determine if String Halves Are Alike

too easy to review

## Minimum Operations to Make Array Equal

too easy to review

## Global and Local Inversions

too easy to review

## Number of Boomerangs

``` cpp
constexpr int distance(int x1, int y1, int x2, int y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

class Solution {
public:
  int numberOfBoomerangs(vector<vector<int>>& points) {
    int len = points.size();
    int answer = 0;
    for(auto &p : points) {
      vector<int> dis;
      for(auto &pp : points) {
        int d = distance(p[0], p[1], pp[0], pp[1]);
        dis.push_back(d);
      }
      sort(dis.begin(), dis.end());
      int d = -1;
      int cnt = 0;
      for(auto dd : dis) {
        if(d != dd) {
          answer += cnt * (cnt - 1);
          d = dd;
          cnt = 1;
        } else {
          cnt += 1;
        }
      }
      answer += cnt * (cnt - 1);
    }
    return answer;
  }
};
```

# April LeetCoding Challenge10

## Description

**Longest Increasing Path in a Matrix**

## Description

Given an `m x n` integers `matrix`, return *the length of the longest increasing path in* `matrix`.

From each cell, you can either move in four directions: left, right, up, or down. You **may not** move **diagonally** or move **outside the boundary** (i.e., wrap-around is not allowed).

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/01/05/grid1.jpg)

```
Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/01/27/tmp-grid.jpg)

```
Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
```

**Example 3:**

```
Input: matrix = [[1]]
Output: 1
```

 

**Constraints:**

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 200`
- <code>0 <= matrix[i][j] <= 2<sup>31</sup> - 1</code>

## Solution

``` cpp
const int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
  int rows;
  int cols;
  bool check(vector<vector<int>>& matrix, int row, int col) {
    int ok = 0;
    for(int i = 0; i < 4; ++i) {
      int newRow = row + moves[i][0];
      int newCol = col + moves[i][1];
      if(newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols ||
         matrix[row][col] <= matrix[newRow][newCol]) {
        ok += 1;
      }
    }
    // cout << row << ' ' << col << ' ' << ok << endl;
    return ok == 4;
  }
  void dfs(vector<vector<int>>& matrix,
           vector<vector<int>> &LIP,
           int row,
           int col,
           int cur
  ) {
    if(cur <= LIP[row][col]) return;
    LIP[row][col] = cur;
    for(int i = 0; i < 4; ++i) {
      int newRow = row + moves[i][0];
      int newCol = col + moves[i][1];
      if(newRow >= rows || newRow < 0 || newCol >= cols || newCol < 0) continue;
      if(matrix[row][col] >= matrix[newRow][newCol]) continue;
      dfs(matrix, LIP, newRow, newCol, cur + 1);
    }
  }
public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    rows = matrix.size();
    cols = matrix.front().size();
    vector<vector<int>> LIP(rows, vector<int>(cols));
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        if(check(matrix, i, j)) dfs(matrix, LIP, i, j, 1);
      }
    }
    int answer = 0;
    for(auto &row : LIP) {
      for(auto n : row) {
        // cout << n << ' ' ;
        answer = max(answer, n);
      }
      // cout << endl;
    }
    return answer;
  }
};
```
