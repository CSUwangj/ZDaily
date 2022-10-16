+++
updated = 2022-07-05 18:14:00+08:00
title = "2022-07-05 Daily-Challenge"
path = "2022-07-05-Daily-Challenge"
date = 2022-07-05 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/longest-consecutive-sequence/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 5

## Description

**Longest Consecutive Sequence**

Given an unsorted array of integers `nums`, return *the length of the longest consecutive elements sequence.*

You must write an algorithm that runs in `O(n)` time.

 

**Example 1:**

```
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
```

**Example 2:**

```
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
```

 

**Constraints:**

- `0 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`

## Solution

``` cpp
class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    if(nums.empty()) return 0;
    sort(nums.begin(), nums.end());
    nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
    int cur = nums.front();
    int len = 0;
    int answer = 1;
    for(auto i : nums) {
      if(i == cur + 1) {
        len += 1;
        answer = max(answer, len);
      } else {
        len = 1;
      }
      cur = i;
    }
    return answer;
  }
};

// Accepted
// 71/71 cases passed (133 ms)
// Your runtime beats 82.18 % of cpp submissions
// Your memory usage beats 85.63 % of cpp submissions (33.8 MB)
```
