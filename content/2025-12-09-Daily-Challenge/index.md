+++
updated = 2025-12-09T08:29:28+01:00
title = "2025-12-09 Daily Challenge"
path = "2025-12-09-Daily-Challenge"
date = 2025-12-09T08:29:28+01:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/count-special-triplets/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 9

## Description

**Count Special Triplets**

<p>You are given an integer array <code>nums</code>.</p>

<p>A <strong>special triplet</strong> is defined as a triplet of indices <code>(i, j, k)</code> such that:</p>

<ul>
	<li><code>0 &lt;= i &lt; j &lt; k &lt; n</code>, where <code>n = nums.length</code></li>
	<li><code>nums[i] == nums[j] * 2</code></li>
	<li><code>nums[k] == nums[j] * 2</code></li>
</ul>

<p>Return the total number of <strong>special triplets</strong> in the array.</p>

<p>Since the answer may be large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [6,3,6]</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<p>The only special triplet is <code>(i, j, k) = (0, 1, 2)</code>, where:</p>

<ul>
	<li><code>nums[0] = 6</code>, <code>nums[1] = 3</code>, <code>nums[2] = 6</code></li>
	<li><code>nums[0] = nums[1] * 2 = 3 * 2 = 6</code></li>
	<li><code>nums[2] = nums[1] * 2 = 3 * 2 = 6</code></li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [0,1,0,0]</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<p>The only special triplet is <code>(i, j, k) = (0, 2, 3)</code>, where:</p>

<ul>
	<li><code>nums[0] = 0</code>, <code>nums[2] = 0</code>, <code>nums[3] = 0</code></li>
	<li><code>nums[0] = nums[2] * 2 = 0 * 2 = 0</code></li>
	<li><code>nums[3] = nums[2] * 2 = 0 * 2 = 0</code></li>
</ul>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [8,4,2,8,4]</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p>There are exactly two special triplets:</p>

<ul>
	<li><code>(i, j, k) = (0, 1, 3)</code>

	<ul>
		<li><code>nums[0] = 8</code>, <code>nums[1] = 4</code>, <code>nums[3] = 8</code></li>
		<li><code>nums[0] = nums[1] * 2 = 4 * 2 = 8</code></li>
		<li><code>nums[3] = nums[1] * 2 = 4 * 2 = 8</code></li>
	</ul>
	</li>
	<li><code>(i, j, k) = (1, 2, 4)</code>
	<ul>
		<li><code>nums[1] = 4</code>, <code>nums[2] = 2</code>, <code>nums[4] = 4</code></li>
		<li><code>nums[1] = nums[2] * 2 = 2 * 2 = 4</code></li>
		<li><code>nums[4] = nums[2] * 2 = 2 * 2 = 4</code></li>
	</ul>
	</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= n == nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
  const int MOD = 1e9 + 7;
public:
  int specialTriplets(vector<int>& nums) {
    map<int, vector<int>> positions;
    int len = nums.size();
    for(int i = 0; i < len; ++i) {
      positions[nums[i]].push_back(i);
    }
    int answer = 0;
    for(auto &[jNum, jPos] : positions) {
      if(!jNum) {
        int sz = jPos.size();
        answer += 1LL * sz * (sz - 1) * (sz - 2) / 6 % MOD;
        continue;
      }
      if(!positions.count(jNum * 2) || positions[jNum * 2].size() < 2) continue;
      vector<int> &ik = positions[jNum * 2];
      int sz = ik.size();
      int k = upper_bound(ik.begin(), ik.end(), jPos[0]) - ik.begin();
      for(auto j : jPos) {
        k = upper_bound(ik.begin() + k, ik.end(), j) - ik.begin();
        if(k == sz) break;
        answer += 1LL * (k) * (sz - k) % MOD;
        answer %= MOD;
      }
      // cout << jNum << ' ' << answer << endl;
    }
    return answer;
  }
};

// Accepted
// 1121/1121 cases passed (725 ms)
// Your runtime beats 64.23 % of cpp submissions
// Your memory usage beats 61.68 % of cpp submissions (368.9 MB)
```
