+++
title = "2022-01-12 Daily-Challenge"
path = "2022-01-12-Daily-Challenge"
date = 2022-01-12 18:56:00+08:00
updated = 2022-01-12 19:00:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/insert-into-a-binary-search-tree/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 12

## Description

**Insert into a Binary Search Tree**

You are given the `root` node of a binary search tree (BST) and a `value` to insert into the tree. Return *the root node of the BST after the insertion*. It is **guaranteed** that the new value does not exist in the original BST.

**Notice** that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return **any of them**.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/10/05/insertbst.jpg)

```
Input: root = [4,2,7,1,3], val = 5
Output: [4,2,7,1,3,5]
Explanation: Another accepted tree is:
```

**Example 2:**

```
Input: root = [40,20,60,10,30,50,70], val = 25
Output: [40,20,60,10,30,50,70,null,null,25]
```

**Example 3:**

```
Input: root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
Output: [4,2,7,1,3,5]
```

 

**Constraints:**


<ul>
	<li>The number of nodes in&nbsp;the tree will be in the range <code>[0,&nbsp;10<sup>4</sup>]</code>.</li>
	<li><code>-10<sup>8</sup> &lt;= Node.val &lt;= 10<sup>8</sup></code></li>
	<li>All the values <code>Node.val</code> are <strong>unique</strong>.</li>
	<li><code>-10<sup>8</sup> &lt;= val &lt;= 10<sup>8</sup></code></li>
	<li>It&#39;s <strong>guaranteed</strong> that <code>val</code> does not exist in the original BST.</li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(!root) return new TreeNode(val);
    if(root->val > val) {
      root->left = insertIntoBST(root->left, val);
    } else {
      root->right = insertIntoBST(root->right, val);
    }
    return root;
  }
};

// Accepted
// 35/35 cases passed (136 ms)
// Your runtime beats 21.66 % of cpp submissions
// Your memory usage beats 80.92 % of cpp submissions (56.9 MB)
```
