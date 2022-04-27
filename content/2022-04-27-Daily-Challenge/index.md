+++
updated = 2022-04-27 19:58:00+08:00
title = "2022-04-27 Daily-Challenge"
path = "2022-04-27-Daily-Challenge"
date = 2022-04-27 19:57:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/smallest-string-with-swaps/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 27

## Description

**Smallest String With Swaps**

You are given a string `s`, and an array of pairs of indices in the string `pairs` where `pairs[i] = [a, b]` indicates 2 indices(0-indexed) of the string.

You can swap the characters at any pair of indices in the given `pairs` **any number of times**.

Return the lexicographically smallest string that `s` can be changed to after using the swaps.

 

**Example 1:**

```
Input: s = "dcab", pairs = [[0,3],[1,2]]
Output: "bacd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"
```

**Example 2:**

```
Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
Output: "abcd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[0] and s[2], s = "acbd"
Swap s[1] and s[2], s = "abcd"
```

**Example 3:**

```
Input: s = "cba", pairs = [[0,1],[1,2]]
Output: "abc"
Explaination: 
Swap s[0] and s[1], s = "bca"
Swap s[1] and s[2], s = "bac"
Swap s[0] and s[1], s = "abc"
```

 

**Constraints:**

- `1 <= s.length <= 10^5`
- `0 <= pairs.length <= 10^5`
- `0 <= pairs[i][0], pairs[i][1] < s.length`
- `s` only contains lower case English letters.

## Solution

sort the characters in the same union set 

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
struct UnionSet {
  vector<int> parent;
public:
  UnionSet(int size): parent(size) {
    for(int i = 0; i < size; ++i) {
      parent[i] = i;
    }
  }

  int find(int x) {
    if(parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
  }

  void merge(int x, int y) {
    x = find(x);
    y = find(y);
    parent[x] = y;
  }
};
class Solution {
public:
  string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
    int len = s.length();
    UnionSet us(s.length());
    for(const auto &pair : pairs) {
      us.merge(pair[0], pair[1]);
    }
    unordered_map<int, vector<int>> indice;
    unordered_map<int, string> chars;
    for(int i = 0; i < len; ++i) {
      int parent = us.find(i);
      indice[parent].push_back(i);
      chars[parent].push_back(s[i]);
    }
    for(auto &[parent, s] : chars) {
      sort(s.begin(), s.end());
    }
    string answer(len, '\x00');
    for(const auto &[parent, index]: indice) {
      for(int i = 0; i < index.size(); ++i) {
        answer[index[i]] = chars[parent][i];
      }
    }
    return move(answer);
  }
};

// Accepted
// 36/36 cases passed (176 ms)
// Your runtime beats 85.32 % of cpp submissions
// Your memory usage beats 73.82 % of cpp submissions (49.6 MB)
```
