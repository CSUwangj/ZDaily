+++
title = "2020-10-05 Daily-Challenge"
path = "2020-10-05-Daily-Challenge"
date = 2020-10-05 14:12:08+08:00
updated = 2020-10-05 15:23:09+08:00

[taxonomies]
tags = ["Design", "Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is an example of *The non-Designer's Design Book* on bottom of Page 56 and *Range Sum Query - Mutable* on [leetcode](https://leetcode.com/problems/range-sum-query-mutable/) and leetcode's [October LeetCoding Challenge](https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/559/week-1-october-1st-october-7th/3484/) with `cpp`.

BTW, I decided to have Saturday and Sunday as review days, so pressure of review doesn't get me down.

<!-- more -->

# The non-Designer's Design Book

my answer:

- [F] color of green text
- [F] color of purple text
- [F] color of green background
- [F] font of green text

shit...

# Range Sum Query - Mutable

## Description
Given an integer array *nums*, find the sum of the elements between indices *i* and *j* (*i* ≤ *j*), inclusive.

The *update(i, val)* function modifies *nums* by updating the element at index *i* to *val*.

**Example:**

```
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
```

**Constraints:**

- The array is only modifiable by the *update* function.
- You may assume the number of calls to *update* and *sumRange* function is distributed evenly.
- `0 <= i <= j <= nums.length - 1`

## Solution

using Binary Indexed Tree, I'll do it using segment tree for review.

``` cpp
class NumArray {
  vector<int> original;
  vector<int> bit;
  int lowbit(int x) {
    return x&(-x);
  }
  int sum(int x) {
    int ans = 0;
    while(x) {
      ans += bit[x];
      x -= lowbit(x);
    }
    return ans;
  }
  void add(int pos, int val) {
    while(pos < bit.size()) {
      bit[pos] += val;
      pos += lowbit(pos);
    }
  }
public:
  NumArray(vector<int>& nums) {
    original = nums;
    bit = vector<int>(nums.size()+1, 0);
    for (int i = 0; i < nums.size(); ++i) {
      add(i+1, nums[i]);
    }
  }
  
  void update(int i, int val) {
    int diff = val - original[i];
    original[i] = val;
    add(i+1, diff);
    return;
  }
  
  int sumRange(int i, int j) {
    return sum(j+1) - sum(i);
  }
};
```

# October LeetCoding Challenge 5

## Description

**Complement of Base 10 Integer**

Every non-negative integer `N` has a binary representation. For example, `5` can be represented as `"101"` in binary, `11` as `"1011"` in binary, and so on. Note that except for `N = 0`, there are no leading zeroes in any binary representation.

The *complement* of a binary representation is the number in binary you get when changing every `1` to a `0` and `0` to a `1`. For example, the complement of `"101"` in binary is `"010"` in binary.

For a given number `N` in base-10, return the complement of it's binary representation as a base-10 integer.

**Example 1:**

```
Input: 5
Output: 2
Explanation: 5 is "101" in binary, with complement "010" in binary, which is 2 in base-10.
```

**Example 2:**

```
Input: 7
Output: 0
Explanation: 7 is "111" in binary, with complement "000" in binary, which is 0 in base-10.
```

**Example 3:**

```
Input: 10
Output: 5
Explanation: 10 is "1010" in binary, with complement "0101" in binary, which is 5 in base-10.
```

**Note:**

1. `0 <= N < 10^9`
2. This question is the same as 476: https://leetcode.com/problems/number-complement/

## Solution

buildin function seems still be function

``` cpp
class Solution {
public:
  int bitwiseComplement(int N) {
    return ~N & ((1 << (32-__builtin_clz(N|1)))-1);
  }
};
```