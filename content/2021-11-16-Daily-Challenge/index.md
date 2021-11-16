+++
title = "2021-11-15 Daily-Challenge"
path = "2021-11-15-Daily-Challenge"
date = 2021-11-16 20:17:53+08:00
updated = 2021-11-16 20:39:23+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 16

## Description

**Kth Smallest Number in Multiplication Table**

Nearly everyone has used the [Multiplication Table](https://en.wikipedia.org/wiki/Multiplication_table). The multiplication table of size `m x n` is an integer matrix `mat` where `mat[i][j] == i * j` (**1-indexed**).

Given three integers `m`, `n`, and `k`, return *the* `kth` *smallest element in the* `m x n` *multiplication table*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/05/02/multtable1-grid.jpg)

```
Input: m = 3, n = 3, k = 5
Output: 3
Explanation: The 5th smallest number is 3.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/05/02/multtable2-grid.jpg)

```
Input: m = 2, n = 3, k = 6
Output: 6
Explanation: The 6th smallest number is 6.
```

 

**Constraints:**

- `1 <= m, n <= 3 * 10^4`
- `1 <= k <= m * n`

## Solution

``` cpp
class Solution {
  int count(int rows, int col, int num) {
    int row = 1;
    int cnt = 0;
    while(row <= rows && col) {
      if(row * col <= num) {
        cnt += col;
        row += 1;
      } else {
        col -= 1;
      }
    }
    return cnt;
  }
public:
  int findKthNumber(int m, int n, int k) {
    int low = 1;
    int high = m * n;
    if(k == 1) return low;
    if(k == n * m) return high;
    while(low < high) {
      int mid = (low + high) >> 1;
      if(count(m, n, mid) < k) {
        low = mid + 1;
      }else{
        high = mid;
      }
    }
    return low;
  }
};

// Accepted
// 70/70 cases passed (12 ms)
// Your runtime beats 95.06 % of cpp submissions
// Your memory usage beats 68.64 % of cpp submissions (5.9 MB)
```
