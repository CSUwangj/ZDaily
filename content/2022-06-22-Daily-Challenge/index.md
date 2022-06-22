+++
updated = 2022-06-22 18:14:00+08:00
title = "2022-06-22 Daily-Challenge"
path = "2022-06-22-Daily-Challenge"
date = 2022-06-22 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/kth-largest-element-in-an-array/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 22

## Description

**Kth Largest Element in an Array**

Given an integer array `nums` and an integer `k`, return *the* `kth` *largest element in the array*.

Note that it is the `kth` largest element in the sorted order, not the `kth` distinct element.

 

**Example 1:**

```
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
```

**Example 2:**

```
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
```

 

**Constraints:**

- `1 <= k <= nums.length <= 104`
- `-104 <= nums[i] <= 104`

## Solution

``` cpp
class Solution {
  int KthLargest(vector<int>& nums, int begin, int len, int k) {
    if(len <= 1) return nums[begin];
    const int pivot = nums[begin + rand()%len];
    int front = begin, index = begin, back = begin+len;
    while(index < back) {
      if(nums[index] < pivot) {
        swap(nums[index], nums[front]);
        index += 1;
        front += 1;
      } else if(nums[index] > pivot) {
        back -= 1;
        swap(nums[index], nums[back]);
      } else {
        index += 1;
      }
    }
    cout << endl;
    if(front >= k) return KthLargest(nums, begin, front-begin, k);
    else if (back < k) return KthLargest(nums, back, begin+len-back, k);
    return pivot;
  }
public:
  int findKthLargest(vector<int>& nums, int k) {
    int len = nums.size();
    return KthLargest(nums, 0, len, len-k+1);
  }
};

// Accepted
// 32/32 cases passed (7 ms)
// Your runtime beats 90.68 % of cpp submissions
// Your memory usage beats 61.91 % of cpp submissions (10.1 MB)
```
