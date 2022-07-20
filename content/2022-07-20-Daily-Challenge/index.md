+++
updated = 2022-07-20 18:14:00+08:00
title = "2022-07-20 Daily-Challenge"
path = "2022-07-20-Daily-Challenge"
date = 2022-07-20 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/number-of-matching-subsequences/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 20

## Description

**Number of Matching Subsequences**

Given a string `s` and an array of strings `words`, return *the number of* `words[i]` *that is a subsequence of* `s`.

A **subsequence** of a string is a new string generated  from the original string with some characters (can be none) deleted  without changing the relative order of the remaining characters.

- For example, `"ace"` is a subsequence of `"abcde"`.

 

**Example 1:**

```
Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
```

**Example 2:**

```
Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
Output: 2
```

 

**Constraints:**

- `1 <= s.length <= 5 * 10^4`
- `1 <= words.length <= 5000`
- `1 <= words[i].length <= 50`
- `s` and `words[i]` consist of only lowercase English letters.

## Solution

``` cpp
class Solution {
  bool isSubsequence(const vector<vector<int>> &pos, string &word) {
    int prev = -1;
    for(auto c : word) {
      int cha = c - 'a';
      int idx = upper_bound(pos[cha].begin(), pos[cha].end(), prev) - pos[cha].begin();
      if(idx == pos[cha].size()) return false;
      prev = pos[cha][idx];
    }
    return true;
  }
public:
  int numMatchingSubseq(string s, vector<string>& words) {
    vector<vector<int>> pos(26);
    for(int i = 0; i < s.length(); ++i) {
      pos[s[i] - 'a'].push_back(i);
    }
    int answer = 0;
    for(auto &word : words) {
      answer += isSubsequence(pos, word);
    }
    return answer;
  }
};

// Accepted
// 52/52 cases passed (225 ms)
// Your runtime beats 83.68 % of cpp submissions
// Your memory usage beats 70.32 % of cpp submissions (48.1 MB)
```
