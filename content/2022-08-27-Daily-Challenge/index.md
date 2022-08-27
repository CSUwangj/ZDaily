+++
updated = 2022-08-27 18:14:00+08:00
title = "2022-08-27 Daily-Challenge"
path = "2022-08-27-Daily-Challenge"
date = 2022-08-27 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 27

## Description

**Max Sum of Rectangle No Larger Than K**

Given an `m x n` matrix `matrix` and an integer `k`, return *the max sum of a rectangle in the matrix such that its sum is no larger than* `k`.

It is **guaranteed** that there will be a rectangle with a sum no larger than `k`.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/03/18/sum-grid.jpg)

```
Input: matrix = [[1,0,1],[0,-2,3]], k = 2
Output: 2
Explanation: Because the sum of the blue rectangle [[0, 1], [-2, 3]] is 2, and 2 is the max number no larger than k (k = 2).
```

**Example 2:**

```
Input: matrix = [[2,2,-1]], k = 3
Output: 3
```

 

**Constraints:**

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 100`
- `-100 <= matrix[i][j] <= 100`
- `-10^5 <= k <= 10^5`

**Follow up:** What if the number of rows is much larger than the number of columns?

## Solution

``` cpp
class Solution {
public:
  int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    int rows = matrix.size();
    int cols = matrix.front().size(); 
    // cout << "---------------" << endl;
    vector<vector<int>> prefix(rows, vector<int>(cols + 1));
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        prefix[i][j + 1] = prefix[i][j] + matrix[i][j];
      }
    }

    int answer = INT_MIN;
    for(int i = 0; i < cols; ++i) {
      for(int j = i + 1; j <= cols; ++j) {
        set<int> tmp{0};
        int sum = 0;
        // cout << endl;
        for(int row = 0; row < rows; ++row) {
          sum += prefix[row][j] - prefix[row][i];
          // cout << i << ' ' << j << ' ' << row << ' ' << sum << endl;
          int diff = sum - k;
          auto it = tmp.lower_bound(diff);
          if(it != tmp.end()) {
            answer = max(answer, sum - *it);
            if(answer == k) return answer;
          }
          tmp.insert(sum);
        }
      }
    }

    return answer;
  }
};

// Accepted
// 39/39 cases passed (1363 ms)
// Your runtime beats 78.29 % of cpp submissions
// Your memory usage beats 78.2 % of cpp submissions (192.5 MB)
```
