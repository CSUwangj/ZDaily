+++
updated = 2022-04-02 16:18:00+08:00
title = "2022-04-02 Daily-Challenge"
path = "2022-04-02-Daily-Challenge"
date = 2022-04-02 16:09:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/reverse-string/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 2

## Description

**Valid Palindrome II**

Given a string `s`, return `true` *if the* `s` *can be palindrome after deleting **at most one** character from it*.

 

**Example 1:**

```
Input: s = "aba"
Output: true
```

**Example 2:**

```
Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
```

**Example 3:**

```
Input: s = "abc"
Output: false
```

 

**Constraints:**

- `1 <= s.length <= 10^5`
- `s` consists of lowercase English letters.

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  bool validPalindrome(const string &s, int left, int right, int del = 1) {
    if(left >= right) return true;
    if(s[left] == s[right]) return validPalindrome(s, left + 1, right - 1, del);
    if(del) return validPalindrome(s, left, right - 1, 0) || validPalindrome(s, left + 1, right, 0);
    return false;
  }
public:
  bool validPalindrome(string s) {
    int len = s.length();
    return validPalindrome(s, 0, len - 1);
  }
};

// Accepted
// 467/467 cases passed (36 ms)
// Your runtime beats 99.67 % of cpp submissions
// Your memory usage beats 87.28 % of cpp submissions (19.5 MB)
```
