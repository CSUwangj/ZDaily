+++
title = "2021-08-12 Daily-Challenge"
path = "2021-08-12-Daily-Challenge"
date = 2021-08-12 18:20:03+08:00
updated = 2021-08-12 18:34:24+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Delete Leaves With a Given Value](https://leetcode.com/problems/delete-leaves-with-a-given-value/description/) and leetcode's [August LeetCoding Challenge](https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/614/week-2-august-8th-august-14th/3887/) with `cpp`.

<!-- more -->

# Delete Leaves With a Given Value

## Description

Given a binary tree `root` and an integer `target`, delete all the **leaf nodes** with value `target`.

Note that once you delete a leaf node with value `target`**,** if it's parent node becomes a leaf node and has the value `target`, it should also be deleted (you need to continue doing that until you can't).

 

**Example 1:**

**![img](https://assets.leetcode.com/uploads/2020/01/09/sample_1_1684.png)**

```
Input: root = [1,2,3,2,null,2,4], target = 2
Output: [1,null,3,null,4]
Explanation: Leaf nodes in green with value (target = 2) are removed (Picture in left). 
After removing, new nodes become leaf nodes with value (target = 2) (Picture in center).
```

**Example 2:**

**![img](https://assets.leetcode.com/uploads/2020/01/09/sample_2_1684.png)**

```
Input: root = [1,3,3,3,2], target = 3
Output: [1,3,null,null,2]
```

**Example 3:**

**![img](https://assets.leetcode.com/uploads/2020/01/15/sample_3_1684.png)**

```
Input: root = [1,2,null,2,null,2], target = 2
Output: [1]
Explanation: Leaf nodes in green with value (target = 2) are removed at each step.
```

**Example 4:**

```
Input: root = [1,1,1], target = 1
Output: []
```

**Example 5:**

```
Input: root = [1,2,3], target = 1
Output: [1,2,3]
```

 

**Constraints:**

- `1 <= target <= 1000`
- The given binary tree will have between `1` and `3000` nodes.
- Each node's value is between `[1, 1000]`.

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
  TreeNode* removeLeafNodes(TreeNode* root, int target) {
    if(!root) return nullptr;
    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);
    if(root->val == target && !root->left && !root->right) return nullptr;
    return root;
  }
};

// Accepted
// 50/50 cases passed (12 ms)
// Your runtime beats 88.29 % of cpp submissions
// Your memory usage beats 14.7 % of cpp submissions (22 MB)
```

# August LeetCoding Challenge 12

## Description

**Group Anagrams**

Given an array of strings `strs`, group **the anagrams** together. You can return the answer in **any order**.

An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

**Example 1:**

```
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
```

**Example 2:**

```
Input: strs = [""]
Output: [[""]]
```

**Example 3:**

```
Input: strs = ["a"]
Output: [["a"]]
```

 

**Constraints:**

- `1 <= strs.length <= 10^4`
- `0 <= strs[i].length <= 100`
- `strs[i]` consists of lower-case English letters.

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
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;
    for(auto s : strs) {
      string key = s;
      sort(key.begin(), key.end());
      groups[key].push_back(s);
    }
    vector<vector<string>> answer;
    for(auto [key, group] : groups) {
      answer.emplace_back(group);
    }
    return answer;
  }
};

// Accepted
// 114/114 cases passed (28 ms)
// Your runtime beats 89.97 % of cpp submissions
// Your memory usage beats 35.7 % of cpp submissions (20.8 MB)
```
