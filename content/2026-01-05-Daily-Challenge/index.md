+++
updated = 2026-01-05T21:06:46+01:00
title = "2026-01-05 Daily Challenge"
path = "2026-01-05-Daily-Challenge"
date = 2026-01-05T21:06:46+01:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/maximum-matrix-sum/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 5

## Description

**Maximum Matrix Sum**

<p>You are given an <code>n x n</code> integer <code>matrix</code>. You can do the following operation <strong>any</strong> number of times:</p>

<ul>
	<li>Choose any two <strong>adjacent</strong> elements of <code>matrix</code> and <strong>multiply</strong> each of them by <code>-1</code>.</li>
</ul>

<p>Two elements are considered <strong>adjacent</strong> if and only if they share a <strong>border</strong>.</p>

<p>Your goal is to <strong>maximize</strong> the summation of the matrix&#39;s elements. Return <em>the <strong>maximum</strong> sum of the matrix&#39;s elements using the operation mentioned above.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/16/pc79-q2ex1.png" style="width: 401px; height: 81px;" />
<pre>
<strong>Input:</strong> matrix = [[1,-1],[-1,1]]
<strong>Output:</strong> 4
<b>Explanation:</b> We can follow the following steps to reach sum equals 4:
- Multiply the 2 elements in the first row by -1.
- Multiply the 2 elements in the first column by -1.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/16/pc79-q2ex2.png" style="width: 321px; height: 121px;" />
<pre>
<strong>Input:</strong> matrix = [[1,2,3],[-1,-2,-3],[1,2,3]]
<strong>Output:</strong> 16
<b>Explanation:</b> We can follow the following step to reach sum equals 16:
- Multiply the 2 last elements in the second row by -1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == matrix.length == matrix[i].length</code></li>
	<li><code>2 &lt;= n &lt;= 250</code></li>
	<li><code>-10<sup>5</sup> &lt;= matrix[i][j] &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  long long maxMatrixSum(vector<vector<int>>& matrix) {
    long long answer = 0;
    int negCount = 0;
    int minAbso = INT_MAX;
    for(const auto &row : matrix) {
      for(auto c : row) {
        answer += abs(c);
        minAbso = min(minAbso, abs(c));
        negCount += c < 0;
      }
    }
    if(negCount & 1) {
      answer -= 2 * minAbso;
    }
    return answer;
  }
};

// Accepted
// 98/98 cases passed (4 ms)
// Your runtime beats 32.54 % of cpp submissions
// Your memory usage beats 61.72 % of cpp submissions (39.1 MB)
```
