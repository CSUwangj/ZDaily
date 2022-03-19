+++
updated = 2022-03-18 20:39:00+08:00
title = "2022-03-18 Daily-Challenge"
path = "2022-03-18-Daily-Challenge"
date = 2022-03-18 20:25:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/remove-duplicate-letters/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 18

## Description

**Remove Duplicate Letters**

Given a string `s`, remove duplicate letters so that every letter appears once and only once. You must make sure your result is **the smallest in lexicographical order** among all possible results.

 

**Example 1:**

```
Input: s = "bcabc"
Output: "abc"
```

**Example 2:**

```
Input: s = "cbacdcbc"
Output: "acdb"
```

 

**Constraints:**

- `1 <= s.length <= 10^4`
- `s` consists of lowercase English letters.

 

**Note:** This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

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
  string removeDuplicateLetters(string s) {
    vector<int> cnt(26);
    vector<int> used(26);
    for(auto c : s) {
      cnt[c - 'a'] += 1;
    }

    string answer;
    for(auto c : s) {
      if(used[c - 'a']) {
        cnt[c - 'a'] -= 1;
        continue;
      }
      while(answer.length() && answer.back() > c && cnt[answer.back() - 'a']) {
        used[answer.back() - 'a'] = false;
        answer.pop_back();
      }
      answer.push_back(c);
      used[c - 'a'] = true;
      cnt[c - 'a'] -= 1;
    }
    return answer;
  }
};

// Accepted
// 289/289 cases passed (4 ms)
// Your runtime beats 61.69 % of cpp submissions
// Your memory usage beats 66.29 % of cpp submissions (6.6 MB)
```
