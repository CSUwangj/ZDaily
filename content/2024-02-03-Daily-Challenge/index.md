+++
updated = 2024-02-03T14:18:31+08:00
title = "2024-02-03 Daily Challenge"
path = "2024-02-03-Daily-Challenge"
date = 2024-02-03T14:18:31+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/partition-array-for-maximum-sum/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 3

## Description

**Partition Array for Maximum Sum**

<p>Given an integer array <code>arr</code>, partition the array into (contiguous) subarrays of length <strong>at most</strong> <code>k</code>. After partitioning, each subarray has their values changed to become the maximum value of that subarray.</p>

<p>Return <em>the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a <strong>32-bit</strong> integer.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> arr = [1,15,7,9,2,5,10], k = 3
<strong>Output:</strong> 84
<strong>Explanation:</strong> arr becomes [15,15,15,9,10,10,10]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
<strong>Output:</strong> 83
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> arr = [1], k = 1
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 500</code></li>
	<li><code>0 &lt;= arr[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= arr.length</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int maxSumAfterPartitioning(vector<int>& arr, int k) {
    vector<int> dp(arr.size());
    dp[0] = arr[0];
    for(int i = 1; i < arr.size(); ++i) {
      int mmax = INT_MIN;
      for(int j = i; j >= max(0, i - k + 1); --j) {
        mmax = max(mmax, arr[j]);
        dp[i] = max(dp[i], (j ? dp[j - 1] : 0) + (i - j + 1) * mmax);
      }
    }
    return dp.back();
  }
};

// Accepted
// 52/52 cases passed (3 ms)
// Your runtime beats 99.46 % of cpp submissions
// Your memory usage beats 23.07 % of cpp submissions (10.9 MB)
```
