+++
title = "2021-07-04 Daily-Challenge"
path = "2021-07-04-Daily-Challenge"
date = 2021-07-04 15:20:19+08:00
updated = 2021-07-04 15:57:59+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I gonna review the tasks I've done this week, and finish today's leetcode's [July LeetCoding Challenge](https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/608/week-1-july-1st-july-7th/3802/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 4

## Description

**Count Vowels Permutation**

GGiven an integer `n`, your task is to count how many strings of length `n` can be formed under the following rules:

- Each character is a lower case vowel (`'a'`, `'e'`, `'i'`, `'o'`, `'u'`)
- Each vowel `'a'` may only be followed by an `'e'`.
- Each vowel `'e'` may only be followed by an `'a'` or an `'i'`.
- Each vowel `'i'` **may not** be followed by another `'i'`.
- Each vowel `'o'` may only be followed by an `'i'` or a `'u'`.
- Each vowel `'u'` may only be followed by an `'a'.`

Since the answer may be too large, return it modulo `10^9 + 7.`

 

**Example 1:**

```
Input: n = 1
Output: 5
Explanation: All possible strings are: "a", "e", "i" , "o" and "u".
```

**Example 2:**

```
Input: n = 2
Output: 10
Explanation: All possible strings are: "ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" and "ua".
```

**Example 3:** 

```
Input: n = 5
Output: 68
```

 

**Constraints:**

- `1 <= n <= 2 * 10^4`

## Solution

``` cpp
int dp[2][5];
const int MOD = 1e9 + 7;
class Solution {
public:
  int countVowelPermutation(int n) {
    for(int i = 0; i < 5; ++i) dp[1][i] = 1;
    for(int l = 2; l <= n; ++l) {
      int parity = l & 1;
      dp[parity][3] = dp[!parity][2];
      dp[parity][4] = (dp[!parity][2] + dp[!parity][3]) % MOD;
      dp[parity][1] = (dp[!parity][2] + dp[!parity][0]) % MOD;
      dp[parity][0] = (dp[!parity][1] + dp[!parity][4]) % MOD;
      dp[parity][0] = (dp[parity][0] + dp[!parity][2]) % MOD;
      dp[parity][2] = (dp[!parity][3] + dp[!parity][1]) % MOD;
    }

    int answer = 0;
    for(int v = 0; v < 5; ++v) {
      answer += dp[n & 1][v];
      answer %= MOD;
    }
    return answer;
  }
};
```

``` cpp
int dp[2][5];
const int MOD = 1e9 + 7;
class Solution {
public:
  int countVowelPermutation(int n) {
    for(int i = 0; i < 5; ++i) dp[1][i] = 1;
    for(int l = 1; l <= n; ++l) {
      int parity = l & 1;
      for(int v = 0; v < 5; ++v) {
        dp[!parity][v] = 0;
      }
      dp[!parity][1] = (dp[!parity][1] + dp[parity][0]) % MOD;
      dp[!parity][0] = (dp[!parity][0] + dp[parity][1]) % MOD;
      dp[!parity][2] = (dp[!parity][2] + dp[parity][1]) % MOD;
      dp[!parity][2] = (dp[!parity][2] + dp[parity][3]) % MOD;
      dp[!parity][4] = (dp[!parity][4] + dp[parity][3]) % MOD;
      dp[!parity][0] = (dp[!parity][0] + dp[parity][4]) % MOD;
      for(int v = 0; v < 5; ++v) {
        if(v == 2) continue;
        dp[!parity][v] = (dp[!parity][v] + dp[parity][2]) % MOD;
      }
    }

    int answer = 0;
    for(int v = 0; v < 5; ++v) {
      answer += dp[n & 1][v];
      answer %= MOD;
    }
    return answer;
  }
};
```
