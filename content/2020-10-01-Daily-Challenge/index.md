+++
title = "2020-10-01 Daily-Challenge"
path = "2020-10-01-Daily-Challenge"
date = 2019-10-01
updated = 2020-10-01 12:27:00+08:00
in_search_index = true

[taxonomies]
tags = ["Design", "Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is an example of *The non-Designer's Design Book* on Page 54 and *Check If a Word Occurs As a Prefix of Any Word in a Sentence* on [leetcode](https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/) with `cpp`.

<!-- more -->

# The non-Designer's Design Book

my answer:

- [T] color scheme of top and bottom
- [F] heart shape
- [F] subtitle's font and color
- [T] dividing line
- [T] font of title and subtitle

# Reconstruct Original Digits from English

## Description
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

there are unique characters in words so that you can easily find what numbers
in the string.

``` cpp
class Solution {
  int cnt[256];
public:
  string originalDigits(string s) {
    for(auto &a: s) {
      cnt[a] += 1;
    }
    while(cnt['z']) {
      cnt['z'] -= 1;
      cnt['e'] -= 1;
      cnt['r'] -= 1;
      cnt['o'] -= 1;
      cnt[0] += 1;
    }
    while(cnt['x']) {
      cnt['s'] -= 1;
      cnt['i'] -= 1;
      cnt['x'] -= 1;
      cnt[6] += 1;
    }
    while(cnt['w']) {
      cnt['t'] -= 1;
      cnt['w'] -= 1;
      cnt['o'] -= 1;
      cnt[2] += 1;
    }
    while(cnt['g']) {
      cnt['e'] -= 1;
      cnt['i'] -= 1;
      cnt['g'] -= 1;
      cnt['h'] -= 1;
      cnt['t'] -= 1;
      cnt[8] += 1;
    }
    while(cnt['s']) {
      cnt['s'] -= 1;
      cnt['e'] -= 1;
      cnt['v'] -= 1;
      cnt['e'] -= 1;
      cnt['n'] -= 1;
      cnt[7] += 1;
    }
    while(cnt['v']) {
      cnt['f'] -= 1;
      cnt['i'] -= 1;
      cnt['v'] -= 1;
      cnt['e'] -= 1;
      cnt[5] += 1;
    }
    while(cnt['f']) {
      cnt['f'] -= 1;
      cnt['o'] -= 1;
      cnt['u'] -= 1;
      cnt['r'] -= 1;
      cnt[4] += 1;
    }
    while(cnt['t']) {
      cnt['t'] -= 1;
      cnt['h'] -= 1;
      cnt['r'] -= 1;
      cnt['e'] -= 1;
      cnt['e'] -= 1;
      cnt[3] += 1;
    }
    while(cnt['i']) {
      cnt['n'] -= 1;
      cnt['i'] -= 1;
      cnt['n'] -= 1;
      cnt['e'] -= 1;
      cnt[9] += 1;
    }
    while(cnt['o']) {
      cnt['o'] -= 1;
      cnt['n'] -= 1;
      cnt['e'] -= 1;
      cnt[1] += 1;
    }
    stringstream ss;
    for(int i = 0; i < 10; ++i) {
      while(cnt[i]) {
        ss << i;
        cnt[i] -= 1;
      }
    }
    return ss.str();
  }
};
```