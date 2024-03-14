+++
updated = 2024-03-14T17:05:12+08:00
title = "2024-03-14 Daily Challenge"
path = "2024-03-14-Daily-Challenge"
date = 2024-03-14T17:05:12+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/binary-subarrays-with-sum/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 14

## Description

**Binary Subarrays With Sum**

<p>Given a binary array <code>nums</code> and an integer <code>goal</code>, return <em>the number of non-empty <strong>subarrays</strong> with a sum</em> <code>goal</code>.</p>

<p>A <strong>subarray</strong> is a contiguous part of the array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,0,1,0,1], goal = 2
<strong>Output:</strong> 4
<strong>Explanation:</strong> The 4 subarrays are bolded and underlined below:
[<u><strong>1,0,1</strong></u>,0,1]
[<u><strong>1,0,1,0</strong></u>,1]
[1,<u><strong>0,1,0,1</strong></u>]
[1,0,<u><strong>1,0,1</strong></u>]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [0,0,0,0,0], goal = 0
<strong>Output:</strong> 15
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>nums[i]</code> is either <code>0</code> or <code>1</code>.</li>
	<li><code>0 &lt;= goal &lt;= nums.length</code></li>
</ul>

## Solution

``` cpp
class Solution {
public:
  int numSubarraysWithSum(vector<int>& nums, int goal) {
    vector<int> zeros;
    int zero = 0;
    for(auto n : nums) {
      if(n) {
        zeros.push_back(zero);
        zero = 0;
      } else {
        zero += 1;
      }
    }
    zeros.push_back(zero);
    int answer = 0;
    if(goal) {
      for(int i = 0; i + goal < zeros.size(); ++i) {
        answer += (zeros[i] + 1) * (zeros[i + goal] + 1);
      }
    } else {
      for(auto zero : zeros) {
        answer += (1 + zero) * zero / 2;
      }
    }
    return answer;
  }
};
```
