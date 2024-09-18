+++
updated = 2024-09-19T03:17:09+08:00
title = "2024-09-18 Daily Challenge"
path = "2024-09-18-Daily-Challenge"
date = 2024-09-19T03:17:09+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/largest-number/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 18

## Description

**Largest Number**

<p>Given a list of non-negative integers <code>nums</code>, arrange them such that they form the largest number and return it.</p>

<p>Since the result may be very large, so you need to return a string instead of an integer.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [10,2]
<strong>Output:</strong> &quot;210&quot;
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,30,34,5,9]
<strong>Output:</strong> &quot;9534330&quot;
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  string largestNumber(vector<int>& nums) {
    string ans = "";
    sort(nums.begin(), nums.end(), [](int a, int b){
      return to_string(a)+to_string(b)>to_string(b)+to_string(a);
    });
    for(auto i : nums){
      ans += to_string(i);
    }
    return ans[0] == '0' ? "0" : ans;
  }
};
```
