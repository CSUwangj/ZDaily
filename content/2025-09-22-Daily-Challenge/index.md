+++
updated = 2025-09-22T23:10:23+02:00
title = "2025-09-22 Daily Challenge"
path = "2025-09-22-Daily-Challenge"
date = 2025-09-22T23:10:23+02:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/count-elements-with-maximum-frequency/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 22

## Description

**Count Elements With Maximum Frequency**

<p>You are given an array <code>nums</code> consisting of <strong>positive</strong> integers.</p>

<p>Return <em>the <strong>total frequencies</strong> of elements in</em><em> </em><code>nums</code>&nbsp;<em>such that those elements all have the <strong>maximum</strong> frequency</em>.</p>

<p>The <strong>frequency</strong> of an element is the number of occurrences of that element in the array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,2,3,1,4]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The elements 1 and 2 have a frequency of 2 which is the maximum frequency in the array.
So the number of elements in the array with maximum frequency is 4.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,4,5]
<strong>Output:</strong> 5
<strong>Explanation:</strong> All elements of the array have a frequency of 1 which is the maximum.
So the number of elements in the array with maximum frequency is 5.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int maxFrequencyElements(vector<int>& nums) {
    int count[100] = {};
    int ccount[101] = {};
    for(auto n : nums) {
      count[n - 1] += 1;
    }
    for(int i = 0; i < 100; ++i) {
      ccount[count[i]] += 1;
    }
    for(int i = 100; i > 0; --i) {
      if(ccount[i]) return i * ccount[i];
    }
    return -1;
  }
};

// Accepted
// 623/623 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 10 % of cpp submissions (23.4 MB)
```
