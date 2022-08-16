+++
updated = 2022-08-16 18:14:00+08:00
title = "2022-08-16 Daily-Challenge"
path = "2022-08-16-Daily-Challenge"
date = 2022-08-16 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/first-unique-character-in-a-string/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 16

## Description

**First Unique Character in a String**

​	Given a string `s`, *find the first non-repeating character in it and return its index*. If it does not exist, return `-1`.

 

**Example 1:**

```
Input: s = "leetcode"
Output: 0
```

**Example 2:**

```
Input: s = "loveleetcode"
Output: 2
```

**Example 3:**

```
Input: s = "aabb"
Output: -1
```

 

**Constraints:**

- `1 <= s.length <= 10^5`
- `s` consists of only lowercase English letters.

## Solution

``` cpp
class Solution {
public:
  int firstUniqChar(string s) {
    vector<int> pos(26, INT_MAX - 1);
    for(int i = 0; i < s.length(); ++i) {
      if(pos[s[i] - 'a'] == INT_MAX - 1) {
        pos[s[i] - 'a'] = i;
      } else {
        pos[s[i] - 'a'] = INT_MAX;
      }
    }
    int result = *min_element(pos.begin(), pos.end());
    return result > s.length() ? -1 : result;
  }
};

// Accepted
// 105/105 cases passed (32 ms)
// Your runtime beats 82.36 % of cpp submissions
// Your memory usage beats 91.52 % of cpp submissions (10.5 MB)
```
