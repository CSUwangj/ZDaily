+++
updated = 2022-09-04 18:14:00+08:00
title = "2022-09-04 Daily-Challenge"
path = "2022-09-04-Daily-Challenge"
date = 2022-09-04 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 4

## Description

**Vertical Order Traversal of a Binary Tree**

Given the `root` of a binary tree, calculate the **vertical order traversal** of the binary tree.

For each node at position `(row, col)`, its left and right children will be at positions `(row + 1, col - 1)` and `(row + 1, col + 1)` respectively. The root of the tree is at `(0, 0)`.

The **vertical order traversal** of a binary tree is a  list of top-to-bottom orderings for each column index starting from the  leftmost column and ending on the rightmost column. There may be  multiple nodes in the same row and same column. In such a case, sort  these nodes by their values.

Return *the **vertical order traversal** of the binary tree*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/01/29/vtree1.jpg)

```
Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation:
Column -1: Only node 9 is in this column.
Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
Column 1: Only node 20 is in this column.
Column 2: Only node 7 is in this column.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/01/29/vtree2.jpg)

```
Input: root = [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
Column -2: Only node 4 is in this column.
Column -1: Only node 2 is in this column.
Column 0: Nodes 1, 5, and 6 are in this column.
          1 is at the top, so it comes first.
          5 and 6 are at the same position (2, 0), so we order them by their value, 5 before 6.
Column 1: Only node 3 is in this column.
Column 2: Only node 7 is in this column.
```

**Example 3:**

![img](https://assets.leetcode.com/uploads/2021/01/29/vtree3.jpg)

```
Input: root = [1,2,3,4,6,5,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
This case is the exact same as example 2, but with nodes 5 and 6 swapped.
Note that the solution remains the same since 5 and 6 are in the same location and should be ordered by their values.
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[1, 1000]`.
- `0 <= Node.val <= 1000`

## Solution

``` cpp
class Solution {
  typedef struct _node {
    int y;
    int val;
    _node(int y, int val): y(y), val(val) {}
    bool operator<(const _node &a) {
      return this->y > a.y || (this->y == a.y && this->val < a.val);
    }
  } node;
  map<int, vector<node>> result;
  void traversal(TreeNode *root, int x, int y) {
    if(!root) return;
    result[x].push_back(node(y, root->val));
    traversal(root->left, x-1, y-1);
    traversal(root->right, x+1, y-1);
  }
public:
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    traversal(root, 0, 0);
    vector<vector<int>> answer;
    for(auto &[_, nodes] : result) {
      answer.push_back(vector<int>());
      if(nodes.size() == 1) {
        answer.back().push_back(nodes.back().val);
      } else {
        sort(nodes.begin(), nodes.end());
        for(auto &node : nodes) answer.back().push_back(node.val);
      }
    }
    return answer;
  }
};

// Accepted
// 32/32 cases passed (10 ms)
// Your runtime beats 44.99 % of cpp submissions
// Your memory usage beats 72.74 % of cpp submissions (12.9 MB)
```
