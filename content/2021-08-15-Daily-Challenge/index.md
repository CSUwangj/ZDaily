+++
title = "2021-08-15 Daily-Challenge"
path = "2021-08-15-Daily-Challenge"
date = 2021-08-15 20:00:03+08:00
updated = 2021-08-15 20:14:04+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I gonna review the tasks I've done this week, and finish today's leetcode's [August LeetCoding Challenge](https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/615/week-3-august-15th-august-21st/3891/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 15

## Description

**Minimum Window Substring**

Given two strings `s` and `t` of lengths `m` and `n` respectively, return *the **minimum window substring** of* `s` *such that every character in* `t` *(**including duplicates**) is included in the window. If there is no such substring**, return the empty string* `""`*.*

The testcases will be generated such that the answer is **unique**.

A **substring** is a contiguous sequence of characters within the string.

 

**Example 1:**

```
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
```

**Example 2:**

```
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
```

**Example 3:**

```
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
```

 

**Constraints:**

- `m == s.length`
- `n == t.length`
- `1 <= m, n <= 10^5`
- `s` and `t` consist of uppercase and lowercase English letters.

 

**Follow up:** Could you find an algorithm that runs in `O(m + n)` time?

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  int cnt[128] = {};
public:
  string minWindow(string s, string t) {
    int chars = 0;
    for(auto c : t) {
      chars += !cnt[c];
      cnt[c] += 1;
    }
    int end = 0;
    int sLen = s.length();
    while(end < sLen && chars) {
      cnt[s[end]] -= 1;
      chars -= !cnt[s[end]];
      end += 1;
    }
    if(chars) return "";
    int resultLen = INT_MAX;
    int resultBegin = 0;
    for(int begin = 0; begin < end; ++begin) {
      if(end - begin < resultLen) {
        resultLen = end - begin;
        resultBegin = begin;
      }
      cnt[s[begin]] += 1;
      while(end < sLen && cnt[s[begin]] > 0) {
        cnt[s[end]] -= 1;
        end += 1;
      }
      if(cnt[s[begin]] > 0) break;
    }
    return s.substr(resultBegin, resultLen);
  }
};

// Accepted
// 266/266 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 80.15 % of cpp submissions (7.7 MB)
```