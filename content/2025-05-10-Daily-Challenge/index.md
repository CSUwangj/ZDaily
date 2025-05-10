+++
updated = 2025-05-10T12:30:09+08:00
title = "2025-05-10 Daily Challenge"
path = "2025-05-10-Daily-Challenge"
date = 2025-05-10T12:30:09+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 10

## Description

**Minimum Equal Sum of Two Arrays After Replacing Zeros**

<p>You are given two arrays <code>nums1</code> and <code>nums2</code> consisting of positive integers.</p>

<p>You have to replace <strong>all</strong> the <code>0</code>&#39;s in both arrays with <strong>strictly</strong> positive integers such that the sum of elements of both arrays becomes <strong>equal</strong>.</p>

<p>Return <em>the <strong>minimum</strong> equal sum you can obtain, or </em><code>-1</code><em> if it is impossible</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [3,2,0,1,0], nums2 = [6,5,0]
<strong>Output:</strong> 12
<strong>Explanation:</strong> We can replace 0&#39;s in the following way:
- Replace the two 0&#39;s in nums1 with the values 2 and 4. The resulting array is nums1 = [3,2,2,1,4].
- Replace the 0 in nums2 with the value 1. The resulting array is nums2 = [6,5,1].
Both arrays have an equal sum of 12. It can be shown that it is the minimum sum we can obtain.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [2,0,2,0], nums2 = [1,4]
<strong>Output:</strong> -1
<strong>Explanation:</strong> It is impossible to make the sum of both arrays equal.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= 10<sup>6</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  long long minSum(vector<int>& nums1, vector<int>& nums2) {
    long long minSum1 = 0;
    long long minSum2 = 0;
    bool hasZero1 = false;
    bool hasZero2 = false;
    for(auto n : nums1) {
      minSum1 += max(1, n);
      if(!n) hasZero1 = true;
    }
    for(auto n : nums2) {
      minSum2 += max(1, n);
      if(!n) hasZero2 = true;
    }
    if(hasZero1 && hasZero2) {
      return max(minSum1, minSum2);
    } else if(hasZero1) {
      return minSum2 >= minSum1 ? minSum2 : -1;
    } else if(hasZero2) {
      return minSum1 >= minSum2 ? minSum1 : -1;
    }
    return minSum1 == minSum2 ? minSum1 : -1;
  }
};

// Accepted
// 636/636 cases passed (135 ms)
// Your runtime beats 40.68 % of cpp submissions
// Your memory usage beats 6.1 % of cpp submissions (135.7 MB)
```
