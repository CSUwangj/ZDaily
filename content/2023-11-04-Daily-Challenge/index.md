+++
updated = 2023-11-04T20:13:26+08:00
title = "2023-11-04 Daily Challenge"
path = "2023-11-04-Daily-Challenge"
date = 2023-11-04T20:13:26+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 4

## Description

**Last Moment Before All Ants Fall Out of a Plank**

<p>We have a wooden plank of the length <code>n</code> <strong>units</strong>. Some ants are walking on the plank, each ant moves with a speed of <strong>1 unit per second</strong>. Some of the ants move to the <strong>left</strong>, the other move to the <strong>right</strong>.</p>

<p>When two ants moving in two <strong>different</strong> directions meet at some point, they change their directions and continue moving again. Assume changing directions does not take any additional time.</p>

<p>When an ant reaches <strong>one end</strong> of the plank at a time <code>t</code>, it falls out of the plank immediately.</p>

<p>Given an integer <code>n</code> and two integer arrays <code>left</code> and <code>right</code>, the positions of the ants moving to the left and the right, return <em>the moment when the last ant(s) fall out of the plank</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/06/17/ants.jpg" style="width: 450px; height: 610px;" />
<pre>
<strong>Input:</strong> n = 4, left = [4,3], right = [0,1]
<strong>Output:</strong> 4
<strong>Explanation:</strong> In the image above:
-The ant at index 0 is named A and going to the right.
-The ant at index 1 is named B and going to the right.
-The ant at index 3 is named C and going to the left.
-The ant at index 4 is named D and going to the left.
The last moment when an ant was on the plank is t = 4 seconds. After that, it falls immediately out of the plank. (i.e., We can say that at t = 4.0000000001, there are no ants on the plank).
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/06/17/ants2.jpg" style="width: 639px; height: 101px;" />
<pre>
<strong>Input:</strong> n = 7, left = [], right = [0,1,2,3,4,5,6,7]
<strong>Output:</strong> 7
<strong>Explanation:</strong> All ants are going to the right, the ant at index 0 needs 7 seconds to fall.
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/06/17/ants3.jpg" style="width: 639px; height: 100px;" />
<pre>
<strong>Input:</strong> n = 7, left = [0,1,2,3,4,5,6,7], right = []
<strong>Output:</strong> 7
<strong>Explanation:</strong> All ants are going to the left, the ant at index 7 needs 7 seconds to fall.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= left.length &lt;= n + 1</code></li>
	<li><code>0 &lt;= left[i] &lt;= n</code></li>
	<li><code>0 &lt;= right.length &lt;= n + 1</code></li>
	<li><code>0 &lt;= right[i] &lt;= n</code></li>
	<li><code>1 &lt;= left.length + right.length &lt;= n + 1</code></li>
	<li>All values of <code>left</code> and <code>right</code> are unique, and each value can appear <strong>only in one</strong> of the two arrays.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int getLastMoment(int n, vector<int>& left, vector<int>& right) {
    left.push_back(0);
    right.push_back(n);
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    return max(n - right.front(), left.back());
  }
};

// Accepted
// 167/167 cases passed (24 ms)
// Your runtime beats 9.48 % of cpp submissions
// Your memory usage beats 59.05 % of cpp submissions (23 MB)
```
