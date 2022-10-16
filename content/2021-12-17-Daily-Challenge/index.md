+++
title = "2021-12-17 Daily-Challenge"
path = "2021-12-17-Daily-Challenge"
date = 2021-12-17 18:27:00+08:00
updated = 2021-12-17 18:37:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/maximal-square/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 17

## Description

**Maximal Square**

Given an `m x n` binary `matrix` filled with `0`'s and `1`'s, *find the largest square containing only* `1`'s *and return its area*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/11/26/max1grid.jpg)

```
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/11/26/max2grid.jpg)

```
Input: matrix = [["0","1"],["1","0"]]
Output: 1
```

**Example 3:**

```
Input: matrix = [["0"]]
Output: 0
```

 

**Constraints:**

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 300`
- `matrix[i][j]` is `'0'` or `'1'`.

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  int maxSquare(vector<int> &counts, vector<int> &st) {
    int len = counts.size();
    int answer = 0;
    for(int i = 0; i < len; ++i) {
      while(st.back() != -1 && counts[i] < counts[st.back()]) {
        int index = st.back();
        st.pop_back();
        // till the next less
        answer = max(answer, min(i - st.back() - 1, counts[index]));
      }
      st.push_back(i);
    }    
    while(st.back() != -1) st.pop_back();
    return answer;
  }
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int rows = matrix.size();
    int cols = matrix.front().size();
    vector<int> dp(cols + 1);
    vector<int> st{-1};
    int sideLength = 0;
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        dp[j] = matrix[i][j] == '1' ? dp[j] + 1 : 0;
      }
      sideLength = max(sideLength, maxSquare(dp, st));
    }
    return sideLength * sideLength;
  }
};

// Accepted
// 75/75 cases passed (20 ms)
// Your runtime beats 94.4 % of cpp submissions
// Your memory usage beats 75.11 % of cpp submissions (11.4 MB)
```
