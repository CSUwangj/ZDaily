+++
title = "2021-11-15 Daily-Challenge"
path = "2021-11-15-Daily-Challenge"
date = 2021-11-15 20:02:39+08:00
updated = 2021-11-15 20:21:31+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/largest-divisible-subset/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 15

## Description

**Largest Divisible Subset**

Given a set of **distinct** positive integers `nums`, return the largest subset `answer` such that every pair `(answer[i], answer[j])` of elements in this subset satisfies:

- `answer[i] % answer[j] == 0`, or
- `answer[j] % answer[i] == 0`

If there are multiple solutions, return any of them.

 

**Example 1:**

```
Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
```

**Example 2:**

```
Input: nums = [1,2,4,8]
Output: [1,2,4,8]
```

 

**Constraints:**

- `1 <= nums.length <= 1000`
- `1 <= nums[i] <= 2 * 10^9`
- All the integers in `nums` are **unique**.

## Solution

``` cpp
class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int len = nums.size();
    vector<int> dp(len, 1);
    vector<int> child(len, -1);
    
    for(int i = 1; i < len; ++i) {
      for(int j = 0; j < i; ++j) {
        if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
          dp[i] = dp[j] + 1;
          child[i] = j;
        }
      }
    }
    
    int answerLen = 0;
    int answerEnd = -1;
    for(int i = 0; i < len; ++i) {
      if(dp[i] > answerLen) {
        answerLen = dp[i];
        answerEnd = i;
      }
    }
    
    vector<int> answer;
    while(answerEnd != -1) {
      answer.push_back(nums[answerEnd]);
      answerEnd = child[answerEnd];
    }
    
    return answer;
  }
};

// Accepted
// 48/48 cases passed (32 ms)
// Your runtime beats 97.22 % of cpp submissions
// Your memory usage beats 35.59 % of cpp submissions (8.8 MB)
```
