+++
updated = 2025-10-21T16:59:20+02:00
title = "2025-10-21 Daily Challenge"
path = "2025-10-21-Daily-Challenge"
date = 2025-10-21T16:59:20+02:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 21

## Description

**Maximum Frequency of an Element After Performing Operations I**

<p>You are given an integer array <code>nums</code> and two integers <code>k</code> and <code>numOperations</code>.</p>

<p>You must perform an <strong>operation</strong> <code>numOperations</code> times on <code>nums</code>, where in each operation you:</p>

<ul>
	<li>Select an index <code>i</code> that was <strong>not</strong> selected in any previous operations.</li>
	<li>Add an integer in the range <code>[-k, k]</code> to <code>nums[i]</code>.</li>
</ul>

<p>Return the <strong>maximum</strong> possible <span data-keyword="frequency-array" class=" cursor-pointer relative text-dark-blue-s text-sm"><button type="button" aria-haspopup="dialog" aria-expanded="false" aria-controls="radix-:r1l:" data-state="closed" class="">frequency</button></span> of any element in <code>nums</code> after performing the <strong>operations</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,4,5], k = 1, numOperations = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p>We can achieve a maximum frequency of two by:</p>

<ul>
	<li>Adding 0 to <code>nums[1]</code>. <code>nums</code> becomes <code>[1, 4, 5]</code>.</li>
	<li>Adding -1 to <code>nums[2]</code>. <code>nums</code> becomes <code>[1, 4, 4]</code>.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [5,11,20,20], k = 5, numOperations = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p>We can achieve a maximum frequency of two by:</p>

<ul>
	<li>Adding 0 to <code>nums[1]</code>.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= numOperations &lt;= nums.length</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int maxFrequency(vector<int>& nums, int k, int numOperations) {
    int maxVal = *max_element(nums.begin(), nums.end()) + k + 2;
    vector<int> count(maxVal);

    for(auto n : nums) {
      count[n] += 1;
    }

    for(int i = 1; i < maxVal; ++i) {
      count[i] += count[i - 1];
    }

    int answer = 0;
    for(int i = 0; i < maxVal; ++i) {
      int left = max(0, i - k);
      int right = min(maxVal - 1, i + k);
      int total = count[right] - (left ? count[left - 1] : 0);
      int freq = count[i] - (i ? count[i - 1] : 0);
      answer = max(answer, freq + min(numOperations, total - freq));
    }
    return answer;
  }
};

// Accepted
// 635/635 cases passed (4 ms)
// Your runtime beats 99.27 % of cpp submissions
// Your memory usage beats 81.46 % of cpp submissions (96.2 MB)
```
