+++
updated = 2022-07-19 18:14:00+08:00
title = "2022-07-19 Daily-Challenge"
path = "2022-07-19-Daily-Challenge"
date = 2022-07-19 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/pascals-triangle/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 19

## Description

**Pascal's Triangle**

Given an integer `numRows`, return the first numRows of **Pascal's triangle**.

In **Pascal's triangle**, each number is the sum of the two numbers directly above it as shown:

![img](https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif)

 

**Example 1:**

```
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
```

**Example 2:**

```
Input: numRows = 1
Output: [[1]]
```

 

**Constraints:**

- `1 <= numRows <= 30`

## Solution

``` cpp
class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> answer(numRows);
    answer[0] = {1};
    for(int i = 1; i < numRows; ++i) {
      for(int j = 0; j <= i; ++j) {
        if(!j || j == i) {
          answer[i].push_back(1);
        } else {
          answer[i].push_back(answer[i - 1][j - 1] + answer[i - 1][j]);
        }
      }
    }
    return answer;
  }
};

// Accepted
// 14/14 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 33.54 % of cpp submissions (6.6 MB)
```
