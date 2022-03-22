+++
updated = 2022-03-22 18:48:00+08:00
title = "2022-03-22 Daily-Challenge"
path = "2022-03-22-Daily-Challenge"
date = 2022-03-22 18:47:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 22

## Description

**Smallest String With A Given Numeric Value**

The **numeric value** of a **lowercase character** is defined as its position `(1-indexed)` in the alphabet, so the numeric value of `a` is `1`, the numeric value of `b` is `2`, the numeric value of `c` is `3`, and so on.

The **numeric value** of a **string**  consisting of lowercase characters is defined as the sum of its  characters' numeric values. For example, the numeric value of the string `"abe"` is equal to `1 + 2 + 5 = 8`.

You are given two integers `n` and `k`. Return *the **lexicographically smallest string** with **length** equal to `n` and **numeric value** equal to `k`.*

Note that a string `x` is lexicographically smaller than string `y` if `x` comes before `y` in dictionary order, that is, either `x` is a prefix of `y`, or if `i` is the first position such that `x[i] != y[i]`, then `x[i]` comes before `y[i]` in alphabetic order.

 

**Example 1:**

```
Input: n = 3, k = 27
Output: "aay"
Explanation: The numeric value of the string is 1 + 1 + 25 = 27, and it is the smallest string with such a value and length equal to 3.
```

**Example 2:**

```
Input: n = 5, k = 73
Output: "aaszz"
```

 

**Constraints:**

- `1 <= n <= 10^5`
- `n <= k <= 26 * n`


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  string getSmallestString(int n, int k) {
    int zs = max<int>(ceil((k - n) / 25.0) - 1, 0);
    k -= zs * 26;
    n -= zs;
    return string(n - 1, 'a') + string(1, 'a'+ k - n) + string(zs, 'z');
  }
};

// Accepted
// 93/93 cases passed (24 ms)
// Your runtime beats 98.47 % of cpp submissions
// Your memory usage beats 63.02 % of cpp submissions (26.5 MB)
```
