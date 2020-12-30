+++
title = "2020-12-30 Daily-Challenge"
path = "2020-12-30-Daily-Challenge"
date = 2020-12-30 01:34:42+08:00
updated = 2020-12-30 23:12:42+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Sort Array By Parity II](https://leetcode.com/problems/sort-array-by-parity-ii/) on leetcode and leetcode's [December LeetCoding Challenge](https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/572/week-4-december-22nd-december-28th/3586/) with `cpp`.

<!-- more -->
# Sort Array By Parity II

## Description

Given an array `A` of non-negative integers, half of the integers in A are odd, and half of the integers are even.

Sort the array so that whenever `A[i]` is odd, `i` is odd; and whenever `A[i]` is even, `i` is even.

You may return any answer array that satisfies this condition.

**Example 1:**

```
Input: [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
```

**Note:**

1. `2 <= A.length <= 20000`
2. `A.length % 2 == 0`
3. `0 <= A[i] <= 1000`

## Solution

I decide not write `nothing to say` anymore.

``` cpp
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int len = A.size();
        int odd = 1, even = 0;
        while(odd < len && even < len) {
            while(odd < len && ((A[odd] & 1) == 1)) odd += 2;
            while(even < len && ((A[even] & 1) == 0)) even += 2;
            if(odd < len && even < len) swap(A[odd], A[even]);
            odd += 2;
            even += 2;
        }
        return move(A);
    }
};
```

# December LeetCoding Challenge30

**Game of Life**

## Description

According to [Wikipedia's article](https://en.wikipedia.org/wiki/Conway's_Game_of_Life): "The **Game of Life**, also known simply as **Life**, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an `m x n` grid of cells, where each cell has an initial state: **live** (represented by a `1`) or **dead** (represented by a `0`). Each cell interacts with its [eight neighbors](https://en.wikipedia.org/wiki/Moore_neighborhood) (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

1. Any live cell with fewer than two live neighbors dies as if caused by under-population.
2. Any live cell with two or three live neighbors lives on to the next generation.
3. Any live cell with more than three live neighbors dies, as if by over-population.
4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the `m x n` grid `board`, return *the next state*.

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/12/26/grid1.jpg)

```
Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/12/26/grid2.jpg)

```
Input: board = [[1,1],[1,0]]
Output: [[1,1],[1,1]]
```

**Constraints:**

- `m == board.length`
- `n == board[i].length`
- `1 <= m, n <= 25`
- `board[i][j]` is `0` or `1`.

**Follow up:**

- Could you solve it in-place? Remember that the board needs to be updated simultaneously: You cannot update some cells first and then use their updated values to update other cells.
- In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches upon the border of the array (i.e., live cells reach the border). How would you address these problems?

## Solution

`int` has 32 bits

``` cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        for(auto &v : board) {
            for(auto &i : v) {
                i <<= 1;
            }
        }
        int rows = board.size();
        int cols = board[0].size();
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                int cnt = 0;
                if(i) {
                    if(j) cnt += (board[i-1][j-1]&2);
                    cnt += (board[i-1][j]&2);
                    if(j < cols-1) cnt += (board[i-1][j+1]&2);
                }
                if(j) cnt += (board[i][j-1]&2);
                if(j < cols-1) cnt += board[i][j+1];
                if(i < rows-1) {
                    if(j) cnt += board[i+1][j-1];
                    cnt += board[i+1][j];
                    if(j < cols-1) cnt += board[i+1][j+1];
                }
                cnt >>= 1;
                if(board[i][j] & 2) {
                    if(cnt == 2 || cnt == 3) board[i][j] |= 1;
                } else {
                    if(cnt == 3) board[i][j] |= 1;
                }
            }
        }
        for(auto &v : board) {
            for(auto &i : v) {
                i &= 1;
            }
        }
    }
};
```