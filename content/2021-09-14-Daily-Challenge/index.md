+++
title = "2021-09-14 Daily-Challenge"
path = "2021-09-14-Daily-Challenge"
date = 2021-09-14 18:00:00+08:00
updated = 2021-09-14 18:04:55+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/637/week-2-september-8th-september-14th/3974/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 14

## Description

**Reverse Only Letters**

Given a string `s`, reverse the string according to the following rules:

- All the characters that are not English letters remain in the same position.
- All the English letters (lowercase or uppercase) should be reversed.

Return `s` *after reversing it*.

 

**Example 1:**

```
Input: s = "ab-cd"
Output: "dc-ba"
```

**Example 2:**

```
Input: s = "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
```

**Example 3:**

```
Input: s = "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"
```

 

**Constraints:**

- `1 <= s.length <= 100`
- `s` consists of characters with ASCII values in the range `[33, 122]`.
- `s` does not contain `'\"'` or `'\\'`.

## Solution

``` cpp
class Solution {
public:
  string reverseOnlyLetters(string s) {
    int begin = 0;
    int end = s.length() - 1;
    while(begin < end) {
      while(begin < end && !isalpha(s[begin])) begin += 1;
      while(begin < end && !isalpha(s[end])) end -= 1;
      if(begin < end) swap(s[begin], s[end]);
      begin += 1;
      end -= 1;
    }
    return s;
  }
};

// Accepted
// 115/115 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 65.04 % of cpp submissions (6 MB)
```
