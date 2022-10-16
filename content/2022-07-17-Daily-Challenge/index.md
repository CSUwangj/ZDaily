+++
updated = 2022-07-17 18:14:00+08:00
title = "2022-07-17 Daily-Challenge"
path = "2022-07-17-Daily-Challenge"
date = 2022-07-17 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/k-inverse-pairs-array/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 17

## Description

**K Inverse Pairs Array**

For an integer array `nums`, an **inverse pair** is a pair of integers `[i, j]` where `0 <= i < j < nums.length` and `nums[i] > nums[j]`.

Given two integers n and k, return the number of different arrays consist of numbers from `1` to `n` such that there are exactly `k` **inverse pairs**. Since the answer can be huge, return it **modulo** `109 + 7`.

 

**Example 1:**

```
Input: n = 3, k = 0
Output: 1
Explanation: Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0 inverse pairs.
```

**Example 2:**

```
Input: n = 3, k = 1
Output: 2
Explanation: The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.
```

 

**Constraints:**

- `1 <= n <= 1000`
- `0 <= k <= 1000`

## Solution

``` cpp
const int MOD = 1e9 + 7;
int values[1001][1001] = {};
const int SZ = 1000;
void init(int N) {
  values[0][0] = 1;
  for(int i = 1; i <= N; ++i) {
    int nextJ = i * (i + 1) / 2;
    int J = i * (i - 1) / 2;
    J = J > SZ ? SZ : J;
    nextJ = nextJ > SZ ? SZ : nextJ;
    for(int j = 0; j <= J; ++j) {
      values[i][j] = (j ? values[i][j - 1] : 0) + values[i - 1][j] - (i > j ? 0 : values[i - 1][j - i]);
      values[i][j] = (values[i][j] % MOD + MOD) % MOD;
    }
    for(int j = J + 1; j <= nextJ; ++j) {
      values[i][j] = values[i][j - 1];
    }
  }
}

class Solution {
public:
  int kInversePairs(int n, int k) {
    if(!k) return 1;
    init(n);
    int answer = values[n][k] - values[n][k - 1];
    answer = (answer % MOD + MOD) % MOD;
    return answer;
  }
};

// Accepted
// 80/80 cases passed (159 ms)
// Your runtime beats 17.95 % of cpp submissions
// Your memory usage beats 89.74 % of cpp submissions (9.9 MB)
```
