+++
title = "2020-12-14 Daily-Challenge"
path = "2020-12-14-Daily-Challenge"
date = 2020-12-14 18:00:14+08:00
updated = 2020-12-14 18:43:09+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Minimum ASCII Delete Sum for Two Strings](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/) on leetcode and leetcode's [December LeetCoding Challenge](https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/570/week-2-december-8th-december-14th/3565/) with `cpp`.

<!-- more -->

# Minimum ASCII Delete Sum for Two Strings

## Description

Given two strings `s1, s2`, find the lowest ASCII sum of deleted characters to make two strings equal.

**Example 1:**

```
Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
```

**Example 2:**

```
Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d]+101[e]+101[e] to the sum.  Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
```

**Note:**

`0 < s1.length, s2.length <= 1000`.

All elements of each string will have an ASCII value in `[97, 122]`.

## Solution

LCS

``` cpp
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int lenS1 = s1.size();
        int lenS2 = s2.size();
        vector<vector<int>> dp(lenS1+1, vector<int>(lenS2+1));
        for(int i = 1; i <= lenS1; ++i) {
            for(int j = 1; j <= lenS2; ++j) {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1]+s1[i-1]);
                }
            }
        }
        int sum = 0;
        for(auto c : s1) sum += c;
        for(auto c : s2) sum += c;
        return sum - 2*dp[lenS1][lenS2];
    }
};
```

# December LeetCoding Challenge 14

## Description

**Palindrome Partitioning**

Given a string `s`, partition `s` such that every substring of the partition is a **palindrome**. Return all possible palindrome partitioning of `s`.

A **palindrome** string is a string that reads the same backward as forward.

**Example 1:**

```
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
```

**Example 2:**

```
Input: s = "a"
Output: [["a"]]
```

**Constraints:**

- `1 <= s.length <= 16`
- `s` contains only lowercase English letters.

## Solution

dfs

``` cpp
class Solution {
    string s;
    int len;
    
    bool isPalindrome(int begin, int end) {
        while(begin <= end) {
            if(s[begin] != s[end]) return false;
            ++begin;
            --end;
        }
        return true;
    }
    
    void dfs(vector<vector<string>> &result, vector<string> &current, int index) {
        if(index == len) result.push_back(current);
        for(int i = 0; index+i < len; ++i) {
            if(isPalindrome(index, index+i)) {
                current.push_back(s.substr(index, i+1));
                dfs(result, current, index+i+1);
                current.pop_back();
            }
        }
    }
    
public:
    vector<vector<string>> partition(string s) {
        this->s = s;
        len = s.length();
        vector<vector<string>> answer;
        vector<string> tmp;
        dfs(answer, tmp, 0);
        return answer;
    }
};
```