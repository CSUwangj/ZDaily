+++
title = "2021-06-19 Daily-Challenge"
path = "2021-06-19-Daily-Challenge"
date = 2021-06-19 03:23:57+08:00
updated = 2021-06-19 23:53:44+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [June LeetCoding Challenge](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/605/week-3-june-15th-june-21st/3784/) with `cpp`.

<!-- more -->

# LeetCode Review

## Range Sum Query - Mutable

too easy to review

## Number of Subarrays with Bounded Maximum

too easy to review

## Generate Parentheses

too easy to review

## Matchsticks to Square

``` cpp
class Solution {
  int len;
  int target;
  int sides[4] = {};
  bool solve(vector<int> &m, int index) {
    if(index == len) return true;
    for(int i = 0; i < 4; ++i) {
      if([&](){
        for(int j = 0; j < i; ++j) {
          if(sides[j] == sides[i]) return true;
        }
        return false;
      }()) continue;
      if(sides[i] + m[index] > target) continue;
      sides[i] += m[index];
      if(solve(m, index + 1)) return true;
      sides[i] -= m[index];
    }
    return false;
  }
public:
  bool makesquare(vector<int>& matchsticks) {
    len = matchsticks.size();
    if(len < 4) return false;
    sort(matchsticks.rbegin(), matchsticks.rend());
    int sum = 0;
    for(auto l : matchsticks) sum += l;
    if(sum % 4 || matchsticks.back() > sum / 4) return false;
    target = sum / 4;
    return solve(matchsticks, 0); 
  }
};
```

## Maximum Units on a Truck

too easy to review

## Sort Integers by The Number of 1 Bits

too easy to review

## Cells with Odd Values in a Matrix

too easy but review

``` cpp
using ll = long long;

const ll M1 = 0X5555555555555555;
const ll M2 = 0X3333333333333333;
const ll M4 = 0X0F0F0F0F0F0F0F0F;
const ll M8 = 0X00FF00FF00FF00FF;
const ll M16 = 0X0000FFFF0000FFFF;
const ll M32 = 0X00000000FFFFFFFF;

inline constexpr ll popcount(ll X) {
  X = (X & M1) + ((X >> 1) & M1);
  X = (X & M2) + ((X >> 2) & M2);
  X = (X & M4) + ((X >> 4) & M4);
  X = (X & M8) + ((X >> 8) & M8);
  X = (X & M16) + ((X >> 16) & M16);
  X = (X & M32) + ((X >> 32) & M32);
  return X;
}

class Solution {
public:
  int oddCells(int m, int n, vector<vector<int>>& indices) {
    ll row = 0;
    ll col = 0;
    for(auto &index : indices) {
      row ^= (1LL << index[0]);
      col ^= (1LL << index[1]);
    }
    int oddRows = popcount(row);
    int evenRows = m - oddRows;

    int answer = 0;
    for(int i = 0; i < n; i++) {
      if(col & (1LL << i)) answer += evenRows;
      else answer += oddRows;
    }
    return answer;
  }
};
```

## Distribute Coins in Binary Tree

too easy to review

## Search in a Binary Search Tree

too easy to review

## Preimage Size of Factorial Zeroes Function

too easy to review

# June LeetCoding Challenge 19

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

we use `dp[i][j]` represents states which means amount of `permutations of 1-i` have exactly `j` inverse pairs. then we can conclude state transition formula:

$$dp[i][j]=\sum\limits_{j'=max(0, j-i)}^{j} dp[i-1][j']$$

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
```
