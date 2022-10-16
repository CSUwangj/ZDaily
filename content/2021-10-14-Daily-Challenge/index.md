+++
title = "2021-10-14 Daily-Challenge"
path = "2021-10-14-Daily-Challenge"
date = 2021-10-14 19:40:34+08:00
updated = 2021-10-14 19:44:35+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/perfect-squares/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 14

## Description

**Perfect Squares**

Given an integer `n`, return *the least number of perfect square numbers that sum to* `n`.

A **perfect square** is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, `1`, `4`, `9`, and `16` are perfect squares while `3` and `11` are not.

 

**Example 1:**

```
Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
```

**Example 2:**

```
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
```

 

**Constraints:**

- `1 <= n <= 104`

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
int answer[10001];
auto _ = [](){
  for(int i = 1; i < 10001; ++i) {
    answer[i] = INT_MAX;
    int bound = sqrt(i);
    for(int j = 1; j <= bound; ++j) {
      answer[i] = min(answer[i], answer[i - j * j] + 1);
    }
  }
  return 0;
}();
class Solution {
public:
  int numSquares(int n) {
    return answer[n];
  }
};

// Accepted
// 588/588 cases passed (2 ms)
// Your runtime beats 96.2 % of cpp submissions
// Your memory usage beats 82.23 % of cpp submissions (6.1 MB)
```
