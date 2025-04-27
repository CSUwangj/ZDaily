+++
updated = 2025-04-27T11:15:39+08:00
title = "2025-04-27 Daily Challenge"
path = "2025-04-27-Daily-Challenge"
date = 2025-04-27T11:15:39+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 27

## Description

**Count Subarrays of Length Three With a Condition**

<p>Given an integer array <code>nums</code>, return the number of <span data-keyword="subarray-nonempty">subarrays</span> of length 3 such that the sum of the first and third numbers equals <em>exactly</em> half of the second number.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2,1,4,1]</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<p>Only the subarray <code>[1,4,1]</code> contains exactly 3 elements where the sum of the first and third numbers equals half the middle number.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,1,1]</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<p><code>[1,1,1]</code> is the only subarray of length 3. However, its first and third numbers do not add to half the middle number.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 100</code></li>
	<li><code><font face="monospace">-100 &lt;= nums[i] &lt;= 100</font></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int countSubarrays(vector<int>& nums) {
    int answer = 0;
    for(int i = 0; i + 2 < nums.size(); ++i) {
      answer += ((nums[i] + nums[i + 2]) * 2 == nums[i + 1]);
    }
    return answer;
  }
};

// Accepted
// 1691/1691 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 75.3 % of cpp submissions (48.4 MB)
```
