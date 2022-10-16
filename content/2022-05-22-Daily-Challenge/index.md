+++
updated = 2022-05-22 08:14:00+08:00
title = "2022-05-22 Daily-Challenge"
path = "2022-05-22-Daily-Challenge"
date = 2022-05-22 08:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/palindromic-substrings/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 22

## Description

**Palindromic Substrings**

Given a string `s`, return *the number of **palindromic substrings** in it*.

A string is a **palindrome** when it reads the same backward as forward.

A **substring** is a contiguous sequence of characters within the string.

 

**Example 1:**

```
Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
```

**Example 2:**

```
Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
```

 

**Constraints:**

- `1 <= s.length <= 1000`
- `s` consists of lowercase English letters.

## Solution

``` cpp
class Solution {
public:
  int countSubstrings(string s) {
    int dp[1001][1001] = {0};
    int len = s.length();
    int answer = len;
    for(int i = 0; i < len; ++i) {
      dp[i][i] = 1;
      dp[i][i + 1] = 1;
    }
    for(int l = 2; l <= len; ++l) {
      for(int j = 0; j + l <= len; ++j) {
        if(dp[j + 1][j + l - 1] && s[j] == s[j + l - 1]) {
          dp[j][j + l] = 1;
          answer += 1;
        }
      }
    }
    return answer;
  }
};

// Accepted
// 130/130 cases passed (35 ms)
// Your runtime beats 29.77 % of cpp submissions
// Your memory usage beats 35.24 % of cpp submissions (10.8 MB)
```
