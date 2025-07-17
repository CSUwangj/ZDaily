+++
updated = 2025-07-18T02:02:12+08:00
title = "2025-07-17 Daily Challenge"
path = "2025-07-17-Daily-Challenge"
date = 2025-07-18T02:02:12+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 17

## Description

**Find the Maximum Length of Valid Subsequence II**

You are given an integer array <code>nums</code> and a <strong>positive</strong> integer <code>k</code>.
<p>A <span data-keyword="subsequence-array">subsequence</span> <code>sub</code> of <code>nums</code> with length <code>x</code> is called <strong>valid</strong> if it satisfies:</p>

<ul>
	<li><code>(sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x - 1]) % k.</code></li>
</ul>
Return the length of the <strong>longest</strong> <strong>valid</strong> subsequence of <code>nums</code>.
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2,3,4,5], k = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">5</span></p>

<p><strong>Explanation:</strong></p>

<p>The longest valid subsequence is <code>[1, 2, 3, 4, 5]</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,4,2,3,1,4], k = 3</span></p>

<p><strong>Output:</strong> <span class="example-io">4</span></p>

<p><strong>Explanation:</strong></p>

<p>The longest valid subsequence is <code>[1, 4, 1, 4]</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>3</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>7</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>3</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int maximumLength(vector<int>& nums, int k) {
    vector<vector<int>> dp(k, vector<int>(k));
    for(auto n : nums) {
      n %= k;
      for(int prev = 0; prev < k; ++prev) {
        dp[prev][n] = dp[n][prev] + 1;
      }
    }
    int answer = 0;
    for(auto row : dp) {
      answer = max(answer, *max_element(row.begin(), row.end()));
    }
    return answer;
  }
};

// Accepted
// 732/732 cases passed (167 ms)
// Your runtime beats 19.15 % of cpp submissions
// Your memory usage beats 9.12 % of cpp submissions (231.9 MB)
```
