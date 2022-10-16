+++
updated = 2022-03-13 16:02:00+08:00
title = "2022-03-13 Daily-Challenge"
path = "2022-03-13-Daily-Challenge"
date = 2022-03-13 16:00:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/valid-parentheses/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 13

## Description

**Valid Parentheses**

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.

 

**Example 1:**

```
Input: s = "()"
Output: true
```

**Example 2:**

```
Input: s = "()[]{}"
Output: true
```

**Example 3:**

```
Input: s = "(]"
Output: false
```

 

**Constraints:**

- `1 <= s.length <= 10^4`
- `s` consists of parentheses only `'()[]{}'`.

## Solution

``` cpp
class Solution {
public:
  bool isValid(string s) {
    vector<char> st;
    for(auto c : s) {
      switch(c) {
        case '(':
        case '[':
        case '{':
          st.push_back(c);
          break;
        case ')':
          if(st.empty() || st.back() != '(') {
            return false;
          }
          st.pop_back();
          break;
        case ']':
          if(st.empty() || st.back() != '[') {
            return false;
          }
          st.pop_back();
          break;
        case '}':
          if(st.empty() || st.back() != '{') {
            return false;
          }
          st.pop_back();
          break;
        default:
          return false;
      }
    }
    return st.empty();
  }
};

// Accepted
// 91/91 cases passed (5 ms)
// Your runtime beats 18.36 % of cpp submissions
// Your memory usage beats 51.5 % of cpp submissions (6.3 MB)
```
