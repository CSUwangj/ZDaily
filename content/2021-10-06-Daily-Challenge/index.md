+++
title = "2021-10-06 Daily-Challenge"
path = "2021-10-06-Daily-Challenge"
date = 2021-10-06 20:43:00+08:00
updated = 2021-10-06 20:46:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/find-all-duplicates-in-an-array/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 6

## Description

**Find All Duplicates in an Array**

Given an integer array `nums` of length `n` where all the integers of `nums` are in the range `[1, n]` and each integer appears **once** or **twice**, return *an array of all the integers that appears **twice***.

You must write an algorithm that runs in `O(n) `time and uses only constant extra space.

 

**Example 1:**

```
Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
```

**Example 2:**

```
Input: nums = [1,1,2]
Output: [1]
```

**Example 3:**

```
Input: nums = [1]
Output: []
```

 

**Constraints:**

- `n == nums.length`
- `1 <= n <= 10^5`
- `1 <= nums[i] <= n`
- Each element in `nums` appears **once** or **twice**.

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
  vector<int> findDuplicates(vector<int>& nums) {
    int len = nums.size();
    vector<int> answer;
    for(int i = 0; i < len; ++i) {
      int pos = nums[i] > 0 ? nums[i] - 1 : -1 - nums[i];
      cout << pos << endl;
      if(nums[pos] > 0) {
        nums[pos] = -nums[pos]; 
      } else {
        answer.push_back(pos + 1);
      }
    }
    return answer;
  }
};

// Accepted
// 28/28 cases passed (60 ms)
// Your runtime beats 53.68 % of cpp submissions
// Your memory usage beats 74.16 % of cpp submissions (33.5 MB)
```
