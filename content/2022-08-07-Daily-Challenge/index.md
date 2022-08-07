+++
updated = 2022-08-07 18:14:00+08:00
title = "2022-08-07 Daily-Challenge"
path = "2022-08-07-Daily-Challenge"
date = 2022-08-07 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/count-vowels-permutation/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 7

## Description

**Count Vowels Permutation**

Given an integer `n`, your task is to count how many strings of length `n` can be formed under the following rules:

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
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
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

// Accepted
// 43/43 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 93.61 % of cpp submissions (5.9 MB)
```
