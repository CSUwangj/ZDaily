+++
title = "2021-12-13 Daily-Challenge"
path = "2021-12-13-Daily-Challenge"
date = 2021-12-13 18:33:00+08:00
updated = 2021-12-13 18:35:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/consecutive-characters/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 13

## Description

**Consecutive Characters**

The **power** of the string is the maximum length of a non-empty substring that contains only one unique character.

Given a string `s`, return *the **power** of* `s`.

 

**Example 1:**

```
Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 'e' only.
```

**Example 2:**

```
Input: s = "abbcccddddeeeeedcba"
Output: 5
Explanation: The substring "eeeee" is of length 5 with the character 'e' only.
```

**Example 3:**

```
Input: s = "triplepillooooow"
Output: 5
```

**Example 4:**

```
Input: s = "hooraaaaaaaaaaay"
Output: 11
```

**Example 5:**

```
Input: s = "tourist"
Output: 1
```

 

**Constraints:**

- `1 <= s.length <= 500`
- `s` consists of only lowercase English letters.

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int maxPower(string s) {
    int answer = 0;
    int cur = 0;
    char last = 0;
    for(auto c : s) {
      if(c != last) {
        last = c;
        cur = 0;
      }
      cur += 1;
      answer = max(answer, cur);
    }
    return answer;
  }
};

// Accepted
// 333/333 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 72.13 % of cpp submissions (6.8 MB)
```
