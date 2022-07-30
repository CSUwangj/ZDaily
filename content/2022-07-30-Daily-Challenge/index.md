+++
updated = 2022-07-30 18:14:00+08:00
title = "2022-07-30 Daily-Challenge"
path = "2022-07-30-Daily-Challenge"
date = 2022-07-30 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/word-subsets/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 30

## Description

**Word Subsets**

You are given two string arrays `words1` and `words2`.

A string `b` is a **subset** of string `a` if every letter in `b` occurs in `a` including multiplicity.

- For example, `"wrr"` is a subset of `"warrior"` but is not a subset of `"world"`.

A string `a` from `words1` is **universal** if for every string `b` in `words2`, `b` is a subset of `a`.

Return an array of all the **universal** strings in `words1`. You may return the answer in **any order**.

 

**Example 1:**

```
Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
Output: ["facebook","google","leetcode"]
```

**Example 2:**

```
Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["l","e"]
Output: ["apple","google","leetcode"]
```

 

**Constraints:**

- `1 <= words1.length, words2.length <= 10^4`
- `1 <= words1[i].length, words2[i].length <= 10`
- `words1[i]` and `words2[i]` consist only of lowercase English letters.
- All the strings of `words1` are **unique**.

## Solution

``` cpp
class Solution {
public:
  vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
    vector<int> count(26);
    for(auto &b : B) {
      vector<int> tmpCount(26);
      for(auto c : b) tmpCount[c - 'a'] += 1;
      for(int i = 0; i < 26; ++i) count[i] = max(count[i], tmpCount[i]);
    }
    
    vector<string> answer;
    for(auto &a : A) {
      vector<int> tmpCount(26);
      for(auto c : a) tmpCount[c - 'a'] += 1;
      bool universal = true;
      for(int i = 0; i < 26; ++i) universal &= tmpCount[i] >= count[i];
      if(universal) answer.push_back(a);
    }
    return answer;
  }
};

// Accepted
// 56/56 cases passed (282 ms)
// Your runtime beats 62.47 % of cpp submissions
// Your memory usage beats 65.17 % of cpp submissions (102.4 MB)
```
