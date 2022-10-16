+++
title = "2021-01-08 Daily-Challenge"
path = "2021-01-08-Daily-Challenge"
date = 2021-01-08 18:13:43+08:00
updated = 2021-01-07 18:26:49+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Thousand Separator](https://leetcode.com/problems/thousand-separator/) and leetcode's [January LeetCoding Challenge](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/580/week-2-january-8th-january-14th/3597/) with `cpp`.

<!-- more -->

# Thousand Separator

## Description

Given an integer `n`, add a dot (".") as the thousands separator and return it in string format.

 

**Example 1:**

```
Input: n = 987
Output: "987"
```

**Example 2:**

```
Input: n = 1234
Output: "1.234"
```

**Example 3:**

```
Input: n = 123456789
Output: "123.456.789"
```

**Example 4:**

```
Input: n = 0
Output: "0"
```

 

**Constraints:**

- $0 \le  n < 2^{31}$

## Solution

``` cpp
class Solution {
public:
    string thousandSeparator(int n) {
        string answer = "";
        while(n > 1000) {
            string tmp = to_string(n%1000);
            while(tmp.length() < 3) tmp = "0" + tmp;
            answer = "." + tmp + answer;
            n /= 1000;
        }
        answer = to_string(n%1000) + answer;
        return answer;
    }
};
```

# January LeetCoding Challenge 8

## Description

**Check If Two String Arrays are Equivalent**

Given two string arrays `word1` and `word2`, return `true` *if the two arrays **represent** the same string, and* `false` *otherwise.*

A string is **represented** by an array if the array elements concatenated **in order** forms the string.

 

**Example 1:**

```
Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
Output: true
Explanation:
word1 represents string "ab" + "c" -> "abc"
word2 represents string "a" + "bc" -> "abc"
The strings are the same, so return true.
```

**Example 2:**

```
Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
Output: false
```

**Example 3:**

```
Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
Output: true
```

 

**Constraints:**

- $1 \le word1.length, word2.length \le 10^3$
- $1 \le word1[i].length, word2[i].length \le 10^3$
- $1 \le sum(word1[i].length), sum(word2[i].length) \le 10^3$
- `word1[i]` and `word2[i]` consist of lowercase letters.


## Solution

``` cpp
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i1 = 0, i2 = 0, s1 = 0, s2 = 0;
        int len1 = word1.size(), len2 = word2.size();
        while(i1 < len1 && i2 <len2) {
            if(word1[i1][s1] != word2[i2][s2]) return false;
            s1 += 1;
            if(s1 == word1[i1].length()) s1 = 0, i1 += 1;
            s2 += 1;
            if(s2 == word2[i2].length()) s2 = 0, i2 += 1;
        }
        if(i1 != len1 || i2 != len2) return false;
        return true;
    }
};
```