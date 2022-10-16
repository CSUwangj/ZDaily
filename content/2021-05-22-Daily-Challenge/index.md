+++
title = "2021-05-22 Daily-Challenge"
path = "2021-05-22-Daily-Challenge"
date = 2021-05-22 15:03:55+08:00
updated = 2021-05-22 15:27:39+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [May LeetCoding Challenge](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/601/week-4-may-22nd-may-28th/3752/) with `cpp`.

<!-- more -->

# LeetCode Review

## Find and Replace Pattern

too easy to review

## Binary Tree Level Order Traversal

too easy to review

## Longest String Chain

won't review

## Find Duplicate File in System

won't review

## Minimum Moves to Equal Array Elements II

``` cpp
class Solution {
public:
  int minMoves2(vector<int>& nums) {
    int answer = 0;
    sort(nums.begin(), nums.end());
    int target = nums[nums.size() / 2];
    for(auto i : nums) answer += abs(i - target);
    return answer;
  }
};
```

# May LeetCoding Challenge 22

## Description

**N-Queens**

<p>The <strong>n-queens</strong> puzzle is the problem of placing <code>n</code> queens on an <code>n x n</code> chessboard such that no two queens attack each other.</p>

<p>Given an integer <code>n</code>, return <em>all distinct solutions to the <strong>n-queens puzzle</strong></em>.</p>

<p>Each solution contains a distinct board configuration of the n-queens&#39; placement, where <code>&#39;Q&#39;</code> and <code>&#39;.&#39;</code> both indicate a queen and an empty space, respectively.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/queens.jpg" style="width: 600px; height: 268px;" />
<pre><code><strong>Input:</strong> n = 4
<strong>Output:</strong> [[&quot;.Q..&quot;,&quot;...Q&quot;,&quot;Q...&quot;,&quot;..Q.&quot;],[&quot;..Q.&quot;,&quot;Q...&quot;,&quot;...Q&quot;,&quot;.Q..&quot;]]
<strong>Explanation:</strong> There exist two distinct solutions to the 4-queens puzzle as shown above</code></pre>

<p><strong>Example 2:</strong></p>

<pre><code><strong>Input:</strong> n = 1
<strong>Output:</strong> [[&quot;Q&quot;]]</code<</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 9</code></li>
</ul>

## Solution

``` cpp
int rows[9];
bool check(int row, int col) {
  for(int i = 0; i < row; ++i) {
    if(abs(i - row) == abs(rows[i] - col) || col == rows[i]) return false;
  }
  return true;
}
class Solution {
  vector<vector<string>> answer;

  void addResult(int n) {
    vector<string> result;
    for(int i = 0; i < n; ++i) {
      string row(n, '.');
      row[rows[i]] = 'Q';
      result.emplace_back(row);
    }
    answer.emplace_back(result);
  }

  void solve(int cur, int n) {
    if(cur == n) {
      addResult(n);
      return;
    }
    for(int i = 0; i < n; ++i) {
      if(check(cur, i)) {
        rows[cur] = i;
        solve(cur + 1, n);
      }
    }
  }
public:
  vector<vector<string>> solveNQueens(int n) {
    solve(0, n);
    return move(answer);
  }
};
```
