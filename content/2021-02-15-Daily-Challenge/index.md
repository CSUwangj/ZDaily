+++
title = "2021-02-15 Daily-Challenge"
path = "2021-02-15-Daily-Challenge"
date = 2021-02-15 17:30:09+08:00
updated = 2021-02-15 17:52:03+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/586/week-3-february-15th-february-21st/3641/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge15

## Description

**The K Weakest Rows in a Matrix**

## Description

Given a `m * n` matrix `mat` of *ones* (representing soldiers) and *zeros* (representing civilians), return the indexes of the `k` weakest rows in the matrix ordered from the weakest to the strongest.

A row ***i*** is weaker than row ***j***, if the number of soldiers in row ***i*** is less than the number of soldiers in row ***j***, or they have the same number of soldiers but ***i*** is less than ***j***. Soldiers are **always** stand in the frontier of a row, that is, always *ones* may appear first and then *zeros*.

 

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
The number of soldiers for each row is: 
row 0 -> 2 
row 1 -> 4 
row 2 -> 1 
row 3 -> 2 
row 4 -> 5 
Rows ordered from the weakest to the strongest are [2,0,3,1,4]
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
The number of soldiers for each row is: 
row 0 -> 1 
row 1 -> 4 
row 2 -> 1 
row 3 -> 1 
Rows ordered from the weakest to the strongest are [0,2,3,1]
```

 

**Constraints:**

- `m == mat.length`
- `n == mat[i].length`
- `2 <= n, m <= 100`
- `1 <= k <= m`
- `matrix[i][j]` is either 0 **or** 1.

## Solution

``` cpp
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int rows = mat.size();
        int cols = mat.front().size();
        vector<int> rowCount(rows);
        for(int i = 0; i < rows; ++i) {
            int cnt = 0;
            for(auto i : mat[i]) cnt += i;
            rowCount[i] = cnt;
        }
        vector<int> answer(rows);
        for(int i = 0; i < rows; ++i) answer[i] = i;
        
        stable_sort(answer.begin(), answer.end(), [&](int a, int b){
            return rowCount[a] < rowCount[b];
        });
        answer.resize(k);
        return move(answer);
    }
};
```