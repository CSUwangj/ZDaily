+++
title = "2022-02-11 Daily-Challenge"
path = "2022-02-11-Daily-Challenge"
date = 2022-02-11 18:25:00+08:00
updated = 2022-02-11 18:27:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/permutation-in-string/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 11

## Description

**Permutation in String**

Given two strings `s1` and `s2`, return `true` *if* `s2` *contains a permutation of* `s1`*, or* `false` *otherwise*.

In other words, return `true` if one of `s1`'s permutations is the substring of `s2`.

 

**Example 1:**

```
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
```

**Example 2:**

```
Input: s1 = "ab", s2 = "eidboaoo"
Output: false
```

 

**Constraints:**

- `1 <= s1.length, s2.length <= 10^4`
- `s1` and `s2` consist of lowercase English letters.

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    bool checkInclusion(string p, string s) {
    int sLen = s.length();
    int pLen = p.length();
    if(sLen < pLen) return false;
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
      if(current == target) return true;
      current[s[i] - 'a'] += 1;
      current[s[i - pLen] - 'a'] -= 1;
    }
    if(current == target) return true;
    return false;
  }
};

// Accepted
// 106/106 cases passed (8 ms)
// Your runtime beats 77.01 % of cpp submissions
// Your memory usage beats 89.63 % of cpp submissions (7.2 MB)
```
