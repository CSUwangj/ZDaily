+++
updated = 2025-08-21T23:02:25+02:00
title = "2025-08-21 Daily Challenge"
path = "2025-08-21-Daily-Challenge"
date = 2025-08-21T23:02:25+02:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/count-submatrices-with-all-ones/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 21

## Description

**Count Submatrices With All Ones**

<p>Given an <code>m x n</code> binary matrix <code>mat</code>, <em>return the number of <strong>submatrices</strong> that have all ones</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/10/27/ones1-grid.jpg" style="width: 244px; height: 245px;" />
<pre>
<strong>Input:</strong> mat = [[1,0,1],[1,1,0],[1,1,0]]
<strong>Output:</strong> 13
<strong>Explanation:</strong> 
There are 6 rectangles of side 1x1.
There are 2 rectangles of side 1x2.
There are 3 rectangles of side 2x1.
There is 1 rectangle of side 2x2. 
There is 1 rectangle of side 3x1.
Total number of rectangles = 6 + 2 + 3 + 1 + 1 = 13.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/10/27/ones2-grid.jpg" style="width: 324px; height: 245px;" />
<pre>
<strong>Input:</strong> mat = [[0,1,1,0],[0,1,1,1],[1,1,1,0]]
<strong>Output:</strong> 24
<strong>Explanation:</strong> 
There are 8 rectangles of side 1x1.
There are 5 rectangles of side 1x2.
There are 2 rectangles of side 1x3. 
There are 4 rectangles of side 2x1.
There are 2 rectangles of side 2x2. 
There are 2 rectangles of side 3x1. 
There is 1 rectangle of side 3x2. 
Total number of rectangles = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= m, n &lt;= 150</code></li>
	<li><code>mat[i][j]</code> is either <code>0</code> or <code>1</code>.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int numSubmat(vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat.front().size();
    int answer = 0;
    vector<int> height(cols);
    for(int i = 0 ; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        height[j] = mat[i][j] ? height[j] + 1 : 0;
      }
      vector<int> sum(cols);
      vector<int> st;
      for(int j = 0; j < cols; ++j) {
        while(st.size() && height[st.back()] >= height[j]) st.pop_back();
        if(st.size()) {
          int p = st.back();
          sum[j] = sum[p] + height[j] * (j - p);
        } else {
          sum[j] = height[j] * (j + 1);
        }
        st.push_back(j);
        answer += sum[j];
      }
    }
    return answer;
  }
};

// Accepted
// 73/73 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 26.41 % of cpp submissions (19.8 MB)
```
