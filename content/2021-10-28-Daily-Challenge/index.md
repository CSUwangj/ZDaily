+++
title = "2021-10-28 Daily-Challenge"
path = "2021-10-28-Daily-Challenge"
date = 2021-10-28 20:35:43+08:00
updated = 2021-10-28 21:34:37+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/3sum/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 28

## Description

**Sort Colors**

Given an integer array nums, return all the triplets `[nums[i], nums[j], nums[k]]` such that `i != j`, `i != k`, and `j != k`, and `nums[i] + nums[j] + nums[k] == 0`.

Notice that the solution set must not contain duplicate triplets.

 

**Example 1:**

```
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
```

**Example 2:**

```
Input: nums = []
Output: []
```

**Example 3:**

```
Input: nums = [0]
Output: []
```

 

**Constraints:**


<ul>
	<li><code>0 &lt;= nums.length &lt;= 3000</code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  int len;
  
  vector<vector<int>> twoSum(vector<int> &nums, int target, int start) {
    vector<vector<int>> answer;
    unordered_set<int> st;
    for(int i = start; i < len; ++i) {
      if(answer.size() && answer.back()[1] == nums[i]) continue;
      if(st.count(nums[i])) {
        answer.push_back(vector<int>{target-nums[i], nums[i]});
      }
      st.insert(target-nums[i]);
    }
    return answer;
  }
  
  vector<vector<int>> kSum(vector<int> &nums, int target, int start, int k) {
    vector<vector<int>> answer;
    if(nums[start] * k > target || target > nums.back() * k) return answer;
    if(k == 2) return twoSum(nums, target, start);
    for(int i = start; i <= len-k; ++i) {
      if(i != start && nums[i] == nums[i-1]) continue;
      for(auto &vec : kSum(nums, target-nums[i], i+1, k-1)) {
        answer.push_back({nums[i]});
        answer.back().insert(answer.back().end(), vec.begin(), vec.end());
      }
    }
    return answer;
  }
  
  void init(vector<int> &nums) {
    len = nums.size();
    sort(nums.begin(), nums.end());
  }
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    if(nums.size() < 3) return vector<vector<int>>();
    init(nums);
    return kSum(nums, 0, 0, 3);
  }
};

// Accepted
// 318/318 cases passed (1080 ms)
// Your runtime beats 11.23 % of cpp submissions
// Your memory usage beats 5.06 % of cpp submissions (275.3 MB)
```

``` cpp
class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    int len = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> answer;
    for(int i = 0; i < len-2; ++i) {
      if(i && i < len-2 && nums[i] == nums[i-1]) continue;
      int begin = i + 1, end = len - 1;
      while(begin < end) {
        if(nums[begin]+nums[end] == -nums[i]) {
          answer.push_back(vector<int>{nums[i], nums[begin], nums[end]});
          int curBegin = nums[begin];
          int curEnd = nums[end];
          while(begin < end && nums[begin] == curBegin) ++begin;
          while(begin < end && nums[end] == curEnd) --end;
        } else if (nums[begin]+nums[end] < -nums[i]) {
          ++begin;
        } else {
          --end;
        }
      }
    }
    return answer;
  }
};

// Accepted
// 318/318 cases passed (96 ms)
// Your runtime beats 63.5 % of cpp submissions
// Your memory usage beats 67.25 % of cpp submissions (20.1 MB)
```
