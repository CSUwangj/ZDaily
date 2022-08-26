+++
updated = 2022-08-26 18:14:00+08:00
title = "2022-08-26 Daily-Challenge"
path = "2022-08-26-Daily-Challenge"
date = 2022-08-26 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/reordered-power-of-2/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 26

## Description

**Reordered Power of 2**

You are given an integer `n`. We reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return `true` *if and only if we can do this so that the resulting number is a power of two*.

 

**Example 1:**

```
Input: n = 1
Output: true
```

**Example 2:**

```
Input: n = 10
Output: false
```

 

**Constraints:**

- `1 <= n <= 10^9`

## Solution

``` cpp
const set<string> st = {"011237","0122579","012356789","0124","0134449","0145678","01466788","0248","0368888","0469","1","112234778","11266777","122446","125","128","1289","13468","16","2","224588","23","23334455","234455668","23678","256","35566","4","46","8"};
class Solution {
public:
  bool reorderedPowerOf2(int N) {
    string n = to_string(N);
    sort(n.begin(), n.end());
    return st.count(n);
  }
};

// Accepted
// 136/136 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 83.9 % of cpp submissions (6 MB)
```
