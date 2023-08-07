+++
updated = 2023-08-07T12:26:26+08:00
title = "2023-08-07 Daily Challenge"
path = "2023-08-07-Daily-Challenge"
date = 2023-08-07T12:26:26+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/search-a-2d-matrix/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 7

## Description

**Search a 2D Matrix**

<p>You are given an <code>m x n</code> integer matrix <code>matrix</code> with the following two properties:</p>

<ul>
	<li>Each row is sorted in non-decreasing order.</li>
	<li>The first integer of each row is greater than the last integer of the previous row.</li>
</ul>

<p>Given an integer <code>target</code>, return <code>true</code> <em>if</em> <code>target</code> <em>is in</em> <code>matrix</code> <em>or</em> <code>false</code> <em>otherwise</em>.</p>

<p>You must write a solution in <code>O(log(m * n))</code> time complexity.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/05/mat.jpg" style="width: 322px; height: 242px;" />
<pre>
<strong>Input:</strong> matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
<strong>Output:</strong> true
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/05/mat2.jpg" style="width: 322px; height: 242px;" />
<pre>
<strong>Input:</strong> matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>-10<sup>4</sup> &lt;= matrix[i][j], target &lt;= 10<sup>4</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(!matrix.size() || !matrix[0].size()) return false;
    int begin = 0, end = matrix.size()-1;
    vector<int> &a = matrix[0];
    while(begin < end) {
      int mid = (begin + end) / 2;
      if(matrix[mid].front() > target) {
        end = mid - 1;
      } else if (matrix[mid].back() < target) {
        begin = mid + 1;
      } else {
        break;
      }
    }
    a = matrix[(begin+end)/2];
    return binary_search(a.begin(), a.end(), target);
  }
};

// Accepted
// 133/133 cases passed ( ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 19.85 % of cpp submissions (9.6 MB)
```
