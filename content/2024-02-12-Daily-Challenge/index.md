+++
updated = 2024-02-12T13:45:07+08:00
title = "2024-02-12 Daily Challenge"
path = "2024-02-12-Daily-Challenge"
date = 2024-02-12T13:45:07+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/majority-element/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 12

## Description

**Majority Element**

<p>Given an array <code>nums</code> of size <code>n</code>, return <em>the majority element</em>.</p>

<p>The majority element is the element that appears more than <code>&lfloor;n / 2&rfloor;</code> times. You may assume that the majority element always exists in the array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [3,2,3]
<strong>Output:</strong> 3
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [2,2,1,1,1,2,2]
<strong>Output:</strong> 2
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow-up:</strong> Could you solve the problem in linear time and in <code>O(1)</code> space?

## Solution

``` cpp
class Solution {
public:
  int majorityElement(vector<int>& nums) {
    int answer = !nums.front();
    int count = 0;
    for(auto n : nums) {
      if(answer == n) {
        count += 1;
      } else {
        if(!count) {
          answer = n;
        } else {
          count -= 1;
        }
      }
    }
    return answer;
  }
};

// Accepted
// 50/50 cases passed (11 ms)
// Your runtime beats 83.7 % of cpp submissions
// Your memory usage beats 24.81 % of cpp submissions (22.1 MB)
```
