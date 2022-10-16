+++
updated = 2022-05-24 18:14:00+08:00
title = "2022-05-24 Daily-Challenge"
path = "2022-05-24-Daily-Challenge"
date = 2022-05-24 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/longest-valid-parentheses/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 24

## Description

**Longest Valid Parentheses**

Given a string containing just the characters `'('` and `')'`, find the length of the longest valid (well-formed) parentheses substring.

 

**Example 1:**

```
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
```

**Example 2:**

```
Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
```

**Example 3:**

```
Input: s = ""
Output: 0
```

 

**Constraints:**

- `0 <= s.length <= 3 * 10^4`
- `s[i]` is `'('`, or `')'`.

## Solution

``` cpp
template<typename T>
class reversion_wrapper {
private:
  T& iterable;
public:
  explicit reversion_wrapper(T& iterable): iterable{iterable} {}
  auto begin() const { return std::rbegin(iterable); }
  auto end() const { return std::rend(iterable); }
};

class Solution {
public:
  int longestValidParentheses(string s) {
    int left = 0;
    int right = 0;
    int answer = 0;
    for(auto c : s) {
      if(c == '(') {
        left += 1;
      } else {
        right += 1;
        if(left == right) {
          answer = max(answer, left << 1);
        } else if (left < right) {
          left = 0;
          right = 0;
        }
      }
    }
    left = 0;
    right = 0;
    for(auto c : reversion_wrapper(s)) {
      if(c == ')') {
        right += 1;
      } else {
        left += 1;
        if(left == right) {
          answer = max(answer, left << 1);
        } else if(left > right) {
          left = 0;
          right = 0;
        }
      }
    }
    return answer;
  }
};

// Accepted
// 231/231 cases passed (4 ms)
// Your runtime beats 73.76 % of cpp submissions
// Your memory usage beats 96.04 % of cpp submissions (6.7 MB)
```
