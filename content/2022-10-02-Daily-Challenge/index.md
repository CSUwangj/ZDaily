+++
updated = 2022-10-02 18:14:00+08:00
title = "2022-10-02 Daily-Challenge"
path = "2022-10-02-Daily-Challenge"
date = 2022-10-02 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 2

## Description

**Number of Dice Rolls With Target Sum**

You have `n` dice and each die has `k` faces numbered from `1` to `k`.

Given three integers `n`, `k`, and `target`, return *the number of possible ways (out of the* `kn` *total ways)* *to roll the dice so the sum of the face-up numbers equals* `target`. Since the answer may be too large, return it **modulo** `109 + 7`.

 

**Example 1:**

```
Input: n = 1, k = 6, target = 3
Output: 1
Explanation: You throw one die with 6 faces.
There is only one way to get a sum of 3.
```

**Example 2:**

```
Input: n = 2, k = 6, target = 7
Output: 6
Explanation: You throw two dice, each with 6 faces.
There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
```

**Example 3:**

```
Input: n = 30, k = 30, target = 500
Output: 222616187
Explanation: The answer must be returned modulo 109 + 7.
```

 

**Constraints:**

- `1 <= n, k <= 30`
- `1 <= target <= 1000`

## Solution

``` cpp
int dp[2][1001];
const int MOD = 1e9 + 7;
class Solution {
public:
  int numRollsToTarget(int d, int f, int target) {
    if(d * f < target || d > target) return 0;
    if(d == target) return 1;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i <= d; ++i) {
      int parity = i & 1;
      for(int j = 0; j < i; ++j) {
        dp[parity][j] = 0;
      }
      for(int j = i; j <= i * f; ++j) {
        dp[parity][j] = 0;
        for(int k = 1; k <= f; ++k) {
          if(j - k < 0) continue;
          dp[parity][j] += dp[!parity][j - k];
          dp[parity][j] %= MOD;
        }
      }
      // for(int j = 0; j <= i * f; ++j) {
      //   cout << dp[parity][j] << ' ';
      // }
      // cout << endl;
    }
    return dp[d & 1][target];
  }
};

// Accepted
// 65/65 cases passed (0 ms)
// Your runtime beats 100.00 % of cpp submissions
// Your memory usage beats 99.60 % of cpp submissions (5.9 MB)
```
