+++
updated = 2024-01-17T14:24:29+08:00
title = "2024-01-17 Daily Challenge"
path = "2024-01-17-Daily-Challenge"
date = 2024-01-17T14:24:29+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/unique-number-of-occurrences/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 17

## Description

**Unique Number of Occurrences**

<p>Given an array of integers <code>arr</code>, return <code>true</code> <em>if the number of occurrences of each value in the array is <strong>unique</strong> or </em><code>false</code><em> otherwise</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> arr = [1,2,2,1,1,3]
<strong>Output:</strong> true
<strong>Explanation:</strong>&nbsp;The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> arr = [1,2]
<strong>Output:</strong> false
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> arr = [-3,0,1,-3,1,1,1,-3,10,0]
<strong>Output:</strong> true
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 1000</code></li>
	<li><code>-1000 &lt;= arr[i] &lt;= 1000</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  bool uniqueOccurrences(vector<int>& arr) {
    map<int, int> count;
    for(auto n : arr) {
      count[n] += 1;
    }
    vector<int> c;
    c.reserve(count.size());
    for(const auto &[_, cnt] : count) {
      c.push_back(cnt);
    }
    sort(c.begin(), c.end());
    return (unique(c.begin(), c.end()) - c.begin()) == c.size();
  }
};

// Accepted
// 67/67 cases passed (6 ms)
// Your runtime beats 17.82 % of cpp submissions
// Your memory usage beats 9.43 % of cpp submissions (8.9 MB)
```
