+++
title = "2021-06-02 Daily-Challenge"
path = "2021-06-02-Daily-Challenge"
date = 2021-06-02 19:08:03+08:00
updated = 2021-06-02 20:21:38+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Online Election](https://leetcode.com/problems/online-election/description/) and leetcode's [June LeetCoding Challenge](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/603/week-1-june-1st-june-7th/3765/) with `cpp`.

<!-- more -->

# Online Election

## Description

In an election, the `i`-th vote was cast for `persons[i]` at time `times[i]`.

Now, we would like to implement the following query function: `TopVotedCandidate.q(int t)` will return the number of the person that was leading the election at time `t`. 

Votes cast at time `t` will count towards our query. In the case of a tie, the most recent vote (among tied candidates) wins.

 

**Example 1:**

```
Input: ["TopVotedCandidate","q","q","q","q","q","q"], [[[0,1,1,0,0,1,0],[0,5,10,15,20,25,30]],[3],[12],[25],[15],[24],[8]]
Output: [null,0,1,1,0,0,1]
Explanation: 
At time 3, the votes are [0], and 0 is leading.
At time 12, the votes are [0,1,1], and 1 is leading.
At time 25, the votes are [0,1,1,0,0,1], and 1 is leading (as ties go to the most recent vote.)
This continues for 3 more queries at time 15, 24, and 8.
```

 

**Note:**

1. `1 <= persons.length = times.length <= 5000`
2. `0 <= persons[i] <= persons.length`
3. `times` is a strictly increasing array with all elements in `[0, 10^9]`.
4. `TopVotedCandidate.q` is called at most `10000` times per test case.
5. `TopVotedCandidate.q(int t)` is always called with `t >= times[0]`.

## Solution

``` cpp
class TopVotedCandidate {
  vector<int> leading;
  vector<int> &_times;
  int len;
public:
  TopVotedCandidate(vector<int>& persons, vector<int>& times): _times(times) {
    unordered_map<int, int> cnt;
    len = persons.size();
    leading.resize(len);
    int curMax = 0;
    int curLeading = -1;
    for(int i = 0; i < len; ++i) {
      cnt[persons[i]] += 1;
      if(cnt[persons[i]] >= curMax) {
        curMax = cnt[persons[i]];
        curLeading = persons[i];
      }
      leading[i] = curLeading;
    }
  }
  
  int q(int t) {
    int offset = upper_bound(_times.begin(), _times.end(), t) - _times.begin();
    return offset == len ? leading.back() : leading[offset - 1];
  }
};

```

# June LeetCoding Challenge2

## Description

**Interleaving String**

Given strings `s1`, `s2`, and `s3`, find whether `s3` is formed by an **interleaving** of `s1` and `s2`.

An **interleaving** of two strings `s` and `t` is a configuration where they are divided into **non-empty** substrings such that:

- `s = s1 + s2 + ... + sn`
- `t = t1 + t2 + ... + tm`
- `|n - m| <= 1`
- The **interleaving** is `s1 + t1 + s2 + t2 + s3 + t3 + ...` or `t1 + s1 + t2 + s2 + t3 + s3 + ...`

**Note:** `a + b` is the concatenation of strings `a` and `b`.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/09/02/interleave.jpg)

```
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
```

**Example 2:**

```
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
```

**Example 3:**

```
Input: s1 = "", s2 = "", s3 = ""
Output: true
```

 

**Constraints:**

- `0 <= s1.length, s2.length <= 100`
- `0 <= s3.length <= 200`
- `s1`, `s2`, and `s3` consist of lowercase English letters.

 

**Follow up:** Could you solve it using only `O(s2.length)` additional memory space?

## Solution

``` cpp
class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    int len1 = s1.length();
    int len2 = s2.length();
    int len3 = s3.length();
    if(len1 + len2 != len3) return false;
    bool dp[len2 + 1];
    for(int i = 0; i <= len1; ++i) {
      for(int j = 0; j <= len2; ++j) {
        if(!i && !j) {
          dp[j] = true;
        } else if(!i) {
          dp[j] = dp[j - 1] && (s2[j - 1] == s3[i + j - 1]);
        } else if(!j) {
          dp[j] = dp[j] && (s1[i - 1] == s3[i + j - 1]);
        } else {
          dp[j] = (dp[j - 1] && (s2[j - 1] == s3[i + j - 1])) ||
                  (dp[j] && (s1[i - 1] == s3[i + j - 1]));
        }
      }
    }
    return dp[len2];
  }
};
```
