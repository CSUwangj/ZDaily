+++
updated = 2025-03-26T11:36:22+08:00
title = "2025-03-26 Daily Challenge"
path = "2025-03-26-Daily-Challenge"
date = 2025-03-26T11:36:22+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 26

## Description

**Minimum Operations to Make a Uni-Value Grid**

<p>You are given a 2D integer <code>grid</code> of size <code>m x n</code> and an integer <code>x</code>. In one operation, you can <strong>add</strong> <code>x</code> to or <strong>subtract</strong> <code>x</code> from any element in the <code>grid</code>.</p>

<p>A <strong>uni-value grid</strong> is a grid where all the elements of it are equal.</p>

<p>Return <em>the <strong>minimum</strong> number of operations to make the grid <strong>uni-value</strong></em>. If it is not possible, return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/09/21/gridtxt.png" style="width: 164px; height: 165px;" />
<pre>
<strong>Input:</strong> grid = [[2,4],[6,8]], x = 2
<strong>Output:</strong> 4
<strong>Explanation:</strong> We can make every element equal to 4 by doing the following: 
- Add x to 2 once.
- Subtract x from 6 once.
- Subtract x from 8 twice.
A total of 4 operations were used.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/09/21/gridtxt-1.png" style="width: 164px; height: 165px;" />
<pre>
<strong>Input:</strong> grid = [[1,5],[2,3]], x = 1
<strong>Output:</strong> 5
<strong>Explanation:</strong> We can make every element equal to 3.
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/09/21/gridtxt-2.png" style="width: 164px; height: 165px;" />
<pre>
<strong>Input:</strong> grid = [[1,2],[3,4]], x = 2
<strong>Output:</strong> -1
<strong>Explanation:</strong> It is impossible to make every element equal.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= x, grid[i][j] &lt;= 10<sup>4</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int minOperations(vector<vector<int>>& grid, int x) {
    int target = grid.front().front() % x;
    vector<int> nums;
    for(auto &row : grid) {
      for(auto n : row) {
        if(n % x != target) return -1;
        nums.push_back(n);
      }
    }

    sort(nums.begin(), nums.end());
    target = nums[nums.size() / 2];
    int answer = 0;
    for(auto n : nums) {
      answer += abs(n - target) / x;
    }

    return answer;
  }
};

// Accepted
// 62/62 cases passed (32 ms)
// Your runtime beats 78.72 % of cpp submissions
// Your memory usage beats 67.78 % of cpp submissions (87.1 MB)
```
