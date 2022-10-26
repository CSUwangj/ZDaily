+++
updated = 2022-10-26T13:23:28+08:00
title = "2022-10-26 Daily Challenge"
path = "2022-10-26-Daily-Challenge"
date = 2022-10-26T13:23:28+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/continuous-subarray-sum/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 26

## Description

**Continuous Subarray Sum**

<p>Given an integer array <code>nums</code> and an integer <code>k</code>, return <code>true</code> <em>if </em><code>nums</code><em> has a continuous subarray of size <strong>at least two</strong> whose elements sum up to a multiple of</em> <code>k</code><em>, or </em><code>false</code><em> otherwise</em>.</p>

<p>An integer <code>x</code> is a multiple of <code>k</code> if there exists an integer <code>n</code> such that <code>x = n * k</code>. <code>0</code> is <strong>always</strong> a multiple of <code>k</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [23,<u>2,4</u>,6,7], k = 6
<strong>Output:</strong> true
<strong>Explanation:</strong> [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [<u>23,2,6,4,7</u>], k = 6
<strong>Output:</strong> true
<strong>Explanation:</strong> [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [23,2,6,4,7], k = 13
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= sum(nums[i]) &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>1 &lt;= k &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> count{{0, -1}};
    int sum = 0;
    for(int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      sum %= k;
      if(count.count(sum)) {
        if(i - count[sum] > 1) return true;
      } else {
        count[sum] = i;
      }
    }
    return false;
  }
};

// Accepted
// 97/97 cases passed (352 ms)
// Your runtime beats 70.44 % of cpp submissions
// Your memory usage beats 88.57 % of cpp submissions (112.6 MB)
```
