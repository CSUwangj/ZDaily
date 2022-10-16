+++
updated = 2022-07-08 18:14:00+08:00
title = "2022-07-08 Daily-Challenge"
path = "2022-07-08-Daily-Challenge"
date = 2022-07-08 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/paint-house-iii/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 8

## Description

**Paint House III**

There is a row of `m` houses in a small city, each house must be painted with one of the `n` colors (labeled from `1` to `n`), some houses that have been painted last summer should not be painted again.

A neighborhood is a maximal group of continuous houses that are painted with the same color.

- For example: `houses = [1,2,2,3,3,2,1,1]` contains `5` neighborhoods `[{1}, {2,2}, {3,3}, {2}, {1,1}]`.

Given an array `houses`, an `m x n` matrix `cost` and an integer `target` where:

- `houses[i]`: is the color of the house `i`, and `0` if the house is not painted yet.
- `cost[i][j]`: is the cost of paint the house `i` with the color `j + 1`.

Return *the minimum cost of painting all the remaining houses in such a way that there are exactly* `target` *neighborhoods*. If it is not possible, return `-1`.

 

**Example 1:**

```
Input: houses = [0,0,0,0,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5, n = 2, target = 3
Output: 9
Explanation: Paint houses of this way [1,2,2,1,1]
This array contains target = 3 neighborhoods, [{1}, {2,2}, {1,1}].
Cost of paint all houses (1 + 1 + 1 + 1 + 5) = 9.
```

**Example 2:**

```
Input: houses = [0,2,1,2,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5, n = 2, target = 3
Output: 11
Explanation: Some houses are already painted, Paint the houses of this way [2,2,1,2,2]
This array contains target = 3 neighborhoods, [{2,2}, {1}, {2,2}]. 
Cost of paint the first and last house (10 + 1) = 11.
```

**Example 3:**

```
Input: houses = [3,1,2,3], cost = [[1,1,1],[1,1,1],[1,1,1],[1,1,1]], m = 4, n = 3, target = 3
Output: -1
Explanation: Houses are already painted with a total of 4 neighborhoods [{3},{1},{2},{3}] different of target = 3.
```

 

**Constraints:**

- `m == houses.length == cost.length`
- `n == cost[i].length`
- `1 <= m <= 100`
- `1 <= n <= 20`
- `1 <= target <= m`
- `0 <= houses[i] <= n`
- `1 <= cost[i][j] <= 10^4`

## Solution

`dp[i][j][k]` means minimum costs for beginning `i` house group into `j` neighborhoods end with color `k`

``` cpp
class Solution {
  bool noWay(const vector<int> &houses, int target, int m) {
    int pos = 0;
    while(pos < m && !houses[pos]) {
      pos += 1;
    }
    if(pos == m) return false;
    int current = houses[pos];
    int count = 1;
    for(;pos < m; ++pos) {
      if(houses[pos] && houses[pos] != current) {
        current = houses[pos];
        count += 1;
      }
    }
    return m < count;
  }
public:
  int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
    if(noWay(houses, target, m)) return -1;
    int dp[101][101][21];
    memset(dp, 0x33333333, sizeof(dp));
    memset(dp[0][0], 0, sizeof(dp[0][0]));
    for(int i = 0; i < m; ++i) {
      for(int j = 1; j <= target; ++j) {
        for(int k = 1; k <= n; ++k) {
          if(houses[i] && houses[i] != k) continue;
          dp[i + 1][j][k] = dp[i][j][k];
          for(int _k = 1; _k <= n; ++_k) {
            // cout << i << ' ' << j << ' ' << k << ' ' << _k << endl;
            if(_k == k) continue;
            dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j - 1][_k]);
          }
          if(!houses[i]) dp[i + 1][j][k] += cost[i][k - 1];
          // cout << "#" << i + 1 << ' ' << j << ' ' << k  << ' ' << dp[i + 1][j][k] << endl;
        }
      }
    }
    int result = *min_element(dp[m][target] + 1, dp[m][target] + n + 1);
    if(result >= 0x33333333) result = -1;
    return result;
  }
};

// Accepted
// 60/60 cases passed (78 ms)
// Your runtime beats 86.44 % of cpp submissions
// Your memory usage beats 77.13 % of cpp submissions (10.8 MB)
```
