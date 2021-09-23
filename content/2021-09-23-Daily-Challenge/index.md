+++
title = "2021-09-23 Daily-Challenge"
path = "2021-09-23-Daily-Challenge"
date = 2021-09-23 19:13:15+08:00
updated = 2021-09-23 19:17:07+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/639/week-4-september-22nd-september-28th/3985/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 23

## Description

**Break a Palindrome**

Given a palindromic string of lowercase English letters `palindrome`, replace **exactly one** character with any lowercase English letter so that the resulting string is **not** a palindrome and that it is the **lexicographically smallest** one possible.

Return *the resulting string. If there is no way to replace a character to make it not a palindrome, return an **empty string**.*

A string `a` is lexicographically smaller than a string `b` (of the same length) if in the first position where `a` and `b` differ, `a` has a character strictly smaller than the corresponding character in `b`. For example, `"abcc"` is lexicographically smaller than `"abcd"` because the first position they differ is at the fourth character, and `'c'` is smaller than `'d'`.

 

**Example 1:**

```
Input: palindrome = "abccba"
Output: "aaccba"
Explanation: There are many ways to make "abccba" not a palindrome, such as "zbccba", "aaccba", and "abacba".
Of all the ways, "aaccba" is the lexicographically smallest.
```

**Example 2:**

```
Input: palindrome = "a"
Output: ""
Explanation: There is no way to replace a single character to make "a" not a palindrome, so return an empty string.
```

**Example 3:**

```
Input: palindrome = "aa"
Output: "ab"
```

**Example 4:**

```
Input: palindrome = "aba"
Output: "abb"
```

 

**Constraints:**

- `1 <= palindrome.length <= 1000`
- `palindrome` consists of only lowercase English letters.

## Solution

``` cpp
class Solution {
public:
  string breakPalindrome(string palindrome) {
    int len = palindrome.length();
    if(len == 1) return "";
    for(int i = 0; i * 2 + 1 < len; ++i) {
      if(palindrome[i] != 'a') {
        palindrome[i] = 'a';
        return palindrome;
      }
    }
    palindrome.back() = 'b';
    return palindrome;
  }
};

// Accepted
// 30/30 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 45.58 % of cpp submissions (6.2 MB)
```
