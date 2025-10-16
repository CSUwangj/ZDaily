+++
updated = 2025-10-16T23:52:06+02:00
title = "2025-10-16 Daily Challenge"
path = "2025-10-16-Daily-Challenge"
date = 2025-10-16T23:52:06+02:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 16

## Description

**Smallest Missing Non-negative Integer After Operations**

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> and an integer <code>value</code>.</p>

<p>In one operation, you can add or subtract <code>value</code> from any element of <code>nums</code>.</p>

<ul>
	<li>For example, if <code>nums = [1,2,3]</code> and <code>value = 2</code>, you can choose to subtract <code>value</code> from <code>nums[0]</code> to make <code>nums = [-1,2,3]</code>.</li>
</ul>

<p>The MEX (minimum excluded) of an array is the smallest missing <strong>non-negative</strong> integer in it.</p>

<ul>
	<li>For example, the MEX of <code>[-1,2,3]</code> is <code>0</code> while the MEX of <code>[1,0,3]</code> is <code>2</code>.</li>
</ul>

<p>Return <em>the maximum MEX of </em><code>nums</code><em> after applying the mentioned operation <strong>any number of times</strong></em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,-10,7,13,6,8], value = 5
<strong>Output:</strong> 4
<strong>Explanation:</strong> One can achieve this result by applying the following operations:
- Add value to nums[1] twice to make nums = [1,<strong><u>0</u></strong>,7,13,6,8]
- Subtract value from nums[2] once to make nums = [1,0,<strong><u>2</u></strong>,13,6,8]
- Subtract value from nums[3] twice to make nums = [1,0,2,<strong><u>3</u></strong>,6,8]
The MEX of nums is 4. It can be shown that 4 is the maximum MEX we can achieve.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,-10,7,13,6,8], value = 7
<strong>Output:</strong> 2
<strong>Explanation:</strong> One can achieve this result by applying the following operation:
- subtract value from nums[2] once to make nums = [1,-10,<u><strong>0</strong></u>,13,6,8]
The MEX of nums is 2. It can be shown that 2 is the maximum MEX we can achieve.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length, value &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int findSmallestInteger(vector<int>& nums, int value) {
    value = abs(value);
    if(value == 1) return nums.size();
    map<int, int> rem;
    for(auto n : nums) {
      rem[((n % value) + value) % value] += 1;
    }
    int minRem = rem[0];
    int minPos = 0;
    if(!minRem) return 0;
    for(int i = 1; i < value; ++i) {
      if(rem[i] < minRem) {
        minRem = rem[i];
        minPos = i;
      }
    }
    return minRem * value + minPos;
  }
};

// Accepted
// 1062/1062 cases passed (139 ms)
// Your runtime beats 14.29 % of cpp submissions
// Your memory usage beats 11.28 % of cpp submissions (137.3 MB)
```
