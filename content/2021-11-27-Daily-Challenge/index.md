+++
title = "2021-11-27 Daily-Challenge"
path = "2021-11-27-Daily-Challenge"
date = 2021-11-27 12:29:00+08:00
updated = 2021-11-27 12:29:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/product-of-array-except-self/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 27

## Description

**Product of Array Except Self**

Given an integer array `nums`, return *an array* `answer` *such that* `answer[i]` *is equal to the product of all the elements of* `nums` *except* `nums[i]`.

The product of any prefix or suffix of `nums` is **guaranteed** to fit in a **32-bit** integer.

You must write an algorithm that runs in `O(n)` time and without using the division operation.

 

**Example 1:**

```
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
```

**Example 2:**

```
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
```

 

**Constraints:**

- `2 <= nums.length <= 105`
- `-30 <= nums[i] <= 30`
- The product of any prefix or suffix of `nums` is **guaranteed** to fit in a **32-bit** integer.

 

**Follow up:** Can you solve the problem in `O(1) `extra space complexity? (The output array **does not** count as extra space for space complexity analysis.)

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
  vector<int> productExceptSelf(vector<int>& nums) {
    int sum = nums[0];
    int n = nums.size();
    vector<int> ans(n);
    ans[0] = 1;

    for(int i = 1; i < n; ++i){
      ans[i] = sum;
      sum = sum * nums[i];
    }

    sum = 1;

    for(int i = n - 1; i >= 0; --i){
      ans[i] = ans[i] * sum;
      sum = sum * nums[i];
    }

    return ans;
  }
};

// Accepted
// 20/20 cases passed (28 ms)
// Your runtime beats 50.92 % of cpp submissions
// Your memory usage beats 56.08 % of cpp submissions (24 MB)
```
