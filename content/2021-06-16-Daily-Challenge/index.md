+++
title = "2021-06-16 Daily-Challenge"
path = "2021-06-16-Daily-Challenge"
date = 2021-06-16 17:33:44+08:00
updated = 2021-06-16 19:49:15+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Distribute Coins in Binary Tree](https://leetcode.com/problems/distribute-coins-in-binary-tree/description/) and leetcode's [June LeetCoding Challenge](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/605/week-3-june-15th-june-21st/3781/) with `cpp`.

<!-- more -->

# Distribute Coins in Binary Tree

## Description

You are given the `root` of a binary tree with `n` nodes where each `node` in the tree has `node.val` coins. There are `n` coins in total throughout the whole tree.

In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to child, or from child to parent.

Return *the **minimum** number of moves required to make every node have **exactly** one coin*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2019/01/18/tree1.png)

```
Input: root = [3,0,0]
Output: 2
Explanation: From the root of the tree, we move one coin to its left child, and one coin to its right child.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2019/01/18/tree2.png)

```
Input: root = [0,3,0]
Output: 3
Explanation: From the left child of the root, we move two coins to the root [taking two moves]. Then, we move one coin from the root of the tree to the right child.
```

**Example 3:**

![img](https://assets.leetcode.com/uploads/2019/01/18/tree3.png)

```
Input: root = [1,0,2]
Output: 2
```

**Example 4:**

![img](https://assets.leetcode.com/uploads/2019/01/18/tree4.png)

```
Input: root = [1,0,0,null,3]
Output: 4
```

 

**Constraints:**

- The number of nodes in the tree is `n`.
- `1 <= n <= 100`
- `0 <= Node.val <= n`
- The sum of all `Node.val` is `n`.

## Solution

``` cpp
class Solution {
  int answer;
  pair<int, int> solve(TreeNode *root) {
    if(!root) return {0, 0};
    int curNode = 1;
    int curCoin = root->val;
    auto [leftNode, leftCoin] = solve(root->left);
    auto [rightNode, rightCoin] = solve(root->right);
    // cout << answer << ' ' << leftNode << ' ' << rightNode << ' ' << leftCoin << ' ' << rightCoin << endl;
    answer += abs(leftNode - leftCoin) + abs(rightNode - rightCoin);
    return {curNode + leftNode + rightNode, curCoin + leftCoin + rightCoin};
  }
public:
  int distributeCoins(TreeNode* root) {
    answer = 0;
    solve(root);
    return answer;
  }
};
```

# June LeetCoding Challenge 16

## Description

**Generate Parentheses**

Given `n` pairs of parentheses, write a function to *generate all combinations of well-formed parentheses*.

 

**Example 1:**

```
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
```

**Example 2:**

```
Input: n = 1
Output: ["()"]
```

 

**Constraints:**

- `1 <= n <= 8`

## Solution

``` cpp
class Solution {
  void generateParenthesis(
    vector<string> &result,
    string &cur,
    int rest,
    int left
  ) {
    if(!rest && !left) {
      result.push_back(cur);
      return;
    }
    if(rest) {
      cur.push_back('(');
      generateParenthesis(result, cur, rest - 1, left + 1);
      cur.pop_back();
    }
    if(left) {
      cur.push_back(')');
      generateParenthesis(result, cur, rest, left - 1);
      cur.pop_back();
    }
  }
public:
  vector<string> generateParenthesis(int n) {
    vector<string> answer;
    string tmp;
    generateParenthesis(answer, tmp, n, 0);
    return answer;
  }
};
```
