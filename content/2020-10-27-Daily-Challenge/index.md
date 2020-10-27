+++
title = "2020-10-27 Daily-Challenge"
path = "2020-10-27-Daily-Challenge"
date = 2020-10-27 00:38:47+08:00
updated = 2020-10-27 19:18:48+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done *Number of Islands* on [leetcode](https://leetcode.com/problems/number-of-islands/) and leetcode's [October LeetCoding Challenge](https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/562/week-4-october-22nd-october-28th/3509/) with `cpp`.

<!-- more -->

# Number of Islands

## Description

Given an `m x n` 2d `grid` map of `'1'`s (land) and `'0'`s (water), return *the number of islands*.

An **island** is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

**Example 1:**

```
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
```

**Example 2:**

```
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
```

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 300`
- `grid[i][j]` is `'0'` or `'1'`.

## Solution

simple bfs

``` cpp
class Solution {
  vector<vector<int>> move{{1,0},{0,1},{-1,0},{0,-1}};
public:
  int numIslands(vector<vector<char>>& grid) {
    int sz = grid.size() * grid[0].size(), width = grid[0].size(), height = grid.size(), ans = 0;
    vector<vector<bool>> visited(height, vector<bool>(width));
    queue<pair<int, int>> start_points, q;
    for(int i = 0; i < height; ++i) {
      for(int j = 0; j < width; ++j) {
        if(grid[i][j] == '1') {
          start_points.push(make_pair(i, j));
        }
      }
    }
    while(start_points.size()) {
      auto start_point = start_points.front();
      start_points.pop();
      if(visited[start_point.first][start_point.second]) {
        continue;
      }
      ans += 1;
      visited[start_point.first][start_point.second] = true;
      q.push(start_point);
      while(q.size()) {
        auto tmp = q.front();
        int row = tmp.first, col = tmp.second;
        q.pop();
        for(int i = 0; i < 4; ++i) {
          int nrow = row+move[i][0], ncol = col+move[i][1];
          if(nrow < height && nrow >=0 && ncol < width && ncol >=0 &&
            grid[nrow][ncol] == '1' && !visited[nrow][ncol]) {
            q.push(make_pair(nrow, ncol));
            visited[nrow][ncol] = true;
          }
        }
      }
    }
    return ans;
  }
};
```

# October LeetCoding Challenge27

**Linked List Cycle II**

## Description

Given a linked list, return the node where the cycle begins. If there is no cycle, return `null`.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the `next` pointer. Internally, `pos` is used to denote the index of the node that tail's `next` pointer is connected to. **Note that `pos` is not passed as a parameter**.

**Notice** that you **should not modify** the linked list.

**Follow up:**

Can you solve it using `O(1)` (i.e. constant) memory?

**Example 1:**

![img](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist.png)

```
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test2.png)

```
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
```

**Example 3:**

![img](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test3.png)

```
Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
```

**Constraints:**

- The number of the nodes in the list is in the range `[0, 104]`.
- `-105 <= Node.val <= 105`
- `pos` is `-1` or a **valid index** in the linked-list.

## Solution

will try O(1) space when reviewing.

``` cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    set<ListNode*> st;
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        ListNode* cur = head;
        while(cur) {
            if(st.count(cur)) return cur;
            st.insert(cur);
            cur = cur->next;
        }
        return NULL;
    }
};
```
