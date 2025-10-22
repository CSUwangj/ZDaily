+++
updated = 2025-10-22T02:00:19+02:00
title = "2025-10-22 Daily Challenge"
path = "2025-10-22-Daily-Challenge"
date = 2025-10-22T02:00:19+02:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-ii/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 22

## Description

**Maximum Frequency of an Element After Performing Operations II**

<p>You are given an integer array <code>nums</code> and two integers <code>k</code> and <code>numOperations</code>.</p>

<p>You must perform an <strong>operation</strong> <code>numOperations</code> times on <code>nums</code>, where in each operation you:</p>

<ul>
	<li>Select an index <code>i</code> that was <strong>not</strong> selected in any previous operations.</li>
	<li>Add an integer in the range <code>[-k, k]</code> to <code>nums[i]</code>.</li>
</ul>

<p>Return the <strong>maximum</strong> possible <span data-keyword="frequency-array">frequency</span> of any element in <code>nums</code> after performing the <strong>operations</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,4,5], k = 1, numOperations = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p>We can achieve a maximum frequency of two by:</p>

<ul>
	<li>Adding 0 to <code>nums[1]</code>, after which <code>nums</code> becomes <code>[1, 4, 5]</code>.</li>
	<li>Adding -1 to <code>nums[2]</code>, after which <code>nums</code> becomes <code>[1, 4, 4]</code>.</li>
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
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= numOperations &lt;= nums.length</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int maxFrequency(vector<int>& nums, int k, int numOperations) {
    int len = nums.size();
    if(len == 1) return 1;
    sort(nums.begin(), nums.end());
    int left = 0;
    int right = 0;
    for(int i = 0; i < len; ++i) {
      int target = min<long long>(nums[i] + 2LL * k, INT_MAX);
      while(left < len && nums[left] <= target) {
        left += 1;
      }
      right = max(right, left - i);
    }
    right = min(right, numOperations);
    left = 0;
    int index = 0;
    int freq = 0;
    for(int i = 0; i < len; ++i) {
      int n = nums[i];
      freq = (i && nums[i] == nums[i - 1]) ? freq + 1 : 1;
      int mmin = n - k;
      int mmax = n + k;
      while((index < len && nums[index] < mmin) || (left < len && nums[left] <= mmax)) {
        if((index < len && nums[index] < mmin)) {
          index += 1;
        } else {
          left += 1;
        }
      }
      right = max(right, min(freq + numOperations, left - index));
    }
    return right;
  }
};

// Accepted
// 633/633 cases passed (35 ms)
// Your runtime beats 96.21 % of cpp submissions
// Your memory usage beats 99.05 % of cpp submissions (83.2 MB)
```
