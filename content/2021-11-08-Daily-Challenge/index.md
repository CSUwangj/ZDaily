+++
title = "2021-11-08 Daily-Challenge"
path = "2021-11-08-Daily-Challenge"
date = 2021-11-08 20:08:13+08:00
updated = 2021-11-08 20:18:21+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/unique-binary-search-trees) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 8

## Description

**Unique Binary Search Trees**

Given an integer `n`, return *the number of structurally unique **BST'**s (binary search trees) which has exactly* `n` *nodes of unique values from* `1` *to* `n`.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/01/18/uniquebstn3.jpg)

```
Input: n = 3
Output: 5
```

**Example 2:**

```
Input: n = 1
Output: 1
```

 

**Constraints:**

- `1 <= n <= 19`

## Solution

``` cpp
constexpr auto result = []{
  array<int, 20> arr{1, 1};
  for(int i = 2; i < 20; ++i) {
    for(int j = 0; j < i; ++j) {
      arr[i] += arr[j] * arr[i - j - 1];
    }
  }
  return arr;
}();
class Solution {
public:
  int numTrees(int n) {
    return result[n];
  }
};

// Accepted
// 19/19 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 64.16 % of cpp submissions (5.9 MB)
```
