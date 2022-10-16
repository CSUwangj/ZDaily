+++
title = "2021-07-13 Daily-Challenge"
path = "2021-07-13-Daily-Challenge"
date = 2021-07-13 18:00:04+08:00
updated = 2021-07-13 18:11:57+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Diagonal Traverse](https://leetcode.com/problems/diagonal-traverse/description/) and leetcode's [July LeetCoding Challenge](https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/609/week-2-july-8th-july-14th/3812/) with `cpp`.

<!-- more -->

# Diagonal Traverse

## Description

Given an `m x n` matrix `mat`, return *an array of all the elements of the array in a diagonal order*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/04/10/diag1-grid.jpg)

```
Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]
```

**Example 2:**

```
Input: mat = [[1,2],[3,4]]
Output: [1,2,3,4]
```

 

**Constraints:**

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= mat[i][j] &lt;= 10<sup>5</sup></code></li>
</ul>

## Solution

``` cpp
class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat.front().size();
    int row = 0;
    int col = 0;
    int direction = 1;
    vector<int> answer;
    while(row < rows && col < cols) {
      // cout << row << ' ' <<col << " -> ";
      answer.push_back(mat[row][col]);
      row -= direction;
      col += direction;
      // cout << row << ' ' <<col << endl;
      direction = -direction;
      if(col == cols) {
        row += 2;
        col -= 1;
      } else if(row == rows) {
        col += 2;
        row -= 1;
      } else if(row < 0) {
        row = 0;
      } else if(col < 0) {
        col = 0;
      } else {
        direction = -direction;
      }
    }
    return answer;
  }
};
```

# July LeetCoding Challenge 13

## Description

**Find Peak Element**

A peak element is an element that is strictly greater than its neighbors.

Given an integer array `nums`, find a peak element, and return its index. If the array contains multiple peaks, return the index to **any of the peaks**.

You may imagine that `nums[-1] = nums[n] = -∞`.

You must write an algorithm that runs in `O(log n)` time.

 

**Example 1:**

```
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
```

**Example 2:**

```
Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
```

 

**Constraints:**

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>nums[i] != nums[i + 1]</code> for all valid <code>i</code>.</li>
</ul>



## Solution

``` cpp
class Solution {
public:
  int findPeakElement(vector<int>& nums) {
    int len = nums.size();
    if(len == 1) return 0;
    int start = 0;
    int end = len - 1;
    if(nums[start] > nums[start + 1]) return start;
    if(nums[end] > nums[end - 1]) return end;
    while(start < end) {
      int mid = (start + end) >> 1;
      // cout << start << ' ' << mid << ' ' << end << endl;
      if(nums[mid] > nums[mid + 1] && (!mid || nums[mid] > nums[mid - 1])) return mid;
      if(!mid || nums[mid] > nums[mid - 1]) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }
    return start;
  }
};
```
