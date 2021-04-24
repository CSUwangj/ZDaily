+++
title = "2021-02-24 Daily-Challenge"
path = "2021-02-24-Daily-Challenge"
date = 2021-02-24 20:03:41+08:00
updated = 2021-02-24 20:56:53+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Delete Nodes And Return Forest](https://leetcode.com/problems/delete-nodes-and-return-forest/) and leetcode's [February LeetCoding Challenge](https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/587/week-4-february-22nd-february-28th/3651/) with `cpp`.

<!-- more -->

# Delete Nodes And Return Forest

## Description

Given the `root` of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in `to_delete`, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest. You may return the result in any order.

 

**Example 1:**

**![img](https://assets.leetcode.com/uploads/2019/07/01/screen-shot-2019-07-01-at-53836-pm.png)**

```
Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]
```

 

**Constraints:**

- The number of nodes in the given tree is at most `1000`.
- Each node has a distinct value between `1` and `1000`.
- `to_delete.length <= 1000`
- `to_delete` contains distinct values between `1` and `1000`.

## Solution

``` cpp
class Solution {
    TreeNode *travelAndDeleteRoot(TreeNode *root, vector<TreeNode*> &answer, vector<int>& to_delete) {
        if(!root) return nullptr;
        TreeNode *left = travelAndDeleteRoot(root->left, answer, to_delete);
        TreeNode *right = travelAndDeleteRoot(root->right, answer, to_delete);
        if(find(to_delete.begin(), to_delete.end(), root->val) != to_delete.end()) {
            if(left) answer.push_back(root->left);
            if(right) answer.push_back(root->right);
            return nullptr;
        }
        root->left = left;
        root->right = right;
        return root;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> answer;
        if(travelAndDeleteRoot(root, answer, to_delete)) answer.push_back(root);
        
        return move(answer);
    }
};
```

# February LeetCoding Challenge24

## Description

**Score of Parentheses**

Given a balanced parentheses string `S`, compute the score of the string based on the following rule:

- `()` has score 1
- `AB` has score `A + B`, where A and B are balanced parentheses strings.
- `(A)` has score `2 * A`, where A is a balanced parentheses string.

 

**Example 1:**

```
Input: "()"
Output: 1
```

**Example 2:**

```
Input: "(())"
Output: 2
```

**Example 3:**

```
Input: "()()"
Output: 2
```

**Example 4:**

```
Input: "(()(()))"
Output: 6
```

 

**Note:**

1. `S` is a balanced parentheses string, containing only `(` and `)`.
2. `2 <= S.length <= 50`

## Solution

``` cpp
class Solution {
public:
    int scoreOfParentheses(string S) {
        vector<int> pos;
        vector<int> sum;
        int current = 0;
        for(int i = 0; i < S.length(); ++i) {
            if(S[i] == '(') {
                pos.push_back(i);
                sum.push_back(current);
                current = 0;
            } else {
                if(pos.back() == i - 1) {
                    current += 1;
                    current += sum.back();
                } else {
                    current *= 2;
                    current += sum.back();
                }
                sum.pop_back();
                pos.pop_back();
            }
        }
        return current;
    }
};
```
