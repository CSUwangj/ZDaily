+++
title = "2022-01-10 Daily-Challenge"
path = "2022-01-10-Daily-Challenge"
date = 2022-01-10 18:46:00+08:00
updated = 2022-01-10 18:51:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/add-binary/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 10

## Description

**Add Binary**

Given two binary strings `a` and `b`, return *their sum as a binary string*.

 

**Example 1:**

```
Input: a = "11", b = "1"
Output: "100"
```

**Example 2:**

```
Input: a = "1010", b = "1011"
Output: "10101"
```

 

**Constraints:**

- `1 <= a.length, b.length <= 104`
- `a` and `b` consist only of `'0'` or `'1'` characters.
- Each string does not contain leading zeros except for the zero itself.

## Solution

``` cpp
class Solution {
public:
  string addBinary(string a, string b) {
    int len1 = a.length();
    int len2 = b.length();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int pos = 0;
    int carry = 0;
    string answer;
    for(; pos < len1 && pos < len2; ++pos) {
      int result = a[pos] + b[pos] + carry;
      answer.push_back('0' + (result & 1));
      carry = ((result >> 1) & 1);
    }
    int len = len1;
    string *target = &a;
    if(len1 < len2) {
      len = len2;
      target = &b;
    }
    while(carry && pos < len) {
      if((*target)[pos++] == '1') {
        answer.push_back('0');
      } else {
        answer.push_back('1');
        carry = 0;
      }
    }
    while(pos < len) {
      answer.push_back((*target)[pos++]);
    }
    if(carry) {
      answer.push_back('1');
    }
    reverse(answer.begin(), answer.end());
    return answer;
  }
};

// Accepted
// 294/294 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 96.62 % of cpp submissions (6.1 MB)
```
