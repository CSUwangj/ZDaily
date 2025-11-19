+++
updated = 2025-11-19T21:54:48+01:00
title = "2025-11-19 Daily Challenge"
path = "2025-11-19-Daily-Challenge"
date = 2025-11-19T21:54:48+01:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/keep-multiplying-found-values-by-two/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 19

## Description

**Keep Multiplying Found Values by Two**

<p>You are given an array of integers <code>nums</code>. You are also given an integer <code>original</code> which is the first number that needs to be searched for in <code>nums</code>.</p>

<p>You then do the following steps:</p>

<ol>
	<li>If <code>original</code> is found in <code>nums</code>, <strong>multiply</strong> it by two (i.e., set <code>original = 2 * original</code>).</li>
	<li>Otherwise, <strong>stop</strong> the process.</li>
	<li><strong>Repeat</strong> this process with the new number as long as you keep finding the number.</li>
</ol>

<p>Return <em>the <strong>final</strong> value of </em><code>original</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [5,3,6,1,12], original = 3
<strong>Output:</strong> 24
<strong>Explanation:</strong> 
- 3 is found in nums. 3 is multiplied by 2 to obtain 6.
- 6 is found in nums. 6 is multiplied by 2 to obtain 12.
- 12 is found in nums. 12 is multiplied by 2 to obtain 24.
- 24 is not found in nums. Thus, 24 is returned.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,7,9], original = 4
<strong>Output:</strong> 4
<strong>Explanation:</strong>
- 4 is not found in nums. Thus, 4 is returned.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i], original &lt;= 1000</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int findFinalValue(vector<int>& nums, int original) {
    sort(nums.begin(), nums.end());
    auto it = lower_bound(nums.begin(), nums.end(), original);
    while(it != nums.end() && *it == original) {
      original *= 2;
      it = lower_bound(it, nums.end(), original);
    }
    return original;
  }
};

// Accepted
// 81/81 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 89.21 % of cpp submissions (14 MB)
```
