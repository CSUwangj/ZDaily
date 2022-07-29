+++
updated = 2022-07-29 18:14:00+08:00
title = "2022-07-29 Daily-Challenge"
path = "2022-07-29-Daily-Challenge"
date = 2022-07-29 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/find-and-replace-pattern/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 29

## Description

**Find and Replace Pattern**

Given a list of strings `words` and a string `pattern`, return *a list of* `words[i]` *that match* `pattern`. You may return the answer in **any order**.

A word matches the pattern if there exists a permutation of letters `p` so that after replacing every letter `x` in the pattern with `p(x)`, we get the desired word.

Recall that a permutation of letters is a bijection from letters to  letters: every letter maps to another letter, and no two letters map to  the same letter.

 

**Example 1:**

```
Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.
```

**Example 2:**

```
Input: words = ["a","b","c"], pattern = "a"
Output: ["a","b","c"]
```

 

**Constraints:**

- `1 <= pattern.length <= 20`
- `1 <= words.length <= 50`
- `words[i].length == pattern.length`
- `pattern` and `words[i]` are lowercase English letters.

## Solution

``` cpp
string unify(string s) {
  char mp[26] = {};
  int cnt = 0;
  for(auto &c : s) {
    if(!mp[c - 'a']) {
      mp[c - 'a'] = 'a' + cnt;
      cnt += 1;
    }
    c = mp[c - 'a'];
  }
  return s;
}
class Solution {
public:
  vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    vector<string> answer;
    pattern = unify(pattern);
    for(auto &word : words) {
      if(unify(word) == pattern) answer.push_back(word);
    }
    return answer;
  }
};

// Accepted
// 47/47 cases passed (10 ms)
// Your runtime beats 28.33 % of cpp submissions
// Your memory usage beats 98.2 % of cpp submissions (7.7 MB)
```
