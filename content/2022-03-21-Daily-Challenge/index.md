+++
updated = 2022-03-21 18:25:00+08:00
title = "2022-03-21 Daily-Challenge"
path = "2022-03-21-Daily-Challenge"
date = 2022-03-21 18:22:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/partition-labels/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 21

## Description

**Partition Labels**

You are given a string `s`. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be `s`.

Return *a list of integers representing the size of these parts*.

 

**Example 1:**

```
Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
```

**Example 2:**

```
Input: s = "eccbbbbdec"
Output: [10]
```

 

**Constraints:**

- `1 <= s.length <= 500`
- `s` consists of lowercase English letters.

## Solution

``` cpp
class Solution {
public:
  vector<int> partitionLabels(string s) {
    vector<pair<int, int>> pos(26, {-1, -1});
    for(int i = 0; i < s.length(); ++i) {
      if(pos[s[i] - 'a'].first == -1) {
        pos[s[i] - 'a'].first = i;
      }
      pos[s[i] - 'a'].second = i;
    }
    sort(pos.begin(), pos.end());
    vector<int> answer;
    int begin = pos.front().first;
    int end = pos.front().second;
    for(auto [b, e] : pos) {
      if(b > end) {
        if(begin != -1) {
          answer.push_back(end - begin + 1);
        }
        begin = b;
        end = e;
      } else {
        end = max(end, e);
      }
    }
    answer.push_back(end - begin + 1);
    return answer;
  }
};

// Accepted
// 117/117 cases passed (3 ms)
// Your runtime beats 85.7 % of cpp submissions
// Your memory usage beats 64.08 % of cpp submissions (6.6 MB)
```
