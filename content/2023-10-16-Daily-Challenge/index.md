+++
updated = 2023-10-16T12:20:31+08:00
title = "2023-10-16 Daily Challenge"
path = "2023-10-16-Daily-Challenge"
date = 2023-10-16T12:20:31+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/pascals-triangle-ii/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 16

## Description

**Pascal's Triangle II**

<p>Given an integer <code>rowIndex</code>, return the <code>rowIndex<sup>th</sup></code> (<strong>0-indexed</strong>) row of the <strong>Pascal&#39;s triangle</strong>.</p>

<p>In <strong>Pascal&#39;s triangle</strong>, each number is the sum of the two numbers directly above it as shown:</p>
<img alt="" src="https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif" style="height:240px; width:260px" />
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> rowIndex = 3
<strong>Output:</strong> [1,3,3,1]
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> rowIndex = 0
<strong>Output:</strong> [1]
</pre><p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> rowIndex = 1
<strong>Output:</strong> [1,1]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= rowIndex &lt;= 33</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Could you optimize your algorithm to use only <code>O(rowIndex)</code> extra space?</p>


## Solution

``` cpp
constexpr int combination(int m, int n) {
  m = n - m > m ? m : n - m;
  long long result = 1;
  for(int i = 0; i < m; ++i) {
    result *= n - i;
    result /= i + 1;
  }
  return result;
}
class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> answer(rowIndex + 1);
    for(int i = 0; i <= rowIndex; ++i) {
      answer[i] = combination(i, rowIndex);
    }
    return answer;
  }
};

// Accepted
// 34/34 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 52.72 % of cpp submissions (6.4 MB)
```
