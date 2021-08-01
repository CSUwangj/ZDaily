+++
title = "2021-06-11 Daily-Challenge"
path = "2021-06-11-Daily-Challenge"
date = 2021-06-11 17:44:33+08:00
updated = 2021-06-11 23:47:23+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Scramble String](https://leetcode.com/problems/scramble-string/description/) and leetcode's [June LeetCoding Challenge](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/603/week-1-june-1st-june-7th/3775/) with `cpp`.

<!-- more -->

# Scramble String

## Description

We can scramble a string s to get a string t using the following algorithm:

1. If the length of the string is 1, stop.
2. If the length of the string is > 1, do the following:
   - Split the string into two non-empty substrings at a random index, i.e., if the string is `s`, divide it to `x` and `y` where `s = x + y`.
   - **Randomly** decide to swap the two substrings or to keep them in the same order. i.e., after this step, `s` may become `s = x + y` or `s = y + x`.
   - Apply step 1 recursively on each of the two substrings `x` and `y`.

Given two strings `s1` and `s2` of **the same length**, return `true` if `s2` is a scrambled string of `s1`, otherwise, return `false`.

 

**Example 1:**

```
Input: s1 = "great", s2 = "rgeat"
Output: true
Explanation: One possible scenario applied on s1 is:
"great" --> "gr/eat" // divide at random index.
"gr/eat" --> "gr/eat" // random decision is not to swap the two substrings and keep them in order.
"gr/eat" --> "g/r / e/at" // apply the same algorithm recursively on both substrings. divide at ranom index each of them.
"g/r / e/at" --> "r/g / e/at" // random decision was to swap the first substring and to keep the second substring in the same order.
"r/g / e/at" --> "r/g / e/ a/t" // again apply the algorithm recursively, divide "at" to "a/t".
"r/g / e/ a/t" --> "r/g / e/ a/t" // random decision is to keep both substrings in the same order.
The algorithm stops now and the result string is "rgeat" which is s2.
As there is one possible scenario that led s1 to be scrambled to s2, we return true.
```

**Example 2:**

```
Input: s1 = "abcde", s2 = "caebd"
Output: false
```

**Example 3:**

```
Input: s1 = "a", s2 = "a"
Output: true
```

 

**Constraints:**

- `s1.length == s2.length`
- `1 <= s1.length <= 30`
- `s1` and `s2` consist of lower-case English letters.

## Solution

just try divide strings into four parts where front part of s1 have the same characters as front part of s2 or back part of s2 and recursively check.

``` cpp
unordered_map<char, int> cnta;
unordered_map<char, int> cntb;
bool test(string &a, string &b, int sa, int ea, int sb, int eb) {
  // cout << a << ' ' << b << ' ' << sa << ' ' << ea << ' ' << sb << ' ' << eb << endl;
  cnta.clear();
  cntb.clear();
  int len = ea - sa;
  bool ok = true;
  for(int i = 0; i < len; ++i) {
    ok &= a[sa + i] == b[sb + i];
    cnta[a[sa + i]] += 1;
    cntb[b[sb + i]] += 1;
  }
  if(ok) return true;
  if(cnta != cntb) return false;
  cnta.clear();
  cntb.clear();
  int begin = -1;
  for(int i = 0; i < len - 1; ++i) {
    cnta[a[sa + i]] += 1;
    cntb[b[sb + i]] += 1;
    if(cnta == cntb) begin = i;
  }
  begin += 1;
  if(begin) return test(a, b, sa, sa + begin, sb, sb + begin) && test(a, b, sa + begin, ea, sb + begin, eb);
  int end = -1;
  cnta.clear();
  cntb.clear();
  for(int i = 0; i < len - 1; ++i) {
    cnta[a[sa + i]] += 1;
    cntb[b[eb - 1 - i]] += 1;
    if(cnta == cntb) end = i;
  }
  end += 1;
  if(end) return test(a, b, sa, sa + end, eb - end, eb) && test(a, b, sa + end, ea, sb, sb + len - end);
  return false;
}

class Solution {
public:
  bool isScramble(string a, string b) {
    int len1 = a.length();
    int len2 = b.length();
    if(len1 != len2) return false;
    return test(a, b, 0, len1, 0, len2);
  }
};
```

# June LeetCoding Challenge 11

## Description

**Stone Game VII**

Alice and Bob take turns playing a game, with **Alice starting first**.

There are `n` stones arranged in a row. On each player's turn, they can **remove** either the leftmost stone or the rightmost stone from the row and receive points equal to the **sum** of the remaining stones' values in the row. The winner is the one with the higher score when there are no stones left to remove.

Bob found that he will always lose this game (poor Bob, he always loses), so he decided to **minimize the score's difference**. Alice's goal is to **maximize the difference** in the score.

Given an array of integers `stones` where `stones[i]` represents the value of the `ith` stone **from the left**, return *the **difference** in Alice and Bob's score if they both play **optimally**.*

 

**Example 1:**

```
Input: stones = [5,3,1,4,2]
Output: 6
Explanation: 
- Alice removes 2 and gets 5 + 3 + 1 + 4 = 13 points. Alice = 13, Bob = 0, stones = [5,3,1,4].
- Bob removes 5 and gets 3 + 1 + 4 = 8 points. Alice = 13, Bob = 8, stones = [3,1,4].
- Alice removes 3 and gets 1 + 4 = 5 points. Alice = 18, Bob = 8, stones = [1,4].
- Bob removes 1 and gets 4 points. Alice = 18, Bob = 12, stones = [4].
- Alice removes 4 and gets 0 points. Alice = 18, Bob = 12, stones = [].
The score difference is 18 - 12 = 6.
```

**Example 2:**

```
Input: stones = [7,90,5,1,100,10,10,2]
Output: 122
```

 

**Constraints:**

- `n == stones.length`
- `2 <= n <= 1000`
- `1 <= stones[i] <= 1000`

## Solution

I thought it was `Hard`

follow strategy towards `Game Theory` type, start from scratch and choose optimal steps. because we don't know where to start, so we use two-dimension dynamic programming enumerate all path

``` cpp
class Solution {
public:
  int stoneGameVII(vector<int>& stones) {
    int len = stones.size();
    int prefix[len + 1];
    prefix[0] = 0;
    for (int i = 0; i < len; ++i) prefix[i + 1] = prefix[i] + stones[i];
    int dp[len + 1][len + 1][2];
    memset(dp, 0, sizeof(dp));
    for (int i = 2; i <= len; ++i) {
      bool parity = i & 1;
      for(int j = 0; j + i <= len; ++j) {
        if(prefix[j + i] - prefix[j + 1] + dp[j + 1][j + i][parity] - dp[j + 1][j + i][!parity] >
           prefix[j + i - 1] - prefix[j] + dp[j][j + i - 1][parity] - dp[j][j + i - 1][!parity]) {
          dp[j][j + i][parity] = prefix[j + i] - prefix[j + 1] + dp[j + 1][j + i][parity];
          dp[j][j + i][!parity] = dp[j + 1][j + i][!parity];
        } else {
          dp[j][j + i][parity] = prefix[j + i - 1] - prefix[j] + dp[j][j + i - 1][parity];
          dp[j][j + i][!parity] = dp[j][j + i - 1][!parity];
        }
      }
    }
    return abs(dp[0][len][0] - dp[0][len][1]);
  }
};
```
