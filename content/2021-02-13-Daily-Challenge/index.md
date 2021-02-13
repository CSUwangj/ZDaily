+++
title = "2021-02-13 Daily-Challenge"
path = "2021-02-13-Daily-Challenge"
date = 2021-02-13 22:20:59+08:00
updated = 2021-02-13 23:29:14+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Find K Pairs with Smallest Sums](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/) and leetcode's [February LeetCoding Challenge](https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/585/week-2-february-8th-february-14th/3638/) with `cpp`.

Ops, today is Saturday, I need to review the challenge.

<!-- more -->

# LeetCode Review

## Merge In Between Linked Lists

too easy to review

## Random Point in Non-overlapping Rectangles

too easy to review

## Rotate Image

already done a good work

## Find and Replace Pattern

already done a good work

## Peeking Iterator

with cache

``` cpp
class PeekingIterator : public Iterator {
    int num;
    bool has;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        has = Iterator::hasNext();
        if(has) num = Iterator::next();
    }
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return num;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        int cur = num;
        has = Iterator::hasNext();
        if(has) num = Iterator::next();
        return cur;
	}
	
    bool hasNext() const {
        return has;
    }
};
```

# Find K Pairs with Smallest Sums

## Description

You are given two integer arrays **nums1** and **nums2** sorted in ascending order and an integer **k**.

Define a pair **(u,v)** which consists of one element from the first array and one element from the second array.

Find the k pairs **(u1,v1),(u2,v2) ...(uk,vk)** with the smallest sums.

**Example 1:**

```
Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]] 
Explanation: The first 3 pairs are returned from the sequence: 
             [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
```

**Example 2:**

```
Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [1,1],[1,1]
Explanation: The first 2 pairs are returned from the sequence: 
             [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
```

**Example 3:**

```
Input: nums1 = [1,2], nums2 = [3], k = 3
Output: [1,3],[2,3]
Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]
```

## Solution

brute force solution

``` cpp
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> answer;
        for(auto i : nums1) {
            for(auto j : nums2) answer.push_back(vector<int>{i, j});
        }
        sort(answer.begin(), answer.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] + a[1] < b[1] + b[0];
        });
        int sz = answer.size();
        answer.resize(min(k, sz));
        return move(answer);
    }
};
```

# February LeetCoding Challenge13

**Shortest Path in Binary Matrix**

## Description

In an N by N square grid, each cell is either empty (0) or blocked (1).

A *clear path from top-left to bottom-right* has length `k` if and only if it is composed of cells `C_1, C_2, ..., C_k` such that:

- Adjacent cells `C_i` and `C_{i+1}` are connected 8-directionally (ie., they are different and share an edge or corner)
- `C_1` is at location `(0, 0)` (ie. has value `grid[0][0]`)
- `C_k` is at location `(N-1, N-1)` (ie. has value `grid[N-1][N-1]`)
- If `C_i` is located at `(r, c)`, then `grid[r][c]` is empty (ie. `grid[r][c] == 0`).

Return the length of the shortest such clear path from top-left to bottom-right. If such a path does not exist, return -1.

 

**Example 1:**

```
Input: [[0,1],[1,0]]


Output: 2
```

**Example 2:**

```
Input: [[0,0,0],[1,1,0],[1,1,0]]


Output: 4
```

 

**Note:**

1. `1 <= grid.length == grid[0].length <= 100`
2. `grid[r][c]` is `0` or `1`

## Solution

``` cpp
class Solution {
    int move[8][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid.front().front() || grid.back().back()) return -1;
        int n = grid.size();
        vector<vector<int>> dis(n, vector<int>(n));
        dis[0][0] = 1;
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        while(!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            for(int i = 0; i < 8; ++i) {
                int newRow = row + move[i][0];
                int newCol = col + move[i][1];
                if(newRow < 0 || newRow >= n || newCol < 0 || newCol >= n || grid[newRow][newCol]) continue;
                if(dis[newRow][newCol]) continue;
                dis[newRow][newCol] = dis[row][col] + 1;
                q.push(make_pair(newRow, newCol));
            }
        }
        return dis.back().back() ? dis.back().back() : -1;
    }
};
```
