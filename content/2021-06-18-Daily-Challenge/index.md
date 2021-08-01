+++
title = "2021-06-18 Daily-Challenge"
path = "2021-06-18-Daily-Challenge"
date = 2021-06-18 17:43:49+08:00
updated = 2021-06-18 18:03:36+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Sort Integers by The Number of 1 Bits](https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/description/) and leetcode's [June LeetCoding Challenge](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/605/week-3-june-15th-june-21st/3783/) with `cpp`.

<!-- more -->

# Sort Integers by The Number of 1 Bits

## Description

Given an integer array `arr`. You have to sort the integers in the array in ascending order by the number of **1's** in their binary representation and in case of two or more integers have the same number of **1's** you have to sort them in ascending order.

Return *the sorted array*.

 

**Example 1:**

```
Input: arr = [0,1,2,3,4,5,6,7,8]
Output: [0,1,2,4,8,3,5,6,7]
Explantion: [0] is the only integer with 0 bits.
[1,2,4,8] all have 1 bit.
[3,5,6] have 2 bits.
[7] has 3 bits.
The sorted array by bits is [0,1,2,4,8,3,5,6,7]
```

**Example 2:**

```
Input: arr = [1024,512,256,128,64,32,16,8,4,2,1]
Output: [1,2,4,8,16,32,64,128,256,512,1024]
Explantion: All integers have 1 bit in the binary representation, you should just sort them in ascending order.
```

**Example 3:**

```
Input: arr = [10000,10000]
Output: [10000,10000]
```

**Example 4:**

```
Input: arr = [2,3,5,7,11,13,17,19]
Output: [2,3,5,17,7,11,13,19]
```

**Example 5:**

```
Input: arr = [10,100,1000,10000]
Output: [10,100,10000,1000]
```

 

**Constraints:**

- `1 <= arr.length <= 500`
- `0 <= arr[i] <= 10^4`

## Solution

``` cpp
const int M1  = 0X55555555; // 01010101010101010101010101010101
const int M2  = 0X33333333; // 00110011001100110011001100110011
const int M4  = 0X0F0F0F0F; // 00001111000011110000111100001111
const int M8  = 0X00FF00FF; // 00000000111111110000000011111111
const int M16 = 0X0000FFFF; // 00000000000000001111111111111111
constexpr int popcount(int x) { 
  x = (x & M1) + ((x >> 1) & M1);
  x = (x & M2) + ((x >> 2) & M2);
  x = (x & M4) + ((x >> 4) & M4);
  x = (x & M8) + ((x >> 8) & M8);
  x = (x & M16) + ((x >> 16) & M16);
  return x;
}
class Solution {
public:
  vector<int> sortByBits(vector<int>& arr) {
    sort(arr.begin(), arr.end(), [](int a, int b) {
      int ba = popcount(a);
      int bb = popcount(b);
      return ba < bb || (ba == bb && a < b); 
    });
    return arr;
  }
};
```

# June LeetCoding Challenge 18

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

- `1 <= nums.length <= 3 * 10^4`
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
    if(!len) return;
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
```
