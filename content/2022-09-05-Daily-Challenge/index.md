+++
updated = 2022-09-05 18:14:00+08:00
title = "2022-09-05 Daily-Challenge"
path = "2022-09-05-Daily-Challenge"
date = 2022-09-05 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/n-ary-tree-level-order-traversal/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 5

## Description

**N-ary Tree Level Order Traversal**

Given an n-ary tree, return the *level order* traversal of its nodes' values.

*Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See  examples).*

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png)

```
Input: root = [1,null,3,2,4,null,5,6]
Output: [[1],[3,2,4],[5,6]]
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2019/11/08/sample_4_964.png)

```
Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
```

 

**Constraints:**

- The height of the n-ary tree is less than or equal to `1000`
- The total number of nodes is between `[0, 10^4]`

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
  vector<vector<int>> levelOrder(Node* root) {
    if(!root) return {};
    vector<vector<int>> answer;
    queue<Node*> q;
    q.push(root);
    while(q.size()) {
      int sz = q.size();
      vector<int> level;
      for(int _ = 0; _ < sz; ++_) {
        auto cur = q.front();
        q.pop();
        level.push_back(cur->val);
        for(auto child : cur->children) {
          q.push(child);
        }
      }
      answer.push_back(level);
    }
    return answer;
  }
};

// Accepted
// 38/38 cases passed (20 ms)
// Your runtime beats 86.78 % of cpp submissions
// Your memory usage beats 34.23 % of cpp submissions (11.9 MB)
```
