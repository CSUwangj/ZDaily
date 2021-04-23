+++
title = "2021-01-18 Daily-Challenge"
path = "2021-01-18-Daily-Challenge"
date = 2021-01-18 18:00:59+08:00
updated = 2021-01-18 18:42:46+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching/) and leetcode's [January LeetCoding Challenge](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/581/week-3-january-15th-january-21st/3608/) with `cpp`.

<!-- more -->

# Regular Expression Matching

## Description

Given an input string (`s`) and a pattern (`p`), implement regular expression matching with support for `'.'` and `'*'` where:` `

- `'.'` Matches any single character.
- `'*'` Matches zero or more of the preceding element.

The matching should cover the **entire** input string (not partial).

 

**Example 1:**

```
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
```

**Example 2:**

```
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
```

**Example 3:**

```
Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
```

**Example 4:**

```
Input: s = "aab", p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
```

**Example 5:**

```
Input: s = "mississippi", p = "mis*is*p*."
Output: false
```

 

**Constraints:**

- `0 <= s.length <= 20`
- `0 <= p.length <= 30`
- `s` contains only lowercase English letters.
- `p` contains only lowercase English letters, `'.'`, and `'*'`.
- It is guaranteed for each appearance of the character `'*'`, there will be a previous valid character to match.

## Solution

recursive way without optimization

Runtime: 24 ms, faster than 31.41% of C++ online submissions

Memory Usage: 6.3 MB, less than 98.57% of C++ online submissions

``` cpp
class Solution {
    string source;
    string regex;
    int lenS;
    int lenR;
    
    bool match(char s, char r) {
        return r == '.' || s == r;
    }
    
    bool helper(int posS, int posR) {
        // cout << posS << ' ' << posR << endl;
        if(posS == lenS && posR == lenR) return true;
        if(posS == lenS) {
            if((lenR - posR) % 2 == 1 || regex[posR + 1] != '*') return false;
            return helper(posS, posR + 2);
        }
        if(posR == lenR) return false;
        if(posR < lenR-1 && regex[posR + 1] == '*') {
            if(helper(posS, posR + 2)) return true;
            for(int i = posS; i < lenS && match(source[i], regex[posR]); ++i) {
                if(helper(i + 1, posR + 2)) return true;
            }
        } else if(match(source[posS], regex[posR])) {
            return helper(posS + 1, posR + 1);
        }
        return false;
    }
public:
    bool isMatch(string s, string p) {
        source = s;
        regex = p;
        lenS = s.length();
        lenR = p.length();
        return helper(0, 0);
    }
};
```

# January LeetCoding Challenge18

## Description

**Max Number of K-Sum Pairs**

## Description

You are given an integer array `nums` and an integer `k`.

In one operation, you can pick two numbers from the array whose sum equals `k` and remove them from the array.

Return *the maximum number of operations you can perform on the array*.

 

**Example 1:**

```
Input: nums = [1,2,3,4], k = 5
Output: 2
Explanation: Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.
```

**Example 2:**

```
Input: nums = [3,1,3,4,3], k = 6
Output: 1
Explanation: Starting with nums = [3,1,3,4,3]:
- Remove the first two 3's, then nums = [1,4,3]
There are no more pairs that sum up to 6, hence a total of 1 operation.
```

 

**Constraints:**

- `1 <= nums.length <= 105`
- `1 <= nums[i] <= 109`
- `1 <= k <= 109`

## Solution

``` cpp
class Solution {
    unordered_map<int, int> count;
public:
    int maxOperations(vector<int>& nums, int k) {
        for(auto i : nums) count[i] += 1;
        int answer = 0;
        for(auto [num, cnt] : count) {
            if(!count.count(k-num)) continue;
            answer += min(cnt, count[k-num]);
        }
        answer /= 2;
        return answer;
    }
};
```
