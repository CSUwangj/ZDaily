+++
updated = 2022-07-07 18:14:00+08:00
title = "2022-07-07 Daily-Challenge"
path = "2022-07-07-Daily-Challenge"
date = 2022-07-07 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/interleaving-string/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 7

## Description

**Interleaving String**

Given strings `s1`, `s2`, and `s3`, find whether `s3` is formed by an **interleaving** of `s1` and `s2`.

An **interleaving** of two strings `s` and `t` is a configuration where they are divided into **non-empty** substrings such that:

- `s = s1 + s2 + ... + sn`
- `t = t1 + t2 + ... + tm`
- `|n - m| <= 1`
- The **interleaving** is `s1 + t1 + s2 + t2 + s3 + t3 + ...` or `t1 + s1 + t2 + s2 + t3 + s3 + ...`

**Note:** `a + b` is the concatenation of strings `a` and `b`.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/09/02/interleave.jpg)

```
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
```

**Example 2:**

```
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
```

**Example 3:**

```
Input: s1 = "", s2 = "", s3 = ""
Output: true
```

 

**Constraints:**

- `0 <= s1.length, s2.length <= 100`
- `0 <= s3.length <= 200`
- `s1`, `s2`, and `s3` consist of lowercase English letters.

 

**Follow up:** Could you solve it using only `O(s2.length)` additional memory space?

## Solution

``` cpp
class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    int len1 = s1.length();
    int len2 = s2.length();
    int len3 = s3.length();
    if(len1 + len2 != len3) return false;
    bool dp[len2 + 1];
    for(int i = 0; i <= len1; ++i) {
      for(int j = 0; j <= len2; ++j) {
        if(!i && !j) {
          dp[j] = true;
        } else if(!i) {
          dp[j] = dp[j - 1] && (s2[j - 1] == s3[i + j - 1]);
        } else if(!j) {
          dp[j] = dp[j] && (s1[i - 1] == s3[i + j - 1]);
        } else {
          dp[j] = (dp[j - 1] && (s2[j - 1] == s3[i + j - 1])) ||
                  (dp[j] && (s1[i - 1] == s3[i + j - 1]));
        }
      }
    }
    return dp[len2];
  }
};

// Accepted
// 106/106 cases passed (8 ms)
// Your runtime beats 51.77 % of cpp submissions
// Your memory usage beats 89.89 % of cpp submissions (6.2 MB)
```
