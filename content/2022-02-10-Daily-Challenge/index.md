+++
title = "2022-02-10 Daily-Challenge"
path = "2022-02-10-Daily-Challenge"
date = 2022-02-10 21:25:00+08:00
updated = 2022-02-10 21:27:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/subarray-sum-equals-k/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 10

## Description

**Subarray Sum Equals K**

Given an array of integers `nums` and an integer `k`, return *the total number of continuous subarrays whose sum equals to `k`*.

 

**Example 1:**

```
Input: nums = [1,1,1], k = 2
Output: 2
```

**Example 2:**

```
Input: nums = [1,2,3], k = 3
Output: 2
```

 

**Constraints:**

- `1 <= nums.length <= 2 * 10^4`
- `-1000 <= nums[i] <= 1000`
- `-10^7 <= k <= 10^7`

## Solution

``` cpp
class Solution {
public:
  int findPairs(vector<int>& nums, int k) {
    unordered_map<int, int> cnt;
    for(auto i : nums) {
      cnt[i] += 1;
    }

    int answer = 0;
    for(auto [i, c] : cnt) {
      if(k) answer += cnt.count(i + k);
      else answer += c > 1;
    }
    return answer;
  }
};

// Accepted
// 60/60 cases passed (11 ms)Vubmissions
// Your memory usage beats 68.98 % of cpp submissions (13.1 MB)auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixCount{{0, 1}};
    int sum = 0;
    int answer = 0;
    for(auto n : nums) {
      sum += n;
      if(prefixCount.count(sum - k)) {
        answer += prefixCount[sum - k];
      }
      prefixCount[sum] += 1;
    }
    return answer;
  }
};

// Accepted
// 89/89 cases passed (60 ms)
// Your runtime beats 98.77 % of cpp submissions
// Your memory usage beats 39.62 % of cpp submissions (38.3 MB)
```
