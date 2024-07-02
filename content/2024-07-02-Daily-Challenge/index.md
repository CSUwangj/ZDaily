+++
updated = 2024-07-02T17:42:01+08:00
title = "2024-07-02 Daily Challenge"
path = "2024-07-02-Daily-Challenge"
date = 2024-07-02T17:42:01+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/intersection-of-two-arrays-ii/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 2

## Description

**Intersection of Two Arrays II**

<p>Given two integer arrays <code>nums1</code> and <code>nums2</code>, return <em>an array of their intersection</em>. Each element in the result must appear as many times as it shows in both arrays and you may return the result in <strong>any order</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [1,2,2,1], nums2 = [2,2]
<strong>Output:</strong> [2,2]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [4,9,5], nums2 = [9,4,9,8,4]
<strong>Output:</strong> [4,9]
<strong>Explanation:</strong> [9,4] is also accepted.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= 1000</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong></p>

<ul>
	<li>What if the given array is already sorted? How would you optimize your algorithm?</li>
	<li>What if <code>nums1</code>&#39;s size is small compared to <code>nums2</code>&#39;s size? Which algorithm is better?</li>
	<li>What if elements of <code>nums2</code> are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    vector<int> answer;
    auto it1 = nums1.begin();
    auto it2 = nums2.begin();
    while(it1 != nums1.end() && it2 != nums2.end()) {
      if(*it1 == *it2) {
        answer.push_back(*it1);
        ++it1;
        ++it2;
      } else if(*it1 < *it2) {
        ++it1;
      } else {
        ++it2;
      }
    }

    return answer;
  }
};

// Accepted
// 55/55 cases passed (3 ms)
// Your runtime beats 91.05 % of cpp submissions
// Your memory usage beats 88.6 % of cpp submissions (9.9 MB)
```
