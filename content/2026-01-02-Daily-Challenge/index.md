+++
updated = 2026-01-02T06:36:33+01:00
title = "2026-01-02 Daily Challenge"
path = "2026-01-02-Daily-Challenge"
date = 2026-01-02T06:36:33+01:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/n-repeated-element-in-size-2n-array/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 2

## Description

**N-Repeated Element in Size 2N Array**

<p>You are given an integer array <code>nums</code> with the following properties:</p>

<ul>
	<li><code>nums.length == 2 * n</code>.</li>
	<li><code>nums</code> contains <code>n + 1</code> <strong>unique</strong> elements.</li>
	<li>Exactly one element of <code>nums</code> is repeated <code>n</code> times.</li>
</ul>

<p>Return <em>the element that is repeated </em><code>n</code><em> times</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,2,3,3]
<strong>Output:</strong> 3
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [2,1,2,5,3,2]
<strong>Output:</strong> 2
</pre><p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> nums = [5,1,5,2,5,3,5,4]
<strong>Output:</strong> 5
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 5000</code></li>
	<li><code>nums.length == 2 * n</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>nums</code> contains <code>n + 1</code> <strong>unique</strong> elements and one of them is repeated exactly <code>n</code> times.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int repeatedNTimes(vector<int>& nums) {
    set<int> st;
    for(auto n : nums) {
      if(st.count(n)) return n;
      st.insert(n);
    }
    return -1;
  }
};

// Accepted
// 103/103 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 96.55 % of cpp submissions (28.3 MB)
```
