+++
updated = 2023-10-22T10:48:14+08:00
title = "2023-10-22 Daily Challenge"
path = "2023-10-22-Daily-Challenge"
date = 2023-10-22T10:48:14+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/maximum-score-of-a-good-subarray/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 22

## Description

**Maximum Score of a Good Subarray**

<p>You are given an array of integers <code>nums</code> <strong>(0-indexed)</strong> and an integer <code>k</code>.</p>

<p>The <strong>score</strong> of a subarray <code>(i, j)</code> is defined as <code>min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1)</code>. A <strong>good</strong> subarray is a subarray where <code>i &lt;= k &lt;= j</code>.</p>

<p>Return <em>the maximum possible <strong>score</strong> of a <strong>good</strong> subarray.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,4,3,7,4,5], k = 3
<strong>Output:</strong> 15
<strong>Explanation:</strong> The optimal subarray is (1, 5) with a score of min(4,3,7,4,5) * (5-1+1) = 3 * 5 = 15. 
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [5,5,4,5,4,1,1,1], k = 0
<strong>Output:</strong> 20
<strong>Explanation:</strong> The optimal subarray is (0, 4) with a score of min(5,5,4,5,4) * (4-0+1) = 4 * 5 = 20.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= k &lt; nums.length</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int maximumScore(vector<int>& nums, int k) {
    int left = k;
    int right = k;
    int minVal = nums[k];
    int maxScore = nums[k];

    while(left > 0 || right < nums.size() - 1) {
      if(!left || (right < nums.size() - 1 && nums[right + 1] > nums[left - 1])) {
        right += 1;
      } else {
        left -= 1;
      }

      minVal = min({minVal, nums[left], nums[right]});
      maxScore = max(maxScore, minVal * (right - left + 1));
    }

    return maxScore;
  }
};

// Accepted
// 72/72 cases passed (136 ms)
// Your runtime beats 63.82 % of cpp submissions
// Your memory usage beats 59.87 % of cpp submissions (90 MB)
```
