+++
updated = 2025-10-15T23:52:06+02:00
title = "2025-10-15 Daily Challenge"
path = "2025-10-15-Daily-Challenge"
date = 2025-10-15T23:52:06+02:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 15

## Description

**Adjacent Increasing Subarrays Detection II**

<p>Given an array <code>nums</code> of <code>n</code> integers, your task is to find the <strong>maximum</strong> value of <code>k</code> for which there exist <strong>two</strong> adjacent <span data-keyword="subarray-nonempty">subarrays</span> of length <code>k</code> each, such that both subarrays are <strong>strictly</strong> <strong>increasing</strong>. Specifically, check if there are <strong>two</strong> subarrays of length <code>k</code> starting at indices <code>a</code> and <code>b</code> (<code>a &lt; b</code>), where:</p>

<ul>
	<li>Both subarrays <code>nums[a..a + k - 1]</code> and <code>nums[b..b + k - 1]</code> are <strong>strictly increasing</strong>.</li>
	<li>The subarrays must be <strong>adjacent</strong>, meaning <code>b = a + k</code>.</li>
</ul>

<p>Return the <strong>maximum</strong> <em>possible</em> value of <code>k</code>.</p>

<p>A <strong>subarray</strong> is a contiguous <b>non-empty</b> sequence of elements within an array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [2,5,7,8,9,2,3,4,3,1]</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>The subarray starting at index 2 is <code>[7, 8, 9]</code>, which is strictly increasing.</li>
	<li>The subarray starting at index 5 is <code>[2, 3, 4]</code>, which is also strictly increasing.</li>
	<li>These two subarrays are adjacent, and 3 is the <strong>maximum</strong> possible value of <code>k</code> for which two such adjacent strictly increasing subarrays exist.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2,3,4,4,4,4,5,6,7]</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>The subarray starting at index 0 is <code>[1, 2]</code>, which is strictly increasing.</li>
	<li>The subarray starting at index 2 is <code>[3, 4]</code>, which is also strictly increasing.</li>
	<li>These two subarrays are adjacent, and 2 is the <strong>maximum</strong> possible value of <code>k</code> for which two such adjacent strictly increasing subarrays exist.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
  bool isOk(map<int, int> &increasing, int k) {
    for(auto [start, size] : increasing) {
      if(size >= 2 * k) return true;
      if(size < k) continue;
      if(increasing.count(start + size) && increasing[start + size] >= k) return true;
    }
    return false;
  }
public:
  int maxIncreasingSubarrays(vector<int>& nums) {
    map<int, int> increasing;
    int start = 0;
    int size = 1;
    int len = nums.size();
    for(int i = 1; i < len; ++i) {
      if(nums[i] > nums[i - 1]) {
        size += 1;
        continue;
      }
      increasing[start] = size;
      start = i;
      size = 1;
    }
    increasing[start] = size;
    int low = 1;
    int high = 1;
    for(auto [_start, size] : increasing) {
      if(size > high) high = size;
    }
    while(low < high) {
      int mid = (low + high + 1) / 2;
      if(isOk(increasing, mid)) {
        low = mid;
      } else {
        high = mid - 1;
      }
    }
    return low;
  }
};

// Accepted
// 1111/1111 cases passed (354 ms)
// Your runtime beats 5.54 % of cpp submissions
// Your memory usage beats 8.4 % of cpp submissions (204.9 MB)
```
