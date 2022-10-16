+++
updated = 2022-08-25 18:14:00+08:00
title = "2022-08-25 Daily-Challenge"
path = "2022-08-25-Daily-Challenge"
date = 2022-08-25 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/ransom-note/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 25

## Description

**Ransom Note**

Given two strings `ransomNote` and `magazine`, return `true` *if* `ransomNote` *can be constructed by using the letters from* `magazine` *and* `false` *otherwise*.

Each letter in `magazine` can only be used once in `ransomNote`.

 

**Example 1:**

```
Input: ransomNote = "a", magazine = "b"
Output: false
```

**Example 2:**

```
Input: ransomNote = "aa", magazine = "ab"
Output: false
```

**Example 3:**

```
Input: ransomNote = "aa", magazine = "aab"
Output: true
```

 

**Constraints:**

- `1 <= ransomNote.length, magazine.length <= 10^5`
- `ransomNote` and `magazine` consist of lowercase English letters.

## Solution

``` cpp
class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    int cnt[26] = {};
    for(auto c : magazine) {
      cnt[c - 'a'] += 1;
    }
    for(auto c : ransomNote) {
      cnt[c - 'a'] -= 1;
    }
    return *min_element(cnt, cnt + 26) >= 0;
  }
};

// Accepted
// 127/127 cases passed (10 ms)
// Your runtime beats 95.81 % of cpp submissions
// Your memory usage beats 97.37 % of cpp submissions (8.6 MB)
```
