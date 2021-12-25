+++
title = "2021-12-25 Daily-Challenge"
path = "2021-12-25-Daily-Challenge"
date = 2021-12-25 16:38:00+08:00
updated = 2021-12-25 16:48:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/basic-calculator-ii/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 25

## Description

**Basic Calculator II**

Given a string `s` which represents an expression, *evaluate this expression and return its value*. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of `[-231, 231 - 1]`.

**Note:** You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as `eval()`.

 

**Example 1:**

```
Input: s = "3+2*2"
Output: 7
```

**Example 2:**

```
Input: s = " 3/2 "
Output: 1
```

**Example 3:**

```
Input: s = " 3+5 / 2 "
Output: 5
```

 

**Constraints:**

<ul>
	<li><code>1 &lt;= s.length &lt;= 3 * 10<sup>5</sup></code></li>
	<li><code>s</code> consists of integers and operators <code>(&#39;+&#39;, &#39;-&#39;, &#39;*&#39;, &#39;/&#39;)</code> separated by some number of spaces.</li>
	<li><code>s</code> represents <strong>a valid expression</strong>.</li>
	<li>All the integers in the expression are non-negative integers in the range <code>[0, 2<sup>31</sup> - 1]</code>.</li>
	<li>The answer is <strong>guaranteed</strong> to fit in a <strong>32-bit integer</strong>.</li>
</ul>

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int calculate(string s) {
    s.push_back('+');
    char prevSign = '+';
    int prev = 0;
    int cur = 0;
    int result = 0;
    for(auto c : s) {
      if(c == ' ') continue;
      if(isdigit(c)) {
        cur *= 10;
        cur += c - '0';
        continue;
      }
      if(prevSign == '+' || prevSign == '-') {
        result += prev;
        prev = prevSign == '+' ? cur : -cur;
      } else if(prevSign == '*') {
        prev = prev * cur;
      } else {
        prev = prev / cur;
      }
      prevSign = c;
      cur = 0;
    }
    return result + prev;
  }
};

// Accepted
// 109/109 cases passed (4 ms)
// Your runtime beats 98.87 % of cpp submissions
// Your memory usage beats 75.38 % of cpp submissions (7.9 MB)
```
