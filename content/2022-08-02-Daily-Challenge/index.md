+++
updated = 2022-08-02 18:14:00+08:00
title = "2022-08-02 Daily-Challenge"
path = "2022-08-02-Daily-Challenge"
date = 2022-08-02 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 2

## Description

**Kth Smallest Element in a Sorted Matrix**

Given an `n x n` `matrix` where each of the rows and columns is sorted in ascending order, return *the* `kth` *smallest element in the matrix*.

Note that it is the `kth` smallest element **in the sorted order**, not the `kth` **distinct** element.

You must find a solution with a memory complexity better than `O(n2)`.

 

**Example 1:**

```
Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
```

**Example 2:**

```
Input: matrix = [[-5]], k = 1
Output: -5
```

 

**Constraints:**

- `n == matrix.length == matrix[i].length`
- `1 <= n <= 300`
- `-10^9 <= matrix[i][j] <= 10^9`
- All the rows and columns of `matrix` are **guaranteed** to be sorted in **non-decreasing order**.
- `1 <= k <= n^2`

 

**Follow up:**

- Could you solve the problem with a constant memory (i.e., `O(1)` memory complexity)?
- Could you solve the problem in `O(n)` time complexity? The solution may be too advanced for an interview but you may find reading [this paper](http://www.cse.yorku.ca/~andy/pubs/X+Y.pdf) fun.

## Solution

``` cpp
class Solution {
public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    if(k == 1) return matrix.front().front();
    if(k == n * n) return matrix.back().back();
    priority_queue<int> pq;
    for(auto &row : matrix) {
      for(auto i : row) {
        pq.push(i);
        while(pq.size() > k) pq.pop();
      }
    }
    return pq.top();
  }
};

// Accepted
// 85/85 cases passed (36 ms)
// Your runtime beats 54.31 % of cpp submissions
// Your memory usage beats 33.33 % of cpp submissions (14.3 MB)
```
