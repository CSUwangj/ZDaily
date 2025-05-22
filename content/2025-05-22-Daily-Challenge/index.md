+++
updated = 2025-05-23T03:49:57+08:00
title = "2025-05-22 Daily Challenge"
path = "2025-05-22-Daily-Challenge"
date = 2025-05-23T03:49:57+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/zero-array-transformation-iii/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 22

## Description

**Zero Array Transformation III**

<p>You are given an integer array <code>nums</code> of length <code>n</code> and a 2D array <code>queries</code> where <code>queries[i] = [l<sub>i</sub>, r<sub>i</sub>]</code>.</p>

<p>Each <code>queries[i]</code> represents the following action on <code>nums</code>:</p>

<ul>
	<li>Decrement the value at each index in the range <code>[l<sub>i</sub>, r<sub>i</sub>]</code> in <code>nums</code> by <strong>at most</strong><strong> </strong>1.</li>
	<li>The amount by which the value is decremented can be chosen <strong>independently</strong> for each index.</li>
</ul>

<p>A <strong>Zero Array</strong> is an array with all its elements equal to 0.</p>

<p>Return the <strong>maximum </strong>number of elements that can be removed from <code>queries</code>, such that <code>nums</code> can still be converted to a <strong>zero array</strong> using the <em>remaining</em> queries. If it is not possible to convert <code>nums</code> to a <strong>zero array</strong>, return -1.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [2,0,2], queries = [[0,2],[0,2],[1,1]]</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<p>After removing <code>queries[2]</code>, <code>nums</code> can still be converted to a zero array.</p>

<ul>
	<li>Using <code>queries[0]</code>, decrement <code>nums[0]</code> and <code>nums[2]</code> by 1 and <code>nums[1]</code> by 0.</li>
	<li>Using <code>queries[1]</code>, decrement <code>nums[0]</code> and <code>nums[2]</code> by 1 and <code>nums[1]</code> by 0.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,1,1,1], queries = [[1,3],[0,2],[1,3],[1,2]]</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p>We can remove <code>queries[2]</code> and <code>queries[3]</code>.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2,3,4], queries = [[0,3]]</span></p>

<p><strong>Output:</strong> <span class="example-io">-1</span></p>

<p><strong>Explanation:</strong></p>

<p><code>nums</code> cannot be converted to a zero array even after using all the queries.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>queries[i].length == 2</code></li>
	<li><code>0 &lt;= l<sub>i</sub> &lt;= r<sub>i</sub> &lt; nums.length</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
    sort(queries.begin(), queries.end());
    priority_queue<int> candidates;
    priority_queue<int, vector<int>, greater<int>> chosen;
    int need = 0;
    int pos = 0;
    for(int i = 0; i < nums.size(); ++i) {
      while(pos < queries.size() && queries[pos][0] == i) {
        candidates.push(queries[pos][1]);
        pos += 1;
      }
      nums[i] -= chosen.size();
      while(nums[i] > 0 && candidates.size() && candidates.top() >= i) {
        need += 1;
        chosen.push(candidates.top());
        candidates.pop();
        nums[i] -= 1;
      }
      if(nums[i] > 0) return -1;
      while(chosen.size() && chosen.top() == i) {
        chosen.pop();
      }
    }
    return queries.size() - need;
  }
};

// Accepted
// 824/824 cases passed (131 ms)
// Your runtime beats 51.38 % of cpp submissions
// Your memory usage beats 49.31 % of cpp submissions (224.5 MB)
```
