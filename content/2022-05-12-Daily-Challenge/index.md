+++
updated = 2022-05-12 19:56:00+08:00
title = "2022-05-12 Daily-Challenge"
path = "2022-05-12-Daily-Challenge"
date = 2022-05-12 19:55:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/permutations-ii/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 12

## Description

**Permutations II**

Given a collection of numbers, `nums`, that might contain duplicates, return *all possible unique permutations **in any order**.*

 

**Example 1:**

```
Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
```

**Example 2:**

```
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

 

**Constraints:**

- `1 <= nums.length <= 8`
- `-10 <= nums[i] <= 10`

## Solution

``` cpp
class Solution {
  bool next_permutation(vector<int>& nums) {
    if(nums.size() < 2) return false;
    int len = nums.size();
    int a = len - 2;
    
    while(a >= 0 && nums[a] >= nums[a+1]) a -= 1;
    if(a == -1) return false;
    
    int minGreater = INT_MAX, b = -1;
    int i = a+1;
    while(i < len) {
      if(nums[i] > nums[a] && nums[i] < minGreater) {
        b = i;
        minGreater = nums[i];
      }
      i += 1;
    }
    
    swap(nums[a], nums[b]);
    sort(nums.begin()+a+1, nums.end());
    return true;
  }
public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans{nums};
    while(next_permutation(nums)) {
        ans.push_back(nums);
    }
    return ans;
  }
};

// Accepted
// 33/33 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 89.32 % of cpp submissions (8.5 MB)
```
