+++
title = "2021-06-30 Daily-Challenge"
path = "2021-06-30-Daily-Challenge"
date = 2021-06-30 18:46:39+08:00
updated = 2021-06-30 20:35:08+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Minimize Maximum Pair Sum in Array](https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/description/) and leetcode's [June LeetCoding Challenge](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/607/week-5-june-29th-june-30th/3797/) with `cpp`.

<!-- more -->

# Minimize Maximum Pair Sum in Array

## Description

The **pair sum** of a pair `(a,b)` is equal to `a + b`. The **maximum pair sum** is the largest **pair sum** in a list of pairs.

- For example, if we have pairs `(1,5)`, `(2,3)`, and `(4,4)`, the **maximum pair sum** would be `max(1+5, 2+3, 4+4) = max(6, 5, 8) = 8`.

Given an array `nums` of **even** length `n`, pair up the elements of `nums` into `n / 2` pairs such that:

- Each element of `nums` is in **exactly one** pair, and
- The **maximum pair sum** is **minimized**.

Return *the minimized **maximum pair sum** after optimally pairing up the elements*.

 

**Example 1:**

```
Input: nums = [3,5,2,3]
Output: 7
Explanation: The elements can be paired up into pairs (3,3) and (5,2).
The maximum pair sum is max(3+3, 5+2) = max(6, 7) = 7.
```

**Example 2:**

```
Input: nums = [3,5,4,2,4,6]
Output: 8
Explanation: The elements can be paired up into pairs (3,5), (4,4), and (6,2).
The maximum pair sum is max(3+5, 4+4, 6+2) = max(8, 8, 8) = 8.
```

 

**Constraints:**

- `n == nums.length`
- `2 <= n <= 10^5`
- `n` is **even**.
- `1 <= nums[i] <= 10^5`

## Solution

``` cpp
auto speedup = []() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int minPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int len = nums.size();
    int answer = 0;
    for(int i = 0; i * 2 < len; ++i) {
      answer = max(answer, nums[i] + nums[len - i - 1]);
    }
    return answer;
  }
};

// Accepted
// 37/37 cases passed (140 ms)
// Your runtime beats 99.92 % of cpp submissions
// Your memory usage beats 17.97 % of cpp submissions (96.3 MB)
```

# June LeetCoding Challenge30

## Description

**Lowest Common Ancestor of a Binary Tree**

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the [definition of LCA on Wikipedia](https://en.wikipedia.org/wiki/Lowest_common_ancestor): “The lowest common ancestor is defined between two nodes `p` and `q` as the lowest node in `T` that has both `p` and `q` as descendants (where we allow **a node to be a descendant of itself**).”

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2018/12/14/binarytree.png)

```
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2018/12/14/binarytree.png)

```
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
```

**Example 3:**

```
Input: root = [1,2], p = 1, q = 2
Output: 1
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[2, 105]`.
- `-109 <= Node.val <= 109`
- All `Node.val` are **unique**.
- `p != q`
- `p` and `q` will exist in the tree.

## Solution

``` cpp
class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == p || root == q) return root;
    if(!root) return nullptr;
    auto left = lowestCommonAncestor(root->left, p, q);
    auto right = lowestCommonAncestor(root->right, p, q);
    if(left && right) return root;
    if(!left && !right) return nullptr;
    if(!left) return right;
    return left;
  }
};
```
