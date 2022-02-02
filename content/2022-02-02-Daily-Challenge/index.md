+++
title = "2022-02-02 Daily-Challenge"
path = "2022-02-02-Daily-Challenge"
date = 2022-02-02 13:50:00+08:00
updated = 2022-02-02 13:52:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/find-all-anagrams-in-a-string/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 2

## Description

**Find All Anagrams in a String**

Given two strings `s` and `p`, return *an array of all the start indices of* `p`*'s anagrams in* `s`. You may return the answer in **any order**.

An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the  original letters exactly once.

 

**Example 1:**

```
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
```

**Example 2:**

```
Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
```

 

**Constraints:**

- `1 <= s.length, p.length <= 3 * 10^4`
- `s` and `p` consist of lowercase English letters.

## Solution

``` cpp
class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    int sLen = s.length();
    int pLen = p.length();
    if(sLen < pLen) return {};
    vector<int> target(26);
    for(auto c : p) {
      target[c - 'a'] += 1;
    }
    vector<int> current(26);
    for(int i = 0; i < pLen; ++i) {
      current[s[i] - 'a'] += 1;
    }
    vector<int> answer;
    for(int i = pLen; i < sLen; ++i) {
      if(current == target) answer.push_back(i - pLen);
      current[s[i] - 'a'] += 1;
      current[s[i - pLen] - 'a'] -= 1;
    }
    if(current == target) answer.push_back(sLen - pLen);
    return answer;
  }
};

// Accepted
// 61/61 cases passed (8 ms)
// Your runtime beats 97.21 % of cpp submissions
// Your memory usage beats 90.96 % of cpp submissions (8.6 MB)
```
