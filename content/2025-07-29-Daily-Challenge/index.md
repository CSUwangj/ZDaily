+++
updated = 2025-07-30T02:59:58+08:00
title = "2025-07-29 Daily Challenge"
path = "2025-07-29-Daily-Challenge"
date = 2025-07-30T02:59:58+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 29

## Description

**Smallest Subarrays With Maximum Bitwise OR**

<p>You are given a <strong>0-indexed</strong> array <code>nums</code> of length <code>n</code>, consisting of non-negative integers. For each index <code>i</code> from <code>0</code> to <code>n - 1</code>, you must determine the size of the <strong>minimum sized</strong> non-empty subarray of <code>nums</code> starting at <code>i</code> (<strong>inclusive</strong>) that has the <strong>maximum</strong> possible <strong>bitwise OR</strong>.</p>

<ul>
	<li>In other words, let <code>B<sub>ij</sub></code> be the bitwise OR of the subarray <code>nums[i...j]</code>. You need to find the smallest subarray starting at <code>i</code>, such that bitwise OR of this subarray is equal to <code>max(B<sub>ik</sub>)</code> where <code>i &lt;= k &lt;= n - 1</code>.</li>
</ul>

<p>The bitwise OR of an array is the bitwise OR of all the numbers in it.</p>

<p>Return <em>an integer array </em><code>answer</code><em> of size </em><code>n</code><em> where </em><code>answer[i]</code><em> is the length of the <strong>minimum</strong> sized subarray starting at </em><code>i</code><em> with <strong>maximum</strong> bitwise OR.</em></p>

<p>A <strong>subarray</strong> is a contiguous non-empty sequence of elements within an array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,0,2,1,3]
<strong>Output:</strong> [3,3,2,2,1]
<strong>Explanation:</strong>
The maximum possible bitwise OR starting at any index is 3. 
- Starting at index 0, the shortest subarray that yields it is [1,0,2].
- Starting at index 1, the shortest subarray that yields the maximum bitwise OR is [0,2,1].
- Starting at index 2, the shortest subarray that yields the maximum bitwise OR is [2,1].
- Starting at index 3, the shortest subarray that yields the maximum bitwise OR is [1,3].
- Starting at index 4, the shortest subarray that yields the maximum bitwise OR is [3].
Therefore, we return [3,3,2,2,1]. 
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2]
<strong>Output:</strong> [2,1]
<strong>Explanation:
</strong>Starting at index 0, the shortest subarray that yields the maximum bitwise OR is of length 2.
Starting at index 1, the shortest subarray that yields the maximum bitwise OR is of length 1.
Therefore, we return [2,1].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  vector<int> smallestSubarrays(vector<int>& nums) {
    vector<int> bitPosition(31);
    vector<int> answer(nums.size());
    for(int i = nums.size() - 1; i >= 0; --i) {
      for(int b = 0; b < 31; ++b) {
        if((1 << b) & nums[i]) bitPosition[b] = i;
      }
      answer[i] = max(1, *max_element(bitPosition.begin(), bitPosition.end()) - i + 1);
    }
    return answer;
  }
};

// Accepted
// 59/59 cases passed (33 ms)
// Your runtime beats 47.85 % of cpp submissions
// Your memory usage beats 54.74 % of cpp submissions (60.7 MB)
```
