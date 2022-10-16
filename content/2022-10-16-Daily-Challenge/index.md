+++
updated = 2022-10-16 18:14:00+08:00
title = "2022-10-16 Daily-Challenge"
path = "2022-10-16-Daily-Challenge"
date = 2022-10-16 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge"]
archives = [ "archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 16

## Description

**Minimum Difficulty of a Job Schedule**

You want to schedule a list of jobs in `d` days. Jobs are dependent (i.e To work on the `ith` job, you have to finish all the jobs `j` where `0 <= j < i`).

You have to finish **at least** one task every day. The difficulty of a job schedule is the sum of difficulties of each day of the `d` days. The difficulty of a day is the maximum difficulty of a job done on that day.

You are given an integer array `jobDifficulty` and an integer `d`. The difficulty of the `ith` job is `jobDifficulty[i]`.

Return *the minimum difficulty of a job schedule*. If you cannot find a schedule for the jobs return `-1`.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/01/16/untitled.png)

```
Input: jobDifficulty = [6,5,4,3,2,1], d = 2
Output: 7
Explanation: First day you can finish the first 5 jobs, total difficulty = 6.
Second day you can finish the last job, total difficulty = 1.
The difficulty of the schedule = 6 + 1 = 7 
```

**Example 2:**

```
Input: jobDifficulty = [9,9,9], d = 4
Output: -1
Explanation: If you finish a job per day you will still have a free day. you cannot find a schedule for the given jobs.
```

**Example 3:**

```
Input: jobDifficulty = [1,1,1], d = 3
Output: 3
Explanation: The schedule is one job per day. total difficulty will be 3.
```

 

**Constraints:**

- `1 <= jobDifficulty.length <= 300`
- `0 <= jobDifficulty[i] <= 1000`
- `1 <= d <= 10`

## Solution

``` cpp
class Solution {
public:
  int minDifficulty(vector<int>& jobDifficulty, int d) {
    int len = jobDifficulty.size();
    if(len < d) return -1;
    if(len == d) return accumulate(jobDifficulty.begin(), jobDifficulty.end(), 0);
    int dp[d][len];
    dp[0][0] = jobDifficulty[0];
    for(int i = 1; i < len; ++i) dp[0][i] = max(dp[0][i - 1], jobDifficulty[i]);
    for(int i = 1; i < d; ++i) {
      vector<int> monoStack;
      for(int j = i; j < len; ++j) {
        dp[i][j] = dp[i - 1][j - 1] + jobDifficulty[j];
        while(monoStack.size() && jobDifficulty[monoStack.back()] < jobDifficulty[j]) {
          dp[i][j] = min(dp[i][j], dp[i][monoStack.back()] - jobDifficulty[monoStack.back()] + jobDifficulty[j]);
          monoStack.pop_back();
        }
        if(monoStack.size()) {
          dp[i][j] = min(dp[i][j], dp[i][monoStack.back()]);
        }
        monoStack.push_back(j);
      }
    }
    return dp[d - 1][len - 1];
  }
};

// Accepted
// 34/34 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 83.12 % of cpp submissions (7.3 MB)
```
