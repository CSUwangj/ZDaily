+++
title = "2022-01-24 Daily-Challenge"
path = "2022-01-24-Daily-Challenge"
date = 2022-01-24 17:59:00+08:00
updated = 2022-01-24 18:04:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/detect-capital/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 24

## Description

**Detect Capital**

- `word` consists of lowercase and uppercase English letters.

## Solution

``` cpp
class Solution {
public:
  bool detectCapitalUse(string word) {
    int count = 0;
    for(auto c : word) {
      count += !!isupper(c);
    }
    // int count = count_if(word.begin(), word.end(), isupper);
    return count == word.length() || count == 0 || (count == 1 && isupper(word.front()));
  }
};

// Accepted
// 550/550 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 67.65 % of cpp submissions (6 MB)
```
