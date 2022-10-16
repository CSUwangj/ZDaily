+++
updated = 2022-08-09 18:14:00+08:00
title = "2022-08-09 Daily-Challenge"
path = "2022-08-09-Daily-Challenge"
date = 2022-08-09 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/binary-trees-with-factors/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 9

## Description

**Binary Trees With Factors**

Given an array of unique integers, `arr`, where each integer `arr[i]` is strictly greater than `1`.

We make a binary tree using these integers, and each number may be  used for any number of times. Each non-leaf node's value should be equal to the product of the values of its children.

Return *the number of binary trees we can make*. The answer may be too large so return the answer **modulo** `10^9 + 7`.

 

**Example 1:**

```
Input: arr = [2,4]
Output: 3
Explanation: We can make these trees: [2], [4], [4, 2, 2]
```

**Example 2:**

```
Input: arr = [2,4,5,10]
Output: 7
Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].
```

 

**Constraints:**

- `1 <= arr.length <= 1000`
- `2 <= arr[i] <= 10^9`
- All the values of `arr` are **unique**.

## Solution

``` cpp
const int MOD = 1e9 + 7;
class Solution {
public:
  int numFactoredBinaryTrees(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int len = arr.size();
    vector<int> count(len, 1);
    for(int i = 1; i < len; ++i) {
      for(int j = 0; arr[i] / arr[j] >= arr[j]; ++j) {
        if(arr[i] % arr[j]) continue;
        int pos = lower_bound(arr.begin(), arr.end(), arr[i] / arr[j]) - arr.begin();
        if(arr[i] / arr[j] != arr[pos]) continue;
        count[i] += (2LL - (arr[j] == arr[pos])) * count[j] * count[pos] % MOD;
        count[i] %= MOD;
      }
    }
    
    int answer = accumulate(count.begin(), count.end(), 0, [](int prev, int cur) {
      return (prev + cur) % MOD;
    });
    return answer;
  }
};

// Accepted
// 48/48 cases passed (67 ms)
// Your runtime beats 90.15 % of cpp submissions
// Your memory usage beats 99.08 % of cpp submissions (8.3 MB)
```
