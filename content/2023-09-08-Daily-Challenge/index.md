+++
updated = 2023-09-08T03:34:24+08:00
title = "2023-09-08 Daily Challenge"
path = "2023-09-08-Daily-Challenge"
date = 2023-09-08T03:34:24+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/pascals-triangle/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 8

## Description

**Pascal's Triangle**

<p>Given an integer <code>numRows</code>, return the first numRows of <strong>Pascal&#39;s triangle</strong>.</p>

<p>In <strong>Pascal&#39;s triangle</strong>, each number is the sum of the two numbers directly above it as shown:</p>
<img alt="" src="https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif" style="height:240px; width:260px" />
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> numRows = 5
<strong>Output:</strong> [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> numRows = 1
<strong>Output:</strong> [[1]]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= numRows &lt;= 30</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> answer(numRows);
    answer[0] = {1};
    for(int i = 1; i < numRows; ++i) {
      for(int j = 0; j <= i; ++j) {
        if(!j || j == i) {
          answer[i].push_back(1);
        } else {
          answer[i].push_back(answer[i - 1][j - 1] + answer[i - 1][j]);
        }
      }
    }
    return answer;
  }
};

// Accepted
// 14/14 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 33.54 % of cpp submissions (6.6 MB)
```
