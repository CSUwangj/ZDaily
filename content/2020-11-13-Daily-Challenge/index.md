+++
title = "2020-11-13 Daily-Challenge"
path = "2020-11-13-Daily-Challenge"
date = 2020-11-13 00:08:33+08:00
updated = 2020-11-13 21:27:42+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done *Plus One* on [leetcode](https://leetcode.com/problems/plus-one/) and leetcode's [November LeetCoding Challenge](https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/565/week-2-november-8th-november-14th/3529/) with `cpp`.

<!-- more -->

# Plus One

## Description

Given a **non-empty** array of decimal digits representing a non-negative integer, increment one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

**Example 1:**

```
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
```

**Example 2:**

```
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
```

**Example 3:**

```
Input: digits = [0]
Output: [1]
```

**Constraints:**

- `1 <= digits.length <= 100`
- `0 <= digits[i] <= 9`

## Solution

nothing to say

``` cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(auto it = digits.rbegin(); carry && it != digits.rend(); ++it) {
            int curVal = *it + carry;
            carry = curVal / 10;
            *it = curVal % 10;
        }
        if(carry == 1) {
            digits.insert(digits.begin(), 1, 1);
        }
        return digits;
    }
};
```

# November LeetCoding Challenge13

**Populating Next Right Pointers in Each Node**

## Description

You are given a **perfect binary tree** where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

```
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
```

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to `NULL`.

Initially, all next pointers are set to `NULL`.

**Follow up:**

- You may only use constant extra space.
- Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.

**Example 1:**

![img](https://assets.leetcode.com/uploads/2019/02/14/116_sample.png)

```
Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
```

**Constraints:**

- The number of nodes in the given tree is less than `4096`.
- `-1000 <= node.val <= 1000`

## Solution

I failed to come up with solution with O(1) space complexity...

``` cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root, int level=0) {
        if(!root) return root;
        queue<pair<Node*, int>> q;
        q.push(make_pair(root, 0));
        Node *rightNode = NULL;
        int nodeLevel = -1;
        while(q.size()) {
            auto [cur, level] = q.front();
            q.pop();
            if(nodeLevel == level) {
                cur->next = rightNode;
            } else {
                cur->next = NULL;
            }
            rightNode = cur;
            nodeLevel = level;
            if(cur->right) q.push(make_pair(cur->right, level+1));
            if(cur->left) q.push(make_pair(cur->left, level+1));
        }
        return root;
    }
};
```
