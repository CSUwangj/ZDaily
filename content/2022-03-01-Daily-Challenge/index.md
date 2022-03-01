+++
title = "2022-03-01 Daily-Challenge"
path = "2022-03-01-Daily-Challenge"
date = 2022-03-01 18:00:00+08:00
updated = 2022-03-01 18:01:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/counting-bits/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 1

## Description

**Counting Bits**

Given an integer `n`, return *an array* `ans` *of length* `n + 1` *such that for each* `i` (`0 <= i <= n`)*,* `ans[i]` *is the **number of*** `1`***'s** in the binary representation of* `i`.

 

**Example 1:**

```
Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
```

**Example 2:**

```
Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
```

 

**Constraints:**

- `0 <= n <= 10^5`

 

**Follow up:**

- It is very easy to come up with a solution with a runtime of `O(n log n)`. Can you do it in linear time `O(n)` and possibly in a single pass?
- Can you do it without using any built-in function (i.e., like `__builtin_popcount` in C++)?

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
constexpr int pop_count(int x) {
  const int m1  = 0X55555555;
  const int m2  = 0X33333333;
  const int m4  = 0X0F0F0F0F;
  const int m8  = 0X00FF00FF;
  const int m16 = 0X0000FFFF;
  x = (x &  m1) + ((x >>  1) &  m1);
  x = (x &  m2) + ((x >>  2) &  m2);
  x = (x &  m4) + ((x >>  4) &  m4);
  x = (x &  m8) + ((x >>  8) &  m8);
  x = (x & m16) + ((x >> 16) & m16);
  return x;
}
class Solution {
public:
  vector<int> countBits(int n) {
    vector<int> answer(n + 1);
    for(int i = 1; i <= n; ++i) {
      answer[i] = pop_count(i);
    }
    return move(answer);
  }
};

// Accepted
// 15/15 cases passed (12 ms)
// Your runtime beats 25.62 % of cpp submissions
// Your memory usage beats 48.88 % of cpp submissions (8 MB)
```
