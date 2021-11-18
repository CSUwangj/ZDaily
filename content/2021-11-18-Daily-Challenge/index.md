+++
title = "2021-11-18 Daily-Challenge"
path = "2021-11-18-Daily-Challenge"
date = 2021-11-18 19:40:28+08:00
updated = 2021-11-18 19:45:13+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 18

## Description

**Find All Numbers Disappeared in an Array**

Given an array `nums` of `n` integers where `nums[i]` is in the range `[1, n]`, return *an array of all the integers in the range* `[1, n]` *that do not appear in* `nums`.

 

**Example 1:**

```
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
```

**Example 2:**

```
Input: nums = [1,1]
Output: [2]
```

 

**Constraints:**

- `n == nums.length`
- `1 <= n <= 10^5`
- `1 <= nums[i] <= n`

 

**Follow up:** Could you do it without extra space and in `O(n)` runtime? You may assume the returned list does not count as extra space.

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
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    for(auto i : nums) {
      i = i < 0 ? -i : i;
      nums[i - 1] = nums[i - 1] < 0 ? nums[i - 1] : -nums[i - 1];    
    }
    vector<int> answer;
    for(int i = 0; i < nums.size(); ++i) {
      if(nums[i] > 0) {
        answer.push_back(i + 1);
      }
    }
    return answer;
  }
};

// Accepted
// 33/33 cases passed (28 ms)
// Your runtime beats 99.89 % of cpp submissions
// Your memory usage beats 54.3 % of cpp submissions (33.8 MB)
```
