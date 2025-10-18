+++
updated = 2025-10-18T22:21:39+02:00
title = "2025-10-18 Daily Challenge"
path = "2025-10-18-Daily-Challenge"
date = 2025-10-18T22:21:39+02:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 18

## Description

**Maximum Number of Distinct Elements After Operations**

<p>You are given an integer array <code>nums</code> and an integer <code>k</code>.</p>

<p>You are allowed to perform the following <strong>operation</strong> on each element of the array <strong>at most</strong> <em>once</em>:</p>

<ul>
	<li>Add an integer in the range <code>[-k, k]</code> to the element.</li>
</ul>

<p>Return the <strong>maximum</strong> possible number of <strong>distinct</strong> elements in <code>nums</code> after performing the <strong>operations</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2,2,3,3,4], k = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">6</span></p>

<p><strong>Explanation:</strong></p>

<p><code>nums</code> changes to <code>[-1, 0, 1, 2, 3, 4]</code> after performing operations on the first four elements.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [4,4,4,4], k = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<p>By adding -1 to <code>nums[0]</code> and 1 to <code>nums[1]</code>, <code>nums</code> changes to <code>[3, 5, 4, 4]</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int maxDistinctElements(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    nums[0] -= k;
    int len = nums.size();
    for(int i = 1; i < len; ++i) {
      nums[i] = min(max(nums[i - 1] + 1, nums[i] - k), nums[i] + k);
    }
    sort(nums.begin(), nums.end());
    return unique(nums.begin(), nums.end()) - nums.begin();
  }
};

// Accepted
// 633/633 cases passed (147 ms)
// Your runtime beats 28.89 % of cpp submissions
// Your memory usage beats 87.94 % of cpp submissions (97.5 MB)
```
