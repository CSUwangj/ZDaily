+++
title = "2021-09-22 Daily-Challenge"
path = "2021-09-22-Daily-Challenge"
date = 2021-09-22 19:03:44+08:00
updated = 2021-09-22 19:22:09+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/639/week-4-september-22nd-september-28th/3984/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 22

## Description

**Maximum Length of a Concatenated String with Unique Characters**

Given an array of strings `arr`. String `s` is a concatenation of a sub-sequence of `arr` which have **unique characters**.

Return *the maximum possible length* of `s`.

 

**Example 1:**

```
Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All possible concatenations are "","un","iq","ue","uniq" and "ique".
Maximum length is 4.
```

**Example 2:**

```
Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible solutions are "chaers" and "acters".
```

**Example 3:**

```
Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
```

 

**Constraints:**

- `1 <= arr.length <= 16`
- `1 <= arr[i].length <= 26`
- `arr[i]` contains only lower case English letters.

## Solution

``` cpp
class Solution {
  int answer = 0;
  int len;
  vector<int> masks;
  vector<int> lens;
  void init(vector<string>& arr) {
    len = arr.size();
    masks.resize(len);
    lens.resize(len);

    for(int i = 0; i < len; ++i) {
      lens[i] = arr[i].length();
      for(auto c : arr[i]) {
        int m = (1 << (c - 'a'));
        if(m & masks[i]) {
          masks[i] = 0;
          lens[i] = 0;
          break;
        }
        masks[i] |= m;
      }
    }
  }

  void solve(int index = 0, int mask = 0, int length = 0) {
    if(index == len) {
      if(length > answer) answer = length;
      return;
    }
    solve(index + 1, mask, length);
    if(lens[index] && (masks[index] & mask) == 0) {
      solve(index + 1, mask | masks[index], length + lens[index]);
    }
  }
public:
  int maxLength(vector<string>& arr) {
    init(arr);
    solve();
    return answer;
  }
};

// Accepted
// 85/85 cases passed (4 ms)
// Your runtime beats 95.24 % of cpp submissions
// Your memory usage beats 93.33 % of cpp submissions (8 MB)
```
