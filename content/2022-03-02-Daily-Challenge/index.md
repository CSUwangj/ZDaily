+++
title = "2022-03-02 Daily-Challenge"
path = "2022-03-02-Daily-Challenge"
date = 2022-03-02 18:00:00+08:00
updated = 2022-03-02 18:01:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/is-subsequence/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 2

## Description

**Is Subsequence**

Given two strings `s` and `t`, return `true` *if* `s` *is a **subsequence** of* `t`*, or* `false` *otherwise*.

A **subsequence** of a string is a new string that is  formed from the original string by deleting some (can be none) of the  characters without disturbing the relative positions of the remaining  characters. (i.e., `"ace"` is a subsequence of `"abcde"` while `"aec"` is not).

 

**Example 1:**

```
Input: s = "abc", t = "ahbgdc"
Output: true
```

**Example 2:**

```
Input: s = "axc", t = "ahbgdc"
Output: false
```

 

**Constraints:**

- `0 <= s.length <= 100`
- `0 <= t.length <= 10^4`
- `s` and `t` consist only of lowercase English letters.

 

**Follow up:** Suppose there are lots of incoming `s`, say `s1, s2, ..., sk` where `k >= 109`, and you want to check one by one to see if `t` has its subsequence. In this scenario, how would you change your code?

## Solution

``` cpp
class Solution {
public:
  bool isSubsequence(string s, string t) {
    int sLen = s.length();
    int tLen = t.length();
    if(sLen > tLen) return false;
    int sPos = 0;
    int tPos = 0;
    while(sPos < sLen && tPos < tLen) {
      if(s[sPos] == t[tPos]) {
        sPos += 1;
      }
      tPos += 1;
    }
    return sPos == sLen;
  }
};

// Accepted
// 17/17 cases passed (2 ms)
// Your runtime beats 52.38 % of cpp submissions
// Your memory usage beats 72.95 % of cpp submissions (6.4 MB)
```
