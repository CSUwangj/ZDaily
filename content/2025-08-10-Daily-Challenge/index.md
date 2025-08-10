+++
updated = 2025-08-10T22:21:19+08:00
title = "2025-08-10 Daily Challenge"
path = "2025-08-10-Daily-Challenge"
date = 2025-08-10T22:21:19+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/reordered-power-of-2/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 10

## Description

**Reordered Power of 2**

<p>You are given an integer <code>n</code>. We reorder the digits in any order (including the original order) such that the leading digit is not zero.</p>

<p>Return <code>true</code> <em>if and only if we can do this so that the resulting number is a power of two</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 1
<strong>Output:</strong> true
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 10
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code></li>
</ul>


## Solution

``` cpp
const set<string> st = {"011237","0122579","012356789","0124","0134449","0145678","01466788","0248","0368888","0469","1","112234778","11266777","122446","125","128","1289","13468","16","2","224588","23","23334455","234455668","23678","256","35566","4","46","8"};
class Solution {
public:
  bool reorderedPowerOf2(int N) {
    string n = to_string(N);
    sort(n.begin(), n.end());
    return st.count(n);
  }
};

// Accepted
// 136/136 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 83.9 % of cpp submissions (6 MB)
```
