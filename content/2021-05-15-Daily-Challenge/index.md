+++
title = "2021-05-15 Daily-Challenge"
path = "2021-05-15-Daily-Challenge"
date = 2021-05-15 15:05:33+08:00
updated = 2021-05-15 16:17:50+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [May LeetCoding Challenge](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/599/week-2-may-8th-may-14th/3744/) with `cpp`.

<!-- more -->

# LeetCode Review

## Flatten Binary Tree to Linked List

too easy to review

## Ambiguous Coordinates

too easy to review

## Range Sum Query 2D - Immutable

too easy to review

## Count Primes

too easy to review

## Maximum Points You Can Obtain from Cards

``` cpp
class Solution {
public:
	int maxScore(vector<int>& cardPoints, int k) {
		int len = cardPoints.size();
		int sum = 0;
    for(int i = 0; i < k; ++i) {
      sum += cardPoints[i];
    }
    int answer = sum;
    for(int i = 0; i < k; ++i) {
      sum = sum - cardPoints[k - 1 - i] + cardPoints[len - 1 - i];
      answer = max(sum, answer);
    }
		return answer;
	}
};
```

# May LeetCoding Challenge 15

## Description

**Valid Number**

A **valid number** can be split up into these components (in order):

1. A **decimal number** or an **integer**.
2. (Optional) An `'e'` or `'E'`, followed by an **integer**.

A **decimal number** can be split up into these components (in order):

1. (Optional) A sign character (either `'+'` or `'-'`).
2. One of the following formats:
   1. At least one digit, followed by a dot `'.'`.
   2. At least one digit, followed by a dot `'.'`, followed by at least one digit.
   3. A dot `'.'`, followed by at least one digit.

An **integer** can be split up into these components (in order):

1. (Optional) A sign character (either `'+'` or `'-'`).
2. At least one digit.

For example, all the following are valid numbers: `["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"]`, while the following are not valid numbers: `["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"]`.

Given a string `s`, return `true` *if* `s` *is a **valid number***.

 

**Example 1:**

```
Input: s = "0"
Output: true
```

**Example 2:**

```
Input: s = "e"
Output: false
```

**Example 3:**

```
Input: s = "."
Output: false
```

**Example 4:**

```
Input: s = ".1"
Output: true
```

 

**Constraints:**

- `1 <= s.length <= 20`
- `s` consists of only English letters (both uppercase and lowercase), digits (`0-9`), plus `'+'`, minus `'-'`, or dot `'.'`.

## Solution

1A, haha

``` cpp
class Solution {
  int len;
  void checkSign(string &s, int &pos) {
    if(s[pos] == '+' || s[pos] == '-')
    pos += 1;
  }

  bool checkInteger(string &s, int &pos) {
    int initPos = pos;
    checkSign(s, pos);
    if(pos < len && isdigit(s[pos])) {
      while(pos < len && isdigit(s[pos])) pos += 1;
      return true;
    } else {
      pos = initPos;
      return false;
    }
  }

  bool checkDecimal(string &s, int &pos) {
    int initPos = pos;
    bool ok = true;
    checkSign(s, pos);
    bool hasFirst = false;
    if(pos < len && isdigit(s[pos])) {
      hasFirst = true;
      while(pos < len && isdigit(s[pos])) pos += 1;
    }
    if(pos < len && s[pos] == '.') {
      pos += 1;
    } else {
      pos = initPos;
      return false;
    }
    if(pos < len && isdigit(s[pos])) {
      while(pos < len && isdigit(s[pos])) pos += 1;
    } else if(!hasFirst) {
      pos = initPos;
      return false;
    }
    return true;
  }  
public:
  bool isNumber(string s) {
    int pos = 0;
    len = s.length();
    if(!(checkDecimal(s, pos) || checkInteger(s, pos))) {
      return false;
    }
    if(pos < len) {
      if(s[pos] != 'e' && s[pos] != 'E') return false;
      pos += 1;
      if(!checkInteger(s, pos)) {
        return false;
      }
    }
    return pos == len;
  }
};
```

or use regular expression

``` cpp
const regex re("^[-+]?((\\d+\\.\\d*)|(\\.\\d+)|\\d+)([eE][+-]?\\d+)?$");
class Solution {
public:
  bool isNumber(string s) {
    return regex_search(s, re);
  }
};
```
