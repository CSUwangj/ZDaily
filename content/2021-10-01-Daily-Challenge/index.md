+++
title = "2021-10-01 Daily-Challenge"
path = "2021-10-01-Daily-Challenge"
date = 2021-10-01 21:15:53+08:00
updated = 2021-10-01 22:53:38+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/longest-common-subsequence/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 1

## Description

**Longest Common Subsequence**

Given two strings `text1` and `text2`, return *the length of their longest **common subsequence**.* If there is no **common subsequence**, return `0`.

A **subsequence** of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

- For example, `"ace"` is a subsequence of `"abcde"`.

A **common subsequence** of two strings is a subsequence that is common to both strings.

 

**Example 1:**

```
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
```

**Example 2:**

```
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
```

**Example 3:**

```
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
```

 

**Constraints:**

- `1 <= text1.length, text2.length <= 1000`
- `text1` and `text2` consist of only lowercase English characters.

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  int dp[2][1001] = {};
public:
  int longestCommonSubsequence(string text1, string text2) {
    int len1 = text1.length();
    int len2 = text2.length();
    for(int i = 0; i < len1; ++i) {
      int parity =  i & 1;
      for(int j = 0; j < len2; ++j) {
        dp[parity][j + 1] = max({dp[!parity][j + 1], dp[parity][j], dp[!parity][j] + (text1[i] == text2[j])});
      }
    }
    return dp[~len1 & 1][len2];
  }
};

// Accepted
// 44/44 cases passed (35 ms)
// Your runtime beats 20.16 % of cpp submissions
// Your memory usage beats 98.32 % of cpp submissions (6.4 MB)
```
