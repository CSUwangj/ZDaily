+++
updated = 2022-09-16 18:14:00+08:00
title = "2022-09-16 Daily-Challenge"
path = "2022-09-16-Daily-Challenge"
date = 2022-09-16 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 16

## Description

**Maximum Score from Performing Multiplication Operations**

You are given two integer arrays `nums` and `multipliers` of size `n` and `m` respectively, where `n >= m`. The arrays are **1-indexed**.

You begin with a score of `0`. You want to perform **exactly** `m` operations. On the `ith` operation **(1-indexed)**, you will:

- Choose one integer `x` from **either the start or the end** of the array `nums`.
- Add `multipliers[i] * x` to your score.
- Remove `x` from the array `nums`.

Return *the **maximum** score after performing* `m` *operations.*

 

**Example 1:**

```
Input: nums = [1,2,3], multipliers = [3,2,1]
Output: 14
Explanation: An optimal solution is as follows:
- Choose from the end, [1,2,3], adding 3 * 3 = 9 to the score.
- Choose from the end, [1,2], adding 2 * 2 = 4 to the score.
- Choose from the end, [1], adding 1 * 1 = 1 to the score.
The total score is 9 + 4 + 1 = 14.
```

**Example 2:**

```
Input: nums = [-5,-3,-3,-2,7,1], multipliers = [-10,-5,3,4,6]
Output: 102
Explanation: An optimal solution is as follows:
- Choose from the start, [-5,-3,-3,-2,7,1], adding -5 * -10 = 50 to the score.
- Choose from the start, [-3,-3,-2,7,1], adding -3 * -5 = 15 to the score.
- Choose from the start, [-3,-2,7,1], adding -3 * 3 = -9 to the score.
- Choose from the end, [-2,7,1], adding 1 * 4 = 4 to the score.
- Choose from the end, [-2,7], adding 7 * 6 = 42 to the score. 
The total score is 50 + 15 - 9 + 4 + 42 = 102.
```

 

**Constraints:**

- `n == nums.length`
- `m == multipliers.length`
- `1 <= m <= 10^3`
- `m <= n <= 10^5`` `
- `-1000 <= nums[i], multipliers[i] <= 1000`

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
constexpr int SZ = 1001;

class Solution {
public:
  int maximumScore(vector<int>& nums, vector<int>& multipliers) {
    int m = multipliers.size();
    int len = nums.size();
    int dp[SZ][SZ] = {0};
    for(int i = 1; i <= m; ++i) {
      for(int j = 0; j <= i; ++j) {
        dp[i][j] = INT_MIN;
        if(j) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + nums[j - 1] * multipliers[i - 1]);
        if(j != i) dp[i][j] = max(dp[i][j], dp[i - 1][j] + nums[len - i + j] * multipliers[i - 1]);
      }
    }
    
    int answer = INT_MIN;
    for(int i = 0; i <= m; ++i) answer = max(answer, dp[m][i]);
    
    return answer;
  }
};

// Accepted
// 50/50 cases passed (373 ms)
// Your runtime beats 95.59 % of cpp submissions
// Your memory usage beats 98.4 % of cpp submissions (54.7 MB)
```
