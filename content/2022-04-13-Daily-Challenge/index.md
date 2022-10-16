+++
updated = 2022-04-13 19:09:00+08:00
title = "2022-04-13 Daily-Challenge"
path = "2022-04-13-Daily-Challenge"
date = 2022-04-13 19:04:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/spiral-matrix-ii/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 13

## Description

**Spiral Matrix II**

<p>Given a positive integer <code>n</code>, generate an <code>n x n</code> <code>matrix</code> filled with elements from <code>1</code> to <code>n<sup>2</sup></code> in spiral order.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/spiraln.jpg" style="width: 242px; height: 242px;" />
<pre>
<strong>Input:</strong> n = 3
<strong>Output:</strong> [[1,2,3],[8,9,4],[7,6,5]]
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 1
<strong>Output:</strong> [[1]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 20</code></li>
</ul>

## Solution

``` cpp
class Solution {
  int move[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  int sat(vector<vector<int>> &result, int newH, int newW, int n) {
    return newH >= 0 && newW >= 0 && newH < n && newW < n && !result[newH][newW];
  }
public:
  vector<vector<int>> generateMatrix(int n) {
    auto result = vector<vector<int>>(n, vector<int>(n, 0));
    result[0][0] = 1;
    if(n == 1) return result;
    int h = 0;
    int w = 1;
    int direction = 0;
    while(true) {
      result[h][w] = result[h-move[direction][0]][w-move[direction][1]] + 1;
      int turn = 0;
      while(turn < 4 && !sat(result, h + move[direction][0], w + move[direction][1], n)) {
        direction = (direction + 1) % 4;
        turn += 1;
      }
      if(turn == 4) break;
      h += move[direction][0];
      w += move[direction][1];
    }
    return result;
  }
};

// Accepted
// 20/20 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 85.87 % of cpp submissions (6.5 MB)
```
