+++
updated = 2022-06-14 18:14:00+08:00
title = "2022-06-14 Daily-Challenge"
path = "2022-06-14-Daily-Challenge"
date = 2022-06-14 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/delete-operation-for-two-strings/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 14

## Description

**Delete Operation for Two Strings**

Given two strings `word1` and `word2`, return *the minimum number of **steps** required to make* `word1` *and* `word2` *the same*.

In one **step**, you can delete exactly one character in either string.

 

**Example 1:**

```
Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
```

**Example 2:**

```
Input: word1 = "leetcode", word2 = "etco"
Output: 4
```

 

**Constraints:**

- `1 <= word1.length, word2.length <= 500`
- `word1` and `word2` consist of only lowercase English letters.

## Solution

``` cpp
class Solution {
  int LCS(string &s1, string &s2) {
    int len1 = s1.length();
    int len2 = s2.length();
    int dp[2][len2 + 1];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < len1; ++i) {
      for(int j = 1; j <= len2; ++j) {
        int parity = i & 1;
        dp[parity][j] = max(dp[!parity][j], dp[parity][j - 1]);
        if(s2[j - 1] == s1[i]) {
          dp[parity][j] = max(dp[parity][j], dp[!parity][j - 1] + 1);
        }
      }
    }
    return dp[!(len1 & 1)][len2];
  }
public:
  int minDistance(string s1, string s2) {
    return s1.length() + s2.length() - LCS(s1, s2) * 2;
  }
};

// Accepted
// 1306/1306 cases passed (17 ms)
// Your runtime beats 77.81 % of cpp submissions
// Your memory usage beats 99.74 % of cpp submissions (6.4 MB)
```
