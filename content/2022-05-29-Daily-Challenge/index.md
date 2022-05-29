+++
updated = 2022-05-29 18:14:00+08:00
title = "2022-05-29 Daily-Challenge"
path = "2022-05-29-Daily-Challenge"
date = 2022-05-29 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/maximum-product-of-word-lengths/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 29

## Description

**Maximum Product of Word Lengths**

​	Given a string array `words`, return *the maximum value of* `length(word[i]) * length(word[j])` *where the two words do not share common letters*. If no such two words exist, return `0`.

 

**Example 1:**

```
Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16
Explanation: The two words can be "abcw", "xtfn".
```

**Example 2:**

```
Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
Output: 4
Explanation: The two words can be "ab", "cd".
```

**Example 3:**

```
Input: words = ["a","aa","aaa","aaaa"]
Output: 0
Explanation: No such pair of words.
```

 

**Constraints:**

- `2 <= words.length <= 1000`
- `1 <= words[i].length <= 1000`
- `words[i]` consists only of lowercase English letters.

## Solution

``` cpp
class Solution {
public:
  int maxProduct(vector<string>& words) {
    int sz = words.size();
    vector<int> mask(sz);
    vector<int> len(sz);
    for(int i = 0; i < sz; ++i) {
      for(auto c : words[i]) mask[i] |= (1 << (c - 'a'));
      len[i] = words[i].length();
    }
    int answer = 0;
    for(int i = 0; i < sz - 1; ++i) {
      for(int j = i + 1; j < sz; ++j) {
        if(!(mask[i] & mask[j])) answer = max(answer, len[i] * len[j]);
      }
    }
    return answer;
  }
};

// Accepted
// 167/167 cases passed (62 ms)
// Your runtime beats 67.22 % of cpp submissions
// Your memory usage beats 59.25 % of cpp submissions (15.8 MB)
```
