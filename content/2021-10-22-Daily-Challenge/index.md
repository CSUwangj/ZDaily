+++
title = "2021-10-22 Daily-Challenge"
path = "2021-10-22-Daily-Challenge"
date = 2021-10-22 17:25:33+08:00
updated = 2021-10-22 17:31:42+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/sort-characters-by-frequency/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 22

## Description

**Sort Characters By Frequency**

Given a string `s`, sort it in **decreasing order** based on the **frequency** of the characters. The **frequency** of a character is the number of times it appears in the string.

Return *the sorted string*. If there are multiple answers, return *any of them*.

 

**Example 1:**

```
Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
```

**Example 2:**

```
Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
```

**Example 3:**

```
Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
```

 

**Constraints:**

- `1 <= s.length <= 5 * 10^5`
- `s` consists of uppercase and lowercase English letters and digits.

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  int count[128] = {};
public:
  string frequencySort(string s) {
    for(auto c : s) {
      count[c] += 1;
    }
    sort(s.begin(), s.end(), [&](char a, char b) {
      return count[a] > count[b] || (count[a] == count[b] && a > b);
    });
    return s;
  }
};

// Accepted
// 32/32 cases passed (24 ms)
// Your runtime beats 21.2 % of cpp submissions
// Your memory usage beats 92.44 % of cpp submissions (8 MB)
```
