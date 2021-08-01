+++
title = "2021-07-14 Daily-Challenge"
path = "2021-07-14-Daily-Challenge"
date = 2021-07-13 23:43:50+08:00
updated = 2021-07-14 21:24:03+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Excel Sheet Column Number](https://leetcode.com/problems/excel-sheet-column-number/description/) and leetcode's [July LeetCoding Challenge](https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/609/week-2-july-8th-july-14th/3813/) with `cpp`.

<!-- more -->

# Excel Sheet Column Number

## Description

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

**Example 4:**

```
Input: columnTitle = "FXSHRXW"
Output: 2147483647
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
    int result = 0;
    for(auto c : columnTitle) {
      result *= 26;
      result += c - 'A' + 1;
    }
  }
};
```

# July LeetCoding Challenge 14

## Description

**Custom Sort String**

`order` and `str` are strings composed of lowercase letters. In `order`, no letter occurs more than once.

`order` was sorted in some custom order previously. We want to permute the characters of `str` so that they match the order that `order` was sorted. More specifically, if `x` occurs before `y` in `order`, then `x` should occur before `y` in the returned string.

Return any permutation of `str` (as a string) that satisfies this property.

```
Example:
Input: 
order = "cba"
str = "abcd"
Output: "cbad"
Explanation: 
"a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a". 
Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.
```

 

**Note:**

- `order` has length at most `26`, and no character is repeated in `order`.
- `str` has length at most `200`.
- `order` and `str` consist of lowercase letters only.

## Solution

``` cpp
class Solution {
public:
  string customSortString(string order, string str) {
    int pos[128] = {};
    for(int i = 0; i < order.length(); ++i) pos[order[i]] = i + 1;
    sort(str.begin(), str.end(), [&](const char &a, const char &b) {
      return pos[a] < pos[b];
    });
    return str;
  }
};
```

``` cpp
class Solution {
public:
  string customSortString(string order, string str) {
    int cnt[128] = {};
    for(auto c : str) cnt[c] += 1;
    string answer;
    for(auto c : order) {
      while(cnt[c]) {
        answer.push_back(c);
        cnt[c] -= 1;
      }
    }
    for(char i = 'a'; i <= 'z'; ++i) {
      while(cnt[i]) {
        answer.push_back(i);
        cnt[i] -= 1;
      }
    }
    return answer;
  }
};
```
