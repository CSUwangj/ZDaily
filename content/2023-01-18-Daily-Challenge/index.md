+++
updated = 2023-01-18T14:24:28+08:00
title = "2023-01-18 Daily Challenge"
path = "2023-01-18-Daily-Challenge"
date = 2023-01-18T14:24:28+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/maximum-sum-circular-subarray/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 18

## Description

**Maximum Sum Circular Subarray**

<p>Given a <strong>circular integer array</strong> <code>nums</code> of length <code>n</code>, return <em>the maximum possible sum of a non-empty <strong>subarray</strong> of </em><code>nums</code>.</p>

<p>A <strong>circular array</strong> means the end of the array connects to the beginning of the array. Formally, the next element of <code>nums[i]</code> is <code>nums[(i + 1) % n]</code> and the previous element of <code>nums[i]</code> is <code>nums[(i - 1 + n) % n]</code>.</p>

<p>A <strong>subarray</strong> may only include each element of the fixed buffer <code>nums</code> at most once. Formally, for a subarray <code>nums[i], nums[i + 1], ..., nums[j]</code>, there does not exist <code>i &lt;= k1</code>, <code>k2 &lt;= j</code> with <code>k1 % n == k2 % n</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,-2,3,-2]
<strong>Output:</strong> 3
<strong>Explanation:</strong> Subarray [3] has maximum sum 3.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [5,-3,5]
<strong>Output:</strong> 10
<strong>Explanation:</strong> Subarray [5,5] has maximum sum 5 + 5 = 10.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [-3,-2,-3]
<strong>Output:</strong> -2
<strong>Explanation:</strong> Subarray [-2] has maximum sum -2.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>-3 * 10<sup>4</sup> &lt;= nums[i] &lt;= 3 * 10<sup>4</sup></code></li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int maxSubarraySumCircular(vector<int>& nums) {
    int currentMinSum = INT_MAX - 30000;
    int minSum = INT_MAX;
    int currentMaxSum = INT_MIN + 30000;
    int maxSum = INT_MIN;
    for(auto n : nums) {
      currentMinSum = min(n, currentMinSum + n);
      minSum = min(minSum, currentMinSum);
      currentMaxSum = max(n, currentMaxSum + n);
      maxSum = max(maxSum, currentMaxSum);
    }
    return maxSum > 0 ? max(accumulate(nums.begin(), nums.end(), 0) - minSum, maxSum) : maxSum;
  }
};

// Accepted
// 111/111 cases passed (49 ms)
// Your runtime beats 98.93 % of cpp submissions
// Your memory usage beats 20.64 % of cpp submissions (40.2 MB)
```
