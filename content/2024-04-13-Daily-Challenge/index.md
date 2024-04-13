+++
updated = 2024-04-13T15:22:33+08:00
title = "2024-04-13 Daily Challenge"
path = "2024-04-13-Daily-Challenge"
date = 2024-04-13T15:22:33+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/maximal-rectangle/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 13

## Description

**Maximal Rectangle**

<p>Given a <code>rows x cols</code>&nbsp;binary <code>matrix</code> filled with <code>0</code>&#39;s and <code>1</code>&#39;s, find the largest rectangle containing only <code>1</code>&#39;s and return <em>its area</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/14/maximal.jpg" style="width: 402px; height: 322px;" />
<pre>
<strong>Input:</strong> matrix = [[&quot;1&quot;,&quot;0&quot;,&quot;1&quot;,&quot;0&quot;,&quot;0&quot;],[&quot;1&quot;,&quot;0&quot;,&quot;1&quot;,&quot;1&quot;,&quot;1&quot;],[&quot;1&quot;,&quot;1&quot;,&quot;1&quot;,&quot;1&quot;,&quot;1&quot;],[&quot;1&quot;,&quot;0&quot;,&quot;0&quot;,&quot;1&quot;,&quot;0&quot;]]
<strong>Output:</strong> 6
<strong>Explanation:</strong> The maximal rectangle is shown in the above picture.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> matrix = [[&quot;0&quot;]]
<strong>Output:</strong> 0
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> matrix = [[&quot;1&quot;]]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>rows == matrix.length</code></li>
	<li><code>cols == matrix[i].length</code></li>
	<li><code>1 &lt;= row, cols &lt;= 200</code></li>
	<li><code>matrix[i][j]</code> is <code>&#39;0&#39;</code> or <code>&#39;1&#39;</code>.</li>
</ul>


## Solution

``` cpp
class Solution {
  int largestRectangleArea(vector<int>& heights, vector<int> &st) {
    heights.push_back(0);
    int len = heights.size();
    int answer = 0;
    for(int i = 0; i < len; ++i) {
      while(st.back() != -1 && heights[i] < heights[st.back()]) {
        int index = st.back();
        st.pop_back();
        int h = heights[index];
        int w = i - st.back() - 1;
        answer = max(answer, h*w);
      }
      st.push_back(i);
    }
    while(st.size() != 1) st.pop_back();
    return answer;
  }
public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    vector<int> st{-1};
    int row = matrix.size();
    if(!row) return 0;
    int col = matrix.front().size();
    vector<int> dp(col);
    int answer = 0;
    for(int i = 0; i < row; ++i) {
      for(int j = 0; j < col; ++j) {
        if(matrix[i][j] == '1') {
          dp[j] = dp[j] + 1;
        } else {
          dp[j] = 0;
        }
      }
      answer = max(answer, largestRectangleArea(dp, st));
    }
    return answer;
  }
};

// Accepted
// 71/71 cases passed (24 ms)
// Your runtime beats 95.14 % of cpp submissions
// Your memory usage beats 90.31 % of cpp submissions (11 MB)
```
