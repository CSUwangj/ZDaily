+++
title = "2021-12-19 Daily-Challenge"
path = "2021-12-19-Daily-Challenge"
date = 2021-12-19 14:50:00+08:00
updated = 2021-12-19 14:57:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/numbers-at-most-n-given-digit-set/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 19

## Description

**Decode String**

Given an encoded string, return its decoded string.

The encoding rule is: `k[encoded_string]`, where the `encoded_string` inside the square brackets is being repeated exactly `k` times. Note that `k` is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, `k`. For example, there won't be input like `3a` or `2[4]`.

 

**Example 1:**

```
Input: s = "3[a]2[bc]"
Output: "aaabcbc"
```

**Example 2:**

```
Input: s = "3[a2[c]]"
Output: "accaccacc"
```

**Example 3:**

```
Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
```

**Example 4:**

```
Input: s = "abc3[cd]xyz"
Output: "abccdcdcdxyz"
```

 

**Constraints:**

- `1 <= s.length <= 30`
- `s` consists of lowercase English letters, digits, and square brackets `'[]'`.
- `s` is guaranteed to be **a valid** input.
- All the integers in `s` are in the range `[1, 300]`.

## Solution

``` cpp
class Solution {
  int len;
  string decode(string &s, int &pos) {
    string result;
    while(pos < len) {
      if(islower(s[pos])) {
        result.push_back(s[pos]);
      } else if(isdigit(s[pos])) {
        int repeat = 0;
        while(isdigit(s[pos])) {
          repeat *= 10;
          repeat += s[pos] - '0';
          pos += 1;
        }
        pos += 1;
        string repeatS = decode(s, pos);
        while(repeat--) {
          result += repeatS;
        }
      } else if(s[pos] == ']') {
        return result;
      }
      pos += 1;
    }
    return result;
  }
public:
  string decodeString(string s) {
    len = s.length();
    int pos = 0;
    return decode(s, pos);
  }
};

// Accepted
// 34/34 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 90.28 % of cpp submissions (6.4 MB)
```
