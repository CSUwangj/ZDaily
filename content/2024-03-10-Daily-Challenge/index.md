+++
updated = 2024-03-10T16:21:19+08:00
title = "2024-03-10 Daily Challenge"
path = "2024-03-10-Daily-Challenge"
date = 2024-03-10T16:21:19+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/intersection-of-two-arrays/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 10

## Description

**Intersection of Two Arrays**

<p>Given two integer arrays <code>nums1</code> and <code>nums2</code>, return <em>an array of their intersection</em>. Each element in the result must be <strong>unique</strong> and you may return the result in <strong>any order</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [1,2,2,1], nums2 = [2,2]
<strong>Output:</strong> [2]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [4,9,5], nums2 = [9,4,9,8,4]
<strong>Output:</strong> [9,4]
<strong>Explanation:</strong> [4,9] is also accepted.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= 1000</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> answer(max(nums1.size(), nums2.size()));
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    auto it = set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), answer.begin());
    answer.resize(it - answer.begin());
    answer.resize(unique(answer.begin(), answer.end()) - answer.begin());
    return answer;
  }
};
```
