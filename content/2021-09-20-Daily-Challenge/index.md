+++
title = "2021-09-20 Daily-Challenge"
path = "2021-09-20-Daily-Challenge"
date = 2021-09-20 18:01:34+08:00
updated = 2021-09-20 18:11:23+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/638/week-3-september-15th-september-21st/3981/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 20

## Description

**Find Winner on a Tic Tac Toe Game**

Tic-tac-toe is played by two players *A* and *B* on a *3* x *3* grid.

Here are the rules of Tic-Tac-Toe:

- Players take turns placing characters into empty squares (" ").
- The first player *A* always places "X" characters, while the second player *B* always places "O" characters.
- "X" and "O" characters are always placed into empty squares, never on filled ones.
- The game ends when there are 3 of the same (non-empty) character filling any row, column, or diagonal.
- The game also ends if all squares are non-empty.
- No more moves can be played if the game is over.

Given an array `moves` where each element is another array of size 2 corresponding to the row and column of the grid where they mark their respective character in the order in which *A* and *B* play.

Return the winner of the game if it exists (*A* or *B*), in case the game ends in a draw return "Draw", if there are still movements to play return "Pending".

You can assume that `moves` is **valid** (It follows the rules of Tic-Tac-Toe), the grid is initially empty and *A* will play **first**.

 

**Example 1:**

```
Input: moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]
Output: "A"
Explanation: "A" wins, he always plays first.
"X  "    "X  "    "X  "    "X  "    "X  "
"   " -> "   " -> " X " -> " X " -> " X "
"   "    "O  "    "O  "    "OO "    "OOX"
```

**Example 2:**

```
Input: moves = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
Output: "B"
Explanation: "B" wins.
"X  "    "X  "    "XX "    "XXO"    "XXO"    "XXO"
"   " -> " O " -> " O " -> " O " -> "XO " -> "XO " 
"   "    "   "    "   "    "   "    "   "    "O  "
```

**Example 3:**

```
Input: moves = [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]
Output: "Draw"
Explanation: The game ends in a draw since there are no moves to make.
"XXO"
"OOX"
"XOX"
```

**Example 4:**

```
Input: moves = [[0,0],[1,1]]
Output: "Pending"
Explanation: The game has not finished yet.
"X  "
" O "
"   "
```

 

**Constraints:**

- `1 <= moves.length <= 9`
- `moves[i].length == 2`
- `0 <= moves[i][j] <= 2`
- There are no repeated elements on `moves`.
- `moves` follow the rules of tic tac toe.

## Solution

``` cpp
class Solution {
  int board[3][3] = {};
  int checkWinner() {
    for(int w = 1; w < 3; ++w) {
      if (board[0][0] == w && board[1][0] == w && board[2][0] == w ||
          board[0][1] == w && board[1][1] == w && board[2][1] == w ||
          board[0][2] == w && board[1][2] == w && board[2][2] == w ||
          board[0][0] == w && board[0][1] == w && board[0][2] == w ||
          board[1][0] == w && board[1][1] == w && board[1][2] == w ||
          board[2][0] == w && board[2][1] == w && board[2][2] == w ||
          board[0][0] == w && board[1][1] == w && board[2][2] == w ||
          board[0][2] == w && board[1][1] == w && board[2][0] == w
      ) {
        return w;
      }
    }
    return 0;
  }
public:
  string tictactoe(vector<vector<int>>& moves) {
    int len = moves.size();
    for(int i = 0; i < len; i += 2) {
      board[moves[i][0]][moves[i][1]] = 1;
    }
    for(int i = 1; i < len; i += 2) {
      board[moves[i][0]][moves[i][1]] = 2;
    }
    int winner = checkWinner();
    if(winner) {
      return winner == 1 ? "A" : "B";
    }
    return moves.size() == 9 ? "Draw" : "Pending";
  }
};

// Accepted
// 100/100 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 96.15 % of cpp submissions (8.1 MB)
```
