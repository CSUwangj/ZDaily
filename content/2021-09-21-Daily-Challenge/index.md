+++
title = "2021-09-21 Daily-Challenge"
path = "2021-09-21-Daily-Challenge"
date = 2021-09-21 16:15:13+08:00
updated = 2021-09-21 16:18:53+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/638/week-3-september-15th-september-21st/3982/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 21

## Description

**Max Consecutive Ones**

Given a binary array `nums`, return *the maximum number of consecutive* `1`*'s in the array*.

 

**Example 1:**

```
Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
```

**Example 2:**

```
Input: nums = [1,0,1,1,0,1]
Output: 2
```

 

**Constraints:**

- `1 <= nums.length <= 10^5`
- `nums[i]` is either `0` or `1`.

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
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int count = 0;
    int answer = 0;
    for(auto i : nums) {
      if(!i) {
        count = 0;
      } else {
        count += 1;
      }
      answer = count > answer ? count : answer;
    }
    return answer;
  }
};

// Accepted
// 42/42 cases passed (32 ms)
// Your runtime beats 82.03 % of cpp submissions
// Your memory usage beats 21.16 % of cpp submissions (36.2 MB)
```
