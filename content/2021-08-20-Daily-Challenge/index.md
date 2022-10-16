+++
title = "2021-08-20 Daily-Challenge"
path = "2021-08-20-Daily-Challenge"
date = 2021-08-20 18:01:03+08:00
updated = 2021-08-20 18:15:30+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/description/) and leetcode's [August LeetCoding Challenge](https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/615/week-3-august-15th-august-21st/3904/) with `cpp`.

<!-- more -->

# Implement Queue using Stacks

## Description

Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (`push`, `peek`, `pop`, and `empty`).

Implement the `MyQueue` class:

- `void push(int x)` Pushes element x to the back of the queue.
- `int pop()` Removes the element from the front of the queue and returns it.
- `int peek()` Returns the element at the front of the queue.
- `boolean empty()` Returns `true` if the queue is empty, `false` otherwise.

**Notes:**

- You must use **only** standard operations of a stack, which means only `push to top`, `peek/pop from top`, `size`, and `is empty` operations are valid.
- Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.

 

**Example 1:**

```
Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
```

 

**Constraints:**

- `1 <= x <= 9`
- At most `100` calls will be made to `push`, `pop`, `peek`, and `empty`.
- All the calls to `pop` and `peek` are valid.

 

**Follow-up:** Can you implement the queue such that each operation is **[amortized](https://en.wikipedia.org/wiki/Amortized_analysis)** `O(1)` time complexity? In other words, performing `n` operations will take overall `O(n)` time even if one of those operations may take longer.

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class MyQueue {
  vector<int> out;
  vector<int> in;

  void refill() {
    if(out.size()) return;
    while(in.size()) {
      out.push_back(in.back());
      in.pop_back();
    }
  }
public:
  /** Initialize your data structure here. */
  MyQueue() {}
  
  /** Push element x to the back of queue. */
  void push(int x) {
    in.push_back(x);
  }
  
  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    refill();
    int val = out.back();
    out.pop_back();
    return val;
  }
  
  /** Get the front element. */
  int peek() {
    refill();
    return out.back();
  }
  
  /** Returns whether the queue is empty. */
  bool empty() {
    return out.empty() && in.empty();
  }
};

// Accepted
// 21/21 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 45.12 % of cpp submissions (7.1 MB)
```

# August LeetCoding Challenge 20

## Description

**Valid Sudoku**

Determine if a `9 x 9` Sudoku board is valid. Only the filled cells need to be validated **according to the following rules**:

1. Each row must contain the digits `1-9` without repetition.
2. Each column must contain the digits `1-9` without repetition.
3. Each of the nine `3 x 3` sub-boxes of the grid must contain the digits `1-9` without repetition.

**Note:**

- A Sudoku board (partially filled) could be valid but is not necessarily solvable.
- Only the filled cells need to be validated according to the mentioned rules.

 

**Example 1:**

![img](https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png)

```
Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
```

**Example 2:**

```
Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
```

 

**Constraints:**

- `board.length == 9`
- `board[i].length == 9`
- `board[i][j]` is a digit or `'.'`.


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  bool visRow[9][9] = {};
  bool visCol[9][9] = {};
  bool visBox[9][9] = {};
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    for(int row = 0; row < 9; ++row) {
      for(int col = 0; col < 9; ++col) {
        int box = row / 3 * 3 + col / 3;
        int digit = board[row][col] == '.' ? -1 : board[row][col] - '1';
        if(digit == -1) continue;
        if(visRow[row][digit] || visCol[col][digit] || visBox[box][digit]) return false;
        visRow[row][digit] = true;
        visCol[col][digit] = true;
        visBox[box][digit] = true;
      }
    }
    return true;
  }
};

// Accepted
// 507/507 cases passed (12 ms)
// Your runtime beats 98.39 % of cpp submissions
// Your memory usage beats 72.54 % of cpp submissions (18 MB)
```
