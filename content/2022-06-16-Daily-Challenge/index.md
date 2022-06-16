+++
updated = 2022-06-16 18:14:00+08:00
title = "2022-06-16 Daily-Challenge"
path = "2022-06-16-Daily-Challenge"
date = 2022-06-16 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/longest-palindromic-substring/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 16

## Description

**Longest Palindromic Substring**

Given a string `s`, return *the longest palindromic substring* in `s`.

 

**Example 1:**

```
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
```

**Example 2:**

```
Input: s = "cbbd"
Output: "bb"
```

 

**Constraints:**

- `1 <= s.length <= 1000`
- `s` consist of only digits and English letters.

## Solution

``` cpp
class Solution {
public:
  string longestPalindrome(string s) {
    int len = s.length();
    int answer = 1;
    int begin = 0;
    for(int i = 0; i < len; ++i) {
      int left = i, right = i;
      while(left > 0 && right < len && s[left-1] == s[right]) {
        left -= 1;
        right += 1;
      }
      if(right - left > answer) {
        answer = right - left;
        begin = left;
      }
      left = i, right = i;
      while(left >= 0 && right < len && s[left] == s[right]) {
        left -= 1;
        right += 1;
      }
      if(right - left - 1 > answer) {
        answer = right - left - 1;
        begin = left + 1;
      }
      
    }
    return s.substr(begin, answer);
  }
};

// Accepted
// 180/180 cases passed (34 ms)
// Your runtime beats 76.7 % of cpp submissions
// Your memory usage beats 81.58 % of cpp submissions (7.2 MB)
```
