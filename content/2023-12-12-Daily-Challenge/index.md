+++
updated = 2023-12-12T08:23:42+08:00
title = "2023-12-12 Daily Challenge"
path = "2023-12-12-Daily-Challenge"
date = 2023-12-12T08:23:42+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 12

## Description

**Maximum Product of Two Elements in an Array**

Given the array of integers <code>nums</code>, you will choose two different indices <code>i</code> and <code>j</code> of that array. <em>Return the maximum value of</em> <code>(nums[i]-1)*(nums[j]-1)</code>.
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,4,5,2]
<strong>Output:</strong> 12 
<strong>Explanation:</strong> If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12. 
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,5,4,5]
<strong>Output:</strong> 16
<strong>Explanation:</strong> Choosing the indices i=1 and j=3 (indexed from 0), you will get the maximum value of (5-1)*(5-1) = 16.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,7]
<strong>Output:</strong> 12
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 500</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10^3</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int maxProduct(vector<int>& nums) {
    sort(nums.begin(), nums.end(), greater<int>());
    return (nums[0] - 1) * (nums[1] - 1);
  }
};

// Accepted
// 104/104 cases passed (4 ms)
// Your runtime beats 58.3 % of cpp submissions
// Your memory usage beats 62.52 % of cpp submissions (10.3 MB)
```
