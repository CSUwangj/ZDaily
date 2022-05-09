+++
updated = 2022-05-09 16:35:00+08:00
title = "2022-05-09 Daily-Challenge"
path = "2022-05-09-Daily-Challenge"
date = 2022-05-09 16:33:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/letter-combinations-of-a-phone-number/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 9

## Description

**Letter Combinations of a Phone Number**

Given a string containing digits from `2-9` inclusive, return all possible letter combinations that the number could represent. Return the answer in **any order**.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

![img](https://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png)

 

**Example 1:**

```
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

**Example 2:**

```
Input: digits = ""
Output: []
```

**Example 3:**

```
Input: digits = "2"
Output: ["a","b","c"]
```

 

**Constraints:**

- `0 <= digits.length <= 4`
- `digits[i]` is a digit in the range `['2', '9']`.

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
  vector<string> letterCombinations(string digits) {
    if(digits.empty()) return vector<string>();
    vector<string> mp = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> nxt;
    vector<string> current{""};
    for(auto c : digits) {
      for(auto &s : current) {
        for(auto letter : mp[c-'2']) {
          nxt.push_back(s+letter);
        }
      }
      current = nxt;
      nxt.clear();
    }
    return current;
  }
};

// Accepted
// 25/25 cases passed (4 ms)
// Your runtime beats 26.23 % of cpp submissions
// Your memory usage beats 35.85 % of cpp submissions (6.6 MB)
```
