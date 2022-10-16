+++
updated = 2022-09-02 18:14:00+08:00
title = "2022-09-02 Daily-Challenge"
path = "2022-09-02-Daily-Challenge"
date = 2022-09-02 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/average-of-levels-in-binary-tree/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 2

## Description

**Average of Levels in Binary Tree**

Given the `root` of a binary tree, return *the average value of the nodes on each level in the form of an array*. Answers within `10-5` of the actual answer will be accepted.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/03/09/avg1-tree.jpg)

```
Input: root = [3,9,20,null,null,15,7]
Output: [3.00000,14.50000,11.00000]
Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
Hence return [3, 14.5, 11].
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/03/09/avg2-tree.jpg)

```
Input: root = [3,9,20,15,7]
Output: [3.00000,14.50000,11.00000]
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[1, 10^4]`.
- `-2^31 <= Node.val <= 2^31 - 1`

## Solution

``` cpp
class Solution {
  vector<pair<int, double>> count;
  void traversal(TreeNode *root, int level) {
    if(!root) return;
    if(count.size() <= level) count.push_back(make_pair(0, 0));
    count[level].first += 1;
    count[level].second += root->val;
    traversal(root->left, level + 1);
    traversal(root->right, level + 1);
  }
public:
  vector<double> averageOfLevels(TreeNode* root) {
    traversal(root, 0);
    vector<double> answer;
    for(auto [cnt, sum] : count) {
      answer.push_back(sum / cnt);
    }
    return move(answer);
  }
};

// Accepted
// 66/66 cases passed (27 ms)
// Your runtime beats 44.2 % of cpp submissions
// Your memory usage beats 72.83 % of cpp submissions (22.5 MB)
```
