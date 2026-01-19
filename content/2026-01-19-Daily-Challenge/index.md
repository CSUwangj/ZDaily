+++
updated = 2026-01-19T15:00:39+01:00
title = "2026-01-19 Daily Challenge"
path = "2026-01-19-Daily-Challenge"
date = 2026-01-19T15:00:39+01:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 19

## Description

**Maximum Side Length of a Square with Sum Less than or Equal to Threshold**

<p>Given a <code>m x n</code> matrix <code>mat</code> and an integer <code>threshold</code>, return <em>the maximum side-length of a square with a sum less than or equal to </em><code>threshold</code><em> or return </em><code>0</code><em> if there is no such square</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/12/05/e1.png" style="width: 335px; height: 186px;" />
<pre>
<strong>Input:</strong> mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
<strong>Output:</strong> 2
<strong>Explanation:</strong> The maximum side length of square with sum less than 4 is 2 as shown.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]], threshold = 1
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 300</code></li>
	<li><code>0 &lt;= mat[i][j] &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= threshold &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
  const int MOD = 1e9 + 7;
  unordered_set<int> getLengths(vector<int> &fences, int border) {
    unordered_set<int> st;
    fences.push_back(1);
    fences.push_back(border);
    sort(fences.begin(), fences.end());
    int sz = fences.size();
    for(int i = 0; i < sz - 1; ++i) {
      for(int j = i + 1; j < sz; ++j) {
        st.insert(fences[j] - fences[i]);
      }
    }
    return st;
  }
public:
  int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
    auto hLengths = getLengths(hFences, m);
    auto vLengths = getLengths(vFences, n);
    int side = 0;
    for(auto hl : hLengths) {
      if(vLengths.count(hl)) side = max(side, hl);
    }
    if(side == 0) return -1;
    return 1LL * side * side % MOD;
  }
};

// Accepted
// 648/648 cases passed (1806 ms)
// Your runtime beats 22.88 % of cpp submissions
// Your memory usage beats 9.8 % of cpp submissions (445.9 MB)
```
