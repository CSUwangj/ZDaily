+++
updated = 2023-03-06T12:23:47+08:00
title = "2023-03-06 Daily Challenge"
path = "2023-03-06-Daily-Challenge"
date = 2023-03-06T12:23:47+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/kth-missing-positive-number/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 6

## Description

**Kth Missing Positive Number**

<p>Given an array <code>arr</code> of positive integers sorted in a <strong>strictly increasing order</strong>, and an integer <code>k</code>.</p>

<p>Return <em>the</em> <code>k<sup>th</sup></code> <em><strong>positive</strong> integer that is <strong>missing</strong> from this array.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> arr = [2,3,4,7,11], k = 5
<strong>Output:</strong> 9
<strong>Explanation: </strong>The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5<sup>th</sup>&nbsp;missing positive integer is 9.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> arr = [1,2,3,4], k = 2
<strong>Output:</strong> 6
<strong>Explanation: </strong>The missing positive integers are [5,6,7,...]. The 2<sup>nd</sup> missing positive integer is 6.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 1000</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 1000</code></li>
	<li><code>1 &lt;= k &lt;= 1000</code></li>
	<li><code>arr[i] &lt; arr[j]</code> for <code>1 &lt;= i &lt; j &lt;= arr.length</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong></p>

<p>Could you solve this problem in less than O(n) complexity?</p>


## Solution

``` cpp
class Solution {
public:
  int findKthPositive(vector<int>& arr, int k) {
    int pos = 0;
    int prev = 0;
    arr.push_back(INT_MAX);
    while(k) {
      while(arr[pos] - prev == 1) {
        prev = arr[pos];
        pos += 1;
      }
      if(prev + k < arr[pos]) return prev+k;
      else {
        k -= arr[pos] - prev - 1;
        prev = arr[pos];
        pos += 1;
      }
    }
    return -1;
  }
};

// Accepted
// 84/84 cases passed (9 ms)
// Your runtime beats 33.58 % of cpp submissions
// Your memory usage beats 73.33 % of cpp submissions (9.6 MB)
```
