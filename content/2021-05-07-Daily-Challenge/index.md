+++
title = "2021-05-07 Daily-Challenge"
path = "2021-05-07-Daily-Challenge"
date = 2021-05-07 18:00:24+08:00
updated = 2021-05-07 19:11:07+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Reverse Words in a String III](https://leetcode.com/problems/reverse-words-in-a-string-iii/) and leetcode's [May LeetCoding Challenge](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3734/) with `cpp`.

<!-- more -->

# Reverse Words in a String III

## Description

Given a string `s`, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

 

**Example 1:**

```
Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
```

**Example 2:**

```
Input: s = "God Ding"
Output: "doG gniD"
```

 

**Constraints:**

- `1 <= s.length <= 5 * 10^4`
- `s` contains printable **ASCII** characters.
- `s` does not contain any leading or trailing spaces.
- There is **at least one** word in `s`.
- All the words in `s` are separated by a single space.


## Solution

``` cpp
class Solution {
public:
  string reverseWords(string s) {
    bool isSpace = true;
    int start = -1;
    for (int i = 0; i < s.length(); ++i) {
      if(isSpace && s[i] != ' ') {
        start = i;
      } else if(!isSpace && s[i] == ' ') {
        reverse(s.begin() + start, s.begin() + i);
      }
      isSpace = s[i] == ' ';
    }
    if(!isSpace) reverse(s.begin() + start, s.end());
    return s;
  }
};
```

# May LeetCoding Challenge 7

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

done before

``` cpp
class Solution {
  int LCS(string &s1, string &s2) {
    int len1 = s1.length();
    int len2 = s2.length();
    vector<vector<int>> dp(2, vector<int>(len2 + 1));
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
```
