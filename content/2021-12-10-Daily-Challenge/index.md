+++
title = "2021-12-10 Daily-Challenge"
path = "2021-12-10-Daily-Challenge"
date = 2021-12-10 17:41:00+08:00
updated = 2021-12-10 17:56:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/domino-and-tromino-tiling/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 10

## Description

**Domino and Tromino Tiling**

You have two types of tiles: a `2 x 1` domino shape and a tromino shape. You may rotate these shapes.

![img](https://assets.leetcode.com/uploads/2021/07/15/lc-domino.jpg)

Given an integer n, return *the number of ways to tile an* `2 x n` *board*. Since the answer may be very large, return it **modulo** `109 + 7`.

In a tiling, every square must be covered by a tile. Two tilings are  different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares  occupied by a tile.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/07/15/lc-domino1.jpg)

```
Input: n = 3
Output: 5
Explanation: The five different ways are show above.
```

**Example 2:**

```
Input: n = 1
Output: 1
```

 

**Constraints:**

- `1 <= n <= 1000`

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
const int MOD = 1e9 + 7;
constexpr auto table = []{
  array<int, 1001> table{1, 1, 2};
  for(int i = 3; i < 1001; ++i) {
    table[i] = 2 * table[i - 1] % MOD + table[i - 3];
    table[i] %= MOD;
  }
  return table;
}();

class Solution {
public:
  int numTilings(int n) {
    return table[n];
  }
};

// Accepted
// 39/39 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 60.67 % of cpp submissions (6.1 MB)
```
