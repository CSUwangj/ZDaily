+++
title = "2022-01-17 Daily-Challenge"
path = "2022-01-17-Daily-Challenge"
date = 2022-01-17 19:05:00+08:00
updated = 2022-01-17 19:07:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/word-pattern/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 17

## Description

**Word Pattern**

Given a `pattern` and a string `s`, find if `s` follows the same pattern.

Here **follow** means a full match, such that there is a bijection between a letter in `pattern` and a **non-empty** word in `s`.

 

**Example 1:**

```
Input: pattern = "abba", s = "dog cat cat dog"
Output: true
```

**Example 2:**

```
Input: pattern = "abba", s = "dog cat cat fish"
Output: false
```

**Example 3:**

```
Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
```

 

**Constraints:**

- `1 <= pattern.length <= 300`
- `pattern` contains only lower-case English letters.
- `1 <= s.length <= 3000`
- `s` contains only lowercase English letters and spaces `' '`.
- `s` **does not contain** any leading or trailing spaces.
- All the words in `s` are separated by a **single space**.

## Solution

``` cpp
class Solution {
  int countWords(string &s) {
    bool isSpace = true;
    int result = 0;
    for(auto c : s) {
      result += (c != ' ') * isSpace;
      isSpace = c == ' ';
    }
    return result;
  }
  string nextWord(string &s, int &index) {
    while(s[index] == ' ') index += 1;
    int len = 0;
    while(index + len < s.length() && s[index + len] != ' ') len += 1;
    index += len;
    return s.substr(index - len, len);
  }
public:
  bool wordPattern(string pattern, string s) {
    if(pattern.length() != countWords(s)) return false;
    unordered_map<char, string> mp;
    unordered_map<string, int> cnt;
    int pos = 0;
    for(auto c : pattern) {
      auto word = nextWord(s, pos);
      if(mp.count(c) && mp[c] != word) return false;
      if(!mp.count(c)){
        mp[c] = word;
        cnt[word] += 1;
      } 
    }
    for(auto [_word, c] : cnt) if(c > 1) return false;
    return true;
  }
};

// Accepted
// 36/36 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 82.42 % of cpp submissions (6.3 MB)
```
