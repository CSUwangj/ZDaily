+++
updated = 2023-05-03T12:08:17+08:00
title = "2023-05-03 Daily Challenge"
path = "2023-05-03-Daily-Challenge"
date = 2023-05-03T12:08:17+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/find-the-difference-of-two-arrays/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 3

## Description

**Find the Difference of Two Arrays**

<p>Given two <strong>0-indexed</strong> integer arrays <code>nums1</code> and <code>nums2</code>, return <em>a list</em> <code>answer</code> <em>of size</em> <code>2</code> <em>where:</em></p>

<ul>
	<li><code>answer[0]</code> <em>is a list of all <strong>distinct</strong> integers in</em> <code>nums1</code> <em>which are <strong>not</strong> present in</em> <code>nums2</code><em>.</em></li>
	<li><code>answer[1]</code> <em>is a list of all <strong>distinct</strong> integers in</em> <code>nums2</code> <em>which are <strong>not</strong> present in</em> <code>nums1</code>.</li>
</ul>

<p><strong>Note</strong> that the integers in the lists may be returned in <strong>any</strong> order.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [1,2,3], nums2 = [2,4,6]
<strong>Output:</strong> [[1,3],[4,6]]
<strong>Explanation:
</strong>For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [1,2,3,3], nums2 = [1,1,2,2]
<strong>Output:</strong> [[3],[]]
<strong>Explanation:
</strong>For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] == nums1[3], their value is only included once and answer[0] = [3].
Every integer in nums2 is present in nums1. Therefore, answer[1] = [].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 1000</code></li>
	<li><code>-1000 &lt;= nums1[i], nums2[i] &lt;= 1000</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    set<int> st1(nums1.begin(), nums1.end());
    set<int> st2(nums2.begin(), nums2.end());

    vector<vector<int>> answer(2);
    for(auto n1 : st1) {
      if(!st2.count(n1)) {
        answer[0].push_back(n1);
      }
    }
    for(auto n2 : st2) {
      if(!st1.count(n2)) {
        answer[1].push_back(n2);
      }
    }

    return answer;
  }
};

// Accepted
// 202/202 cases passed (60 ms)
// Your runtime beats 63.81 % of cpp submissions
// Your memory usage beats 53.88 % of cpp submissions (32.7 MB)
```
