+++
title = "2021-07-01 Daily-Challenge"
path = "2021-07-01-Daily-Challenge"
date = 2021-07-01 21:00:33+08:00
updated = 2021-07-01 21:27:17+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Number of Dice Rolls With Target Sum](https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/) and leetcode's [July LeetCoding Challenge](https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/608/week-1-july-1st-july-7th/3799/) with `cpp`.

<!-- more -->

# Number of Dice Rolls With Target Sum

## Description

You have `d` dice and each die has `f` faces numbered `1, 2, ..., f`.

Return the number of possible ways (out of `fd` total ways) **modulo** 109 + 7 to roll the dice so the sum of the face-up numbers equals `target`.

 

**Example 1:**

```
Input: d = 1, f = 6, target = 3
Output: 1
Explanation: 
You throw one die with 6 faces.  There is only one way to get a sum of 3.
```

**Example 2:**

```
Input: d = 2, f = 6, target = 7
Output: 6
Explanation: 
You throw two dice, each with 6 faces.  There are 6 ways to get a sum of 7:
1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
```

**Example 3:**

```
Input: d = 2, f = 5, target = 10
Output: 1
Explanation: 
You throw two dice, each with 5 faces.  There is only one way to get a sum of 10: 5+5.
```

**Example 4:**

```
Input: d = 1, f = 2, target = 3
Output: 0
Explanation: 
You throw one die with 2 faces.  There is no way to get a sum of 3.
```

**Example 5:**

```
Input: d = 30, f = 30, target = 500
Output: 222616187
Explanation: 
The answer must be returned modulo 10^9 + 7.
```

 

**Constraints:**

- `1 <= d, f <= 30`
- `1 <= target <= 1000`

## Solution

``` cpp
int dp[2][1001];
const int MOD = 1e9 + 7;
class Solution {
public:
  int numRollsToTarget(int d, int f, int target) {
    if(d * f < target || d > target) return 0;
    if(d == target) return 1;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i <= d; ++i) {
      int parity = i & 1;
      for(int j = 0; j < i; ++j) {
        dp[parity][j] = 0;
      }
      for(int j = i; j <= i * f; ++j) {
        dp[parity][j] = 0;
        for(int k = 1; k <= f; ++k) {
          if(j - k < 0) continue;
          dp[parity][j] += dp[!parity][j - k];
          dp[parity][j] %= MOD;
        }
      }
      // for(int j = 0; j <= i * f; ++j) {
      //   cout << dp[parity][j] << ' ';
      // }
      // cout << endl;
    }
    return dp[d & 1][target];
  }
};

// Accepted
// 65/65 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 99.15 % of cpp submissions (5.9 MB)
```

# August LeetCoding Challenge 1

## Description

**Gray Code**

An **n-bit gray code sequence** is a sequence of `2n` integers where:

- Every integer is in the **inclusive** range `[0, 2n - 1]`,
- The first integer is `0`,
- An integer appears **no more than once** in the sequence,
- The binary representation of every pair of **adjacent** integers differs by **exactly one bit**, and
- The binary representation of the **first** and **last** integers differs by **exactly one bit**.

Given an integer `n`, return *any valid **n-bit gray code sequence***.

 

**Example 1:**

```
Input: n = 2
Output: [0,1,3,2]
Explanation:
The binary representation of [0,1,3,2] is [00,01,11,10].
- 00 and 01 differ by one bit
- 01 and 11 differ by one bit
- 11 and 10 differ by one bit
- 10 and 00 differ by one bit
[0,2,3,1] is also a valid gray code sequence, whose binary representation is [00,10,11,01].
- 00 and 10 differ by one bit
- 10 and 11 differ by one bit
- 11 and 01 differ by one bit
- 01 and 00 differ by one bit
```

**Example 2:**

```
Input: n = 1
Output: [0,1]
```

 

**Constraints:**

- `1 <= n <= 16`

## Solution

``` cpp
class Solution {
public:
  vector<int> grayCode(int n) {
    int sz = 1 << n;
    vector<int> answer(sz);
    for(int i = 1; i <= n; ++i) {
      int bound = 1 << i;
      for(int j = 0; j * 2 < bound; ++j) {
        answer[bound - j - 1] = answer[j] | (bound >> 1);
      }
    }
    return answer;
  }
};
```

learn from wikipedia solution

``` cpp
constexpr inline int gray(int x) { 
  return x ^ (x >> 1);
}
class Solution {
public:
  vector<int> grayCode(int n) {
    int sz = 1 << n;
    vector<int> answer(sz);
    for(int i = 0; i < sz; ++i) {
      answer[i] = gray(i);
    }
    return answer;
  }
};
```
