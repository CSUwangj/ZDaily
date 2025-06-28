+++
updated = 2025-06-29T02:42:38+08:00
title = "2025-06-28 Daily Challenge"
path = "2025-06-28-Daily-Challenge"
date = 2025-06-29T02:42:38+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 28

## Description

**Find Subsequence of Length K With the Largest Sum**

<p>You are given an integer array <code>nums</code> and an integer <code>k</code>. You want to find a <strong>subsequence </strong>of <code>nums</code> of length <code>k</code> that has the <strong>largest</strong> sum.</p>

<p>Return<em> </em><em><strong>any</strong> such subsequence as an integer array of length </em><code>k</code>.</p>

<p>A <strong>subsequence</strong> is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,1,3,3], k = 2
<strong>Output:</strong> [3,3]
<strong>Explanation:</strong>
The subsequence has the largest sum of 3 + 3 = 6.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [-1,-2,3,4], k = 3
<strong>Output:</strong> [-1,3,4]
<strong>Explanation:</strong> 
The subsequence has the largest sum of -1 + 3 + 4 = 6.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,4,3,3], k = 2
<strong>Output:</strong> [3,4]
<strong>Explanation:</strong>
The subsequence has the largest sum of 3 + 4 = 7. 
Another possible subsequence is [4, 3].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>-10<sup>5</sup>&nbsp;&lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= nums.length</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  vector<int> maxSubsequence(vector<int>& nums, int k) {
    vector<int> tmp(nums);
    sort(tmp.begin(), tmp.end());
    int len = nums.size();
    multiset<int> candidates;
    for(int i = 1; i <= k; ++i) {
      candidates.insert(tmp[len - i]);
    }
    vector<int> answer;
    for(auto n : nums) {
      if(!candidates.count(n)) continue;
      answer.push_back(n);
      candidates.erase(candidates.find(n));
    }
    return answer;
  }
};

// Accepted
// 49/49 cases passed (11 ms)
// Your runtime beats 7.68 % of cpp submissions
// Your memory usage beats 11.81 % of cpp submissions (14.4 MB)
```
