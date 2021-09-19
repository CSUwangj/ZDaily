+++
title = "2021-09-19 Daily-Challenge"
path = "2021-09-19-Daily-Challenge"
date = 2021-09-19 15:03:38+08:00
updated = 2021-09-19 15:06:44+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/638/week-3-september-15th-september-21st/3979/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 19

## Description

**Distinct Subsequences**

Given two strings `s` and `t`, return *the number of distinct subsequences of `s` which equals `t`*.

A string's **subsequence** is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the remaining characters' relative positions. (i.e., `"ACE"` is a subsequence of `"ABCDE"` while `"AEC"` is not).

It is guaranteed the answer fits on a 32-bit signed integer.

 

**Example 1:**

```
Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from S.
rabbbit
rabbbit
rabbbit
```

**Example 2:**

```
Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from S.
babgbag
babgbag
babgbag
babgbag
babgbag
```

 

**Constraints:**

- `1 <= s.length, t.length <= 1000`
- `s` and `t` consist of English letters.

## Solution

``` cpp
class Solution {
public:
  int numDistinct(string s, string t) {
    int slen = s.length();
    int tlen = t.length();
    if(slen <= tlen) return s == t;
    // answer fits on a 32-bit signed integer doesn't means
    // mid values fit
    vector<long long> dp(tlen+1);
    dp[0] = 1;
    for(int i = 0; i < slen; ++i) {
      int beginPos = max(1, tlen-slen+i);
      int endPos = min(tlen, i+slen-tlen+1);
      for(int j = endPos; j >= beginPos; --j) {
        if(s[i] == t[j-1]) dp[j] += dp[j-1];
      }
    }
    // dp(slen+1)(tlen+1)
    // for(int i = 0; i < slen; ++i) {
    //     for(int j = 1; j < tlen; ++j){
    //         dp[i][j] = dp[i-1][j];
    //         if(s[i]==t[j]) dp[i][j] += dp[i-1][j-1];
    //     }
    // }
    return dp.back();
  }
};

// Accepted
// 63/63 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 97.33 % of cpp submissions (6.4 MB)
```
