+++
title = "2021-02-06 Daily-Challenge"
path = "2021-02-06-Daily-Challenge"
date = 2021-02-06 16:00:59+08:00
updated = 2021-02-06 22:06:34+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Wildcard Matching](https://leetcode.com/problems/wildcard-matching/) and leetcode's [February LeetCoding Challenge](https://leetcode.com/explore/featured/card/february-leetcoding-challenge-2021/584/week-1-february-1st-february-7th/3630/) with `cpp`.

Ops, today is Saturday, I need to review the challenge.

<!-- more -->

# String Compression

## Description

Given an input string (`s`) and a pattern (`p`), implement wildcard pattern matching with support for `'?'` and `'*'` where:

- `'?'` Matches any single character.
- `'*'` Matches any sequence of characters (including the empty sequence).

The matching should cover the **entire** input string (not partial).

 

**Example 1:**

```
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
```

**Example 2:**

```
Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
```

**Example 3:**

```
Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
```

**Example 4:**

```
Input: s = "adceb", p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
```

**Example 5:**

```
Input: s = "acdcb", p = "a*c?b"
Output: false
```

 

**Constraints:**

- `0 <= s.length, p.length <= 2000`
- `s` contains only lowercase English letters.
- `p` contains only lowercase English letters, `'?'` or `'*'`.

## Solution

``` cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.length(), sPos = 0;
        int pLen = p.length(), pPos = 0;
        int starPos = -1, startpPos = -1;
        while(sPos < sLen) {
            if(pPos < pLen && (p[pPos] == '?' || p[pPos] == s[sPos])) {
                sPos += 1;
                pPos += 1;
            } else if(pPos < pLen && p[pPos] == '*') {
                while(pPos < pLen && p[pPos] == '*') pPos += 1;
                starPos = sPos;
                startpPos = pPos;
            } else if(starPos != -1) {
                starPos += 1;
                sPos = starPos;
                pPos = startpPos;
            }else return false;
        }
        // cout << pPos << ' ' << sPos << ' ' << s << ' ' << p << endl;
        while(pPos < pLen && p[pPos] == '*') pPos += 1;
        return pPos == pLen;
    }
};
```

# February LeetCoding Challenge6

**Binary Tree Right Side View**

## Description

Given a binary tree, imagine yourself standing on the *right* side of it, return the values of the nodes you can see ordered from top to bottom.

**Example:**

```
Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
```

## Solution

``` cpp
class Solution {
    vector<int> answer;
    void traversal(TreeNode* root, int level) {
        if(!root) return;
        if(level > answer.size()) answer.push_back(root->val);
        traversal(root->right, level + 1);
        traversal(root->left, level + 1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        traversal(root, 1);
        return move(answer);
    }
};
```

# LeetCode Review

## Check Completeness of a Binary Tree

already done a good job

## Integer to English Words

use vector will be faster

``` cpp
class Solution {
  const string ZERO = "Zero";
  const vector<pair<int, string>> units = {
    { 1000000000, "Billion" },
    { 1000000, "Million" },
    { 1000, "Thousand" },
    { 1, "" }
  };
  vector<string> ge20 = {
    "", // 0
    "", // 10
    "Twenty",
    "Thirty",
    "Forty",
    "Fifty",
    "Sixty",
    "Seventy",
    "Eighty",
    "Ninety" 
  };
  vector<string> lt20 = {
    "",
    "One",
    "Two",
    "Three",
    "Four",
    "Five",
    "Six",
    "Seven",
    "Eight",
    "Nine",
    "Ten",
    "Eleven",
    "Twelve",
    "Thirteen",
    "Fourteen",
    "Fifteen",
    "Sixteen",
    "Seventeen",
    "Eighteen",
    "Nineteen",
  };

  string numberLT1000ToWords(int num)  {
    string result;
    if (num >= 100)  {
      result += lt20[num / 100] + " Hundred";
      if (num % 100 == 0) return result;
      result += " ";
      num %= 100;
    }
        if (!num) return result;
    if (num < 20) {
      result += lt20[num];
    } else {
      result += ge20[num/10];
      if (num % 10)  result += " " + lt20[num % 10];
    }

    return result;
  }

  void numberPartToWords(string &result, int &num, const int threshold, const string &unit)  {
    if (num >= threshold)  {
      if (result.length()) result += " ";
      result += numberLT1000ToWords(num / threshold);
      if (unit.length()) result += " " + unit;
      num %= threshold;
    }
  }

  public:
    string numberToWords(int num)  {
      if (!num) return move(ZERO);
      string answer = "";
      for (const auto &[threshold, unit]: units) {
        numberPartToWords(answer, num, threshold, unit);
      }

      return answer;
    }
};
```

## Throne Inheritance

too easy to review

## String Compression

too easy to review

## Count All Possible Routes

rewrite as memorized dfs, quicker and code is cleaner

``` cpp
class Solution {
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;
    int memo(vector<int> &locations, int curCity, int finish, int fuel) {
        if(fuel < 0) return 0;
        if(dp[curCity][fuel] != -1) return dp[curCity][fuel];
        int answer = curCity == finish;
        for(int nextCity = 0; nextCity < locations.size(); ++nextCity) {
            if(nextCity == curCity) continue;
            answer += memo(locations, nextCity, finish, fuel-abs(locations[nextCity] - locations[curCity]));
            answer %= MOD;
        }
        dp[curCity][fuel] = answer;
        return answer;
    }
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int cityLen = locations.size();
        dp.resize(cityLen, vector<int>(fuel + 1, -1));
        return memo(locations, start, finish, fuel);
    }
};
```

## Number of 1 Bits

built-in pop count

``` cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcountl(n);
    }
};
```

hand-written naive implementation of pop count

``` cpp
const uint32_t m1 = 0x55555555;
const uint32_t m2 = 0x33333333;
const uint32_t m4 = 0x0F0F0F0F;
const uint32_t m8 = 0x00FF00FF;
const uint32_t m16 = 0x0000FFFF;
class Solution { 
public:
    int hammingWeight(uint32_t n) {
        n = (n & m1) + ((n >> 1) & m1);
        n = (n & m2) + ((n >> 2) & m2);
        n = (n & m4) + ((n >> 4) & m4);
        n = (n & m8) + ((n >> 8) & m8);
        n = (n & m16) + ((n >> 16) & m16);
        return n;
    }
};
```

## Trim a Binary Search Tree

too easy to review

## Linked List Cycle

already reviewed

## Longest Harmonious Subsequence

sort with binary search

``` cpp
class Solution {
public: 
    int findLHS(vector<int>& nums) {
        int answer = 0;
        sort(nums.begin(), nums.end());
        auto it = nums.begin();
        while(it != nums.end()) {
            auto eit = upper_bound(nums.begin(), nums.end(), *it+1);
            --eit;
            if((*eit) - 1 == (*it)) {
                int result = distance(it, eit) + 1;
                answer = max(answer, result);
            }
            it = upper_bound(nums.begin(), nums.end(), *it);
        }
        return answer;
    }
};
```

## Simplify Path

cleaner code

``` cpp
class Solution {
    const string currentDir = "./";
    const string currentDirS = ".";
    const string upLevel = "../";
    const string upLevelS = "..";
public:
    string simplifyPath(string path) {
        int pos = 0;
        int len = path.length();
        vector<pair<int, int>> st;
        while(pos < len) {
            while(pos < len && path[pos] == '/') pos += 1;
            
            auto testUp = path.substr(pos, 3);
            if(testUp == upLevel || testUp == upLevelS) {
                if(st.size()) st.pop_back();
                pos += testUp.length();
                continue;
            }
            
            auto testCur = path.substr(pos, 2);
            if(testCur == currentDir || testCur == currentDirS) {
                pos += testCur.length();
                continue;
            }
            
            int begin = pos;
            while(pos < len && path[pos] != '/') pos += 1;
            if(pos != begin) st.push_back(make_pair(begin, pos - begin));
        }
        
        if(st.empty()) return "/";
        string answer;
        for(auto [begin, len] : st) answer += '/' + path.substr(begin, len);
        return answer;
    }
};
```
