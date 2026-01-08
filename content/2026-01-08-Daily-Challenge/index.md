+++
updated = 2026-01-08T21:45:17+01:00
title = "2026-01-08 Daily Challenge"
path = "2026-01-08-Daily-Challenge"
date = 2026-01-08T21:45:17+01:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/max-dot-product-of-two-subsequences/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 8

## Description

**Max Dot Product of Two Subsequences**

<p>Given two arrays <code>nums1</code>&nbsp;and <code><font face="monospace">nums2</font></code><font face="monospace">.</font></p>

<p>Return the maximum dot product&nbsp;between&nbsp;<strong>non-empty</strong> subsequences of nums1 and nums2 with the same length.</p>

<p>A subsequence of a array is a new array which is formed from the original array by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie,&nbsp;<code>[2,3,5]</code>&nbsp;is a subsequence of&nbsp;<code>[1,2,3,4,5]</code>&nbsp;while <code>[1,5,3]</code>&nbsp;is not).</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [2,1,-2,5], nums2 = [3,0,-6]
<strong>Output:</strong> 18
<strong>Explanation:</strong> Take subsequence [2,-2] from nums1 and subsequence [3,-6] from nums2.
Their dot product is (2*3 + (-2)*(-6)) = 18.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [3,-2], nums2 = [2,-6,7]
<strong>Output:</strong> 21
<strong>Explanation:</strong> Take subsequence [3] from nums1 and subsequence [7] from nums2.
Their dot product is (3*7) = 21.</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [-1,-1], nums2 = [1,1]
<strong>Output:</strong> -1
<strong>Explanation: </strong>Take subsequence [-1] from nums1 and subsequence [1] from nums2.
Their dot product is -1.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 500</code></li>
	<li><code>-1000 &lt;= nums1[i], nums2[i] &lt;= 1000</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();

    vector<vector<int>> products(2, vector<int>(n + 1, INT_MIN));
    
    for(int i = 0; i < m; ++i) {
      for(int j = 0; j < n; ++j) {
        int currentProduct = nums1[i] * nums2[j];
        products[i & 1][j + 1] = max({currentProduct, products[((i ^ 1) & 1)][j + 1], products[i & 1][j], currentProduct + max(0, products[((i ^ 1) & 1)][j])});
      }
    }
    return products[(m ^ 1) & 1][n];
  }
};

// Accepted
// 69/69 cases passed (10 ms)
// Your runtime beats 88.98 % of cpp submissions
// Your memory usage beats 93.06 % of cpp submissions (14.3 MB)
```
