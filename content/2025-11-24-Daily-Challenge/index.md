+++
updated = 2025-11-25T00:31:03+01:00
title = "2025-11-24 Daily Challenge"
path = "2025-11-24-Daily-Challenge"
date = 2025-11-25T00:31:03+01:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/binary-prefix-divisible-by-5/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 24

## Description

**Binary Prefix Divisible By 5**

<p>You are given a binary array <code>nums</code> (<strong>0-indexed</strong>).</p>

<p>We define <code>x<sub>i</sub></code> as the number whose binary representation is the subarray <code>nums[0..i]</code> (from most-significant-bit to least-significant-bit).</p>

<ul>
	<li>For example, if <code>nums = [1,0,1]</code>, then <code>x<sub>0</sub> = 1</code>, <code>x<sub>1</sub> = 2</code>, and <code>x<sub>2</sub> = 5</code>.</li>
</ul>

<p>Return <em>an array of booleans </em><code>answer</code><em> where </em><code>answer[i]</code><em> is </em><code>true</code><em> if </em><code>x<sub>i</sub></code><em> is divisible by </em><code>5</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [0,1,1]
<strong>Output:</strong> [true,false,false]
<strong>Explanation:</strong> The input numbers in binary are 0, 01, 011; which are 0, 1, and 3 in base-10.
Only the first number is divisible by 5, so answer[0] is true.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,1,1]
<strong>Output:</strong> [false,false,false]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>nums[i]</code> is either <code>0</code> or <code>1</code>.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  vector<bool> prefixesDivBy5(vector<int>& nums) {
    int current = 0;
    vector<bool> answer;
    answer.reserve(nums.size());
    for(auto n : nums) {
      current *= 2;
      current += n;
      current %= 5;
      answer.push_back(!current);
    }
    return answer;
  }
};

// Accepted
// 24/24 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 37.19 % of cpp submissions (18.5 MB)
```
