+++
updated = 2022-05-15 19:24:00+08:00
title = "2022-05-15 Daily-Challenge"
path = "2022-05-15-Daily-Challenge"
date = 2022-05-15 19:21:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/deepest-leaves-sum/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 15

## Description

**Deepest Leaves Sum**

Given the `root` of a binary tree, return *the sum of values of its deepest leaves*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2019/07/31/1483_ex1.png)

```
Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15
```

**Example 2:**

```
Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 19
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[1, 10^4]`.
- `1 <= Node.val <= 100`

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
  int deepestLeavesSum(TreeNode* root) {
    int answer = 0;
    queue<TreeNode *> q;
    q.push(root);
    while(q.size()) {
      int sz = q.size();
      answer = 0;
      while(sz--) {
        auto cur = q.front();
        q.pop();
        answer += cur->val;
        if(cur->left) q.push(cur->left);
        if(cur->right) q.push(cur->right);
      }
    }
    return answer;
  }
};

// Accepted
// 35/35 cases passed (120 ms)
// Your runtime beats 65.54 % of cpp submissions
// Your memory usage beats 48.29 % of cpp submissions (61.7 MB)
```
