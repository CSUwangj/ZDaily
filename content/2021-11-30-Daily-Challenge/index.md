+++
title = "2021-11-30 Daily-Challenge"
path = "2021-11-30-Daily-Challenge"
date = 2021-11-30 20:30:00+08:00
updated = 2021-11-30 20:50:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/maximal-rectangle/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 30

## Description

**Maximal Rectangle**

Given a `rows x cols` binary `matrix` filled with `0`'s and `1`'s, find the largest rectangle containing only `1`'s and return *its area*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/09/14/maximal.jpg)

```
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
```

**Example 2:**

```
Input: matrix = []
Output: 0
```

**Example 3:**

```
Input: matrix = [["0"]]
Output: 0
```

**Example 4:**

```
Input: matrix = [["1"]]
Output: 1
```

**Example 5:**

```
Input: matrix = [["0","0"]]
Output: 0
```

 

**Constraints:**

- `rows == matrix.length`
- `cols == matrix[i].length`
- `0 <= row, cols <= 200`
- `matrix[i][j]` is `'0'` or `'1'`.

## Solution

``` cpp
class Solution {
  int largestRectangleArea(vector<int>& heights, vector<int> &st) {
    heights.push_back(0);
    int len = heights.size();
    int answer = 0;
    for(int i = 0; i < len; ++i) {
      while(st.back() != -1 && heights[i] < heights[st.back()]) {
        int index = st.back();
        st.pop_back();
        int h = heights[index];
        int w = i - st.back() - 1;
        answer = max(answer, h*w);
      }
      st.push_back(i);
    }
    while(st.size() != 1) st.pop_back();
    return answer;
  }
public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    vector<int> st{-1};
    int row = matrix.size();
    if(!row) return 0;
    int col = matrix.front().size();
    vector<int> dp(col);
    int answer = 0;
    for(int i = 0; i < row; ++i) {
      for(int j = 0; j < col; ++j) {
        if(matrix[i][j] == '1') {
          dp[j] = dp[j] + 1;
        } else {
          dp[j] = 0;
        }
      }
      answer = max(answer, largestRectangleArea(dp, st));
    }
    return answer;
  }
};

// Accepted
// 71/71 cases passed (24 ms)
// Your runtime beats 95.14 % of cpp submissions
// Your memory usage beats 90.31 % of cpp submissions (11 MB)
```
