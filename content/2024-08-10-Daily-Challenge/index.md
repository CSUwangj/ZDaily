+++
updated = 2024-08-10T17:13:10+08:00
title = "2024-08-10 Daily Challenge"
path = "2024-08-10-Daily-Challenge"
date = 2024-08-10T17:13:10+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/regions-cut-by-slashes/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 10

## Description

**Regions Cut By Slashes**

<p>An <code>n x n</code> grid is composed of <code>1 x 1</code> squares where each <code>1 x 1</code> square consists of a <code>&#39;/&#39;</code>, <code>&#39;\&#39;</code>, or blank space <code>&#39; &#39;</code>. These characters divide the square into contiguous regions.</p>

<p>Given the grid <code>grid</code> represented as a string array, return <em>the number of regions</em>.</p>

<p>Note that backslash characters are escaped, so a <code>&#39;\&#39;</code> is represented as <code>&#39;\\&#39;</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/15/1.png" style="width: 200px; height: 200px;" />
<pre>
<strong>Input:</strong> grid = [&quot; /&quot;,&quot;/ &quot;]
<strong>Output:</strong> 2
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/15/2.png" style="width: 200px; height: 198px;" />
<pre>
<strong>Input:</strong> grid = [&quot; /&quot;,&quot;  &quot;]
<strong>Output:</strong> 1
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/15/4.png" style="width: 200px; height: 200px;" />
<pre>
<strong>Input:</strong> grid = [&quot;/\\&quot;,&quot;\\/&quot;]
<strong>Output:</strong> 5
<strong>Explanation: </strong>Recall that because \ characters are escaped, &quot;\\/&quot; refers to \/, and &quot;/\\&quot; refers to /\.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == grid.length == grid[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 30</code></li>
	<li><code>grid[i][j]</code> is either <code>&#39;/&#39;</code>, <code>&#39;\&#39;</code>, or <code>&#39; &#39;</code>.</li>
</ul>


## Solution

``` cpp
struct UnionSet {
  vector<int> parent;
public:
  int count;
  UnionSet(int size): parent(size), count(0) {
    iota(parent.begin(), parent.end(), 0);
  }

  int find(int x) {
    if(parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
  }

  void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) count += 1;
    parent[x] = y;
  }

  void resetCount() {
    count = 0;
  }
};
class Solution {
public:
  int regionsBySlashes(vector<string>& grid) {
    int n = grid.size();
    int dots = n + 1;
    UnionSet us(dots * dots);

    for(int i = 0; i < dots; ++i) {
      us.merge(0, i);
      us.merge(0, i * dots);
      us.merge(0, i * dots + dots - 1);
      us.merge(0, (dots * dots) - dots + i);
    }
    us.resetCount();

    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        if(grid[i][j] == '\\') {
          us.merge(i * dots + j, (i + 1) * dots + j + 1);
        } else if (grid[i][j] == '/') {
          us.merge((i + 1) * dots + j, i * dots + j + 1);
        }
      }
    }
    return us.count + 1;
  }
};
```
