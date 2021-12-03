+++
title = "2021-12-03 Daily-Challenge"
path = "2021-12-03-Daily-Challenge"
date = 2021-12-03 19:30:00+08:00
updated = 2021-12-03 19:37:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/maximum-product-subarray/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 3

## Description

**Maximum Product Subarray**

Given an integer array `nums`, find a contiguous non-empty subarray within the array that has the largest product, and return *the product*.

It is **guaranteed** that the answer will fit in a **32-bit** integer.

A **subarray** is a contiguous subsequence of the array.

 

**Example 1:**

```
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
```

**Example 2:**

```
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
```

 

**Constraints:**

- `1 <= nums.length <= 2 * 10^4`
- `-10 <= nums[i] <= 10`
- The product of any prefix or suffix of `nums` is **guaranteed** to fit in a **32-bit** integer.

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int answer = INT_MIN;
    int l = 1;
    int r = 1;
    int len = nums.size();
    for(int i = 0; i < len; ++i) {
      l *= nums[i];
      r *= nums[len - i - 1];
      answer = max({l, r, answer});
      if(!l) l = 1;
      if(!r) r = 1;
    }
    return answer;
  }
};

// Accepted
// 187/187 cases passed (4 ms)
// Your runtime beats 81.49 % of cpp submissions
// Your memory usage beats 52.62 % of cpp submissions (11.7 MB)
```
