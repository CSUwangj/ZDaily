+++
updated = 2022-05-31 18:14:00+08:00
title = "2022-05-31 Daily-Challenge"
path = "2022-05-31-Daily-Challenge"
date = 2022-05-31 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 31

## Description

**Check If a String Contains All Binary Codes of Size K**

​Given a binary string `s` and an integer `k`, return `true` *if every binary code of length* `k` *is a substring of* `s`. Otherwise, return `false`.

 

**Example 1:**

```
Input: s = "00110110", k = 2
Output: true
Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indices 0, 1, 3 and 2 respectively.
```

**Example 2:**

```
Input: s = "0110", k = 1
Output: true
Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring. 
```

**Example 3:**

```
Input: s = "0110", k = 2
Output: false
Explanation: The binary code "00" is of length 2 and does not exist in the array.
```

 

**Constraints:**

- `1 <= s.length <= 5 * 105`
- `s[i]` is either `'0'` or `'1'`.
- `1 <= k <= 20`

## Solution

``` cpp
class Solution {
public:
  bool hasAllCodes(string s, int k) {
    int len = s.length();
    if((1 << k) > len - k + 1) return false;
    int cur = 0;
    const int MASK = (1 << k) - 1;
    vector<bool> has(1 << k);
    for(int i = 0; i < k; ++i) {
      cur <<= 1;
      cur |= (s[i] == '1');
    }
    has[cur] = true;
    for(int i = k; i < len; ++i) {
      cur <<= 1;
      cur |= (s[i] == '1');
      cur &= MASK;
      has[cur] = true;
    }
    for(auto b : has) if(!b) return false;
    return true;
  }
};

// Accepted
// 200/200 cases passed (92 ms)
// Your runtime beats 88.99 % of cpp submissions
// Your memory usage beats 99.37 % of cpp submissions (17.4 MB)
```
