+++
updated = 2024-06-14T13:27:44+08:00
title = "2024-06-14 Daily Challenge"
path = "2024-06-14-Daily-Challenge"
date = 2024-06-14T13:27:44+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/minimum-increment-to-make-array-unique/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 14

## Description

**Minimum Increment to Make Array Unique**

<p>You are given an integer array <code>nums</code>. In one move, you can pick an index <code>i</code> where <code>0 &lt;= i &lt; nums.length</code> and increment <code>nums[i]</code> by <code>1</code>.</p>

<p>Return <em>the minimum number of moves to make every value in </em><code>nums</code><em> <strong>unique</strong></em>.</p>

<p>The test cases are generated so that the answer fits in a 32-bit integer.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,2]
<strong>Output:</strong> 1
<strong>Explanation:</strong> After 1 move, the array could be [1, 2, 3].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,2,1,2,1,7]
<strong>Output:</strong> 6
<strong>Explanation:</strong> After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
It can be shown with 5 or less moves that it is impossible for the array to have all unique values.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int minIncrementForUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int answer = 0;
    for(int i = 1; i < nums.size(); ++i) {
      if(nums[i] > nums[i - 1]) continue;
      answer += nums[i - 1] - nums[i] + 1;
      nums[i] = nums[i - 1] + 1;
    }
    return answer;
  }
};
```
