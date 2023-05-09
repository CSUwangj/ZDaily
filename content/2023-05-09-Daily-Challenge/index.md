+++
updated = 2023-05-09T18:30:34+08:00
title = "2023-05-09 Daily Challenge"
path = "2023-05-09-Daily-Challenge"
date = 2023-05-09T18:30:34+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/spiral-matrix/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 9

## Description

**Spiral Matrix**

<p>Given an <code>m x n</code> <code>matrix</code>, return <em>all elements of the</em> <code>matrix</code> <em>in spiral order</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/spiral1.jpg" style="width: 242px; height: 242px;" />
<pre>
<strong>Input:</strong> matrix = [[1,2,3],[4,5,6],[7,8,9]]
<strong>Output:</strong> [1,2,3,6,9,8,7,4,5]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/spiral.jpg" style="width: 322px; height: 242px;" />
<pre>
<strong>Input:</strong> matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
<strong>Output:</strong> [1,2,3,4,8,12,11,10,9,5,6,7]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10</code></li>
	<li><code>-100 &lt;= matrix[i][j] &lt;= 100</code></li>
</ul>


## Solution

``` cpp
class Solution {
  int moves[4];
  vector<bool> visit;
  int cols;
  int total;
  
  void init() {
    moves[0] = 1;
    moves[1] = cols;
    moves[2] = -1;
    moves[3] = -cols;
  }
  
  bool check(int pos, int direction) {
    return (direction == 0 && !((pos+1) % cols)) || \
            (pos + moves[direction] >= total)    || \
            (direction == 2 && !(pos % cols))    || \
            (pos + moves[direction] < 0)         || \
            visit[pos+moves[direction]]; 
  }
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    cols = matrix.front().size();
    total = cols * matrix.size();
    init();
    visit.resize(total);
    vector<int> answer;
    int direction = 0, pos = 0;
    while(answer.size() < total) {
      answer.push_back(matrix[pos/cols][pos%cols]);
      visit[pos] = true;
      int turns = 0;
      while(turns < 4 && check(pos, direction)) {
          turns += 1;
          direction = (direction + 1) % 4;
      }
      pos += moves[direction];
    }
    return move(answer);
  }
};

// Accepted
// 23/23 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 72.32 % of cpp submissions (6.8 MB)
```
