+++
title = "2020-10-15 Daily-Challenge"
path = "2020-10-15-Daily-Challenge"
date = 2020-10-15 00:29:31+08:00
updated = 2020-10-15 20:30:42+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done *Count Negative Numbers in a Sorted Matrix* on [leetcode](https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/) and leetcode's [October LeetCoding Challenge](https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/560/week-2-october-8th-october-14th/3496/) with `cpp`.

<!-- more -->

# Count Negative Numbers in a Sorted Matrix

## Description

Given a `m * n` matrix `grid` which is sorted in non-increasing order both row-wise and column-wise. 

Return the number of **negative** numbers in `grid`.

**Example 1:**

```
Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.
```

**Example 2:**

```
Input: grid = [[3,2],[1,0]]
Output: 0
```

**Example 3:**

```
Input: grid = [[1,-1],[-1,-1]]
Output: 3
```

**Example 4:**

```
Input: grid = [[-1]]
Output: 1
```

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 100`
- `-100 <= grid[i][j] <= 100`

## Solution

nothing to say

``` cpp
class Solution {
 public:
  int countNegatives(vector<vector<int>>& grid) {
    int l = grid.size(), ll = grid[0].size(), cnt = 0;
    for (int i = 0; i < l; ++i) {
      for (int j = 0; j < ll; ++j) {
        cnt += grid[i][j] < 0;
      }
    }
    return cnt;
  }
};
```

# October LeetCoding Challenge15

## Description

**Rotate Array**

Given an array, rotate the array to the right by *k* steps, where *k* is non-negative.

**Follow up:**

- Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
- Could you do it in-place with O(1) extra space?

**Example 1:**

```
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
```

**Example 2:**

```
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
```

**Constraints:**

- `1 <= nums.length <= 2 * 104`
- `-231 <= nums[i] <= 231 - 1`
- `0 <= k <= 105`

## Solution

nothing to say

``` cpp
class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    vector<int> ans;
    int offset = (nums.size() - (k % nums.size())) % nums.size();
    auto it = nums.begin();
    advance(it, offset);
    for (auto i = it; i < nums.end(); ++i) {
      ans.push_back(*i);
    }
    for (auto i = nums.begin(); i < it; ++i) {
      ans.push_back(*i);
    }
    nums = ans;
  }
};
```