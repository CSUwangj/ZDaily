+++
title = "2021-08-17 Daily-Challenge"
path = "2021-08-17-Daily-Challenge"
date = 2021-08-17 19:58:59+08:00
updated = 2021-08-17 20:18:14+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Check if Binary String Has at Most One Segment of Ones](https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/description/) and leetcode's [August LeetCoding Challenge](https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/615/week-3-august-15th-august-21st/3893/) with `cpp`.

<!-- more -->

# Check if Binary String Has at Most One Segment of Ones

## Description

Given a binary string `s` **without leading zeros**, return `true` *if* `s` *contains **at most one contiguous segment of ones***. Otherwise, return `false`.

 

**Example 1:**

```
Input: s = "1001"
Output: false
Explanation: The ones do not form a contiguous segment.
```

**Example 2:**

```
Input: s = "110"
Output: true
```

 

**Constraints:**

- `1 <= s.length <= 100`
- `s[i]` is either `'0'` or `'1'`.
- `s[0]` is `'1'`.

## Solution

``` cpp
class Solution {
public:
  bool checkOnesSegment(string s) {
    int change = 0;
    int prev = '0';
    for(auto c : s) {
      change += (c != prev);
      prev = c;
    }
    return change < 3;
  }
};

// Accepted
// 191/191 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 92.06 % of cpp submissions (5.9 MB)
```

# August LeetCoding Challenge 17

## Description

**Count Good Nodes in Binary Tree**

Given a binary tree `root`, a node *X* in the tree is named **good** if in the path from root to *X* there are no nodes with a value *greater than* X.

Return the number of **good** nodes in the binary tree.

 

**Example 1:**

**![img](https://assets.leetcode.com/uploads/2020/04/02/test_sample_1.png)**

```
Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.
```

**Example 2:**

**![img](https://assets.leetcode.com/uploads/2020/04/02/test_sample_2.png)**

```
Input: root = [3,3,null,4,2]
Output: 3
Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.
```

**Example 3:**

```
Input: root = [1]
Output: 1
Explanation: Root is considered as good.
```

 

**Constraints:**

- The number of nodes in the binary tree is in the range `[1, 10^5]`.
- Each node's value is between `[-10^4, 10^4]`.


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
  int goodNodes(TreeNode* root, int X = INT_MIN) {
    if(!root) return 0;
    if(root->val >= X) {
      return 1 + goodNodes(root->left, root->val) + goodNodes(root->right, root->val);
    } else {
      return goodNodes(root->left, X) + goodNodes(root->right, X);
    }
  }
};

// Accepted
// 63/63 cases passed (96 ms)
// Your runtime beats 99.23 % of cpp submissions
// Your memory usage beats 6.64 % of cpp submissions (86.6 MB)
```
