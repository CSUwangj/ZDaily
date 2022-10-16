+++
title = "2022-02-22 Daily-Challenge"
path = "2022-02-22-Daily-Challenge"
date = 2022-02-22 18:03:00+08:00
updated = 2022-02-22 18:04:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/excel-sheet-column-number/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 22

## Description

**Excel Sheet Column Number**

Given a string `columnTitle` that represents the column title as appear in an Excel sheet, return *its corresponding column number*.

For example:

```
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
```

 

**Example 1:**

```
Input: columnTitle = "A"
Output: 1
```

**Example 2:**

```
Input: columnTitle = "AB"
Output: 28
```

**Example 3:**

```
Input: columnTitle = "ZY"
Output: 701
```

 

**Constraints:**

- `1 <= columnTitle.length <= 7`
- `columnTitle` consists only of uppercase English letters.
- `columnTitle` is in the range `["A", "FXSHRXW"]`.

## Solution

``` cpp
class Solution {
public:
  int titleToNumber(string columnTitle) {
    int answer = 0;
    for(auto c : columnTitle) {
      answer *= 26;
      answer += c - 'A' + 1;
    }
    return answer;
  }
};

// Accepted
// 1002/1002 cases passed (4 ms)
// Your runtime beats 47.34 % of cpp submissions
// Your memory usage beats 67.1 % of cpp submissions (6 MB)
```
