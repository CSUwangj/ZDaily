+++
title = "2022-02-25 Daily-Challenge"
path = "2022-02-25-Daily-Challenge"
date = 2022-02-25 19:08:00+08:00
updated = 2022-02-25 19:11:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/compare-version-numbers/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 25

## Description

**Compare Version Numbers**

Given two version numbers, `version1` and `version2`, compare them.



Version numbers consist of **one or more revisions** joined by a dot `'.'`. Each revision consists of **digits** and may contain leading **zeros**. Every revision contains **at least one character**. Revisions are **0-indexed from left to right**, with the leftmost revision being revision 0, the next revision being revision 1, and so on. For example `2.5.33` and `0.1` are valid version numbers.

To compare version numbers, compare their revisions in **left-to-right order**. Revisions are compared using their **integer value ignoring any leading zeros**. This means that revisions `1` and `001` are considered **equal**. If a version number does not specify a revision at an index, then **treat the revision as `0`**. For example, version `1.0` is less than version `1.1` because their revision 0s are the same, but their revision 1s are `0` and `1` respectively, and `0 < 1`.

*Return the following:*

- If `version1 < version2`, return `-1`.
- If `version1 > version2`, return `1`.
- Otherwise, return `0`.

 

**Example 1:**

```
Input: version1 = "1.01", version2 = "1.001"
Output: 0
Explanation: Ignoring leading zeroes, both "01" and "001" represent the same integer "1".
```

**Example 2:**

```
Input: version1 = "1.0", version2 = "1.0.0"
Output: 0
Explanation: version1 does not specify revision 2, which means it is treated as "0".
```

**Example 3:**

```
Input: version1 = "0.1", version2 = "1.1"
Output: -1
Explanation: version1's revision 0 is "0", while version2's revision 0 is "1". 0 < 1, so version1 < version2.
```

 

**Constraints:**

- `1 <= version1.length, version2.length <= 500`
- `version1` and `version2` only contain digits and `'.'`.
- `version1` and `version2` **are valid version numbers**.
- All the given revisions in `version1` and `version2` can be stored in a **32-bit integer**.

## Solution

``` cpp
class Solution {
  vector<int> parseVersion(const string &version) {
    vector<int> result;
    int current = 0;
    for(auto c : version) {
      if(isdigit(c)) {
        current *= 10;
        current += c - '0';
      } else {
        result.push_back(current);
        current = 0;
      }
    }
    result.push_back(current);
    return result;
  }
public:
  int compareVersion(string version1, string version2) {
    auto v1 = parseVersion(version1);
    auto v2 = parseVersion(version2);
    while(v1.size() != v2.size()) {
      if(v1.size() < v2.size()) {
        v1.push_back(0);
      } else {
        v2.push_back(0);
      }
    }
    if(v1 < v2) return -1;
    if(v1 == v2) return 0;
    return 1;
  }
};

// Accepted
// 81/81 cases passed (5 ms)
// Your runtime beats 15.77 % of cpp submissions
// Your memory usage beats 19.06 % of cpp submissions (6.3 MB)
```
