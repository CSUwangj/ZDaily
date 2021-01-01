+++
title = "2021-01-01 Daily-Challenge"
path = "2021-01-01-Daily-Challenge"
date = 2021-01-01 02:33:19+08:00
updated = 2021-01-01 16:34:49+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

HAPPY NEW YEAR!

Today I have done [Construct Quad Tree](https://leetcode.com/problems/construct-quad-tree/) on leetcode and leetcode's [January LeetCoding Challenge](https://leetcode.com/explore/featured/card/january-leetcoding-challenge-2021/579/week-1-january-1st-january-7th/3589/) with `cpp`.

<!-- more -->

# Construct Quad Tree

## Description

Given a `n * n` matrix `grid` of `0's` and `1's` only. We want to represent the `grid` with a Quad-Tree.

Return *the root of the Quad-Tree* representing the `grid`.

Notice that you can assign the value of a node to **True** or **False** when `isLeaf` is **False**, and both are **accepted** in the answer.

A Quad-Tree is a tree data structure in which each internal node has exactly four children. Besides, each node has two attributes:

- `val`: True if the node represents a grid of 1's or False if the node represents a grid of 0's. 
- `isLeaf`: True if the node is leaf node on the tree or False if the node has the four children.

```
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;
}
```

We can construct a Quad-Tree from a two-dimensional area using the following steps:

1. If the current grid has the same value (i.e all `1's` or all `0's`) set `isLeaf` True and set `val` to the value of the grid and set the four children to Null and stop.
2. If the current grid has different values, set `isLeaf` to False and set `val` to any value and divide the current grid into four sub-grids as shown in the photo.
3. Recurse for each of the children with the proper sub-grid.

![img](https://assets.leetcode.com/uploads/2020/02/11/new_top.png)

If you want to know more about the Quad-Tree, you can refer to the [wiki](https://en.wikipedia.org/wiki/Quadtree).

**Quad-Tree format:**

The output represents the serialized format of a Quad-Tree using level order traversal, where `null` signifies a path terminator where no node exists below.

It is very similar to the serialization of the binary tree. The only difference is that the node is represented as a list `[isLeaf, val]`.

If the value of `isLeaf` or `val` is True we represent it as **1** in the list `[isLeaf, val]` and if the value of `isLeaf` or `val` is False we represent it as **0**.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/02/11/grid1.png)

```
Input: grid = [[0,1],[1,0]]
Output: [[0,1],[1,0],[1,1],[1,1],[1,0]]
Explanation: The explanation of this example is shown below:
Notice that 0 represnts False and 1 represents True in the photo representing the Quad-Tree.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/02/12/e2mat.png)

```
Input: grid = [[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0]]
Output: [[0,1],[1,1],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],[1,1]]
Explanation: All values in the grid are not the same. We divide the grid into four sub-grids.
The topLeft, bottomLeft and bottomRight each has the same value.
The topRight have different values so we divide it into 4 sub-grids where each has the same value.
Explanation is shown in the photo below:
```

**Example 3:**

```
Input: grid = [[1,1],[1,1]]
Output: [[1,1]]
```

**Example 4:**

```
Input: grid = [[0]]
Output: [[1,0]]
```

**Example 5:**

```
Input: grid = [[1,1,0,0],[1,1,0,0],[0,0,1,1],[0,0,1,1]]
Output: [[0,1],[1,1],[1,0],[1,0],[1,1]]
```

**Constraints:**

- `n == grid.length == grid[i].length`
- `n == 2^x` where `0 <= x <= 6`

## Solution

``` cpp
class Solution {
    Node* construct(vector<vector<int>>& grid, int left, int top, int size) {
        int one = 0;
        for(int i = 0; i < size; ++i) {
            for(int j = 0; j < size; ++j) {
                one += grid[top+i][left+j];
            }
        }
        if(one == 0 || one == size*size) return new Node(one, true);
        int newSize = size/2;
        Node *topLeft = construct(grid, left, top, newSize);
        Node *topRight = construct(grid, left+newSize, top, newSize);
        Node *bottomLeft = construct(grid, left, top+newSize, newSize);
        Node *bottomRight = construct(grid, left+newSize, top+newSize, newSize);
        return new Node(0, false, topLeft, topRight, bottomLeft, bottomRight);
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        int size = grid.size();
        return construct(grid, 0, 0, size);
    }
};
```

# January LeetCoding Challenge1

**Check Array Formation Through Concatenation**

## Description

You are given an array of **distinct** integers `arr` and an array of integer arrays `pieces`, where the integers in `pieces` are **distinct**. Your goal is to form `arr` by concatenating the arrays in `pieces` **in any order**. However, you are **not** allowed to reorder the integers in each array `pieces[i]`.

Return `true` *if it is possible* *to form the array* `arr` *from* `pieces`. Otherwise, return `false`.

**Example 1:**

```
Input: arr = [85], pieces = [[85]]
Output: true
```

**Example 2:**

```
Input: arr = [15,88], pieces = [[88],[15]]
Output: true
Explanation: Concatenate [15] then [88]
```

**Example 3:**

```
Input: arr = [49,18,16], pieces = [[16,18,49]]
Output: false
Explanation: Even though the numbers match, we cannot reorder pieces[0].
```

**Example 4:**

```
Input: arr = [91,4,64,78], pieces = [[78],[4,64],[91]]
Output: true
Explanation: Concatenate [91] then [4,64] then [78]
```

**Example 5:**

```
Input: arr = [1,3,5,7], pieces = [[2,4,6,8]]
Output: false
```

**Constraints:**

- `1 <= pieces.length <= arr.length <= 100`
- `sum(pieces[i].length) == arr.length`
- `1 <= pieces[i].length <= arr.length`
- `1 <= arr[i], pieces[i][j] <= 100`
- The integers in `arr` are **distinct**.
- The integers in `pieces` are **distinct** (i.e., If we flatten pieces in a 1D array, all the integers in this array are distinct).

## Solution

last two constraints is important.

``` cpp
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, int> pos;
        int len = arr.size();
        for(int i = 0; i < len; ++i) {
            pos[arr[i]] = i;
        }
        for(auto &piece : pieces) {
            int curPos = -1, len = piece.size();
            for(int i = 0; i < len; ++i) {
                if(!pos.count(piece[i]) || (curPos != -1 && pos[piece[i]] != curPos + 1)) return false;
                curPos = pos[piece[i]];
            }
        }
        return true;
    }
};
```