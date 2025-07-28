+++
updated = 2025-07-29T01:38:08+08:00
title = "2025-07-28 Daily Challenge"
path = "2025-07-28-Daily-Challenge"
date = 2025-07-29T01:38:08+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 28

## Description

**Count Number of Maximum Bitwise-OR Subsets**

<p>Given an integer array <code>nums</code>, find the <strong>maximum</strong> possible <strong>bitwise OR</strong> of a subset of <code>nums</code> and return <em>the <strong>number of different non-empty subsets</strong> with the maximum bitwise OR</em>.</p>

<p>An array <code>a</code> is a <strong>subset</strong> of an array <code>b</code> if <code>a</code> can be obtained from <code>b</code> by deleting some (possibly zero) elements of <code>b</code>. Two subsets are considered <strong>different</strong> if the indices of the elements chosen are different.</p>

<p>The bitwise OR of an array <code>a</code> is equal to <code>a[0] <strong>OR</strong> a[1] <strong>OR</strong> ... <strong>OR</strong> a[a.length - 1]</code> (<strong>0-indexed</strong>).</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,1]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The maximum possible bitwise OR of a subset is 3. There are 2 subsets with a bitwise OR of 3:
- [3]
- [3,1]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,2,2]
<strong>Output:</strong> 7
<strong>Explanation:</strong> All non-empty subsets of [2,2,2] have a bitwise OR of 2. There are 2<sup>3</sup> - 1 = 7 total subsets.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,2,1,5]
<strong>Output:</strong> 6
<strong>Explanation:</strong> The maximum possible bitwise OR of a subset is 7. There are 6 subsets with a bitwise OR of 7:
- [3,5]
- [3,1,5]
- [3,2,5]
- [3,2,1,5]
- [2,5]
- [2,1,5]</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 16</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int countMaxOrSubsets(vector<int>& nums) {
    int target = accumulate(nums.begin(), nums.end(), 0, [](int p, int c) { return p | c;});
    int len = nums.size();
    int answer = 0;
    for(int i = 1; i < (1 << len); ++i) {
      int current = 0;
      for(int b = 0; b < len; ++b) {
        if(i & (1 << b)) current |= nums[b];
      }
      if(current == target) answer += 1;
    }
    return answer;
  }
};

// Accepted
// 111/111 cases passed (64 ms)
// Your runtime beats 37.44 % of cpp submissions
// Your memory usage beats 86.47 % of cpp submissions (10.6 MB)
```
