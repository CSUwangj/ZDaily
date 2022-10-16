+++
title = "2021-12-05 Daily-Challenge"
path = "2021-12-05-Daily-Challenge"
date = 2021-12-05 20:00:00+08:00
updated = 2021-12-05 20:14:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/house-robber-iii/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 5

## Description

**House Robber III**

The thief has found himself a new place for his thievery again. There is only one entrance to this area, called `root`.

Besides the `root`, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this  place form a binary tree. It will automatically contact the police if **two directly-linked houses were broken into on the same night**.

Given the `root` of the binary tree, return *the maximum amount of money the thief can rob **without alerting the police***.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/03/10/rob1-tree.jpg)

```
Input: root = [3,2,3,null,3,null,1]
Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/03/10/rob2-tree.jpg)

```
Input: root = [3,4,5,1,3,null,1]
Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
```

 

**Constraints:**

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>4</sup>]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
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
  pair<int, int> solve(TreeNode *root) {
    if(!root) {
      return {0, 0};
    }
    auto [maxLeft, maxNotRobLeft] = solve(root->left);
    auto [maxRight, maxNotRobRight] = solve(root->right);
    int maxRob = root->val + maxNotRobLeft + maxNotRobRight;
    int maxNotRob = maxLeft + maxRight;
    return {max(maxRob, maxNotRob), maxNotRob};
  }
public:
  int rob(TreeNode* root) {
    return solve(root).first;
  }
};

// Accepted
// 124/124 cases passed (4 ms)
// Your runtime beats 99.42 % of cpp submissions
// Your memory usage beats 70.99 % of cpp submissions (22.2 MB)
```
