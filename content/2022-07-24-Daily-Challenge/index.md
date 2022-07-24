+++
updated = 2022-07-24 18:14:00+08:00
title = "2022-07-24 Daily-Challenge"
path = "2022-07-24-Daily-Challenge"
date = 2022-07-24 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/search-a-2d-matrix-ii/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 24

## Description

**Search a 2D Matrix II**

Write an efficient algorithm that searches for a value `target` in an `m x n` integer matrix `matrix`. This matrix has the following properties:

- Integers in each row are sorted in ascending from left to right.
- Integers in each column are sorted in ascending from top to bottom.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/11/24/searchgrid2.jpg)

```
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/11/24/searchgrid.jpg)

```
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false
```

 

**Constraints:**

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= n, m <= 300`
- `-10^9 <= matrix[i][j] <= 10^9`
- All the integers in each row are **sorted** in ascending order.
- All the integers in each column are **sorted** in ascending order.
- `-10^9 <= target <= 10^9`

## Solution

``` cpp
class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix.front().size();
    int row = 0;
    int col = cols - 1;
    while(row < rows && col >= 0) {
      if(matrix[row][col] == target) return true;
      if(matrix[row][col] > target) {
        col -= 1;
      } else {
        row += 1;
      }
    }
    return false;
  }
};

// Accepted
// 129/129 cases passed (184 ms)
// Your runtime beats 45.36 % of cpp submissions
// Your memory usage beats 21.86 % of cpp submissions (15 MB)
```
