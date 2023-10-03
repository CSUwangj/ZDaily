+++
updated = 2023-10-03T10:28:14+08:00
title = "2023-10-03 Daily Challenge"
path = "2023-10-03-Daily-Challenge"
date = 2023-10-03T10:28:14+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/number-of-good-pairs/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 3

## Description

**Number of Good Pairs**

<p>Given an array of integers <code>nums</code>, return <em>the number of <strong>good pairs</strong></em>.</p>

<p>A pair <code>(i, j)</code> is called <em>good</em> if <code>nums[i] == nums[j]</code> and <code>i</code> &lt; <code>j</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,1,1,3]
<strong>Output:</strong> 4
<strong>Explanation:</strong> There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,1,1,1]
<strong>Output:</strong> 6
<strong>Explanation:</strong> Each pair in the array are <em>good</em>.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> 0
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
  int numIdenticalPairs(vector<int>& nums) {
    vector<int> count(101);
    int answer = 0;
    for(auto n : nums) {
      answer += count[n];
      count[n] += 1;
    }
    return answer;
  }
};

// Accepted
// 48/48 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 7.1 % of cpp submissions (7.9 MB)
```
