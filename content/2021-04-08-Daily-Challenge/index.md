+++
title = "2021-04-08 Daily-Challenge"
path = "2021-04-08-Daily-Challenge"
date = 2021-04-08 18:40:02+08:00
updated = 2021-04-08 19:56:35+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Maximum Equal Frequency](https://leetcode.com/problems/maximum-equal-frequency/) and leetcode's [April LeetCoding Challenge](https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/594/week-2-april-8th-april-14th/3701/) with `cpp`.

<!-- more -->

# Maximum Equal Frequency

## Description

Given an array `nums` of positive integers, return the longest possible length of an array prefix of `nums`, such that it is possible to remove **exactly one** element from this prefix so that every number that has appeared in it will have the same number of occurrences.

If after removing one element there are no remaining elements, it's still considered that every appeared number has the same number of ocurrences (0).

 

**Example 1:**

```
Input: nums = [2,2,1,1,5,3,3,5]
Output: 7
Explanation: For the subarray [2,2,1,1,5,3,3] of length 7, if we remove nums[4]=5, we will get [2,2,1,1,3,3], so that each number will appear exactly twice.
```

**Example 2:**

```
Input: nums = [1,1,1,2,2,2,3,3,3,4,4,4,5]
Output: 13
```

**Example 3:**

```
Input: nums = [1,1,1,2,2,2]
Output: 5
```

**Example 4:**

```
Input: nums = [10,2,8,9,3,8,1,5,2,3,7,6]
Output: 8
```

 

**Constraints:**

- `2 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^5`

## Solution

why this problem is `hard`?

``` cpp
class Solution {
public:
  int maxEqualFreq(vector<int>& nums) {
    unordered_map<int, int> cnt;
    unordered_map<int, int> ccnt;
    int answer = 0;
    int len = nums.size();
    for(int i = 0; i < len; ++i) {
      int n = nums[i];
      if(cnt[n] != 0) ccnt[cnt[n]] -= 1;
      if(!ccnt[cnt[n]]) ccnt.erase(cnt[n]);
      cnt[n] += 1;
      ccnt[cnt[n]] += 1;
      if(ccnt.size() == 1 && (ccnt.count(1) || ccnt.begin()->second == 1)) {
        answer = i + 1;
        continue;
      }
      if(ccnt.size() != 2) continue;
      if(ccnt.count(1) && ccnt[1] == 1) {
        answer = i + 1;
      } else if(ccnt.count(cnt[n] - 1) && ccnt[cnt[n]] == 1) {
        answer = i + 1;
      } else if(ccnt.count(cnt[n] + 1) && ccnt[cnt[n] + 1] == 1) {
        answer = i + 1;
      }
    }
    
    return answer;
  }
};

// 44 / 44 test cases passed.
// Status: Accepted
// Runtime: 212 ms
// Memory Usage: 57.8 MB
```

with vector

``` cpp
const int SZ = 100010;
class Solution {
public:
  int maxEqualFreq(vector<int>& nums) {
    vector<int> cnt(SZ);
    vector<int> ccnt(SZ);
    int size = 0;
    int answer = 0;
    int len = nums.size();
    for(int i = 0; i < len; ++i) {
      int n = nums[i];
      if(cnt[n]) ccnt[cnt[n]] -= 1;
      if(cnt[n] && !ccnt[cnt[n]]) size -= 1;
      cnt[n] += 1;
      ccnt[cnt[n]] += 1;
      if(ccnt[cnt[n]] == 1) size += 1;
      // cout << i << ' ' << cnt[n] << ' ' << ccnt[cnt[n]] << ' ' << size << endl;
      if(size == 1 && (ccnt[1] || ccnt[cnt[n]] == 1)) {
        answer = i + 1;
        continue;
      }
      if(size != 2) continue;
      if(ccnt[1] == 1) {
        answer = i + 1;
      } else if(ccnt[cnt[n] - 1] && ccnt[cnt[n]] == 1) {
        answer = i + 1;
      } else if(ccnt[cnt[n] + 1] == 1) {
        answer = i + 1;
      }
    }
    
    return answer;
  }
};


// 44 / 44 test cases passed.
// Status: Accepted
// Runtime: 76 ms
// Memory Usage: 79.6 MB
```

with raw arrays

``` cpp
class Solution {
public:
  int maxEqualFreq(vector<int>& nums) {
    int cnt[100100] = {0};
    int ccnt[100100] = {0};
    int size = 0;
    int answer = 0;
    int len = nums.size();
    for(int i = 0; i < len; ++i) {
      int n = nums[i];
      if(cnt[n]) ccnt[cnt[n]] -= 1;
      if(cnt[n] && !ccnt[cnt[n]]) size -= 1;
      cnt[n] += 1;
      ccnt[cnt[n]] += 1;
      if(ccnt[cnt[n]] == 1) size += 1;
      // cout << i << ' ' << cnt[n] << ' ' << ccnt[cnt[n]] << ' ' << size << endl;
      if(size == 1 && (ccnt[1] || ccnt[cnt[n]] == 1)) {
        answer = i + 1;
        continue;
      }
      if(size != 2) continue;
      if(ccnt[1] == 1) {
        answer = i + 1;
      } else if(ccnt[cnt[n] - 1] && ccnt[cnt[n]] == 1) {
        answer = i + 1;
      } else if(ccnt[cnt[n] + 1] == 1) {
        answer = i + 1;
      }
    }
    
    return answer;
  }
};

// 44 / 44 test cases passed.
// Status: Accepted
// Runtime: 52 ms
// Memory Usage: 40.7 MB
```

# April LeetCoding challenge8

## Description

**Letter Combinations of a Phone Number**

Given a string containing digits from `2-9` inclusive, return all possible letter combinations that the number could represent. Return the answer in **any order**.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

![img](https://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png)

 

**Example 1:**

```
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

**Example 2:**

```
Input: digits = ""
Output: []
```

**Example 3:**

```
Input: digits = "2"
Output: ["a","b","c"]
```

 

**Constraints:**

- `0 <= digits.length <= 4`
- `digits[i]` is a digit in the range `['2', '9']`.

## Solution

already done before

``` cpp
class Solution {
public:
  vector<string> letterCombinations(string digits) {
    if(digits.empty()) return vector<string>();
    vector<string> mp = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> nxt;
    vector<string> current{""};
    for(auto c : digits) {
      for(auto &s : current) {
        for(auto letter : mp[c-'2']) {
          nxt.push_back(s+letter);
        }
      }
      current = nxt;
      nxt.clear();
    }
    return current;
  }
};
```
