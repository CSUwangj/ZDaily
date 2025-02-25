+++
updated = 2025-02-25T17:52:08+08:00
title = "2025-02-25 Daily Challenge"
path = "2025-02-25-Daily-Challenge"
date = 2025-02-25T17:52:08+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 25

## Description

**Number of Sub-arrays With Odd Sum**

<p>Given an array of integers <code>arr</code>, return <em>the number of subarrays with an <strong>odd</strong> sum</em>.</p>

<p>Since the answer can be very large, return it modulo <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> arr = [1,3,5]
<strong>Output:</strong> 4
<strong>Explanation:</strong> All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
All sub-arrays sum are [1,4,9,3,8,5].
Odd sums are [1,9,3,5] so the answer is 4.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> arr = [2,4,6]
<strong>Output:</strong> 0
<strong>Explanation:</strong> All subarrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
All sub-arrays sum are [2,6,12,4,10,6].
All sub-arrays have even sum and the answer is 0.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> arr = [1,2,3,4,5,6,7]
<strong>Output:</strong> 16
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= arr[i] &lt;= 100</code></li>
</ul>


## Solution

``` cpp
class Solution {
  const int MOD = 1e9 + 7;
public:
  int numOfSubarrays(vector<int>& arr) {
    for(auto &n : arr) {
      n ^= (n ^ (n & 1));
    }
    for(int i = 1; i < arr.size(); ++i) {
      arr[i] ^= arr[i - 1];
    }
    int ones = 0;
    int zeros = 1;
    int answer = 0;
    for(auto n : arr) {
      if(n) {
        answer += zeros;
        ones += 1;
      } else {
        answer += ones;
        zeros += 1;
      }
      answer %= MOD;
    }
    return answer;
  }
};

// Accepted
// 151/151 cases passed (2 ms)
// Your runtime beats 76.78 % of cpp submissions
// Your memory usage beats 55.17 % of cpp submissions (112 MB)
```
