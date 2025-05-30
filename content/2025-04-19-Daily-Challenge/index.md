+++
updated = 2025-04-19T13:26:16+08:00
title = "2025-04-19 Daily Challenge"
path = "2025-04-19-Daily-Challenge"
date = 2025-04-19T13:26:16+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/count-the-number-of-fair-pairs/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 19

## Description

**Count the Number of Fair Pairs**

<p>Given a <strong>0-indexed</strong> integer array <code>nums</code> of size <code>n</code> and two integers <code>lower</code> and <code>upper</code>, return <em>the number of fair pairs</em>.</p>

<p>A pair <code>(i, j)</code> is <b>fair </b>if:</p>

<ul>
	<li><code>0 &lt;= i &lt; j &lt; n</code>, and</li>
	<li><code>lower &lt;= nums[i] + nums[j] &lt;= upper</code></li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [0,1,7,4,4,5], lower = 3, upper = 6
<strong>Output:</strong> 6
<strong>Explanation:</strong> There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,7,9,2,5], lower = 11, upper = 11
<strong>Output:</strong> 1
<strong>Explanation:</strong> There is a single fair pair: (2,3).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>nums.length == n</code></li>
	<li><code><font face="monospace">-10<sup>9</sup></font>&nbsp;&lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code><font face="monospace">-10<sup>9</sup>&nbsp;&lt;= lower &lt;= upper &lt;= 10<sup>9</sup></font></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  long long countFairPairs(vector<int>& nums, int lower, int upper) {
    sort(nums.begin(), nums.end());
    long long answer = 0;
    map<int, int> count;
    for(auto n : nums) {
      count[n] += 1;
      auto eit = upper_bound(nums.begin(), nums.end(), upper - n);
      if(eit == nums.begin()) continue;
      auto bit = lower_bound(nums.begin(), nums.end(), lower - n);
      answer += eit - bit;
    }
    for(const auto &[n, c] : count) {
      if(2 * n >= lower && 2 * n <= upper) answer -= c;
    }
    return answer / 2;
  }
};

// Accepted
// 54/54 cases passed (180 ms)
// Your runtime beats 8.23 % of cpp submissions
// Your memory usage beats 5.03 % of cpp submissions (88 MB)
```
