+++
updated = 2022-09-26 18:14:00+08:00
title = "2022-09-26 Daily-Challenge"
path = "2022-09-26-Daily-Challenge"
date = 2022-09-26 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/satisfiability-of-equality-equations/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 26

## Description

**Satisfiability of Equality Equations**

You are given an array of strings `equations` that represent relationships between variables where each string `equations[i]` is of length `4` and takes one of two different forms: `"xi==yi"` or `"xi!=yi"`.Here, `xi` and `yi` are lowercase letters (not necessarily different) that represent one-letter variable names.

Return `true` *if it is possible to assign integers to variable names so as to satisfy all the given equations, or* `false` *otherwise*.

 

**Example 1:**

```
Input: equations = ["a==b","b!=a"]
Output: false
Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
There is no way to assign the variables to satisfy both equations.
```

**Example 2:**

```
Input: equations = ["b==a","a==b"]
Output: true
Explanation: We could assign a = 1 and b = 1 to satisfy both equations.
```

 

**Constraints:**

- `1 <= equations.length <= 500`
- `equations[i].length == 4`
- `equations[i][0]` is a lowercase letter.
- `equations[i][1]` is either `'='` or `'!'`.
- `equations[i][2]` is `'='`.
- `equations[i][3]` is a lowercase letter.

## Solution

``` cpp
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
  bool equationsPossible(vector<string>& equations) {
    UnionSet us(26);
    for(const auto &equation : equations) {
      if(equation[1] == '=') {
        us.merge(equation[0] - 'a', equation[3] - 'a');
      }
    }

    for(const auto &equation : equations) {
      if(equation[1] == '!' && us.find(equation[0] - 'a') == us.find(equation[3] - 'a')) {
        return false;
      }
    }
    return true;
  }
};

// Accepted
// 181/181 cases passed (19 ms)
// Your runtime beats 16.42 % of cpp submissions
// Your memory usage beats 44.49 % of cpp submissions (11.4 MB)
```
