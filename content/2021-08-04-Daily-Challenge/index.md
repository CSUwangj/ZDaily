+++
title = "2021-08-04 Daily-Challenge"
path = "2021-08-04-Daily-Challenge"
date = 2021-08-04 18:56:34+08:00
updated = 2021-08-04 19:22:40+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Sort Array By Parity II](https://leetcode.com/problems/sort-array-by-parity-ii/description/) and leetcode's [August LeetCoding Challenge](https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/613/week-1-august-1st-august-7th/3838/) with `cpp`.

<!-- more -->

# Sort Array By Parity II

## Description

Given an array of integers `nums`, half of the integers in `nums` are **odd**, and the other half are **even**.

Sort the array so that whenever `nums[i]` is odd, `i` is **odd**, and whenever `nums[i]` is even, `i` is **even**.

Return *any answer array that satisfies this condition*.

 

**Example 1:**

```
Input: nums = [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
```

**Example 2:**

```
Input: nums = [2,3]
Output: [2,3]
```

 

**Constraints:**

- `2 <= nums.length <= 2 * 10^4`
- `nums.length` is even.
- Half of the integers in `nums` are even.
- `0 <= nums[i] <= 1000`

 

**Follow Up:** Could you solve it in-place?

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
  vector<int> sortArrayByParityII(vector<int>& nums) {
    int even = 0;
    int odd = 1;
    int len = nums.size();
    while(even < len) {
      while(even < len && ~nums[even] & 1) even += 2;
      while(odd < len && nums[odd] & 1) odd += 2;
      if(even >= len) break;
      swap(nums[odd], nums[even]);
      odd += 2;
      even += 2;
    }
    return nums;
  }
};

// Accepted
// 61/61 cases passed (12 ms)
// Your runtime beats 97.83 % of cpp submissions
// Your memory usage beats 30.87 % of cpp submissions (21.5 MB)
```

# August LeetCoding Challenge 4

## Description

**Path Sum II**

Given the `root` of a binary tree and an integer `targetSum`, return all **root-to-leaf** paths where each path's sum equals `targetSum`.

A **leaf** is a node with no children.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/01/18/pathsumii1.jpg)

```
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/01/18/pathsum2.jpg)

```
Input: root = [1,2,3], targetSum = 5
Output: []
```

**Example 3:**

```
Input: root = [1,2], targetSum = 0
Output: []
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[0, 5000]`.
- `-1000 <= Node.val <= 1000`
- `-1000 <= targetSum <= 1000`

## Solution

``` cpp
class Solution {
  void solve(
    vector<vector<int>> &answer,
    vector<int> &container,
    TreeNode *root,
    int rest
  ) {
    if(!root) return;
    container.push_back(root->val);
    rest -= root->val;
    if(!rest && !root->left && !root->right) {
      answer.push_back(container);
    } else {
      solve(answer, container, root->left, rest);
      solve(answer, container, root->right, rest);
    }
    container.pop_back();
  }
public:
  vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> answer;
    vector<int> temp;
    solve(answer, temp, root, targetSum);
    return move(answer);
  }
};

// Accepted
// 115/115 cases passed ( ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 81.42 % of cpp submissions (19.8 MB)
```