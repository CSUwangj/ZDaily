+++
updated = 2025-08-01T02:57:46+08:00
title = "2025-07-31 Daily Challenge"
path = "2025-07-31-Daily-Challenge"
date = 2025-08-01T02:57:46+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/bitwise-ors-of-subarrays/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 31

## Description

**Bitwise ORs of Subarrays**

<p>Given an integer array <code>arr</code>, return <em>the number of distinct bitwise ORs of all the non-empty subarrays of</em> <code>arr</code>.</p>

<p>The bitwise OR of a subarray is the bitwise OR of each integer in the subarray. The bitwise OR of a subarray of one integer is that integer.</p>

<p>A <strong>subarray</strong> is a contiguous non-empty sequence of elements within an array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> arr = [0]
<strong>Output:</strong> 1
<strong>Explanation:</strong> There is only one possible result: 0.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> arr = [1,1,2]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The possible subarrays are [1], [1], [2], [1, 1], [1, 2], [1, 1, 2].
These yield the results 1, 1, 2, 1, 3, 3.
There are 3 unique values, so the answer is 3.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> arr = [1,2,4]
<strong>Output:</strong> 6
<strong>Explanation:</strong> The possible results are 1, 2, 3, 4, 6, and 7.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= arr[i] &lt;= 10<sup>9</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int subarrayBitwiseORs(vector<int>& A) {
    unordered_set<int> cnt;
    for(int i = 0; i < A.size(); ++i) {
      int pre = 0;
      cnt.insert(A[i]);
      for(int j = i-1; j >= 0 && (pre|A[i]) != pre; --j) {
        pre |= A[j];
        cnt.insert(pre|A[i]);
      }
    }
    return cnt.size();
  }
};

// Accepted
// 85/85 cases passed (275 ms)
// Your runtime beats 96.23 % of cpp submissions
// Your memory usage beats 94.35 % of cpp submissions (106.3 MB)
```
