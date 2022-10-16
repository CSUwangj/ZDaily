+++
title = "2021-08-07 Daily-Challenge"
path = "2021-08-07-Daily-Challenge"
date = 2021-08-07 15:33:34+08:00
updated = 2021-08-07 22:11:43+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [August LeetCoding Challenge](https://leetcode.com/explore/featured/card/august-leetcoding-challenge-2021/613/week-1-august-1st-august-7th/3835/) with `cpp`.

<!-- more -->

# LeetCode Review

## N-ary Tree Level Order Traversal

too easy to review

## Stone Game

too easy to review

## Path Sum II

too easy to review

## Subsets II

too easy to review

## Two Sum

too easy to review

## Largest Substring Between Two Equal Characters

too easy to review

## Defanging an IP Address

too easy to review

## Sort Array By Parity II

too easy to review

## Magical String

too easy to review

## Mean of Array After Removing Some Elements

too easy to review

# August LeetCoding Challenge 7

## Description

**Palindrome Partitioning II**

Given a string `s`, partition `s` such that every substring of the partition is a palindrome.

Return *the minimum cuts needed* for a palindrome partitioning of `s`.

 

**Example 1:**

```
Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
```

**Example 2:**

```
Input: s = "a"
Output: 0
```

**Example 3:**

```
Input: s = "ab"
Output: 1
```

 

**Constraints:**

- `1 <= s.length <= 2000`
- `s` consists of lower-case English letters only.

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
unordered_map<string, int> cache;
class Solution {
  bool isPalindrome(string &s, int len) {
    for(int i = 0; i * 2 < len; ++i) {
      if(s[i] != s[len - 1 - i]) return false;
    }
    return true;
  }
public:
  int minCut(string s) {
    if(cache.count(s)) return cache[s];
    int len = s.length();
    if(isPalindrome(s, len)) return 0;
    int answer = len - 1;
    for(int i = 1; i < len; ++i) {
      if(isPalindrome(s, i)) {
        answer = min(answer, 1 + minCut(s.substr(i)));
      }
    }
    // cout << s << ' ' << answer << endl;
    return cache[s] = answer;
  }
};
// Accepted
// 33/33 cases passed (792 ms)
// Your runtime beats 5.05 % of cpp submissions
// Your memory usage beats 8.67 % of cpp submissions (217.4 MB)
```