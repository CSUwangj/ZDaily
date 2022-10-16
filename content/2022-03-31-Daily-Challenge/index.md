+++
updated = 2022-03-31 18:55:00+08:00
title = "2022-03-31 Daily-Challenge"
path = "2022-03-31-Daily-Challenge"
date = 2022-03-31 18:53:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/split-array-largest-sum/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 31

## Description

**Split Array Largest Sum**

Given an array `nums` which consists of non-negative integers and an integer `m`, you can split the array into `m` non-empty continuous subarrays.

Write an algorithm to minimize the largest sum among these `m` subarrays.

 

**Example 1:**

```
Input: nums = [7,2,5,10,8], m = 2
Output: 18
Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.
```

**Example 2:**

```
Input: nums = [1,2,3,4,5], m = 2
Output: 9
```

**Example 3:**

```
Input: nums = [1,4,4], m = 3
Output: 4
```

 

**Constraints:**

- `1 <= nums.length <= 1000`
- `0 <= nums[i] <= 106`
- `1 <= m <= min(50, nums.length)`

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  int dp[50][1000];
  int len;
  int solve(const vector<int> &prefix, int current, int rest) {
    if(dp[rest][current]) return dp[rest][current];
    if(!rest) {
      dp[rest][current] = prefix[len] - prefix[current];
      return dp[rest][current];
    }
    int result = INT_MAX;
    for(int i = current; i < len - rest; ++i) {
      int currentSum = prefix[i + 1] - prefix[current];
      int largstSum = max(currentSum, solve(prefix, i + 1, rest - 1));
      result = min(result, largstSum);
      if(currentSum >= result) break;
    }
    dp[rest][current] = result;
    return result;
  }
public:
  int splitArray(vector<int>& nums, int m) {
    len = nums.size();
    vector<int> prefix(len + 1);
    for(int i = 0; i < len; ++i) {
      prefix[i + 1] = prefix[i] + nums[i];
    }
    return solve(prefix, 0, m - 1);
  }
};

// Accepted
// 30/30 cases passed (64 ms)
// Your runtime beats 23.90 % of cpp submissions
// Your memory usage beats 25.68 % of cpp submissions (7.5 MB)
```

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  bool check(vector<int> &nums, int m, int target){
    int current = 0;
    for(auto n : nums) {
      if(current + n <= target) {
        current += n;
      } else {
        current = n;
        m -= 1;
      }
    }
    return m > 0;
  }
public:
  int splitArray(vector<int>& nums, int m) {
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    if(m == 1) return high;
    while(low < high) {
      int mid = (low + high) >> 1;
      if(check(nums, m, mid)) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    return high;
  }
};

// Accepted
// 30/30 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 42.53 % of cpp submissions (7.2 MB)
```
