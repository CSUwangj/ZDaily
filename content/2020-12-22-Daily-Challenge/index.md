+++
title = "2020-12-22 Daily-Challenge"
path = "2020-12-22-Daily-Challenge"
date = 2020-12-22 18:00:42+08:00
updated = 2020-12-22 19:42:01+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Make Two Arrays Equal by Reversing Sub-arrays](https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/) on leetcode and leetcode's [December LeetCoding Challenge](https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/572/week-4-december-22nd-december-28th/3577/) with `cpp`.

<!-- more -->

# Make Two Arrays Equal by Reversing Sub-arrays

## Description

Given two integer arrays of equal length `target` and `arr`.

In one step, you can select any **non-empty sub-array** of `arr` and reverse it. You are allowed to make any number of steps.

Return *True* if you can make `arr` equal to `target`, or *False* otherwise.

**Example 1:**

```
Input: target = [1,2,3,4], arr = [2,4,1,3]
Output: true
Explanation: You can follow the next steps to convert arr to target:
1- Reverse sub-array [2,4,1], arr becomes [1,4,2,3]
2- Reverse sub-array [4,2], arr becomes [1,2,4,3]
3- Reverse sub-array [4,3], arr becomes [1,2,3,4]
There are multiple ways to convert arr to target, this is not the only way to do so.
```

**Example 2:**

```
Input: target = [7], arr = [7]
Output: true
Explanation: arr is equal to target without any reverses.
```

**Example 3:**

```
Input: target = [1,12], arr = [12,1]
Output: true
```

**Example 4:**

```
Input: target = [3,7,9], arr = [3,7,11]
Output: false
Explanation: arr doesn't have value 9 and it can never be converted to target.
```

**Example 5:**

```
Input: target = [1,1,1,1,1], arr = [1,1,1,1,1]
Output: true
```

**Constraints:**

- `target.length == arr.length`
- `1 <= target.length <= 1000`
- `1 <= target[i] <= 1000`
- `1 <= arr[i] <= 1000`

## Solution

use count 

``` cpp
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int cnt[1001] = {0};
        for(auto i : target) {
            cnt[i] += 1;
        }
        for(auto i : arr) {
            cnt[i] -= 1;
        }
        for(int i = 0; i <= 1000; ++i) {
            if(cnt[i]) return false;
        }
        return true;
    }
};
```

or check if there are permutations of each other.

``` cpp
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        return arr == target;
    }
};
```

# December LeetCoding Challenge 22

## Description

**Balanced Binary Tree**

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

> a binary tree in which the left and right subtrees of *every* node differ in height by no more than 1.

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/10/06/balance_1.jpg)

```
Input: root = [3,9,20,null,null,15,7]
Output: true
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/10/06/balance_2.jpg)

```
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
```

**Example 3:**

```
Input: root = []
Output: true
```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 5000]`.
- `-104 <= Node.val <= 104`

## Solution

balanced binary tree is not balanced binary search tree

``` cpp
class Solution {
    pair<bool, int> getMinMax(TreeNode* root) {
        if(!root) return make_pair(true, 0);
        auto [balancedLeft, heightLeft] = getMinMax(root->left);
        auto [balancedRight, heightRight] = getMinMax(root->right);
        int diff = abs(heightLeft-heightRight);
        bool balanced = balancedLeft && balancedRight && diff < 2;
        return make_pair(balanced, 1+max(heightRight, heightLeft));
    }
public:
    bool isBalanced(TreeNode* root) {
        auto [balanced, _height] = getMinMax(root);
        return balanced;
    }
};
```