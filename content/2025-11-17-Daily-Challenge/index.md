+++
updated = 2025-11-17T10:05:53+01:00
title = "2025-11-17 Daily Challenge"
path = "2025-11-17-Daily-Challenge"
date = 2025-11-17T10:05:53+01:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 17

## Description

**Check If All 1's Are at Least Length K Places Away**

<p>Given an binary array <code>nums</code> and an integer <code>k</code>, return <code>true</code><em> if all </em><code>1</code><em>&#39;s are at least </em><code>k</code><em> places away from each other, otherwise return </em><code>false</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/04/15/sample_1_1791.png" style="width: 428px; height: 181px;" />
<pre>
<strong>Input:</strong> nums = [1,0,0,0,1,0,0,1], k = 2
<strong>Output:</strong> true
<strong>Explanation:</strong> Each of the 1s are at least 2 places away from each other.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/04/15/sample_2_1791.png" style="width: 320px; height: 173px;" />
<pre>
<strong>Input:</strong> nums = [1,0,0,1,0,1], k = 2
<strong>Output:</strong> false
<strong>Explanation:</strong> The second 1 and third 1 are only one apart from each other.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= k &lt;= nums.length</code></li>
	<li><code>nums[i]</code> is <code>0</code> or <code>1</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  bool kLengthApart(vector<int>& nums, int k) {
    int pos = -1e5;
    int len = nums.size();
    for(int i = 0; i < len; ++i) {
      if(nums[i]) {
        if(i - pos < k + 1) return false;
        pos = i;
      }
    }
    return true;
  }
};

// Accepted
// 69/69 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 47.64 % of cpp submissions (61.5 MB)
```
