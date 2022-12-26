+++
updated = 2022-12-26T13:20:10+08:00
title = "2022-12-26 Daily Challenge"
path = "2022-12-26-Daily-Challenge"
date = 2022-12-26T13:20:10+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/jump-game/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 26

## Description

**Jump Game**

<p>You are given an integer array <code>nums</code>. You are initially positioned at the array&#39;s <strong>first index</strong>, and each element in the array represents your maximum jump length at that position.</p>

<p>Return <code>true</code><em> if you can reach the last index, or </em><code>false</code><em> otherwise</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,3,1,1,4]
<strong>Output:</strong> true
<strong>Explanation:</strong> Jump 1 step from index 0 to 1, then 3 steps to the last index.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,2,1,0,4]
<strong>Output:</strong> false
<strong>Explanation:</strong> You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();

class Solution {
public:
  bool canJump(vector<int>& nums) {
    int cur = 0;
    int len = nums.size();
    for(int i = 0; i < len && i <= cur; ++i) {
      cur = max(cur, i + nums[i]);
      if(cur >= len - 1) return true;
    }
    return false;
  }
};

// Accepted
// 170/170 cases passed (56 ms)
// Your runtime beats 98.71 % of cpp submissions
// Your memory usage beats 79.88 % of cpp submissions (48.3 MB)
```
