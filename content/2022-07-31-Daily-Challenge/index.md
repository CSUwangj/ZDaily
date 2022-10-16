+++
updated = 2022-07-31 18:14:00+08:00
title = "2022-07-31 Daily-Challenge"
path = "2022-07-31-Daily-Challenge"
date = 2022-07-31 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/range-sum-query-mutable/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 31

## Description

**Range Sum Query - Mutable**

Given an integer array `nums`, handle multiple queries of the following types:

1. **Update** the value of an element in `nums`.
2. Calculate the **sum** of the elements of `nums` between indices `left` and `right` **inclusive** where `left <= right`.

Implement the `NumArray` class:

- `NumArray(int[] nums)` Initializes the object with the integer array `nums`.
- `void update(int index, int val)` **Updates** the value of `nums[index]` to be `val`.
- `int sumRange(int left, int right)` Returns the **sum** of the elements of `nums` between indices `left` and `right` **inclusive** (i.e. `nums[left] + nums[left + 1] + ... + nums[right]`).

 

**Example 1:**

```
Input
["NumArray", "sumRange", "update", "sumRange"]
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
Output
[null, 9, null, 8]

Explanation
NumArray numArray = new NumArray([1, 3, 5]);
numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
numArray.update(1, 2);   // nums = [1, 2, 5]
numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8
```

 

**Constraints:**

- `1 <= nums.length <= 3 * 104`
- `-100 <= nums[i] <= 100`
- `0 <= index < nums.length`
- `-100 <= val <= 100`
- `0 <= left <= right < nums.length`
- At most `3 * 104` calls will be made to `update` and `sumRange`.

## Solution

``` cpp
class NumArray {
  vector<int> &_nums;
  int len;
  int lazy[30000 << 2] = {};
  int sum[30000 << 2] = {};

  int opL;
  int opR;
  void build(int l, int r, int o = 0) {
    if(l == r) sum[o] = _nums[l];
    else {
      int m = (l + r) >> 1;
      build(l, m, o * 2 + 1);
      build(m + 1, r, o * 2 + 2);
      sum[o] = sum[o * 2 + 1] + sum[o * 2 + 2];
    }
  }

  void pushdown(int o, int c) {
    if(lazy[o]) {
      sum[o * 2 + 1] += c / 2 * lazy[o];
      sum[o * 2 + 2] += (c - c / 2) * lazy[o];
      lazy[o * 2 + 1] = lazy[o];
      lazy[o * 2 + 2] = lazy[o];
      lazy[o] = 0;
    }
  }

  void update(int l, int r, int o, int v) {
    if(l >= opL && r <= opR) {
      sum[o] += (r - l + 1) * v;
      lazy[o] = v;
      return;
    }
    pushdown(o, r - l + 1);
    int m = (l + r) >> 1;
    if(opL <= m) update(l, m, o * 2 + 1, v);
    if(opR > m) update(m + 1, r, o * 2 + 2, v);
    sum[o] = sum[o * 2 + 1] + sum[o * 2 + 2];
  }

  int sumRange(int l, int r, int o) {
    if(l >= opL && r <= opR) return sum[o];
    pushdown(o, r - l + 1);
    int answer = 0;
    int m = (l + r) >> 1;
    if(opL <= m) answer += sumRange(l, m, o * 2 + 1);
    if(opR > m) answer += sumRange(m + 1, r, o * 2 + 2);
    return answer;
  }
public:
  NumArray(vector<int>& nums): _nums(nums){
    len = _nums.size();
    build(0, len - 1);
  }
  
  void update(int index, int val) {
    int diff = val - _nums[index];
    _nums[index] = val;
    opL = index;
    opR = index;
    update(0, len - 1, 0, diff);
  }
  
  int sumRange(int left, int right) {
    opL = left;
    opR = right;
    return sumRange(0, len - 1, 0);
  }
};

// Accepted
// 15/15 cases passed (600 ms)
// Your runtime beats 69.07 % of cpp submissions
// Your memory usage beats 11 % of cpp submissions (165.2 MB)
```
