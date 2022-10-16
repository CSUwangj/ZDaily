+++
title = "2021-11-25 Daily-Challenge"
path = "2021-11-25-Daily-Challenge"
date = 2021-11-25 18:18:00+08:00
updated = 2021-11-25 18:20:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/maximum-subarray/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 25

## Description

**Maximum Subarray**

Given an integer array `nums`, find the contiguous subarray (containing at least one number) which has the largest sum and return *its sum*.

A **subarray** is a **contiguous** part of an array.

 

**Example 1:**

```
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
```

**Example 2:**

```
Input: nums = [1]
Output: 1
```

**Example 3:**

```
Input: nums = [5,4,-1,7,8]
Output: 23
```

 

**Constraints:**

- `1 <= nums.length <= 10^5`
- `-104 <= nums[i] <= 10^4`

 

**Follow up:** If you have figured out the `O(n)` solution, try coding another solution using the **divide and conquer** approach, which is more subtle.
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
  int maxSubArray(vector<int>& nums) {
    int answer = INT_MIN;
    int sum = 0;
    for(auto i : nums) {
      sum += i;
      if(answer < sum) {
        answer = sum;
      }
      if(sum < 0) {
        sum = 0;
      }
    }
    return answer;
  }
};

// Accepted
// 209/209 cases passed (109 ms)
// Your runtime beats 43.26 % of cpp submissions
// Your memory usage beats 53.84 % of cpp submissions (67.7 MB)
```
