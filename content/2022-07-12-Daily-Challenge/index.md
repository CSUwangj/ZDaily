+++
updated = 2022-07-12 18:14:00+08:00
title = "2022-07-12 Daily-Challenge"
path = "2022-07-12-Daily-Challenge"
date = 2022-07-12 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/matchsticks-to-square/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 12

## Description

**Matchsticks to Square**

You are given an integer array `matchsticks` where `matchsticks[i]` is the length of the `ith` matchstick. You want to use **all the matchsticks** to make one square. You **should not break** any stick, but you can link them up, and each matchstick must be used **exactly one time**.

Return `true` if you can make this square and `false` otherwise.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/04/09/matchsticks1-grid.jpg)

```
Input: matchsticks = [1,1,2,2,2]
Output: true
Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
```

**Example 2:**

```
Input: matchsticks = [3,3,3,3,4]
Output: false
Explanation: You cannot find a way to form a square with all the matchsticks.
```

 

**Constraints:**

- `1 <= matchsticks.length <= 15`
- `1 <= matchsticks[i] <= 10^8`

## Solution

``` cpp
using ll = long long;
class Solution {
  int len;
  long long target;
  bool solve(vector<int> &m, ll a, ll b, ll c, ll d, ll l) {
    if(l == len && a == target && b == target && c == target && d == target) {
      return true;
    }
    if(a > target || b > target || c > target || d > target) {
      return false;
    }
    if(solve(m, a + ll(m[l]), b, c, d, l + 1)) return true;
    if(solve(m, a, b + ll(m[l]), c, d, l + 1)) return true;
    if(solve(m, a, b, c + ll(m[l]), d, l + 1)) return true;
    return solve(m, a, b, c, d + ll(m[l]), l + 1);
  }
public:
  bool makesquare(vector<int>& matchsticks) {
    len = matchsticks.size();
    if(len < 4) return false;
    sort(matchsticks.rbegin(), matchsticks.rend());
    long long sum = 0;
    for(auto l : matchsticks) sum += l;
    if(sum % 4 || matchsticks.back() > sum / 4) return false;
    target = sum / 4;
    return solve(matchsticks, 0, 0, 0, 0, 0); 
  }
};

// Accepted
// 195/195 cases passed (413 ms)
// Your runtime beats 48.03 % of cpp submissions
// Your memory usage beats 47.49 % of cpp submissions (10.1 MB)
```
