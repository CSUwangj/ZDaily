+++
updated = 2025-04-17T12:32:16+08:00
title = "2025-04-17 Daily Challenge"
path = "2025-04-17-Daily-Challenge"
date = 2025-04-17T12:32:16+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 17

## Description

**Count Equal and Divisible Pairs in an Array**

Given a <strong>0-indexed</strong> integer array <code>nums</code> of length <code>n</code> and an integer <code>k</code>, return <em>the <strong>number of pairs</strong></em> <code>(i, j)</code> <em>where</em> <code>0 &lt;= i &lt; j &lt; n</code>, <em>such that</em> <code>nums[i] == nums[j]</code> <em>and</em> <code>(i * j)</code> <em>is divisible by</em> <code>k</code>.
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,1,2,2,2,1,3], k = 2
<strong>Output:</strong> 4
<strong>Explanation:</strong>
There are 4 pairs that meet all the requirements:
- nums[0] == nums[6], and 0 * 6 == 0, which is divisible by 2.
- nums[2] == nums[3], and 2 * 3 == 6, which is divisible by 2.
- nums[2] == nums[4], and 2 * 4 == 8, which is divisible by 2.
- nums[3] == nums[4], and 3 * 4 == 12, which is divisible by 2.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,4], k = 1
<strong>Output:</strong> 0
<strong>Explanation:</strong> Since no value in nums is repeated, there are no pairs (i,j) that meet all the requirements.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i], k &lt;= 100</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int countPairs(vector<int>& nums, int k) {
    map<int, vector<int>> positions;
    for(int i = 0; i < nums.size(); ++i) {
      positions[nums[i]].push_back(i);
    }
    int answer = 0;
    for(const auto &[_n, pos] : positions) {
      for(int i = 0; i < pos.size() - 1; ++i) {
        for(int j = i + 1; j < pos.size(); ++j) {
          answer += !((pos[i] * pos[j]) % k);
        }
      }
    }
    return answer;
  }
};

// Accepted
// 238/238 cases passed (7 ms)
// Your runtime beats 3.85 % of cpp submissions
// Your memory usage beats 6.09 % of cpp submissions (16.2 MB)
```
