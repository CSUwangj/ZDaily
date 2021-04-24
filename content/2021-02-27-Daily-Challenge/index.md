+++
title = "2021-02-27 Daily-Challenge"
path = "2021-02-27-Daily-Challenge"
date = 2021-02-27 22:44:36+08:00
updated = 2021-02-28 01:02:59+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [February LeetCoding Challenge](https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/587/week-4-february-22nd-february-28th/3654/) with `cpp`.


<!-- more -->

# LeetCode Review

## Longest Word in Dictionary through Deleting

``` cpp
class Solution {
    bool isSubsequence(string &s, string &d) {
        int pos = 0;
        int len = d.length();
        for(auto c : s) {
            if(pos == len) break;
            if(c == d[pos]) pos += 1;
        }
        return pos == len;
    }
public:
    string findLongestWord(string s, vector<string>& d) {
        string answer;
        for(auto &d : d) {
            if(d.length() < answer.length() || (d.length() == answer.length() && d >= answer)) continue;
            if(isSubsequence(s, d)) answer = d;
        }
        return answer;
    }
};
```

## Search a 2D Matrix II

``` cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix.front().size();
        int row = 0;
        int col = cols - 1;
        while(row < rows && col >= 0) {
            if(matrix[row][col] == target) return true;
            if(matrix[row][col] > target) {
                col -= 1;
            } else {
                row += 1;
            }
        }
        return false;
    }
};
```

## Score of Parentheses

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
```

## Shortest Unsorted Continuous Subarray

this solution can't be too clean

## Validate Stack Sequences

``` cpp
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int pos = 0;
        int len = pushed.size();
        vector<int> st;
        for(auto i : pushed) {
            st.push_back(i);
            while(st.size() && st.back() == popped[pos]) {
                st.pop_back();
                pos += 1;
            }
        }
        return st.size() == 0;
    }
};
```

# February LeetCoding Challenge27

## Description

**Divide Two Integers**

Given two integers `dividend` and `divisor`, divide two integers without using multiplication, division, and mod operator.

Return the quotient after dividing `dividend` by `divisor`.

The integer division should truncate toward zero, which means losing its fractional part. For example, `truncate(8.345) = 8` and `truncate(-2.7335) = -2`.

**Note:**

- Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For this problem, assume that your function **returns 231 − 1 when the division result overflows**.

 

**Example 1:**

```
Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = truncate(3.33333..) = 3.
```

**Example 2:**

```
Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = truncate(-2.33333..) = -2.
```

**Example 3:**

```
Input: dividend = 0, divisor = 1
Output: 0
```

**Example 4:**

```
Input: dividend = 1, divisor = 1
Output: 1
```

 

**Constraints:**

- $-2^{31} \le dividend, divisor \le 2^{31} - 1$
- `divisor != 0`

## Solution

``` cpp
class Solution {
    int answer = 0;
    int minus(int current, int base, int resultBase) {
        if(current > base) {
            return current;
        }
        if(base >= INT_MIN / 2) current = minus(current, base + base, resultBase + resultBase);
        if(current > base) {
            return current;
        }
        current -= base;
        answer += resultBase;
        return current;
    }
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        int sign = 1;
        if(dividend > 0) {
            sign = -1;
            dividend = 0 - dividend;
        }
        if(divisor > 0) {
            sign = sign == 1 ? -1 : 1;
            divisor = 0 - divisor;
        }
        minus(dividend, divisor, -1);
        answer = sign == 1 ? 0 - answer : answer;
        return answer;
    }
};
```
