+++
updated = 2022-06-13 18:14:00+08:00
title = "2022-06-13 Daily-Challenge"
path = "2022-06-13-Daily-Challenge"
date = 2022-06-13 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/triangle/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 13

## Description

**Triangle**

Given a `triangle` array, return *the minimum path sum from top to bottom*.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index `i` on the current row, you may move to either index `i` or index `i + 1` on the next row.

 

**Example 1:**

```
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
```

**Example 2:**

```
Input: triangle = [[-10]]
Output: -10
```

 

**Constraints:**

- `1 <= triangle.length <= 200`
- `triangle[0].length == 1`
- `triangle[i].length == triangle[i - 1].length + 1`
- `-10^4 <= triangle[i][j] <= 10^4`

 

**Follow up:** Could you do this using only `O(n)` extra space, where `n` is the total number of rows in the triangle?

## Solution

``` cpp
class Solution {
public:
  int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<int> dp(n, INT_MAX);
    dp[0] = triangle.front().front();
    for(int i = 1; i < n; ++i) {
      for(int j = i; j >= 0; --j) {
        if(j == i) dp[j] = dp[j - 1];
        else if(j) dp[j] = min(dp[j], dp[j - 1]);
        dp[j] += triangle[i][j];
      }
    }
    return *min_element(dp.begin(), dp.end());
  }
};

// Accepted
// 44/44 cases passed (2 ms)
// Your runtime beats 98.01 % of cpp submissions
// Your memory usage beats 70.75 % of cpp submissions (8.6 MB)
```
