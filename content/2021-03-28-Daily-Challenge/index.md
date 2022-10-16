+++
title = "2021-03-28 Daily-Challenge"
path = "2021-03-28-Daily-Challenge"
date = 2021-03-28 16:00:00+08:00
updated = 2021-03-28 16:29:20+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [March LeetCoding Challenge](https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/591/week-4-march-22nd-march-28th/3687/) with `cpp`.


<!-- more -->

# March LeetCoding Challenge 28

## Description

**Reconstruct Original Digits from English**

Given a **non-empty** string containing an out-of-order English representation of digits `0-9`, output the digits in ascending order.

**Note:**

1. Input contains only lowercase English letters.
2. Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
3. Input length is less than 50,000.



**Example 1:**

```
Input: "owoztneoer"

Output: "012"
```



**Example 2:**

```
Input: "fviefuro"

Output: "45"
```

## Solution

``` cpp
class Solution {
  int cnt[10];
public:
  string originalDigits(string s) {
    for(int i = 0; i < s.length(); ++i) {
      switch(s[i]){
        case 'z':
          cnt[0] += 1;
          break;
        case 'w':
          cnt[2] += 1;
          break;
        case 'x':
          cnt[6] += 1;
          break;
        case 'g':
          cnt[8] += 1;
          break;
        case 's':
          cnt[7] += 1;
          break;
        case 'v':
          cnt[5] += 1;
          break;
        case 'f':
          cnt[4] += 1;
          break;
        case 't':
          cnt[3] += 1;
          break;
        case 'o':
          cnt[1] += 1;
          break;
        case 'i':
          cnt[9] += 1;
          break;
      }
    }
    cnt[7] -= cnt[6];
    cnt[5] -= cnt[7];
    cnt[4] -= cnt[5];
    cnt[3] -= cnt[2] + cnt[8];
    cnt[1] -= cnt[0] + cnt[2] + cnt[4];
    cnt[9] -= cnt[6] + cnt[8] + cnt[5];
    string answer;
    for(int i = 0; i < 10; ++i) {
      while(cnt[i]) {
        answer.push_back(i + '0');
        cnt[i] -= 1;
      }
    }
    return answer;
  }
};
```
