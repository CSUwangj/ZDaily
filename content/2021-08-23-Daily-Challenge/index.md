+++
title = "2021-08-23 Daily-Challenge"
path = "2021-08-23-Daily-Challenge"
date = 2021-08-23 19:01:03+08:00
updated = 2021-08-23 20:11:52+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Two Sum II - Input array is sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/) and leetcode's [August LeetCoding Challenge](https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/616/week-4-august-22nd-august-28th/3908/) with `cpp`.

<!-- more -->

# Two Sum II - Input array is sorted

## Description

Given an array of integers `numbers` that is already ***sorted in non-decreasing order\***, find two numbers such that they add up to a specific `target` number.

Return *the indices of the two numbers (**1-indexed**) as an integer array* `answer` *of size* `2`*, where* `1 <= answer[0] < answer[1] <= numbers.length`.

The tests are generated such that there is **exactly one solution**. You **may not** use the same element twice.

 

**Example 1:**

```
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
```

**Example 2:**

```
Input: numbers = [2,3,4], target = 6
Output: [1,3]
```

**Example 3:**

```
Input: numbers = [-1,0], target = -1
Output: [1,2]
```

 

**Constraints:**

- `2 <= numbers.length <= 3 * 10^4`
- `-1000 <= numbers[i] <= 1000`
- `numbers` is sorted in **non-decreasing order**.
- `-1000 <= target <= 1000`
- The tests are generated such that there is **exactly one solution**.

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
  vector<int> twoSum(vector<int>& numbers, int target) {
    int begin = 0;
    int end = numbers.size() - 1;
    while(begin < end && numbers[begin] + numbers[end] != target) {
      if(numbers[begin] + numbers[end] < target) {
        begin += 1;
      } else {
        end -= 1;
      }
    }
    return {begin + 1, end + 1};
  }
};
// Accepted
// 19/19 cases passed (4 ms)
// Your runtime beats 88.71 % of cpp submissions
// Your memory usage beats 75.51 % of cpp submissions (9.6 MB)
```

# August LeetCoding Challenge 23

## Description

**Two Sum IV - Input is a BST**

Given the `root` of a Binary Search Tree and a target number `k`, return *`true` if there exist two elements in the BST such that their sum is equal to the given target*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/09/21/sum_tree_1.jpg)

```
Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/09/21/sum_tree_2.jpg)

```
Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
```

**Example 3:**

```
Input: root = [2,1,3], k = 4
Output: true
```

**Example 4:**

```
Input: root = [2,1,3], k = 1
Output: false
```

**Example 5:**

```
Input: root = [2,1,3], k = 3
Output: true
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[1, 10^4]`.
- `-10^4 <= Node.val <= 10^4`
- `root` is guaranteed to be a **valid** binary search tree.
- `-10^5 <= k <= 10^5`

## Solution

morris traversal always got RE, maybe because I modified the tree?

FUCK LEETCODE.

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  unordered_set<int> st;
public:
  bool findTarget(TreeNode* root, int k) {
    if(!root) return false;
    if(st.count(k - root->val)) return true;
    st.insert(root->val);
    return findTarget(root->left, k) || findTarget(root->right, k);
  }
};

// Accepted
// 422/422 cases passed (40 ms)
// Your runtime beats 60.78 % of cpp submissions
// Your memory usage beats 28.45 % of cpp submissions (39 MB)
```

``` cpp
class Solution {
  TreeNode *leftTravel(TreeNode *root, int min) {
    if(!root) return root;
    TreeNode *left = root->left;
    while(left && left->val > min) {
      while(left->right && left->right != root) {
        left = left->right;
      }
      if(left->right == root) {
        left->right = nullptr;
        return root;
      } 
      left->right = root;
      root = root->left;
      left = root->left;
    }
    return root;
  }

  TreeNode *rightTravel(TreeNode *root, int max) {
    if(!root) return root;
    TreeNode *right = root->right;
    while(right && right->val < max) {
      while(right->left && right->left != root) {
        right = right->left;
      }
      if(right->left == root) {
        right->left = nullptr;
        return root;
      } 
      right->left = root;
      root = root->right;
      right = root->right;
    }
    return root;
  }
  TreeNode *copy(TreeNode *root) {
    if(!root) return root;
    TreeNode *newRoot = new TreeNode(root->val);
    newRoot->left = copy(root->left);
    newRoot->right = copy(root->right);
    return newRoot;
  }
public:
  bool findTarget(TreeNode* root, int k) {
    if(!root) return false;
    // comment line below, dump leetcode will RE
    root = copy(root);
    TreeNode *leftCur = leftTravel(root, INT_MIN);
    TreeNode *rightCur = rightTravel(root, INT_MAX);
    while(leftCur && rightCur && leftCur != rightCur) {
    int leftMin = leftCur->val;
    int rightMost = rightCur->val;
      int sum = leftCur->val + rightCur->val;
      if(sum == k) {
        return true;
      } else if (sum < k) {
        leftCur = leftTravel(leftCur->right, leftMin);
      } else {
        rightCur = rightTravel(rightCur->left, rightMost);
      }
    }
    return false;
  }
};

// Accepted
// 422/422 cases passed (52 ms)
// Your runtime beats 22.62 % of cpp submissions
// Your memory usage beats 12.33 % of cpp submissions (40.9 MB)
```
