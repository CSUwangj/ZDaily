+++
updated = 2022-10-21T12:47:44+08:00
title = "2022-10-21 Daily Challenge"
path = "2022-10-21-Daily-Challenge"
date = 2022-10-21T12:47:44+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/contains-duplicate-ii/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 21

## Description

**Contains Duplicate II**

<p>Given an integer array <code>nums</code> and an integer <code>k</code>, return <code>true</code> if there are two <strong>distinct indices</strong> <code>i</code> and <code>j</code> in the array such that <code>nums[i] == nums[j]</code> and <code>abs(i - j) &lt;= k</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,1], k = 3
<strong>Output:</strong> true
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,0,1,1], k = 1
<strong>Output:</strong> true
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,1,2,3], k = 2
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>5</sup></code></li>
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
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int len = nums.size();
    unordered_set<int> st;
    for(int i = 0; i < k && i < len; ++i) {
      if(st.count(nums[i])) return true;
      st.insert(nums[i]);
    }
    for(int i = k; i < len; ++i) {
      if(st.count(nums[i])) return true;
      st.insert(nums[i]);
      st.erase(nums[i - k]);
    }
    return false;
  }
};

// Accepted
// 52/52 cases passed (219 ms)
// Your runtime beats 84.4 % of cpp submissions
// Your memory usage beats 91.47 % of cpp submissions (72.2 MB)
```
