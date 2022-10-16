+++
updated = 2022-06-20 18:14:00+08:00
title = "2022-06-20 Daily-Challenge"
path = "2022-06-20-Daily-Challenge"
date = 2022-06-20 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/short-encoding-of-words/submissions/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 20

## Description

**Short Encoding of Words**

A **valid encoding** of an array of `words` is any reference string `s` and array of indices `indices` such that:

- `words.length == indices.length`
- The reference string `s` ends with the `'#'` character.
- For each index `indices[i]`, the **substring** of `s` starting from `indices[i]` and up to (but not including) the next `'#'` character is equal to `words[i]`.

Given an array of `words`, return *the **length of the shortest reference string*** `s` *possible of any **valid encoding** of* `words`*.*

 

**Example 1:**

```
Input: words = ["time", "me", "bell"]
Output: 10
Explanation: A valid encoding would be s = "time#bell#" and indices = [0, 2, 5].
words[0] = "time", the substring of s starting from indices[0] = 0 to the next '#' is underlined in "time#bell#"
words[1] = "me", the substring of s starting from indices[1] = 2 to the next '#' is underlined in "time#bell#"
words[2] = "bell", the substring of s starting from indices[2] = 5 to the next '#' is underlined in "time#bell#"
```

**Example 2:**

```
Input: words = ["t"]
Output: 2
Explanation: A valid encoding would be s = "t#" and indices = [0].
```

 

**Constraints:**

- `1 <= words.length <= 2000`
- `1 <= words[i].length <= 7`
- `words[i]` consists of only lowercase letters.

## Solution

``` cpp
class Solution {
public:
  int minimumLengthEncoding(vector<string>& words) {
    for(auto &word : words) reverse(word.begin(), word.end());
    sort(words.begin(), words.end());
    int answer = 0;
    int len = words.size();
    for(int i = 0; i < len; ++i) {
      bool unique = true;
      if(i < len - 1 && words[i + 1].rfind(words[i], 0) == 0) unique = false;
      if(unique) answer += words[i].length() + 1;
    }
    return answer;
  }
};

// Accepted
// 36/36 cases passed (50 ms)
// Your runtime beats 93.14 % of cpp submissions
// Your memory usage beats 94.12 % of cpp submissions (13.8 MB)
```
