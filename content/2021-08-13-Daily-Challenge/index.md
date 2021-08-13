+++
title = "2021-08-13 Daily-Challenge"
path = "2021-08-13-Daily-Challenge"
date = 2021-08-13 19:20:03+08:00
updated = 2021-08-13 19:51:59+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Remove Boxes](https://leetcode.com/problems/remove-boxes/description/) and leetcode's [August LeetCoding Challenge](https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/614/week-2-august-8th-august-14th/3888/) with `cpp`.

<!-- more -->

# Remove Boxes

## Description

You are given several `boxes` with different colors represented by different positive numbers.

You may experience several rounds to remove boxes until there is no box left. Each time you can choose some continuous boxes with the same color (i.e., composed of `k` boxes, `k >= 1`), remove them and get `k * k` points.

Return *the maximum points you can get*.

 

**Example 1:**

```
Input: boxes = [1,3,2,2,2,3,4,3,1]
Output: 23
Explanation:
[1, 3, 2, 2, 2, 3, 4, 3, 1] 
----> [1, 3, 3, 4, 3, 1] (3*3=9 points) 
----> [1, 3, 3, 3, 1] (1*1=1 points) 
----> [1, 1] (3*3=9 points) 
----> [] (2*2=4 points)
```

**Example 2:**

```
Input: boxes = [1,1,1]
Output: 9
```

**Example 3:**

```
Input: boxes = [1]
Output: 1
```

 

**Constraints:**

- `1 <= boxes.length <= 100`
- `1 <= boxes[i] <= 100`

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
int dp[101][101][101];
class Solution {
  int solve(vector<int> &boxes, int begin, int end, int cnt) {
    if(begin >= end) return 0;
    if(dp[begin][end][cnt]) return dp[begin][end][cnt];
    int result = (cnt + 1) * (cnt + 1) + solve(boxes, begin + 1, end, 0);
    for(int i = begin + 1; i < end; ++i) {
      if(boxes[i] == boxes[begin]) result = max(result, solve(boxes, begin + 1, i, 0) + solve(boxes, i, end, cnt + 1));
    }
    dp[begin][end][cnt] = result;
    return dp[begin][end][cnt];
  }
public:
  int removeBoxes(vector<int>& boxes) {
    int len = boxes.size();
    memset(dp, 0, sizeof(dp[0]) * len);
    return solve(boxes, 0, len, 0);
  }
};

// Accepted
// 62/62 cases passed (254 ms)
// Your runtime beats 36.25 % of cpp submissions
// Your memory usage beats 93.28 % of cpp submissions (11.6 MB)
```

# August LeetCoding Challenge 13

## Description

**Set Matrix Zeroes**

Given an `m x n` integer matrix `matrix`, if an element is `0`, set its entire row and column to `0`'s, and return *the matrix*.

You must do it [in place](https://en.wikipedia.org/wiki/In-place_algorithm).

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/08/17/mat1.jpg)

```
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/08/17/mat2.jpg)

```
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
```

 

**Constraints:**

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[0].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>-2<sup>31</sup> &lt;= matrix[i][j] &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

 

**Follow up:**

<ul>
	<li>A straightforward solution using <code>O(mn)</code> space is probably a bad idea.</li>
	<li>A simple improvement uses <code>O(m + n)</code> space, but still not the best solution.</li>
	<li>Could you devise a constant space solution?</li>
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
  void setZeroes(vector<vector<int>>& matrix) {
    bool firstRow = false;
    bool firstCol = false;
    int rows = matrix.size();
    int cols = matrix.front().size();
    for(int i = 0; i < rows; ++i) {
      if(!matrix[i][0]) firstCol = true;
    }
    for(int i = 0; i < cols; ++i) {
      if(!matrix[0][i]) firstRow = true;
    }
    for(int i = 1; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        if(!matrix[i][j]) {
          matrix[0][j] = 0;
          matrix[i][0] = 0;
        }
      }
    }
    for(int i = 1; i < rows; ++i) {
      if(!matrix[i][0]) {
        for(int j = 1; j < cols; ++j) {
          matrix[i][j] = 0;
        }
      }
    }
    for(int i = 1; i < cols; ++i) {
      if(!matrix[0][i]) {
        for(int j = 1; j < rows; ++j) {
          matrix[j][i] = 0;
        }
      }
    }
    if(firstCol) {
      for(int j = 0; j < rows; ++j) {
        matrix[j][0] = 0;
      }
    }
    if(firstRow) {
      for(int j = 0; j < cols; ++j) {
        matrix[0][j] = 0;
      }
    }
  }
};

// Accepted
// 164/164 cases passed (11 ms)
// Your runtime beats 82.11 % of cpp submissions
// Your memory usage beats 95.73 % of cpp submissions (13.1 MB)
```
