+++
title = "2021-12-18 Daily-Challenge"
path = "2021-12-18-Daily-Challenge"
date = 2021-12-18 16:43:00+08:00
updated = 2021-12-18 18:07:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/numbers-at-most-n-given-digit-set/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 18

## Description

**Numbers At Most N Given Digit Set**

Given an array of `digits` which is sorted in **non-decreasing** order. You can write numbers using each `digits[i]` as many times as we want. For example, if `digits = ['1','3','5']`, we may write numbers such as `'13'`, `'551'`, and `'1351315'`.

Return *the number of positive integers that can be generated* that are less than or equal to a given integer `n`.

 

**Example 1:**

```
Input: digits = ["1","3","5","7"], n = 100
Output: 20
Explanation: 
The 20 numbers that can be written are:
1, 3, 5, 7, 11, 13, 15, 17, 31, 33, 35, 37, 51, 53, 55, 57, 71, 73, 75, 77.
```

**Example 2:**

```
Input: digits = ["1","4","9"], n = 1000000000
Output: 29523
Explanation: 
We can write 3 one digit numbers, 9 two digit numbers, 27 three digit numbers,
81 four digit numbers, 243 five digit numbers, 729 six digit numbers,
2187 seven digit numbers, 6561 eight digit numbers, and 19683 nine digit numbers.
In total, this is 29523 integers that can be written using the digits array.
```

**Example 3:**

```
Input: digits = ["7"], n = 8
Output: 1
```

 

**Constraints:**

- `1 <= digits.length <= 9`
- `digits[i].length == 1`
- `digits[i]` is a digit from `'1'` to `'9'`.
- All the values in `digits` are **unique**.
- `digits` is sorted in **non-decreasing** order.
- `1 <= n <= 10^9`

## Solution

``` cpp
#define MOD 1000000007
class Solution {
  int dp[11][10] = {};
  int nDigits[11] = {};
  bool digits[10] = {};
public:
  int atMostNGivenDigitSet(vector<string>& ds, int n) {
    for(auto &d : ds) {
      digits[d[0] - '0'] = true;
    }
    int nLen = floor(log10(n)) + 1;
    for(int i = 1; i <= nLen; ++i) {
      nDigits[i] = n % 10;
      n /= 10;
    }
    dp[0][9] = 1;
    for(int i = 1; i <= nLen; ++i) {
      for(int j = 1; j < 10; ++j) {
        dp[i][j] = dp[i][j - 1];
        if(digits[j]) {
          dp[i][j] += dp[i - 1][9];
          dp[i][j] %= MOD;
        }
      }
    }
    int answer = 0;
    for(int i = 1; i < nLen; ++i) {
      answer += dp[i][9];
    }
    for(int i = nLen; i ; --i) {
      if(!nDigits[i]) break;
      answer += dp[1][nDigits[i] - 1] * dp[i - 1][9];
      if(!digits[nDigits[i]]) break;
    }
    bool consN = true;
    for(int i = 1; i <= nLen; ++i) {
      if(!digits[nDigits[i]]) consN = false;
    }
    answer += consN;
    return answer;
  }
};

// Accepted
// 84/84 cases passed (0 ms)
// Your runtime beats 100.0 % of cpp submissions
// Your memory usage beats 22.22 % of cpp submissions (8.3 MB)
```
