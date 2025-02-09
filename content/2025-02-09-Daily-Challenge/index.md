+++
updated = 2025-02-09T10:56:00+08:00
title = "2025-02-09 Daily Challenge"
path = "2025-02-09-Daily-Challenge"
date = 2025-02-09T10:56:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/count-number-of-bad-pairs/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 9

## Description

**Count Number of Bad Pairs**

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code>. A pair of indices <code>(i, j)</code> is a <strong>bad pair</strong> if <code>i &lt; j</code> and <code>j - i != nums[j] - nums[i]</code>.</p>

<p>Return<em> the total number of <strong>bad pairs</strong> in </em><code>nums</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [4,1,3,3]
<strong>Output:</strong> 5
<strong>Explanation:</strong> The pair (0, 1) is a bad pair since 1 - 0 != 1 - 4.
The pair (0, 2) is a bad pair since 2 - 0 != 3 - 4, 2 != -1.
The pair (0, 3) is a bad pair since 3 - 0 != 3 - 4, 3 != -1.
The pair (1, 2) is a bad pair since 2 - 1 != 3 - 1, 1 != 2.
The pair (2, 3) is a bad pair since 3 - 2 != 3 - 3, 1 != 0.
There are a total of 5 bad pairs, so we return 5.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,4,5]
<strong>Output:</strong> 0
<strong>Explanation:</strong> There are no bad pairs.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  long long countBadPairs(vector<int>& nums) {
    map<long long, long long> offsets;
    long long answer = 0;
    for(int i = 0; i < nums.size(); ++i) {
      long long offset = nums[i] - i;
      answer += i - offsets[offset];
      offsets[offset] += 1;
    } 
    return answer;
  }
};

// Accepted
// 65/65 cases passed (141 ms)
// Your runtime beats 7.29 % of cpp submissions
// Your memory usage beats 39.21 % of cpp submissions (89.3 MB)
```
