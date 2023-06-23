+++
updated = 2023-06-23T15:07:14+08:00
title = "2023-06-23 Daily Challenge"
path = "2023-06-23-Daily-Challenge"
date = 2023-06-23T15:07:14+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/longest-arithmetic-subsequence/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 23

## Description

**Longest Arithmetic Subsequence**

<p>Given an array <code>nums</code> of integers, return <em>the length of the longest arithmetic subsequence in</em> <code>nums</code>.</p>

<p><strong>Note</strong> that:</p>

<ul>
	<li>A <strong>subsequence</strong> is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.</li>
	<li>A sequence <code>seq</code> is arithmetic if <code>seq[i + 1] - seq[i]</code> are all the same value (for <code>0 &lt;= i &lt; seq.length - 1</code>).</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,6,9,12]
<strong>Output:</strong> 4
<strong>Explanation: </strong> The whole array is an arithmetic sequence with steps of length = 3.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [9,4,7,2,10]
<strong>Output:</strong> 3
<strong>Explanation: </strong> The longest arithmetic subsequence is [4,7,10].
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [20,1,15,3,10,5,8]
<strong>Output:</strong> 4
<strong>Explanation: </strong> The longest arithmetic subsequence is [20,15,10,5].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 500</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int longestArithSeqLength(vector<int>& nums) {
    int len = nums.size();
    if(len < 2) return len;

    int dp[len + 1][1001];
    memset(dp, 0, sizeof(dp));
    int answer = 1;
    for(int i = 1; i < len; ++i) {
      for(int j = 0; j < i; ++j) {
        int diff = nums[j] - nums[i] + 500;
        int count = 1;

        if(dp[j][diff]) {
          count = dp[j][diff];
        }

        dp[i][diff] = 1 + count;
        answer = max(answer, dp[i][diff]);
      }
    }

    return answer;
  }
};

// Accepted
// 63/63 cases passed (148 ms)
// Your runtime beats 96.32 % of cpp submissions
// Your memory usage beats 93.59 % of cpp submissions (13.9 MB)
```
