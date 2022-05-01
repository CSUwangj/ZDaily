+++
updated = 2022-05-01 18:58:00+08:00
title = "2022-05-01 Daily-Challenge"
path = "2022-05-01-Daily-Challenge"
date = 2022-05-01 18:57:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/backspace-string-compare/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 1

## Description

**Backspace String Compare**

Given two strings `s` and `t`, return `true` *if they are equal when both are typed into empty text editors*. `'#'` means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

 

**Example 1:**

```
Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
```

**Example 2:**

```
Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
```

**Example 3:**

```
Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
```

 

**Constraints:**

- `1 <= s.length, t.length <= 200`
- `s` and `t` only contain lowercase letters and `'#'` characters.

 

**Follow up:** Can you solve it in `O(n)` time and `O(1)` space?

## Solution

``` cpp
class Solution {
  char nextChar(const string &s, int &pos) {
    int backspace = 0;
    while(pos >= 0 && (backspace || s[pos] == '#')) {
      if(s[pos] == '#') {
        backspace += 1;
      } else {
        backspace -= 1;
      }
      pos -= 1;
    }
    if(pos < 0) return -1;
    return s[pos];
  }
public:
  bool backspaceCompare(string s, string t) {
    int sPos = s.length() - 1;
    int tPos = t.length() - 1;
    while(sPos >= 0 || tPos >= 0) {
      char cS = nextChar(s, sPos);
      char cT = nextChar(t, tPos);
      if(cS != cT) return false;
      sPos -= 1;
      tPos -= 1;
    }
    return true;
  }
};

// Accepted
// 114/114 cases passed (4 ms)
// Your runtime beats 27.99 % of cpp submissions
// Your memory usage beats 88.07 % of cpp submissions (6.1 MB)
```
