+++
title = "2021-07-23 Daily-Challenge"
path = "2021-07-23-Daily-Challenge"
date = 2021-07-23 20:03:09+08:00
updated = 2021-07-23 20:34:52+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Minimum Subsequence in Non-Increasing Order](https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/description/) and leetcode's [July LeetCoding Challenge](https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/611/week-4-july-22nd-july-28th/3823/) with `cpp`.

<!-- more -->

# Minimum Subsequence in Non-Increasing Order

## Description

Given the array `nums`, obtain a subsequence of the array whose sum of elements is **strictly greater** than the sum of the non included elements in such subsequence. 

If there are multiple solutions, return the subsequence with **minimum size** and if there still exist multiple solutions, return the subsequence with the **maximum total sum** of all its elements. A subsequence of an array can be obtained by erasing some (possibly zero) elements from the array. 

Note that the solution with the given constraints is guaranteed to be **unique**. Also return the answer sorted in **non-increasing** order.

 

**Example 1:**

```
Input: nums = [4,3,10,9,8]
Output: [10,9] 
Explanation: The subsequences [10,9] and [10,8] are minimal such that the sum of their elements is strictly greater than the sum of elements not included, however, the subsequence [10,9] has the maximum total sum of its elements. 
```

**Example 2:**

```
Input: nums = [4,4,7,6,7]
Output: [7,7,6] 
Explanation: The subsequence [7,7] has the sum of its elements equal to 14 which is not strictly greater than the sum of elements not included (14 = 4 + 4 + 6). Therefore, the subsequence [7,6,7] is the minimal satisfying the conditions. Note the subsequence has to returned in non-decreasing order.  
```

**Example 3:**

```
Input: nums = [6]
Output: [6]
```

 

**Constraints:**

- `1 <= nums.length <= 500`
- `1 <= nums[i] <= 100`

## Solution

little data...

``` cpp
class Solution {
public:
  vector<int> minSubsequence(vector<int>& nums) {
    int len = nums.size();
    priority_queue<int> pq;
    int sum = 0;
    for(int i = 0; i < nums.size(); ++i) {
      pq.push(nums[i]);
      sum += nums[i];
    }
    int cur = 0;
    vector<int> answer;
    while(cur <= sum) {
      answer.push_back(pq.top());
      pq.pop();
      cur += answer.back();
      sum -= answer.back();
    }

    return answer;
  }
};
```

``` cpp
class Solution {
public:
  vector<int> minSubsequence(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    sort(nums.begin(), nums.end(), greater<int>());
    int cur = 0;
    for(int i = 0; i < nums.size(); ++i) {
      if(cur * 2 > sum) {
        nums.resize(i);
        return nums;
      }
      cur += nums[i];
    }
    return nums;
  }
};
```

# July LeetCoding Challenge23

## Description

**Binary Tree Pruning**

Given the `root` of a binary tree, return *the same tree where every subtree (of the given tree) not containing a* `1` *has been removed*.

A subtree of a node `node` is `node` plus every node that is a descendant of `node`.

 

**Example 1:**

![img](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/06/1028_2.png)

```
Input: root = [1,null,0,0,1]
Output: [1,null,0,null,1]
Explanation: 
Only the red nodes satisfy the property "every subtree not containing a 1".
The diagram on the right represents the answer.
```

**Example 2:**

![img](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/06/1028_1.png)

```
Input: root = [1,0,1,0,0,0,1]
Output: [1,null,1,null,1]
```

**Example 3:**

![img](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/05/1028.png)

```
Input: root = [1,1,0,1,1,0,1,0]
Output: [1,1,0,1,1,null,1]
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[1, 200]`.
- `Node.val` is either `0` or `1`.

## Solution

``` cpp
class Solution {
public:
  TreeNode* pruneTree(TreeNode* root) {
    if(!root) return nullptr;
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if(!root->val && !root->left && !root->right) return nullptr;
    return root;
  }
};
```
