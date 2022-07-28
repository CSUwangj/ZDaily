+++
updated = 2022-07-28 18:14:00+08:00
title = "2022-07-28 Daily-Challenge"
path = "2022-07-28-Daily-Challenge"
date = 2022-07-28 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/valid-anagram/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 28

## Description

**Valid Anagram**

Given two strings `s` and `t`, return `true` *if* `t` *is an anagram of* `s`*, and* `false` *otherwise*.

An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the  original letters exactly once.

 

**Example 1:**

```
Input: s = "anagram", t = "nagaram"
Output: true
```

**Example 2:**

```
Input: s = "rat", t = "car"
Output: false
```

 

**Constraints:**

- `1 <= s.length, t.length <= 5 * 104`
- `s` and `t` consist of lowercase English letters.

 

**Follow up:** What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

## Solution

``` cpp
class Solution {
public:
  bool isAnagram(string s, string t) {
    vector<int> sc(26);
    vector<int> tc(26);
    for(auto c : s) sc[c - 'a'] += 1;
    for(auto c : t) tc[c - 'a'] += 1;
    return sc == tc;
  }
};

// Accepted
// 36/36 cases passed (5 ms)
// Your runtime beats 92.06 % of cpp submissions
// Your memory usage beats 7.79 % of cpp submissions (7.4 MB)
```
