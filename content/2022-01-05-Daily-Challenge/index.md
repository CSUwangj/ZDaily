+++
title = "2022-01-05 Daily-Challenge"
path = "2022-01-05-Daily-Challenge"
date = 2022-01-05 18:43:00+08:00
updated = 2022-01-05 18:45:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/palindrome-partitioning/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 5

## Description

**Palindrome Partitioning**

Given a string `s`, partition `s` such that every substring of the partition is a **palindrome**. Return all possible palindrome partitioning of `s`.

A **palindrome** string is a string that reads the same backward as forward.

 

**Example 1:**

```
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
```

**Example 2:**

```
Input: s = "a"
Output: [["a"]]
```

 

**Constraints:**

- `1 <= s.length <= 16`
- `s` contains only lowercase English letters.

## Solution

``` cpp
class Solution {
  int len;
  vector<vector<bool>> isPalindrome;
  
  void init(string &s) {
    len = s.length();
    isPalindrome.resize(len+1, vector<bool>(len+1));
    for(int i = 0; i < len; ++i) {
      isPalindrome[i][i] = true;
      isPalindrome[i][i+1] = true;
    }
    for(int i = 2; i <= len; ++i) {
      for(int j = 0; j+i <= len; ++j) {
        isPalindrome[j][j+i] = isPalindrome[j+1][j+i-1] && (s[j] == s[j+i-1]);
      }
    }
  }
    
  void dfs(vector<vector<string>> &answer, vector<string> &container, string &s, int index) {
    if(index == len) {
      answer.push_back(container);
    }
    for(int i = 1; index+i <= len; ++i) {
      if(isPalindrome[index][index+i]) {
        container.push_back(s.substr(index, i));
        dfs(answer, container, s, index+i);
        container.pop_back();
      }
    }
  }
public:
  vector<vector<string>> partition(string s) {
    init(s);
    vector<vector<string>> answer;
    vector<string> container;
    dfs(answer, container, s, 0);
    return answer;
  }
};


// Accepted
// 32/32 cases passed (125 ms)
// Your runtime beats 51.96 % of cpp submissions
// Your memory usage beats 89.38 % of cpp submissions (49.2 MB)
```
