+++
title = "2020-10-25 Daily-Challenge"
path = "2020-10-25-Daily-Challenge"
date = 2020-10-25 02:24:07+08:00
updated = 2020-10-25 15:21:59+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I gonna review the tasks I've done this week, and finish today's leetcode's [October LeetCoding Challenge](https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/562/week-4-october-22nd-october-28th/3507/) with `cpp`.

BTW I decided to write solution directly on website rather than on VSCode when reviewing.

<!-- more -->

# LeetCode review

## 132 Pattern

find extremum is always easier

``` cpp
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size() < 3) return false;
        stack<int> three;
        int two = INT_MIN;
        three.push(nums.back());
        for(int i = nums.size()-1; i >=0 ; --i) {
            if(nums[i] < two) return true;
            while(three.size() && three.top() < nums[i]) {
                two = three.top();
                three.pop();
            }
            three.push(nums[i]);
        }
        return false;
    }
};
```

## Largest Number

``` cpp
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans = "";
        sort(nums.begin(), nums.end(), [](int a, int b){
            return to_string(a)+to_string(b)>to_string(b)+to_string(a);
        });
        for(auto i : nums){
            ans += to_string(i);
        }
        return ans[0] == '0' ? "0" : ans;
    }
};
```

## Minimum Depth of Binary Tree

```
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while(q.size()) {
            ans += 1;
            int cur_level_nodes = q.size();
            for(int i = 0; i < cur_level_nodes; ++i) {
                TreeNode* cur = q.front();
                q.pop();
                if(!(cur->left) && !(cur->right)) return ans;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
        // can not happen
        return -1;
    }
};
```

## Add One Row to Tree

more gentle

``` cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1) return new TreeNode(v, root, nullptr);
        if(d == 0) return new TreeNode(v, nullptr, root);
        if(!root) return nullptr;
        root->left = addOneRow(root->left, v, d-1);
        root->right = addOneRow(root->right, v, d==2?0:d-1);
        return root;
        
    }
};
```

## Sudoku Solver

write once and solve it XD

``` cpp
class Solution {
    vector<int> rows = vector<int>(9), cols = vector<int>(9), squares = vector<int>(9);
    void init(vector<vector<char>>& board) {
        for(int i = 0; i < 81; ++i){
            int row = i%9, col = i/9, square = i%9/3*3+i/9/3;
            if(board[row][col] == '.') continue;
            rows[row] |= (1 << (board[row][col]-'0'));
            cols[col] |= (1 << (board[row][col]-'0'));
            squares[square] |= (1 << (board[row][col]-'0'));
        }
    }
    bool dfs(vector<vector<char>>& board, int pos) {
        if(pos == 81) return true;
        int row = pos%9, col = pos/9, square = pos%9/3*3+pos/9/3;
        if(board[row][col] != '.') return dfs(board, pos+1);
        for(int i = 1; i < 10; ++i) {
            if(rows[row] & (1 << i) ||
               cols[col] & (1 << i) ||
               squares[square] & (1 << i)) continue;
            rows[row] |= (1 << i);
            cols[col] |= (1 << i);
            squares[square] |= (1 << i);
            if(dfs(board, pos+1)) {
                board[row][col] = i+'0';
                return true;
            }
            rows[row] ^= (1 << i);
            cols[col] ^= (1 << i);
            squares[square] ^= (1 << i);
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        init(board);
        dfs(board, 0);
    }
};
```

# October LeetCoding Challenge25

## Description

**Stone Game IV**

Alice and Bob take turns playing a game, with Alice starting first.

Initially, there are `n` stones in a pile. On each player's turn, that player makes a *move* consisting of removing **any** non-zero **square number** of stones in the pile.

Also, if a player cannot make a move, he/she loses the game.

Given a positive integer `n`. Return `True` if and only if Alice wins the game otherwise return `False`, assuming both players play optimally.

**Example 1:**

```
Input: n = 1
Output: true
Explanation: Alice can remove 1 stone winning the game because Bob doesn't have any moves.
```

**Example 2:**

```
Input: n = 2
Output: false
Explanation: Alice can only remove 1 stone, after that Bob removes the last one winning the game (2 -> 1 -> 0).
```

**Example 3:**

```
Input: n = 4
Output: true
Explanation: n is already a perfect square, Alice can win with one move, removing 4 stones (4 -> 0).
```

**Example 4:**

```
Input: n = 7
Output: false
Explanation: Alice can't win the game if Bob plays optimally.
If Alice starts removing 4 stones, Bob will remove 1 stone then Alice should remove only 1 stone and finally Bob removes the last one (7 -> 3 -> 2 -> 1 -> 0). 
If Alice starts removing 1 stone, Bob will remove 4 stones then Alice only can remove 1 stone and finally Bob removes the last one (7 -> 6 -> 2 -> 1 -> 0).
```

**Example 5:**

```
Input: n = 17
Output: false
Explanation: Alice can't win the game if Bob plays optimally.
```

**Constraints:**

- `1 <= n <= 10^5`

## Solution

simple game theory

``` cpp
class Solution {
public:
  bool winnerSquareGame(int n) {
    vector<bool> state{false};
    int cur = 1;
    while(state.size() <= n) {
      bool win = false;
      for(int i = 1; i <= cur; ++i) {
        if(!state[state.size()-i*i]) {
          win = true;
          break;
        }
      }
      state.push_back(win);
      if(state.size() == (cur+1)*(cur+1)) cur += 1;
    }
    return state[n];
  }
};
```