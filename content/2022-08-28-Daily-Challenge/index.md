+++
updated = 2022-08-28 18:14:00+08:00
title = "2022-08-28 Daily-Challenge"
path = "2022-08-28-Daily-Challenge"
date = 2022-08-28 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/sort-the-matrix-diagonally/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 28

## Description

**Sort the Matrix Diagonally**

A **matrix diagonal** is a diagonal line of cells starting from some cell in either the  topmost row or leftmost column and going in the bottom-right direction  until reaching the matrix's end. For example, the **matrix diagonal** starting from `mat[2][0]`, where `mat` is a `6 x 3` matrix, includes cells `mat[2][0]`, `mat[3][1]`, and `mat[4][2]`.

Given an `m x n` matrix `mat` of integers, sort each **matrix diagonal** in ascending order and return *the resulting matrix*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/01/21/1482_example_1_2.png)

```
Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]
```

**Example 2:**

```
Input: mat = [[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]
Output: [[5,17,4,1,52,7],[11,11,25,45,8,69],[14,23,25,44,58,15],[22,27,31,36,50,66],[84,28,75,33,55,68]]
```

 

**Constraints:**

- `m == mat.length`
- `n == mat[i].length`
- `1 <= m, n <= 100`
- `1 <= mat[i][j] <= 100`

## Solution

``` cpp
class Solution {
public:
  vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat.front().size();
    for(int i = 0; i < rows+cols-1; ++i) {
      int rowBegin = max(0, i+1-cols);
      int colBegin = rowBegin == 0 ? cols - 1 - i : 0;
      // cout << '#' << rowBegin << ' ' << colBegin << endl;
      for(int index = 0; rowBegin + index < rows-1 && colBegin + index < cols-1; ++index) {
        for(int j = 1; rowBegin + j < rows-index && colBegin + j < cols-index; ++j) {
          // cout << rowBegin + j << ' ' << colBegin + j << endl;
          if(mat[rowBegin+j][colBegin+j] < mat[rowBegin+j-1][colBegin+j-1]) {
            swap(mat[rowBegin+j][colBegin+j], mat[rowBegin+j-1][colBegin+j-1]);
          }
        }
      }
    }
    return move(mat);
  }
};

// Accepted
// 15/15 cases passed (33 ms)
// Your runtime beats 10.63 % of cpp submissions
// Your memory usage beats 99.93 % of cpp submissions (8.4 MB)
```
