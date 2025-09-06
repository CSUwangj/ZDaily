+++
updated = 2025-09-06T23:05:35+02:00
title = "2025-09-06 Daily Challenge"
path = "2025-09-06-Daily-Challenge"
date = 2025-09-06T23:05:35+02:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 6

## Description

**Minimum Operations to Make Array Elements Zero**

<p>You are given a 2D array <code>queries</code>, where <code>queries[i]</code> is of the form <code>[l, r]</code>. Each <code>queries[i]</code> defines an array of integers <code>nums</code> consisting of elements ranging from <code>l</code> to <code>r</code>, both <strong>inclusive</strong>.</p>

<p>In one operation, you can:</p>

<ul>
	<li>Select two integers <code>a</code> and <code>b</code> from the array.</li>
	<li>Replace them with <code>floor(a / 4)</code> and <code>floor(b / 4)</code>.</li>
</ul>

<p>Your task is to determine the <strong>minimum</strong> number of operations required to reduce all elements of the array to zero for each query. Return the sum of the results for all queries.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">queries = [[1,2],[2,4]]</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<p>For <code>queries[0]</code>:</p>

<ul>
	<li>The initial array is <code>nums = [1, 2]</code>.</li>
	<li>In the first operation, select <code>nums[0]</code> and <code>nums[1]</code>. The array becomes <code>[0, 0]</code>.</li>
	<li>The minimum number of operations required is 1.</li>
</ul>

<p>For <code>queries[1]</code>:</p>

<ul>
	<li>The initial array is <code>nums = [2, 3, 4]</code>.</li>
	<li>In the first operation, select <code>nums[0]</code> and <code>nums[2]</code>. The array becomes <code>[0, 3, 1]</code>.</li>
	<li>In the second operation, select <code>nums[1]</code> and <code>nums[2]</code>. The array becomes <code>[0, 0, 0]</code>.</li>
	<li>The minimum number of operations required is 2.</li>
</ul>

<p>The output is <code>1 + 2 = 3</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">queries = [[2,6]]</span></p>

<p><strong>Output:</strong> <span class="example-io">4</span></p>

<p><strong>Explanation:</strong></p>

<p>For <code>queries[0]</code>:</p>

<ul>
	<li>The initial array is <code>nums = [2, 3, 4, 5, 6]</code>.</li>
	<li>In the first operation, select <code>nums[0]</code> and <code>nums[3]</code>. The array becomes <code>[0, 3, 4, 1, 6]</code>.</li>
	<li>In the second operation, select <code>nums[2]</code> and <code>nums[4]</code>. The array becomes <code>[0, 3, 1, 1, 1]</code>.</li>
	<li>In the third operation, select <code>nums[1]</code> and <code>nums[2]</code>. The array becomes <code>[0, 0, 0, 1, 1]</code>.</li>
	<li>In the fourth operation, select <code>nums[3]</code> and <code>nums[4]</code>. The array becomes <code>[0, 0, 0, 0, 0]</code>.</li>
	<li>The minimum number of operations required is 4.</li>
</ul>

<p>The output is 4.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>queries[i].length == 2</code></li>
	<li><code>queries[i] == [l, r]</code></li>
	<li><code>1 &lt;= l &lt; r &lt;= 10<sup>9</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
  long long countOps(long long target) {
    long long base = 4;
    long long ops = 2;
    long long result = 0;
    while(target >= base) {
      base *= 4;
      ops += 1;
    }
    base /= 4;
    ops -= 1;
    while(base) {
      result += ops * (target - base + 1);
      target = base - 1;
      ops -= 1;
      base /= 4;
    }
    result += target;
    return result;
  }
public:
  long long minOperations(vector<vector<int>>& queries) {
    long long answer = 0;
    for(auto const &q : queries) {
      // cout << q[1] << ' ' << countOps(q[1]) << endl;
      // cout << q[0] - 1 << ' ' << countOps(q[0] - 1) << endl;
      answer += (countOps(q[1]) - countOps(q[0] - 1) + 1) / 2;
    }
    return answer;
  }
};

// Accepted
// 646/646 cases passed (21 ms)
// Your runtime beats 61.27 % of cpp submissions
// Your memory usage beats 63.38 % of cpp submissions (183.4 MB)
```
