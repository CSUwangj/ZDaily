+++
title = "2022-03-05 Daily-Challenge"
path = "2022-03-05-Daily-Challenge"
date = 2022-03-05 15:50:00+08:00
updated = 2022-03-05 16:01:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/delete-and-earn/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 5

## Description

**Delete and Earn**

You are given an integer array `nums`. You want to maximize the number of points you get by performing the following operation any number of times:

- Pick any `nums[i]` and delete it to earn `nums[i]` points. Afterwards, you must delete **every** element equal to `nums[i] - 1` and **every** element equal to `nums[i] + 1`.

Return *the **maximum number of points** you can earn by applying the above operation some number of times*.

 

**Example 1:**

```
Input: nums = [3,4,2]
Output: 6
Explanation: You can perform the following operations:
- Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
- Delete 2 to earn 2 points. nums = [].
You earn a total of 6 points.
```

**Example 2:**

```
Input: nums = [2,2,3,3,3,4]
Output: 9
Explanation: You can perform the following operations:
- Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums = [3,3].
- Delete a 3 again to earn 3 points. nums = [3].
- Delete a 3 once more to earn 3 points. nums = [].
You earn a total of 9 points.
```

 

**Constraints:**

- `1 <= nums.length <= 2 * 10^4`
- `1 <= nums[i] <= 10^4`

## Solution

``` cpp
class Solution {
public:
  int deleteAndEarn(vector<int>& nums) {
    int dp[10001] = {};
    int count[10001] = {};
    for(auto num : nums) {
      count[num] += 1;
    }
    dp[1] = count[1];
    for(int i = 2; i <= 10000; ++i) {
      dp[i] = max(dp[i - 1], dp[i - 2] + i * count[i]);
    }
    return dp[10000];
  }
};

// Accepted
// 48/48 cases passed (3 ms)
// Your runtime beats 97.58 % of cpp submissions
// Your memory usage beats 90.77 % of cpp submissions (9.2 MB)
```
