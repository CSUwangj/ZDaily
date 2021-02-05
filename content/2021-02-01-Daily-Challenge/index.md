+++
title = "2021-02-01 Daily-Challenge"
path = "2021-02-01-Daily-Challenge"
date = 2021-02-01 18:00:59+08:00
updated = 2021-02-01 18:54:06+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Largest Component Size by Common Factor](https://leetcode.com/problems/check-completeness-of-a-binary-tree/) and leetcode's [February LeetCoding Challenge](https://leetcode.com/explore/featured/card/february-leetcoding-challenge-2021/584/week-1-february-1st-february-7th/3625/) with `cpp`.

<!-- more -->

# Check Completeness of a Binary Tree

## Description

Given the `root` of a binary tree, determine if it is a *complete binary tree*.

In a **[complete binary tree](http://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees)**, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between `1` and `2h` nodes inclusive at the last level `h`.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2018/12/15/complete-binary-tree-1.png)

```
Input: root = [1,2,3,4,5,6]
Output: true
Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2018/12/15/complete-binary-tree-2.png)

```
Input: root = [1,2,3,4,5,null,7]
Output: false
Explanation: The node with value 7 isn't as far left as possible.
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[1, 100]`.
- `1 <= Node.val <= 1000`

## Solution

check comment for explanation

``` cpp
class Solution {
    enum state{ fail, complete, full };
    const pair<state, int> FAIL{fail, -1};
    // pair(state, height)
    pair<state, int> helper(TreeNode *root) {
        if(!root) return make_pair(full, 0);
        auto [leftState, leftHeight] = helper(root->left);
        auto [rightState, rightHeight] = helper(root->right);
        
        // fail if any of left/right subtree is not a complete tree
        if(leftState == fail || rightState == fail) return FAIL;
        
        // fail if height of left subtree is less than or is two or more greater than right subtree's
        if(leftHeight < rightHeight || leftHeight > rightHeight + 1) return FAIL;
        
        if(leftHeight == rightHeight) {
            // fail if left subtree is complete but not full and have right subtree with same height
            if(leftState == complete) return FAIL;
            // if left subtree is full, then state of tree is depend on right subtree
            return make_pair(rightState, leftHeight + 1);
        }
        
        // height of left subtree is one greater than right subtree's
        // if right subtree is not full, it's fail
        if(rightState != full) return FAIL;
        // otherwise, it's a complete binary tree
        return make_pair(complete, leftHeight + 1);
    }
public:
    bool isCompleteTree(TreeNode* root) {
        auto [state, height] = helper(root);
        return state != fail;
    }
};
```

# February LeetCoding Challenge1

**Number of 1 Bits**

## Description

Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the [Hamming weight](http://en.wikipedia.org/wiki/Hamming_weight)).

**Note:**

- Note that in some languages such as Java, there is no unsigned integer type. In this case, the input will be given as a signed integer type. It should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
- In Java, the compiler represents the signed integers using [2's complement notation](https://en.wikipedia.org/wiki/Two's_complement). Therefore, in **Example 3** above, the input represents the signed integer. `-3`.

**Follow up**: If this function is called many times, how would you optimize it?

 

**Example 1:**

```
Input: n = 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
```

**Example 2:**

```
Input: n = 00000000000000000000000010000000
Output: 1
Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.
```

**Example 3:**

```
Input: n = 11111111111111111111111111111101
Output: 31
Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.
```

 

**Constraints:**

- The input must be a **binary string** of length `32`

## Solution

``` cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int answer = 0;
        while(n) {
            answer += (n & 1);
            n >>= 1;
        }
        return answer;
    }
};
```

or low bit

``` cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int answer = 0;
        while(n) {
            answer += 1;
            n &= n-1;
        }
        return answer;
    }
};
```