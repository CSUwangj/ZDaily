+++
title = "2021-02-20 Daily-Challenge"
path = "2021-02-20-Daily-Challenge"
date = 2021-02-20 12:20:59+08:00
updated = 2021-02-20 21:34:18+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [February LeetCoding Challenge](https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/586/week-3-february-15th-february-21st/3646/) with `cpp`.

<!-- more -->

# LeetCode Review

## The K Weakest Rows in a Matrix

early break in count

``` cpp
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int rows = mat.size();
        int cols = mat.front().size();
        vector<int> rowCount(rows);
        for(int i = 0; i < rows; ++i) {
            int cnt = 0;
            for(auto i : mat[i]) {
                if(i) {
                    cnt += i;
                } else break;
            }
            rowCount[i] = cnt;
        }
        vector<int> answer(rows);
        for(int i = 0; i < rows; ++i) answer[i] = i;
        
        stable_sort(answer.begin(), answer.end(), [&](int a, int b){
            return rowCount[a] < rowCount[b];
        });
        answer.resize(k);
        return move(answer);
    }
};
```

use sort instead of stable_sort

``` cpp
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int rows = mat.size();
        int cols = mat.front().size();
        vector<int> rowCount(rows);
        for(int i = 0; i < rows; ++i) {
            int cnt = 0;
            for(auto i : mat[i]) {
                if(i) {
                    cnt += i;
                } else break;
            }
            rowCount[i] = cnt;
        }
        vector<int> answer(rows);
        for(int i = 0; i < rows; ++i) answer[i] = i;
        
        sort(answer.begin(), answer.end(), [&](int a, int b){
            return rowCount[a] < rowCount[b] || (rowCount[a] == rowCount[b] && a < b);
        });
        answer.resize(k);
        return move(answer);
    }
};
```

with binary search

``` cpp
class Solution {
    
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int rows = mat.size();
        int cols = mat.front().size();
        vector<int> rowCount(rows);
        for(int i = 0; i < rows; ++i) {
            int low = 0, high = cols - 1;
            while(low < high) {
                int mid = (low + high) >> 1;
                if(mat[i][mid]) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }
            rowCount[i] = mat[i][low] ? low + 1 : low;
        }
        vector<int> answer(rows);
        for(int i = 0; i < rows; ++i) answer[i] = i;
        
        sort(answer.begin(), answer.end(), [&](int a, int b){
            return rowCount[a] < rowCount[b] || (rowCount[a] == rowCount[b] && a < b);
        });
        answer.resize(k);
        return move(answer);
    }
};
```

## Letter Case Permutation

too easy to review

## Container With Most Water

too easy to review

## Arithmetic Slices

using DP

``` cpp
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int len = A.size();
        if(len < 3) return 0;
        
        int dp = 0;
        int answer = 0;
        for(int i = 2; i < len; ++i) {
            if(A[i] - A[i-1] == A[i-1] - A[i-2]) {
                dp += 1;
                answer += dp;
            } else {
                dp = 0;
            }
        }
        
        return answer;
    }
};
```

## Minimum Remove to Make Valid Parentheses

inplace edit

``` cpp
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int len = s.length();
        
        int end = len;
        int paras = 0;
        for(int i = len-1; i >= 0; --i) {
            if(s[i] == ')') {
                paras += 1;
            } else if(s[i] == '(') {
                if(paras) paras -= 1;
                else continue;
            }
            end -= 1;
            s[end] = s[i];
        }
        
        int newLen = 0;
        paras = 0;
        for(; end < len; ++end) {
            if(s[end] == '(') {
                paras += 1;
            } else if(s[end] == ')') {
                if(paras) paras -= 1;
                else continue;
            }
            s[newLen] = s[end];
            newLen += 1;
        } 
        s.resize(newLen);
        return move(s);
    }
};
```

# February LeetCoding Challenge20

**Roman to Integer**

## Description

Roman numerals are represented by seven different symbols: `I`, `V`, `X`, `L`, `C`, `D` and `M`.

```
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
```

For example, `2` is written as `II` in Roman numeral, just two one's added together. `12` is written as `XII`, which is simply `X + II`. The number `27` is written as `XXVII`, which is `XX + V + II`.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not `IIII`. Instead, the number four is written as `IV`. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as `IX`. There are six instances where subtraction is used:

- `I` can be placed before `V` (5) and `X` (10) to make 4 and 9. 
- `X` can be placed before `L` (50) and `C` (100) to make 40 and 90. 
- `C` can be placed before `D` (500) and `M` (1000) to make 400 and 900.

Given a roman numeral, convert it to an integer.

 

**Example 1:**

```
Input: s = "III"
Output: 3
```

**Example 2:**

```
Input: s = "IV"
Output: 4
```

**Example 3:**

```
Input: s = "IX"
Output: 9
```

**Example 4:**

```
Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
```

**Example 5:**

```
Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
```

 

**Constraints:**

- `1 <= s.length <= 15`
- `s` contains only the characters `('I', 'V', 'X', 'L', 'C', 'D', 'M')`.
- It is **guaranteed** that `s` is a valid roman numeral in the range `[1, 3999]`.

## Solution

``` cpp
class Solution {
    unordered_map<char, int> mp = {
        {'M', 1000},
        {'D', 500},
        {'C', 100},
        {'L', 50},
        {'X', 10},
        {'V', 5},
        {'I', 1}
    };
public:
    int romanToInt(string s) {
        int len = s.length();
        int pos = 0;
        int answer = 0;
        while(pos < len) {
            if(pos < len - 1 && mp[s[pos]] < mp[s[pos + 1]]) {
                answer += mp[s[pos + 1]] - mp[s[pos]];
                pos += 2;
            } else {
                answer += mp[s[pos]];
                pos += 1;
            }
        }
        return answer;
    }
};
```
