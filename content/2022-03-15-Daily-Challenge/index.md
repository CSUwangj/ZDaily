+++
updated = 2022-03-15 18:12:00+08:00
title = "2022-03-15 Daily-Challenge"
path = "2022-03-15-Daily-Challenge"
date = 2022-03-15 18:10:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 15

## Description

**Minimum Remove to Make Valid Parentheses**

Given a string s of `'('` , `')'` and lowercase English characters.

Your task is to remove the minimum number of parentheses ( `'('` or `')'`, in any positions ) so that the resulting *parentheses string* is valid and return **any** valid string.

Formally, a *parentheses string* is valid if and only if:

- It is the empty string, contains only lowercase characters, or
- It can be written as `AB` (`A` concatenated with `B`), where `A` and `B` are valid strings, or
- It can be written as `(A)`, where `A` is a valid string.

 

**Example 1:**

```
Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
```

**Example 2:**

```
Input: s = "a)b(c)d"
Output: "ab(c)d"
```

**Example 3:**

```
Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.
```

 

**Constraints:**

- `1 <= s.length <= 10^5`
- `s[i]` is either`'('` , `')'`, or lowercase English letter`.`

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  string removeOne(const string &s, char front, char back) {
    string result;
    int count = 0;
    for(auto c : s) {
      if(c == front) {
        count += 1;
        result.push_back(front);
      } else if(c == back) {
        if(!count) continue;
        count -= 1;
        result.push_back(back);
      } else {
        result.push_back(c);
      }
    }
    return result;
  }
public:
  string minRemoveToMakeValid(string s) {
    int count = 0;
    string answer = removeOne(s, '(', ')');
    reverse(answer.begin(), answer.end());
    answer = removeOne(answer, ')', '(');
    reverse(answer.begin(), answer.end());
    return answer;
  }
};

// Accepted
// 62/62 cases passed (24 ms)
// Your runtime beats 78.01 % of cpp submissions
// Your memory usage beats 21.74 % of cpp submissions (12.3 MB)
```
