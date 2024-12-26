+++
updated = 2024-12-26T23:49:28+08:00
title = "2024-12-26 Daily Challenge"
path = "2024-12-26-Daily-Challenge"
date = 2024-12-26T23:49:28+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/target-sum/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 26

## Description

**Target Sum**

<p>You are given an integer array <code>nums</code> and an integer <code>target</code>.</p>

<p>You want to build an <strong>expression</strong> out of nums by adding one of the symbols <code>&#39;+&#39;</code> and <code>&#39;-&#39;</code> before each integer in nums and then concatenate all the integers.</p>

<ul>
	<li>For example, if <code>nums = [2, 1]</code>, you can add a <code>&#39;+&#39;</code> before <code>2</code> and a <code>&#39;-&#39;</code> before <code>1</code> and concatenate them to build the expression <code>&quot;+2-1&quot;</code>.</li>
</ul>

<p>Return the number of different <strong>expressions</strong> that you can build, which evaluates to <code>target</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,1,1,1,1], target = 3
<strong>Output:</strong> 5
<strong>Explanation:</strong> There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1], target = 1
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 20</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1000</code></li>
	<li><code>0 &lt;= sum(nums[i]) &lt;= 1000</code></li>
	<li><code>-1000 &lt;= target &lt;= 1000</code></li>
</ul>


## Solution

simple dfs

``` cpp
class Solution {
  int answer = 0;
  void dfs(vector<int> &nums, int pos, int target) {
    if(pos == nums.size()) {
      answer += !target;
      return;
    }
    dfs(nums, pos + 1, target - nums[pos]);
    dfs(nums, pos + 1, target + nums[pos]);
  }
public:
  int findTargetSumWays(vector<int>& nums, int target) {
    dfs(nums, 0, target);
    return answer;
  }
};

// Accepted
// 140/140 cases passed (807 ms)
// Your runtime beats 18.96 % of cpp submissions
// Your memory usage beats 68.89 % of cpp submissions (11.6 MB)
```

then I think it should be feasible for memoriezed computation

``` cpp
class Solution {
  int answer = 0;
  void dfs(vector<int> &nums, vector<map<int, int>> &dp, int pos) {
    if(pos == nums.size()) {
      dp[pos][0] = 1;
      return;
    }
    dfs(nums, dp, pos + 1);
    for(auto [result, count] : dp[pos + 1]) {
      dp[pos][result + nums[pos]] += count;
      dp[pos][result - nums[pos]] += count;
    }
  }
public:
  int findTargetSumWays(vector<int>& nums, int target) {
    vector<map<int, int>> dp(nums.size() + 1);
    dfs(nums, dp, 0);
    return dp[0][target];
  }
};

// Accepted
// 140/140 cases passed (143 ms)
// Your runtime beats 45.95 % of cpp submissions
// Your memory usage beats 18.17 % of cpp submissions (52.8 MB)
```

I finally checked the constraints and realized I could do more optimization

``` cpp
class Solution {
  int answer = 0;
  void dfs(vector<int> &nums, int dp[][2001], int pos) {
    if(pos == nums.size()) {
      return;
    }
    dfs(nums, dp, pos + 1);
    for(int i = 0; i < 2001; ++i) {
      if(!dp[pos + 1][i]) continue;
      dp[pos][i + nums[pos]] += dp[pos + 1][i];
      dp[pos][i - nums[pos]] += dp[pos + 1][i];
    }
  }
public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int dp[21][2001] = {};
    dp[nums.size()][1000] = 1;
    dfs(nums, dp, 0);
    return dp[0][target + 1000];
  }
};

// Accepted
// 140/140 cases passed (5 ms)
// Your runtime beats 76.1 % of cpp submissions
// Your memory usage beats 64.14 % of cpp submissions (11.9 MB)
```
