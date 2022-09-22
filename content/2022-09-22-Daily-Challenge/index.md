+++
updated = 2022-09-22 18:14:00+08:00
title = "2022-09-22 Daily-Challenge"
path = "2022-09-22-Daily-Challenge"
date = 2022-09-22 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/reverse-words-in-a-string-iii/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 22

## Description

**Reverse Words in a String III**

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

// Accepted
// 29/29 cases passed (48 ms)
// Your runtime beats 16.64 % of cpp submissions
// Your memory usage beats 45.42 % of cpp submissions (9.7 MB)
```
