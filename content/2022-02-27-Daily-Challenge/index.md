+++
title = "2022-02-27 Daily-Challenge"
path = "2022-02-27-Daily-Challenge"
date = 2022-02-27 16:36:00+08:00
updated = 2022-02-27 16:46:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/maximum-width-of-binary-tree/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 27

## Description

**Maximum Width of Binary Tree**

Given the `root` of a binary tree, return *the **maximum width** of the given tree*.

The **maximum width** of a tree is the maximum **width** among all levels.

The **width** of one level is defined as the length  between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes are also counted into the length  calculation.

It is **guaranteed** that the answer will in the range of **32-bit** signed integer.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/05/03/width1-tree.jpg)

```
Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/05/03/width2-tree.jpg)

```
Input: root = [1,3,null,5,3]
Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
```

**Example 3:**

![img](https://assets.leetcode.com/uploads/2021/05/03/width3-tree.jpg)

```
Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[1, 3000]`.
- `-100 <= Node.val <= 100`

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
  int widthOfBinaryTree(TreeNode* root) {
    if(!root) return 0;
    long long answer = 0;
    queue<pair<long long, TreeNode*>> q;
    q.push({0, root});
    while(q.size()) {
      int sz = q.size();
      long long mmin = INT_MAX;
      long long mmax = INT_MIN;
      for(int _ = 0; _ < sz; ++_) {
        auto [index, cur] = q.front();
        mmin = min(index, mmin);
        mmax = max(index, mmax);
        q.pop();
        if(cur->left) q.push({index * 2 - mmin, cur->left});
        if(cur->right) q.push({index * 2 + 1 - mmin, cur->right});
      }
      answer = max(answer, mmax - mmin + 1);
    }
    return answer;
  }
};

// Accepted
// 113/113 cases passed (18 ms)
// Your runtime beats 28.12 % of cpp submissions
// Your memory usage beats 21.15 % of cpp submissions (17.4 MB)
```
