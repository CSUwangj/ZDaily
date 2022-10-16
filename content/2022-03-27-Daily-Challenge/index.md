+++
updated = 2022-03-27 15:39:00+08:00
title = "2022-03-27 Daily-Challenge"
path = "2022-03-27-Daily-Challenge"
date = 2022-03-27 15:35:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 27

## Description

**The K Weakest Rows in a Matrix**

You are given an `m x n` binary matrix `mat` of `1`'s (representing soldiers) and `0`'s (representing civilians). The soldiers are positioned **in front** of the civilians. That is, all the `1`'s will appear to the **left** of all the `0`'s in each row.

A row `i` is **weaker** than a row `j` if one of the following is true:

- The number of soldiers in row `i` is less than the number of soldiers in row `j`.
- Both rows have the same number of soldiers and `i < j`.

Return *the indices of the* `k` ***weakest** rows in the matrix ordered from weakest to strongest*.

 

**Example 1:**

```
Input: mat = 
[[1,1,0,0,0],
 [1,1,1,1,0],
 [1,0,0,0,0],
 [1,1,0,0,0],
 [1,1,1,1,1]], 
k = 3
Output: [2,0,3]
Explanation: 
The number of soldiers in each row is: 
- Row 0: 2 
- Row 1: 4 
- Row 2: 1 
- Row 3: 2 
- Row 4: 5 
The rows ordered from weakest to strongest are [2,0,3,1,4].
```

**Example 2:**

```
Input: mat = 
[[1,0,0,0],
 [1,1,1,1],
 [1,0,0,0],
 [1,0,0,0]], 
k = 2
Output: [0,2]
Explanation: 
The number of soldiers in each row is: 
- Row 0: 1 
- Row 1: 4 
- Row 2: 1 
- Row 3: 1 
The rows ordered from weakest to strongest are [0,2,3,1].
```

 

**Constraints:**

- `m == mat.length`
- `n == mat[i].length`
- `2 <= n, m <= 100`
- `1 <= k <= m`
- `matrix[i][j]` is either 0 or 1.

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
  vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    int rows = mat.size();
    int cols = mat.front().size();
    vector<int> rowCount(rows);
    for(int i = 0; i < rows; ++i) {
      int low = 0, high = cols - 1;
      while(low < high) {
        int mid = (low + high) >> 1;
        if(mat[i][mid]) {
          low = mid + 1;
        } else {
          high = mid;
        }
      }
      rowCount[i] = mat[i][low] ? low + 1 : low;
    }
    vector<int> answer(rows);
    for(int i = 0; i < rows; ++i) {
      answer[i] = i;
    }
    sort(answer.begin(), answer.end(), [&](int a, int b) {
      return rowCount[a] < rowCount[b] || (rowCount[a] == rowCount[b] && a < b);
    });
    answer.resize(k);
    return move(answer);
  }
};

// Accepted
// 52/52 cases passed (18 ms)
// Your runtime beats 46.89 % of cpp submissions
// Your memory usage beats 19.79 % of cpp submissions (10.7 MB)
```
