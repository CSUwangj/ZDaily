+++
updated = 2022-04-01 18:55:00+08:00
title = "2022-04-01 Daily-Challenge"
path = "2022-04-01-Daily-Challenge"
date = 2022-04-01 18:53:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/reverse-string/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 31

## Description

**Reverse String**

Write a function that reverses a string. The input string is given as an array of characters `s`.

You must do this by modifying the input array [in-place](https://en.wikipedia.org/wiki/In-place_algorithm) with `O(1)` extra memory.

 

**Example 1:**

```
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
```

**Example 2:**

```
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
```

 

**Constraints:**

- `1 <= s.length <= 10^5`
- `s[i]` is a [printable ascii character](https://en.wikipedia.org/wiki/ASCII#Printable_characters).

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
  void reverseString(vector<char>& s) {
    int len = s.size();
    for(int i = 0; i * 2 < len; ++i) {
      swap(s[i], s[len - 1 - i]);
    }
  }
};

// Accepted
// 477/477 cases passed (20 ms)
// Your runtime beats 89.9 % of cpp submissions
// Your memory usage beats 41.72 % of cpp submissions (23.3 MB)
```
