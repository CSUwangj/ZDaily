+++
updated = 2024-03-09T16:21:19+08:00
title = "2024-03-09 Daily Challenge"
path = "2024-03-09-Daily-Challenge"
date = 2024-03-09T16:21:19+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/minimum-common-value/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 9

## Description

**Minimum Common Value**

<p>Given two integer arrays <code>nums1</code> and <code>nums2</code>, sorted in non-decreasing order, return <em>the <strong>minimum integer common</strong> to both arrays</em>. If there is no common integer amongst <code>nums1</code> and <code>nums2</code>, return <code>-1</code>.</p>

<p>Note that an integer is said to be <strong>common</strong> to <code>nums1</code> and <code>nums2</code> if both arrays have <strong>at least one</strong> occurrence of that integer.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [1,2,3], nums2 = [2,4]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The smallest element common to both arrays is 2, so we return 2.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [1,2,3,6], nums2 = [2,3,4,5]
<strong>Output:</strong> 2
<strong>Explanation:</strong> There are two common elements in the array 2 and 3 out of which 2 is the smallest, so 2 is returned.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums1[i], nums2[j] &lt;= 10<sup>9</sup></code></li>
	<li>Both <code>nums1</code> and <code>nums2</code> are sorted in <strong>non-decreasing</strong> order.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int getCommon(vector<int>& nums1, vector<int>& nums2) {
    int pos1 = 0;
    int pos2 = 0;
    while(pos1 < nums1.size() && pos2 < nums2.size()) {
      if(nums1[pos1] < nums2[pos2]) {
        pos1 += 1;
      } else if(nums1[pos1] > nums2[pos2]) {
        pos2 += 1;
      } else {
        return nums1[pos1];
      }
    }
    return -1;
  }
};
```
