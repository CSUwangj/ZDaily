+++
updated = 2022-03-20 18:38:00+08:00
title = "2022-03-20 Daily-Challenge"
path = "2022-03-20-Daily-Challenge"
date = 2022-03-20 18:13:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 20

## Description

**Minimum Domino Rotations For Equal Row**

<p>In a row of dominoes, <code>tops[i]</code> and <code>bottoms[i]</code> represent the top and bottom halves of the <code>i<sup>th</sup></code> domino. (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)</p>

<p>We may rotate the <code>i<sup>th</sup></code> domino, so that <code>tops[i]</code> and <code>bottoms[i]</code> swap values.</p>

<p>Return the minimum number of rotations so that all the values in <code>tops</code> are the same, or all the values in <code>bottoms</code> are the same.</p>

<p>If it cannot be done, return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/14/domino.png" style="height: 300px; width: 421px;" />
<pre>
<strong>Input:</strong> tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
The first figure represents the dominoes as given by tops and bottoms: before we do any rotations.
If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong> tops = [3,5,1,2,3], bottoms = [3,6,3,3,4]
<strong>Output:</strong> -1
<strong>Explanation:</strong> 
In this case, it is not possible to rotate the dominoes to make one row of values equal.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= tops.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>bottoms.length == tops.length</code></li>
	<li><code>1 &lt;= tops[i], bottoms[i] &lt;= 6</code></li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int minDominoRotations(vector<int>& A, vector<int>& B) {
    vector<int> AA(6), BB(6), same(6);
    int len = A.size();
    for(int i = 0; i < len; ++i) {
      AA[A[i] - 1] += 1;
      BB[B[i] - 1] += 1;
      if(A[i] == B[i]) same[A[i] - 1] += 1;
    }
    for(int i = 0; i < 6; ++i) {
      if(AA[i] + BB[i] - same[i] >= len) {
        return len - max(AA[i], BB[i]);
      }
    }
    return -1;
  }
};

// Accepted
// 83/83 cases passed (84 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 10.64 % of cpp submissions (111.7 MB)
```
