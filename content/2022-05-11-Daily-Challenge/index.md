+++
updated = 2022-05-11 17:21:00+08:00
title = "2022-05-11 Daily-Challenge"
path = "2022-05-11-Daily-Challenge"
date = 2022-05-11 17:20:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/count-sorted-vowel-strings/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 11

## Description

**Count Sorted Vowel Strings**

Given an integer `n`, return *the number of strings of length* `n` *that consist only of vowels (*`a`*,* `e`*,* `i`*,* `o`*,* `u`*) and are **lexicographically sorted**.*

A string `s` is **lexicographically sorted** if for all valid `i`, `s[i]` is the same as or comes before `s[i+1]` in the alphabet.

 

**Example 1:**

```
Input: n = 1
Output: 5
Explanation: The 5 sorted strings that consist of vowels only are ["a","e","i","o","u"].
```

**Example 2:**

```
Input: n = 2
Output: 15
Explanation: The 15 sorted strings that consist of vowels only are
["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.
```

**Example 3:**

```
Input: n = 33
Output: 66045
```

 

**Constraints:**

- `1 <= n <= 50` 

## Solution

``` cpp
class Solution {
public:
  int countVowelStrings(int n) {
    int dp[5] = {1, 1, 1, 1, 1};
    for(int i = 1; i < n; ++i) {
      for(int j = 1; j < 5; ++j) dp[j] += dp[j-1];
    }
    int answer = 0;
    for(int i = 0; i < 5; ++i) answer += dp[i];
    return answer;
  }
};

// Accepted
// 41/41 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 85.48 % of cpp submissions (5.8 MB)
```
