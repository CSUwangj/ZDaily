+++
updated = 2023-02-08T11:38:54+08:00
title = "2023-02-08 Daily Challenge"
path = "2023-02-08-Daily-Challenge"
date = 2023-02-08T11:38:54+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/jump-game-ii/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 8

## Description

**Jump Game II**

<p>You are given a <strong>0-indexed</strong> array of integers <code>nums</code> of length <code>n</code>. You are initially positioned at <code>nums[0]</code>.</p>

<p>Each element <code>nums[i]</code> represents the maximum length of a forward jump from index <code>i</code>. In other words, if you are at <code>nums[i]</code>, you can jump to any <code>nums[i + j]</code> where:</p>

<ul>
	<li><code>0 &lt;= j &lt;= nums[i]</code> and</li>
	<li><code>i + j &lt; n</code></li>
</ul>

<p>Return <em>the minimum number of jumps to reach </em><code>nums[n - 1]</code>. The test cases are generated such that you can reach <code>nums[n - 1]</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,3,1,1,4]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,3,0,1,4]
<strong>Output:</strong> 2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1000</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int jump(vector<int>& nums) {
    int len = nums.size();
    queue<pair<int, int>> q;
    q.push({0, nums[0]});
    nums[0] = -1;
    int answer = 0;
    while(q.size()) {
      int sz = q.size();
      // cout << "round " << answer << ": " << endl;
      for(int i = 0; i < sz; ++i) {
        auto [index, offset] = q.front();
        // cout << index << ' ' << offset << endl;
        if(index == len - 1) return answer;
        q.pop();
        for(int j = max(0, index - offset); j < min(len, index + offset + 1); ++j) {
          if(nums[j] < 0) continue;
          q.push({j, nums[j]});
          nums[j] = - 1;
        }
      }
      // cout << endl;
      answer += 1;
    }
    return -1;
  }
};

// Accepted
// 109/109 cases passed (356 ms)
// Your runtime beats 32.61 % of cpp submissions
// Your memory usage beats 15.91 % of cpp submissions (17.7 MB)
```
