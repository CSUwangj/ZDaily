+++
title = "2021-06-10 Daily-Challenge"
path = "2021-06-10-Daily-Challenge"
date = 2021-06-10 19:36:35+08:00
updated = 2021-06-10 20:49:21+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Longest Uncommon Subsequence II](https://leetcode.com/problems/longest-uncommon-subsequence-ii/description/) and leetcode's [June LeetCoding Challenge](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/603/week-1-june-1st-june-7th/3774/) with `cpp`.

<!-- more -->

# Longest Uncommon Subsequence II

## Description

Given an array of strings `strs`, return *the length of the **longest uncommon subsequence** between them*. If the longest uncommon subsequence does not exist, return `-1`.

An **uncommon subsequence** between an array of strings is a string that is a **subsequence of one string but not the others**.

A **subsequence** of a string `s` is a string that can be obtained after deleting any number of characters from `s`.

- For example, `"abc"` is a subsequence of `"aebdc"` because you can delete the underlined characters in `"aebdc"` to get `"abc"`. Other subsequences of `"aebdc"` include `"aebdc"`, `"aeb"`, and `""` (empty string).

 

**Example 1:**

```
Input: strs = ["aba","cdc","eae"]
Output: 3
```

**Example 2:**

```
Input: strs = ["aaa","aaa","aa"]
Output: -1
```

 

**Constraints:**

- `1 <= strs.length <= 50`
- `1 <= strs[i].length <= 10`
- `strs[i]` consists of lowercase English letters.

## Solution

``` cpp
class Solution {
  bool isSubsequence(string shorter, string longer) {
    int pos = 0;
    for(int i = 0; i < longer.length(); ++i) {
      if(longer[i] == shorter[pos]) {
        pos += 1;
      }
      if(pos == shorter.length()) break;
    }
    return pos == shorter.length();
  }
public:
  int findLUSlength(vector<string>& strs) {
    unordered_map<string, int> mp;
    for(int i = 0; i < strs.size(); ++i) {
      bool ok = true;
      for(int j = 0; ok && j < strs.size(); ++j) {
        if(i == j || strs[i].length() >= strs[j].length()) continue;
        ok = !isSubsequence(strs[i], strs[j]);
      }
      if(ok) mp[strs[i]] += 1;
    }
    int answer = 0;
    for(auto &[str, cnt] : mp) {
      if(cnt > 1) continue;
      if(str.length() > answer) answer = str.length();
    }
    return answer ? answer : -1;
  }
};
```

# June LeetCoding Challenge10

## Description

**My Calendar I**

Implement a `MyCalendar` class to store your events. A new event can be added if adding the event will not cause a double booking.

Your class will have the method, `book(int start, int end)`. Formally, this represents a booking on the half open interval `[start, end)`, the range of real numbers `x` such that `start <= x < end`.

A *double booking* happens when two events have some non-empty intersection (ie., there is some time that is common to both events.)

For each call to the method `MyCalendar.book`, return `true` if the event can be added to the calendar successfully without causing a double booking. Otherwise, return `false` and do not add the event to the calendar.

Your class will be called like this: `MyCalendar cal = new MyCalendar();` `MyCalendar.book(start, end)`

**Example 1:**

```
MyCalendar();
MyCalendar.book(10, 20); // returns true
MyCalendar.book(15, 25); // returns false
MyCalendar.book(20, 30); // returns true
Explanation: 
The first event can be booked.  The second can't because time 15 is already booked by another event.
The third event can be booked, as the first event takes every time less than 20, but not including 20.
```

 

**Note:**

- The number of calls to `MyCalendar.book` per test case will be at most `1000`.
- In calls to `MyCalendar.book(start, end)`, `start` and `end` are integers in the range `[0, 10^9]`.

## Solution

``` cpp
class MyCalendar {
  set<int> times;
public:
  MyCalendar(){}
  
  bool book(int start, int end) {
    bool isStart = true;
    bool removeEnd = false;
    bool removeStart = false;
    int prevStart = -1;
    for(auto i : times) {
      if(isStart && i == end) removeEnd = true;
      if(!isStart && i == start) removeStart = true;
      if(isStart) {
        prevStart = i;
      } else {
        if(start >= prevStart && start < i) return false;
        if(end <= i && end > prevStart) return false;
      }
      isStart = !isStart;
    }
    if(times.upper_bound(start) != times.lower_bound(end)) return false;
    if(removeEnd) times.erase(end);
    else times.insert(end);
    if(removeStart) times.erase(start);
    else times.insert(start);
    return true;
  }
};
```
