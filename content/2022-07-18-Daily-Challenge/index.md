+++
updated = 2022-07-18 18:14:00+08:00
title = "2022-07-18 Daily-Challenge"
path = "2022-07-18-Daily-Challenge"
date = 2022-07-18 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 18

## Description

**Number of Submatrices That Sum to Target**

Given a `matrix` and a `target`, return the number of non-empty submatrices that sum to target.

A submatrix `x1, y1, x2, y2` is the set of all cells `matrix[x][y]` with `x1 <= x <= x2` and `y1 <= y <= y2`.

Two submatrices `(x1, y1, x2, y2)` and `(x1', y1', x2', y2')` are different if they have some coordinate that is different: for example, if `x1 != x1'`.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/09/02/mate1.jpg)

```
Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
Output: 4
Explanation: The four 1x1 submatrices that only contain 0.
```

**Example 2:**

```
Input: matrix = [[1,-1],[-1,1]], target = 0
Output: 5
Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.
```

**Example 3:**

```
Input: matrix = [[904]], target = 0
Output: 0
```

 

**Constraints:**

- `1 <= matrix.length <= 100`
- `1 <= matrix[0].length <= 100`
- `-1000 <= matrix[i] <= 1000`
- `-10^8 <= target <= 10^8`

## Solution

``` cpp
class Solution {
public:
  int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix.front().size();
    vector<vector<int>> sum(rows + 1, vector<int>(cols + 1));
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + matrix[i][j];
      }
    }
    int answer = 0;
    for(int i = 0; i < cols; ++i) {
      for(int j = i + 1; j <= cols; ++j) {
        multiset<int> tmp{0};
        for(int row = 1; row <= rows; ++row) {
          int curSum = sum[row][j] - sum[row][i];
          answer += tmp.count(curSum - target);
          tmp.insert(curSum);
        }
      }
    }
    return answer;
  }
};

// Accepted
// 40/40 cases passed (1111 ms)
// Your runtime beats 57.65 % of cpp submissions
// Your memory usage beats 41.05 % of cpp submissions (166 MB)
```
