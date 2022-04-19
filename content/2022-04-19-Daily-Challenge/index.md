+++
updated = 2022-04-19 18:55:00+08:00
title = "2022-04-19 Daily-Challenge"
path = "2022-04-19-Daily-Challenge"
date = 2022-04-19 18:53:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/recover-binary-search-tree/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 19

## Description

**Recover Binary Search Tree**

You are given the `root` of a binary search tree (BST), where the values of **exactly** two nodes of the tree were swapped by mistake. *Recover the tree without changing its structure*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/10/28/recover1.jpg)

```
Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/10/28/recover2.jpg)

```
Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
```

 

**Constraints:**

<ul>
	<li>The number of nodes in the tree is in the range <code>[2, 1000]</code>.</li>
	<li><code>-2<sup>31</sup> &lt;= Node.val &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

**Follow up:** A solution using `O(n)` space is pretty straight-forward. Could you devise a constant `O(1)` space solution?

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {    
  vector<TreeNode*> wrongNodes;
  void check(TreeNode* cur, TreeNode* prev) {
    if(prev && prev->val >= cur->val) {
      wrongNodes.push_back(prev);
      wrongNodes.push_back(cur);
    }
  }
public:
  void recoverTree(TreeNode* root) {
    TreeNode *cur = root, *prev = nullptr;
    while(cur) {
      if(!(cur->left)) {
        check(cur, prev);
        prev = cur;
        cur = cur->right;
      } else {
        TreeNode *pred = cur->left;
        while(pred->right && pred->right != cur) pred = pred->right;
        if(pred->right) {
          pred->right = nullptr;
          check(cur, prev);
          prev = cur;
          cur = cur->right;
        } else {
          pred->right = cur;
          cur = cur->left;
        }
      }
    }
    swap(wrongNodes.front()->val, wrongNodes.back()->val);
  }
};

// Accepted
// 1919/1919 cases passed (20 ms)
// Your runtime beats 98.38 % of cpp submissions
// Your memory usage beats 35.12 % of cpp submissions (58 MB)
```
