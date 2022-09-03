+++
updated = 2022-09-03 18:14:00+08:00
title = "2022-09-03 Daily-Challenge"
path = "2022-09-03-Daily-Challenge"
date = 2022-09-03 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/numbers-with-same-consecutive-differences/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 3

## Description

**Numbers With Same Consecutive Differences**

Return all **non-negative** integers of length `n` such that the absolute difference between every two consecutive digits is `k`.

Note that **every** number in the answer **must not** have leading zeros. For example, `01` has one leading zero and is invalid.

You may return the answer in **any order**.

 

**Example 1:**

```
Input: n = 3, k = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
```

**Example 2:**

```
Input: n = 2, k = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
```

 

**Constraints:**

- `2 <= n <= 9`
- `0 <= k <= 9`

## Solution

``` cpp
class Solution {
  void solve(
    vector<int> &answer,
    int current,
    int k,
    int rest
  ) {
    if(!rest) {
      answer.push_back(current);
      return;
    }
    if(current % 10 >= k) {
      solve(answer, current * 10 + current % 10 - k, k, rest - 1);
    }
    if(k && current % 10 + k < 10) {
      solve(answer, current * 10 + current % 10 + k, k, rest - 1);
    }
  }
public:
  vector<int> numsSameConsecDiff(int n, int k) {
    vector<int> answer;
    for(int i = 1; i < 10; ++i) {
      solve(answer, i, k, n - 1);
    }
    return answer;
  }
};

// Accepted
// 81/81 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 49.91 % of cpp submissions (8.7 MB)
```
