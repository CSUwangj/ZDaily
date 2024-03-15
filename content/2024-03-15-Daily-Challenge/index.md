+++
updated = 2024-03-15T12:48:11+08:00
title = "2024-03-15 Daily Challenge"
path = "2024-03-15-Daily-Challenge"
date = 2024-03-15T12:48:11+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/product-of-array-except-self/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 15

## Description

**Product of Array Except Self**

<p>Given an integer array <code>nums</code>, return <em>an array</em> <code>answer</code> <em>such that</em> <code>answer[i]</code> <em>is equal to the product of all the elements of</em> <code>nums</code> <em>except</em> <code>nums[i]</code>.</p>

<p>The product of any prefix or suffix of <code>nums</code> is <strong>guaranteed</strong> to fit in a <strong>32-bit</strong> integer.</p>

<p>You must write an algorithm that runs in&nbsp;<code>O(n)</code>&nbsp;time and without using the division operation.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,2,3,4]
<strong>Output:</strong> [24,12,8,6]
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [-1,1,0,-3,3]
<strong>Output:</strong> [0,0,9,0,0]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-30 &lt;= nums[i] &lt;= 30</code></li>
	<li>The product of any prefix or suffix of <code>nums</code> is <strong>guaranteed</strong> to fit in a <strong>32-bit</strong> integer.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong>&nbsp;Can you solve the problem in <code>O(1)</code>&nbsp;extra&nbsp;space complexity? (The output array <strong>does not</strong> count as extra space for space complexity analysis.)</p>


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
  vector<int> productExceptSelf(vector<int>& nums) {
    int sum = nums[0];
    int n = nums.size();
    vector<int> ans(n);
    ans[0] = 1;

    for(int i = 1; i < n; ++i){
      ans[i] = sum;
      sum = sum * nums[i];
    }

    sum = 1;

    for(int i = n - 1; i >= 0; --i){
      ans[i] = ans[i] * sum;
      sum = sum * nums[i];
    }

    return ans;
  }
};

// Accepted
// 20/20 cases passed (8 ms)
// Your runtime beats 99.98 % of cpp submissions
// Your memory usage beats 56.08 % of cpp submissions (24.1 MB)
```
