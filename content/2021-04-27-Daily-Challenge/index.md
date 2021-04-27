+++
title = "2021-04-27 Daily-Challenge"
path = "2021-04-27-Daily-Challenge"
date = 2021-04-27 19:43:30+08:00
updated = 2021-04-27 20:35:24+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Lexicographically Smallest String After Applying Operations](https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/) and leetcode's [April LeetCoding Challenge](https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/596/week-4-april-22nd-april-28th/3721/) with `cpp`.

<!-- more -->

# Lexicographically Smallest String After Applying Operations

## Description

You can apply either of the following two operations any number of times and in any order on `s`:

- Add `a` to all odd indices of `s` **(0-indexed)**. Digits post `9` are cycled back to `0`. For example, if `s = "3456"` and `a = 5`, `s` becomes `"3951"`.
- Rotate `s` to the right by `b` positions. For example, if `s = "3456"` and `b = 1`, `s` becomes `"6345"`.

Return *the **lexicographically smallest** string you can obtain by applying the above operations any number of times on* `s`.

A string `a` is lexicographically smaller than a string `b` (of the same length) if in the first position where `a` and `b` differ, string `a` has a letter that appears earlier in the alphabet than the corresponding letter in `b`. For example, `"0158"` is lexicographically smaller than `"0190"` because the first position they differ is at the third letter, and `'5'` comes before `'9'`.

 

**Example 1:**

```
Input: s = "5525", a = 9, b = 2
Output: "2050"
Explanation: We can apply the following operations:
Start:  "5525"
Rotate: "2555"
Add:    "2454"
Add:    "2353"
Rotate: "5323"
Add:    "5222"
Add:    "5121"
Rotate: "2151"
Add:    "2050"
There is no way to obtain a string that is lexicographically smaller then "2050".
```

**Example 2:**

```
Input: s = "74", a = 5, b = 1
Output: "24"
Explanation: We can apply the following operations:
Start:  "74"
Rotate: "47"
Add:    "42"
Rotate: "24"
There is no way to obtain a string that is lexicographically smaller then "24".
```

**Example 3:**

```
Input: s = "0011", a = 4, b = 2
Output: "0011"
Explanation: There are no sequence of operations that will give us a lexicographically smaller string than "0011".
```

**Example 4:**

```
Input: s = "43987654", a = 7, b = 3
Output: "00553311"
```

 

**Constraints:**

- `2 <= s.length <= 100`
- `s.length` is even.
- `s` consists of digits from `0` to `9` only.
- `1 <= a <= 9`
- `1 <= b <= s.length - 1`

## Solution

I first write this and got `TLE`

``` cpp
class Solution {
  string rotate(string &s, int b) {
    return s.substr(s.length() - b, b) + s.substr(0, s.length() - b);
  }
  void add(string &s, int a) {
    for(int i = 1; i < s.length(); i += 2) {
      s[i] = (s[i] - '0' + a) % 10 + '0';
    }
  }
public:
  string findLexSmallestString(string s, int a, int b) {
    set<string> count{s};
    set<string> vis;
    int sz;
    do {
      sz = count.size();
      set<string> tmp;
      for(auto s : count) {
        if(!vis.count(s)) {
          vis.insert(s);
          tmp.insert(rotate(s, b));
          add(s, a);
          tmp.insert(s);
        }
      }
      count.merge(tmp);
    } while(sz != count.size());
    return *count.begin();
  }
};
```

then rewrite as follows:

``` cpp
class Solution {
  string rotate(string &s, int b) {
    return s.substr(s.length() - b, b) + s.substr(0, s.length() - b);
  }
  void add(string &s, int a) {
    for(int i = 1; i < s.length(); i += 2) {
      s[i] = (s[i] - '0' + a) % 10 + '0';
    }
  }
  void dfs(string s, set<string> &vis, int a, int b) {
    if(vis.count(s)) return;
    vis.insert(s);
    dfs(rotate(s, b), vis, a, b);
    for(int i = 0; i < 9; ++i) {
      add(s, a);
      dfs(s, vis, a, b);
    }
  }
public:
  string findLexSmallestString(string s, int a, int b) {
    set<string> vis;
    dfs(s, vis, a, b);
    return *vis.begin();
  }
};

// 80/80 cases passed (1216 ms)
// Your runtime beats 5.02 % of cpp submissions
// Your memory usage beats 5.02 % of cpp submissions (187.7 MB)
```

ok, I will optimize it later.

# April LeetCoding challenge27

## Description

**Power of Three**

Given an integer `n`, return *`true` if it is a power of three. Otherwise, return `false`*.

An integer `n` is a power of three, if there exists an integer `x` such that `n == 3x`.

 

**Example 1:**

```
Input: n = 27
Output: true
```

**Example 2:**

```
Input: n = 0
Output: false
```

**Example 3:**

```
Input: n = 9
Output: true
```

**Example 4:**

```
Input: n = 45
Output: false
```

 

**Constraints:**

-<code>-2<sup>31</sup> <= n <= 2<sup>31</sup> - 1</code>

 

**Follow up:** Could you solve it without loops/recursion?


## Solution

``` cpp
const unordered_set<int> ST{1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969, 14348907, 43046721, 129140163, 387420489, 1162261467};
class Solution {
public:
  bool isPowerOfThree(int n) {
    return ST.count(n);
  }
};
```

``` cpp
class Solution {
public:
  bool isPowerOfThree(int n) {
    return n > 0 && 1162261467 % n == 0;
  }
};
```
