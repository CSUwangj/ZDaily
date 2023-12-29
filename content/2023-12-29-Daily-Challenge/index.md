+++
updated = 2023-12-29T13:18:11+08:00
title = "2023-12-29 Daily Challenge"
path = "2023-12-29-Daily-Challenge"
date = 2023-12-29T13:18:11+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 29

## Description

**Minimum Difficulty of a Job Schedule**

<p>You want to schedule a list of jobs in <code>d</code> days. Jobs are dependent (i.e To work on the <code>i<sup>th</sup></code> job, you have to finish all the jobs <code>j</code> where <code>0 &lt;= j &lt; i</code>).</p>

<p>You have to finish <strong>at least</strong> one task every day. The difficulty of a job schedule is the sum of difficulties of each day of the <code>d</code> days. The difficulty of a day is the maximum difficulty of a job done on that day.</p>

<p>You are given an integer array <code>jobDifficulty</code> and an integer <code>d</code>. The difficulty of the <code>i<sup>th</sup></code> job is <code>jobDifficulty[i]</code>.</p>

<p>Return <em>the minimum difficulty of a job schedule</em>. If you cannot find a schedule for the jobs return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/01/16/untitled.png" style="width: 365px; height: 370px;" />
<pre>
<strong>Input:</strong> jobDifficulty = [6,5,4,3,2,1], d = 2
<strong>Output:</strong> 7
<strong>Explanation:</strong> First day you can finish the first 5 jobs, total difficulty = 6.
Second day you can finish the last job, total difficulty = 1.
The difficulty of the schedule = 6 + 1 = 7 
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> jobDifficulty = [9,9,9], d = 4
<strong>Output:</strong> -1
<strong>Explanation:</strong> If you finish a job per day you will still have a free day. you cannot find a schedule for the given jobs.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> jobDifficulty = [1,1,1], d = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> The schedule is one job per day. total difficulty will be 3.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= jobDifficulty.length &lt;= 300</code></li>
	<li><code>0 &lt;= jobDifficulty[i] &lt;= 1000</code></li>
	<li><code>1 &lt;= d &lt;= 10</code></li>
</ul>


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
