+++
title = "2022-01-26 Daily-Challenge"
path = "2022-01-26-Daily-Challenge"
date = 2022-01-26 18:01:00+08:00
updated = 2022-01-26 18:11:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/all-elements-in-two-binary-search-trees/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 26

## Description

**All Elements in Two Binary Search Trees**

Given two binary search trees `root1` and `root2`, return *a list containing all the integers from both trees sorted in **ascending** order*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2019/12/18/q2-e1.png)

```
Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2019/12/18/q2-e5-.png)

```
Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]
```

 

**Constraints:**

- The number of nodes in each tree is in the range `[0, 5000]`.
- `-10^5 <= Node.val <= 10^5`


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Stream {
  TreeNode *root;
  TreeNode *cur = root;
  int current;
public:
  Stream(TreeNode *r) : root(r) {
    iterate();
  }
  int getNum() {
    return current;
  }
  bool hasNum() {
    return current != INT_MAX;
  }
  void iterate() {
    if(!cur) {
      current = INT_MAX;
      return;
    }
    while(cur) {
      if(cur->left) {
        TreeNode *left = cur->left;
        while(left->right && left->right != cur) {
          left = left->right;
        }
        if(left->right == cur) {
          left->right = nullptr;
          current = cur->val;
          cur = cur->right;
          return;
        } else {
          left->right = cur;
          cur = cur->left;
        }
      } else {
        current = cur->val;
        cur = cur->right;
        return;
      }
    }
  }
};
class Solution {
public:
  vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    vector<int> answer;
    Stream stream1(root1);
    Stream stream2(root2);
    while(stream1.hasNum() && stream2.hasNum()) {
      if(stream1.getNum() <= stream2.getNum()) {
        answer.push_back(stream1.getNum());
        stream1.iterate();
      } else {
        answer.push_back(stream2.getNum());
        stream2.iterate();
      }
    }
    while(stream1.hasNum()) {
      answer.push_back(stream1.getNum());
      stream1.iterate();
    }
    while(stream2.hasNum()) {
      answer.push_back(stream2.getNum());
      stream2.iterate();
    }
    return answer;
  }
};

// Accepted
// 48/48 cases passed (211 ms)
// Your runtime beats 35.95 % of cpp submissions
// Your memory usage beats 67.43 % of cpp submissions (84.5 MB)
```
