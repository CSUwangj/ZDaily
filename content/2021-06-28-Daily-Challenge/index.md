+++
title = "2021-06-28 Daily-Challenge"
path = "2021-06-28-Daily-Challenge"
date = 2021-06-28 19:19:44+08:00
updated = 2021-06-28 20:00:52+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Number of Ways to Stay in the Same Place After Some Steps](https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/description/) and leetcode's [June LeetCoding Challenge](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/606/week-4-june-22nd-june-28th/3794/) with `cpp`.

<!-- more -->

# Number of Ways to Stay in the Same Place After Some Steps

## Description

You have a pointer at index `0` in an array of size `arrLen`. At each step, you can move 1 position to the left, 1 position to the right in the array, or stay in the same place (The pointer should not be placed outside the array at any time).

Given two integers `steps` and `arrLen`, return the number of ways such that your pointer still at index `0` after **exactly** `steps` steps. Since the answer may be too large, return it **modulo** `109 + 7`.

 

**Example 1:**

```
Input: steps = 3, arrLen = 2
Output: 4
Explanation: There are 4 differents ways to stay at index 0 after 3 steps.
Right, Left, Stay
Stay, Right, Left
Right, Stay, Left
Stay, Stay, Stay
```

**Example 2:**

```
Input: steps = 2, arrLen = 4
Output: 2
Explanation: There are 2 differents ways to stay at index 0 after 2 steps
Right, Left
Stay, Stay
```

**Example 3:**

```
Input: steps = 4, arrLen = 2
Output: 8
```

 

**Constraints:**

- `1 <= steps <= 500`
- `1 <= arrLen <= 10^6`

## Solution

``` cpp
const int MOD = 1e9 + 7;
int ways[2][500];
class Solution {
public:
  int numWays(int steps, int arrLen) {
    if(arrLen == 1) return 1;
    memset(ways, 0, sizeof(ways));
    ways[0][0] = 1;
    int boundary = min(arrLen, 500);
    for(int i = 1; i <= steps; ++i) {
      int parity = i & 1;
      ways[parity][0] = (ways[!parity][0] + ways[!parity][1]) % MOD;
      ways[parity][boundary - 1] = (ways[!parity][boundary - 1] + ways[!parity][boundary - 2]) % MOD;
      for(int j = 1; j < boundary - 1; ++j) {
        ways[parity][j] = ways[!parity][j - 1];
        ways[parity][j] += ways[!parity][j];
        ways[parity][j] %= MOD;
        ways[parity][j] += ways[!parity][j + 1];
        ways[parity][j] %= MOD;
      }
    }
    return ways[steps & 1][0];
  }
};
```

# June LeetCoding Challenge 28

## Description

**Remove All Adjacent Duplicates In String**

You are given a string `s` consisting of lowercase English letters. A **duplicate removal** consists of choosing two **adjacent** and **equal** letters and removing them.

We repeatedly make **duplicate removals** on `s` until we no longer can.

Return *the final string after all such duplicate removals have been made*. It can be proven that the answer is **unique**.

 

**Example 1:**

```
Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
```

**Example 2:**

```
Input: s = "azxxzy"
Output: "ay"
```

 

**Constraints:**

- `1 <= s.length <= 105`
- `s` consists of lowercase English letters.

## Solution

``` cpp
class Solution {
public:
  string removeDuplicates(string s) {
    string answer;
    for(auto c : s) {
      if(answer.length() && answer.back() == c) {
        answer.pop_back();
      } else {
        answer.push_back(c);
      }
    }
    return answer;
  }
};
```
