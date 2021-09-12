+++
title = "2021-09-11 Daily-Challenge"
path = "2021-09-11-Daily-Challenge"
date = 2021-09-11 15:13:29+08:00
updated = 2021-09-11 21:35:44+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [September LeetCoding Challenge](https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/637/week-2-september-8th-september-14th/3971/) with `cpp`.

<!-- more -->

# LeetCode Review

## Binary Gap

too easy to review

## Kth Ancestor of a Tree Node

too easy to review

## Strange Printer

too easy to review

## Lexicographical Numbers

too easy to review

## Checking Existence of Edge Length Limited Paths

too easy to review

## Arithmetic Slices II - Subsequence

too easy to review

## Largest Plus Sign

too easy to review

## Shifting Letters

too easy to review

## Reverse Linked List

too easy to review

## Slowest Key

too easy to review

# September LeetCoding Challenge 11

## Description

**Basic Calculator**

Given a string `s` representing a valid expression, implement a basic calculator to evaluate it, and return *the result of the evaluation*.

**Note:** You are **not** allowed to use any built-in function which evaluates strings as mathematical expressions, such as `eval()`.

 

**Example 1:**

```
Input: s = "1 + 1"
Output: 2
```

**Example 2:**

```
Input: s = " 2-1 + 2 "
Output: 3
```

**Example 3:**

```
Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
```

 

**Constraints:**

- `1 <= s.length <= 3 * 10^5`
- `s` consists of digits, `'+'`, `'-'`, `'('`, `')'`, and `' '`.
- `s` represents a valid expression.
- `'+'` is not used as a unary operation.
- `'-'` could be used as a unary operation but it has to be inside parentheses.
- There will be no two consecutive operators in the input.
- Every number and running calculation will fit in a signed 32-bit integer.

## Solution

``` cpp
class Solution {
  bool shouldCompute(char current, char last) {
    if(current == '(') return false;
    if((current == '+' || current == '-') && last != '(') return true;
    if(last == '*' || last == '/') return true;
    return false;
  }
  void compute(stack<int> &n, stack<char> &op) {
    char o = op.top();
    op.pop();
    int op2 = n.top();
    n.pop();
    if(o == 'u') {
      n.push(-op2);
      return;
    }
    int op1 = n.top();
    n.pop();
    // cout << op1 << ' '<< o << " " << op2 << endl;
    switch(o){
      case '+':
        n.push(op1+op2);
        break;
      case '-':
        n.push(op1-op2);
        break;
      case '*':
        n.push(op1*op2);
        break;
      case '/':
        n.push(op1/op2);
        break;
    }
  }
public:
  int calculate(string s) {
    int curNum = 0;
    stack<int> n;
    stack<char> op;
    bool inNum = false;
    bool inCompute = false;
    bool negative = false;
    // cout << "$$$$$$$$$$$$$$$$$$$$" << endl;
    for(auto c : s) {
      if(c == ' ') continue;
      if(inNum && !isdigit(c)) {
        if(negative) curNum = -curNum;
        // cout << curNum << endl;
        n.push(curNum);
        curNum = 0;
        inNum = false;
        negative = false;
      }
      if(!inCompute && !inNum && c == '-') {
        op.push('u');
      } else if(isdigit(c)) {
        curNum *= 10;
        curNum += c - '0';
        inNum = true;
      } else if(c == ')') {
        while(op.size() && op.top() != '(') {
          compute(n, op);
        }
        op.pop();
      } else {
        while(op.size() && shouldCompute(c, op.top())) {
          compute(n, op);
        }
        op.push(c);
      }
      inCompute = c != '(';
    }
    if(inNum) n.push(curNum);
    while(op.size()) {
      compute(n, op);
    }
    return n.top();
  }
};
```