+++
title = "2021-04-25 Daily-Challenge"
path = "2021-04-25-Daily-Challenge"
date = 2021-04-25 15:00:05+08:00
updated = 2021-04-25 15:07:10+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I gonna review the tasks I've done this week, and finish today's leetcode's [April LeetCoding Challenge](https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/596/week-4-april-22nd-april-28th/3720/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 25

## Description

**Rotate Image**

You are given an *n* x *n* 2D `matrix` representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image [**in-place**](https://en.wikipedia.org/wiki/In-place_algorithm), which means you have to modify the input 2D matrix directly. **DO NOT** allocate another 2D matrix and do the rotation.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/08/28/mat1.jpg)

```
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/08/28/mat2.jpg)

```
Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
```

**Example 3:**

```
Input: matrix = [[1]]
Output: [[1]]
```

**Example 4:**

```
Input: matrix = [[1,2],[3,4]]
Output: [[3,1],[4,2]]
```

 

**Constraints:**

- `matrix.length == n`
- `matrix[i].length == n`
- `1 <= n <= 20`
- `-1000 <= matrix[i][j] <= 1000`

## Solution

done at spring festival

``` cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int low = n / 2;
        int high = n - low;
        for(int j = 0; j < high; ++j) {
            for(int i = 0; i+j < n-1-j; ++i) {
                swap(matrix[j][j+i], matrix[j+i][n-1-j]);
                swap(matrix[j][j+i], matrix[n-1-i-j][j]);
                swap(matrix[n-1-j][n-1-i-j], matrix[n-1-i-j][j]);
            }
        }
    }
};

// [0, 0], [0, n-1], [n-1, n-1], [n-1, 0] -> [n-1, 0], [0, 0], [0, n-1], [n-1, n-1]
// [0, 1], [1, n-1], [n-1, n-2], [n-2, 0] -> [n-2, 0], [0, 1], [1, n-1], [n-1, n-2]
// ...
// [0, i], [i, n-1], [n-1, n-1-i], [n-1-i, 0] -> ...
// ...
// [0, n-2], [n-2, n-1], [n-1, 1], [1, 0] -> ...

// [1, 1], [1, n-2], [n-2, n-2], [n-2, 1] -> ...
// [1, 2], [2, n-2], [n-2, n-3], [n-3, 1] -> ...
// ...
// [1, 1+i], [1+i, n-2], [n-2, n-2-i], [n-2-i, 1] -> ...

// [j, j+i], [j+i, n-1-j], [n-1-j, n-1-i-j], [n-1-i-j, j] -> ...
```
