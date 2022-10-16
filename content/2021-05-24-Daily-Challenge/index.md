+++
title = "2021-05-24 Daily-Challenge"
path = "2021-05-24-Daily-Challenge"
date = 2021-05-24 18:33:11+08:00
updated = 2021-05-24 18:44:56+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Count Negative Numbers in a Sorted Matrix](https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/) and leetcode's [May LeetCoding Challenge](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/601/week-4-may-22nd-may-28th/3754/) with `cpp`.

<!-- more -->

# Count Negative Numbers in a Sorted Matrix

## Description

Given a `m x n` matrix `grid` which is sorted in non-increasing order both row-wise and column-wise, return *the number of **negative** numbers in* `grid`.

 

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

 

**Follow up:** Could you find an `O(n + m)` solution?

## Solution

``` cpp
class Solution {
public:
  int countNegatives(vector<vector<int>>& grid) {
    int answer = 0;
    for(auto &row : grid) {
      for(auto i : row) {
        answer += i < 0;
      }
    }
    return answer;
  }
};
```

because it's sorted, so we can solve it in $O(n+m)$ time

``` cpp
class Solution {
public:
  int countNegatives(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid.front().size();
    int row = rows;
    int col = 0;
    int answer = 0;
    while(row-- && col < cols) {
      while(col < cols && grid[row][col] >= 0) {
        col += 1;
      }
      answer += cols - col;
    }
    return answer;
  }
};
```

# May LeetCoding Challenge 24

## Description

**To Lower Case**

Given a string `s`, return *the string after replacing every uppercase letter with the same lowercase letter*.

 

**Example 1:**

```
Input: s = "Hello"
Output: "hello"
```

**Example 2:**

```
Input: s = "here"
Output: "here"
```

**Example 3:**

```
Input: s = "LOVELY"
Output: "lovely"
```

 

**Constraints:**

- `1 <= s.length <= 100`
- `s` consists of printable ASCII characters.

## Solution

``` cpp
class Solution {
public:
  string toLowerCase(string s) {
    for(auto &c : s) c = tolower(c);
    return s;
  }
};
```
