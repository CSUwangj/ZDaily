+++
updated = 2022-06-10 18:14:00+08:00
title = "2022-06-10 Daily-Challenge"
path = "2022-06-10-Daily-Challenge"
date = 2022-06-10 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/longest-substring-without-repeating-characters/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 10

## Description

**Longest Substring Without Repeating Characters**

Given a string `s`, find the length of the **longest substring** without repeating characters.

 

**Example 1:**

```
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
```

**Example 2:**

```
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
```

**Example 3:**

```
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
```

 

**Constraints:**

- `0 <= s.length <= 5 * 10^4`
- `s` consists of English letters, digits, symbols and spaces.

## Solution

``` cpp
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    bool has[128] = {false};
    int head = 0, tail = 0;
    int answer = 0;
    int len = s.length();
    while(head < len) {
      if(!has[s[head]]) {
        has[s[head]] = true;
        ++head;
        answer = max(head-tail, answer);
      } else {
        while(has[s[head]]) {
          has[s[tail]] = false;
          ++tail;
        }
      }
    }
    return answer;
  }
};

// Accepted
// 987/987 cases passed (4 ms)
// Your runtime beats 96.63 % of cpp submissions
// Your memory usage beats 89.6 % of cpp submissions (7 MB)
```
