+++
title = "2021-12-08 Daily-Challenge"
path = "2021-12-08-Daily-Challenge"
date = 2021-12-08 18:17:00+08:00
updated = 2021-12-08 18:19:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/binary-tree-tilt/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 8

## Description

**Binary Tree Tilt**

Given the `root` of a binary tree, return *the sum of every tree node's **tilt**.*

The **tilt** of a tree node is the **absolute difference** between the sum of all left subtree node **values** and all right subtree node **values**. If a node does not have a left child, then the sum of the left subtree node **values** is treated as `0`. The rule is similar if there the node does not have a right child.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/10/20/tilt1.jpg)

```
Input: root = [1,2,3]
Output: 1
Explanation: 
Tilt of node 2 : |0-0| = 0 (no children)
Tilt of node 3 : |0-0| = 0 (no children)
Tilt of node 1 : |2-3| = 1 (left subtree is just left child, so sum is 2; right subtree is just right child, so sum is 3)
Sum of every tilt : 0 + 0 + 1 = 1
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/10/20/tilt2.jpg)

```
Input: root = [4,2,9,3,5,null,7]
Output: 15
Explanation: 
Tilt of node 3 : |0-0| = 0 (no children)
Tilt of node 5 : |0-0| = 0 (no children)
Tilt of node 7 : |0-0| = 0 (no children)
Tilt of node 2 : |3-5| = 2 (left subtree is just left child, so sum is 3; right subtree is just right child, so sum is 5)
Tilt of node 9 : |0-7| = 7 (no left child, so sum is 0; right subtree is just right child, so sum is 7)
Tilt of node 4 : |(3+5+2)-(9+7)| = |10-16| = 6 (left subtree values are 3, 5, and 2, which sums to 10; right subtree values are 9 and 7, which sums to 16)
Sum of every tilt : 0 + 0 + 0 + 2 + 7 + 6 = 15
```

**Example 3:**

![img](https://assets.leetcode.com/uploads/2020/10/20/tilt3.jpg)

```
Input: root = [21,7,14,1,1,2,2,3,3]
Output: 9
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[0, 10^4]`.
- `-1000 <= Node.val <= 1000`

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  int answer = 0;
  int solve(TreeNode *root) {
    if(!root) return 0;
    int leftSum = solve(root->left);
    int rightSum = solve(root->right);
    answer += abs(leftSum - rightSum);
    return leftSum + rightSum + root->val;
  }
public:
  int findTilt(TreeNode* root) {
    solve(root);
    return answer;
  }
};

// Accepted
// 77/77 cases passed (12 ms)
// Your runtime beats 94.11 % of cpp submissions
// Your memory usage beats 11.69 % of cpp submissions (23.8 MB)
```
