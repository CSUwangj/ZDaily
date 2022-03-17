+++
updated = 2022-03-17 18:18:00+08:00
title = "2022-03-17 Daily-Challenge"
path = "2022-03-17-Daily-Challenge"
date = 2022-03-17 18:17:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/score-of-parentheses/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 17

## Description

**Score of Parentheses**

iven a balanced parentheses string `s`, return *the **score** of the string*.

The **score** of a balanced parentheses string is based on the following rule:

- `"()"` has score `1`.
- `AB` has score `A + B`, where `A` and `B` are balanced parentheses strings.
- `(A)` has score `2 * A`, where `A` is a balanced parentheses string.

 

**Example 1:**

```
Input: s = "()"
Output: 1
```

**Example 2:**

```
Input: s = "(())"
Output: 2
```

**Example 3:**

```
Input: s = "()()"
Output: 2
```

 

**Constraints:**

- `2 <= s.length <= 50`
- `s` consists of only `'('` and `')'`.


## Solution

``` cpp
class Solution {
public:
  int scoreOfParentheses(string S) {
    int answer = 0;
    int count = 0;
    char last = 0;
    for(auto c : S) {
      if(c == '(') {
        count += 1;
      } else {
        count -= 1;
        if(last == '(') answer += (1 << count);
      }
      last = c;
    }
    return answer;
  }
};

// Accepted
// 86/86 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 99.93 % of cpp submissions (5.8 MB)
```
