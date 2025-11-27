+++
updated = 2025-11-28T00:18:52+01:00
title = "2025-11-27 Daily Challenge"
path = "2025-11-27-Daily-Challenge"
date = 2025-11-28T00:18:52+01:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 27

## Description

**Maximum Subarray Sum With Length Divisible by K**

<p>You are given an array of integers <code>nums</code> and an integer <code>k</code>.</p>

<p>Return the <strong>maximum</strong> sum of a <span data-keyword="subarray-nonempty">subarray</span> of <code>nums</code>, such that the size of the subarray is <strong>divisible</strong> by <code>k</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2], k = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<p>The subarray <code>[1, 2]</code> with sum 3 has length equal to 2 which is divisible by 1.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [-1,-2,-3,-4,-5], k = 4</span></p>

<p><strong>Output:</strong> <span class="example-io">-10</span></p>

<p><strong>Explanation:</strong></p>

<p>The maximum sum subarray is <code>[-1, -2, -3, -4]</code> which has length equal to 4 which is divisible by 4.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [-5,1,2,-3,4], k = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">4</span></p>

<p><strong>Explanation:</strong></p>

<p>The maximum sum subarray is <code>[1, 2, -3, 4]</code> which has length equal to 4 which is divisible by 2.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= nums.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  long long maxSubarraySum(vector<int>& nums, int k) {
    int len = nums.size();
    if(k == len) {
      long long answer = 0;
      for(auto n : nums) answer += n;
      return answer;
    }
    vector<long long> sums(k + 1);
    long long sum = 0;
    long long answer = LONG_LONG_MIN;
    for(int i = 0; i < len; ++i) {
      sum += nums[i];
      if(i >= k - 1) {
        answer = max(answer, sum - sums[(i + 1) % k]);
        sums[(i + 1) % k] = min(sum, sums[(i + 1) % k]);
      } else {
        sums[i + 1] = sum;
      }
    }
    return answer;
  }
};

// Accepted
// 661/661 cases passed (8 ms)
// Your runtime beats 76.85 % of cpp submissions
// Your memory usage beats 99.33 % of cpp submissions (160.6 MB)
```
