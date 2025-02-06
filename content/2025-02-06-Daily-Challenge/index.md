+++
updated = 2025-02-06T21:55:00+08:00
title = "2025-02-06 Daily Challenge"
path = "2025-02-06-Daily-Challenge"
date = 2025-02-06T21:55:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/tuple-with-same-product/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 6

## Description

**Tuple with Same Product**

<p>Given an array <code>nums</code> of <strong>distinct</strong> positive integers, return <em>the number of tuples </em><code>(a, b, c, d)</code><em> such that </em><code>a * b = c * d</code><em> where </em><code>a</code><em>, </em><code>b</code><em>, </em><code>c</code><em>, and </em><code>d</code><em> are elements of </em><code>nums</code><em>, and </em><code>a != b != c != d</code><em>.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,3,4,6]
<strong>Output:</strong> 8
<strong>Explanation:</strong> There are 8 valid tuples:
(2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
(3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,4,5,10]
<strong>Output:</strong> 16
<strong>Explanation:</strong> There are 16 valid tuples:
(1,10,2,5) , (1,10,5,2) , (10,1,2,5) , (10,1,5,2)
(2,5,1,10) , (2,5,10,1) , (5,2,1,10) , (5,2,10,1)
(2,10,4,5) , (2,10,5,4) , (10,2,4,5) , (10,2,5,4)
(4,5,2,10) , (4,5,10,2) , (5,4,2,10) , (5,4,10,2)
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li>All elements in <code>nums</code> are <strong>distinct</strong>.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int tupleSameProduct(vector<int>& nums) {
    int len = nums.size();
    if(len < 4) return 0;
    map<int, int> productCount;
    for(int i = 0; i < nums.size(); ++i) {
      for(int j = i + 1; j < nums.size(); ++j) {
        productCount[nums[i] * nums[j]] += 1;
      }
    }
    int answer = 0;
    for(auto [_, c] : productCount) {
      answer += 4 * c * (c - 1);
    }
    return answer;
  }
};

// Accepted
// 37/37 cases passed (681 ms)
// Your runtime beats 14.73 % of cpp submissions
// Your memory usage beats 15.67 % of cpp submissions (99.2 MB)
```
