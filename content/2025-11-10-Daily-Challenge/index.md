+++
updated = 2025-11-10T21:59:55+01:00
title = "2025-11-10 Daily Challenge"
path = "2025-11-10-Daily-Challenge"
date = 2025-11-10T21:59:55+01:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 10

## Description

**Minimum Operations to Convert All Elements to Zero**

<p>You are given an array <code>nums</code> of size <code>n</code>, consisting of <strong>non-negative</strong> integers. Your task is to apply some (possibly zero) operations on the array so that <strong>all</strong> elements become 0.</p>

<p>In one operation, you can select a <span data-keyword="subarray">subarray</span> <code>[i, j]</code> (where <code>0 &lt;= i &lt;= j &lt; n</code>) and set all occurrences of the <strong>minimum</strong> <strong>non-negative</strong> integer in that subarray to 0.</p>

<p>Return the <strong>minimum</strong> number of operations required to make all elements in the array 0.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [0,2]</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Select the subarray <code>[1,1]</code> (which is <code>[2]</code>), where the minimum non-negative integer is 2. Setting all occurrences of 2 to 0 results in <code>[0,0]</code>.</li>
	<li>Thus, the minimum number of operations required is 1.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [3,1,2,1]</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Select subarray <code>[1,3]</code> (which is <code>[1,2,1]</code>), where the minimum non-negative integer is 1. Setting all occurrences of 1 to 0 results in <code>[3,0,2,0]</code>.</li>
	<li>Select subarray <code>[2,2]</code> (which is <code>[2]</code>), where the minimum non-negative integer is 2. Setting all occurrences of 2 to 0 results in <code>[3,0,0,0]</code>.</li>
	<li>Select subarray <code>[0,0]</code> (which is <code>[3]</code>), where the minimum non-negative integer is 3. Setting all occurrences of 3 to 0 results in <code>[0,0,0,0]</code>.</li>
	<li>Thus, the minimum number of operations required is 3.</li>
</ul>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2,1,2,1,2]</span></p>

<p><strong>Output:</strong> <span class="example-io">4</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Select subarray <code>[0,5]</code> (which is <code>[1,2,1,2,1,2]</code>), where the minimum non-negative integer is 1. Setting all occurrences of 1 to 0 results in <code>[0,2,0,2,0,2]</code>.</li>
	<li>Select subarray <code>[1,1]</code> (which is <code>[2]</code>), where the minimum non-negative integer is 2. Setting all occurrences of 2 to 0 results in <code>[0,0,0,2,0,2]</code>.</li>
	<li>Select subarray <code>[3,3]</code> (which is <code>[2]</code>), where the minimum non-negative integer is 2. Setting all occurrences of 2 to 0 results in <code>[0,0,0,0,0,2]</code>.</li>
	<li>Select subarray <code>[5,5]</code> (which is <code>[2]</code>), where the minimum non-negative integer is 2. Setting all occurrences of 2 to 0 results in <code>[0,0,0,0,0,0]</code>.</li>
	<li>Thus, the minimum number of operations required is 4.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n == nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int minOperations(vector<int>& nums) {
    vector<int> st;
    int answer = 0;
    for(auto n : nums) {
      while(st.size() && st.back() > n) {
        st.pop_back();
      }
      if(st.size() && st.back() == n) continue;
      if(!n) continue;
      st.push_back(n);
      answer += 1;
    }
    return answer;
  }
};

// Accepted
// 968/968 cases passed (27 ms)
// Your runtime beats 80.11 % of cpp submissions
// Your memory usage beats 88.59 % of cpp submissions (221.9 MB)
```
