+++
updated = 2022-03-30 18:55:00+08:00
title = "2022-03-30 Daily-Challenge"
path = "2022-03-30-Daily-Challenge"
date = 2022-03-30 18:53:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/search-a-2d-matrix/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 30

## Description

**Search a 2D Matrix**

Write an efficient algorithm that searches for a value `target` in an `m x n` integer matrix `matrix`. This matrix has the following properties:

- Integers in each row are sorted from left to right.
- The first integer of each row is greater than the last integer of the previous row.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/10/05/mat.jpg)

```
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/10/05/mat2.jpg)

```
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
```

 

**Constraints:**

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 100`
- `-10^4 <= matrix[i][j], target <= 10^4`

## Solution

``` cpp
class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(!matrix.size() || !matrix[0].size()) return false;
    int begin = 0, end = matrix.size()-1;
    vector<int> &a = matrix[0];
    while(begin < end) {
      int mid = (begin + end) / 2;
      if(matrix[mid].front() > target) {
        end = mid - 1;
      } else if (matrix[mid].back() < target) {
        begin = mid + 1;
      } else {
        break;
      }
    }
    a = matrix[(begin+end)/2];
    return binary_search(a.begin(), a.end(), target);
  }
};

// Accepted
// 133/133 cases passed (8 ms)
// Your runtime beats 35.04 % of cpp submissions
// Your memory usage beats 78.43 % of cpp submissions (9.4 MB)
```
