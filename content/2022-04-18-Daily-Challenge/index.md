+++
updated = 2022-04-18 18:55:00+08:00
title = "2022-04-18 Daily-Challenge"
path = "2022-04-18-Daily-Challenge"
date = 2022-04-18 18:53:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/kth-smallest-element-in-a-bst/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 18

## Description

**Kth Smallest Element in a BST**

Given the `root` of a binary search tree, and an integer `k`, return *the* `kth` *smallest value (**1-indexed**) of all the values of the nodes in the tree*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/01/28/kthtree1.jpg)

```
Input: root = [3,1,4,null,2], k = 1
Output: 1
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/01/28/kthtree2.jpg)

```
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
```

 

**Constraints:**

- The number of nodes in the tree is `n`.
- `1 <= k <= n <= 10^4`
- `0 <= Node.val <= 10^4`

 

**Follow up:** If the BST is modified often (i.e., we  can do insert and delete operations) and you need to find the kth  smallest frequently, how would you optimize?

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  void traversal(TreeNode *root, int &rest, int &result) {
    if(!root) return;
    traversal(root->left, rest, result);
    if(result != -1) return;
    if((--rest) == 0) {
      result = root->val;
      return;
    }
    traversal(root->right, rest, result);
  }
public:
  int kthSmallest(TreeNode* root, int k) {
    int answer = -1;
    traversal(root, k, answer);
    return answer;
  }
};

// Accepted
// 93/93 cases passed (7 ms)
// Your runtime beats 99.88 % of cpp submissions
// Your memory usage beats 60.91 % of cpp submissions (24.2 MB)
```
