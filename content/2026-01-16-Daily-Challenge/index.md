+++
updated = 2026-01-16T22:46:24+01:00
title = "2026-01-16 Daily Challenge"
path = "2026-01-16-Daily-Challenge"
date = 2026-01-16T22:46:24+01:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 16

## Description

**Maximum Square Area by Removing Fences From a Field**

<p>There is a large <code>(m - 1) x (n - 1)</code> rectangular field with corners at <code>(1, 1)</code> and <code>(m, n)</code> containing some horizontal and vertical fences given in arrays <code>hFences</code> and <code>vFences</code> respectively.</p>

<p>Horizontal fences are from the coordinates <code>(hFences[i], 1)</code> to <code>(hFences[i], n)</code> and vertical fences are from the coordinates <code>(1, vFences[i])</code> to <code>(m, vFences[i])</code>.</p>

<p>Return <em>the <strong>maximum</strong> area of a <strong>square</strong> field that can be formed by <strong>removing</strong> some fences (<strong>possibly none</strong>) or </em><code>-1</code> <em>if it is impossible to make a square field</em>.</p>

<p>Since the answer may be large, return it <strong>modulo</strong> <code>10<sup>9 </sup>+ 7</code>.</p>

<p><strong>Note: </strong>The field is surrounded by two horizontal fences from the coordinates <code>(1, 1)</code> to <code>(1, n)</code> and <code>(m, 1)</code> to <code>(m, n)</code> and two vertical fences from the coordinates <code>(1, 1)</code> to <code>(m, 1)</code> and <code>(1, n)</code> to <code>(m, n)</code>. These fences <strong>cannot</strong> be removed.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2023/11/05/screenshot-from-2023-11-05-22-40-25.png" /></p>

<pre>
<strong>Input:</strong> m = 4, n = 3, hFences = [2,3], vFences = [2]
<strong>Output:</strong> 4
<strong>Explanation:</strong> Removing the horizontal fence at 2 and the vertical fence at 2 will give a square field of area 4.
</pre>

<p><strong class="example">Example 2:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2023/11/22/maxsquareareaexample1.png" style="width: 285px; height: 242px;" /></p>

<pre>
<strong>Input:</strong> m = 6, n = 7, hFences = [2], vFences = [4]
<strong>Output:</strong> -1
<strong>Explanation:</strong> It can be proved that there is no way to create a square field by removing fences.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= m, n &lt;= 10<sup>9</sup></code></li>
	<li><code><font face="monospace">1 &lt;= hF</font>ences<font face="monospace">.length, vFences.length &lt;= 600</font></code></li>
	<li><code><font face="monospace">1 &lt; hFences[i] &lt; m</font></code></li>
	<li><code><font face="monospace">1 &lt; vFences[i] &lt; n</font></code></li>
	<li><code><font face="monospace">hFences</font></code><font face="monospace"> and </font><code><font face="monospace">vFences</font></code><font face="monospace"> are unique.</font></li>
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
