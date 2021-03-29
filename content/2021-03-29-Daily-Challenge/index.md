+++
title = "2021-03-29 Daily-Challenge"
path = "2021-03-29-Daily-Challenge"
date = 2021-03-29 18:14:17+08:00
updated = 2021-03-29 18:26:06+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Search Suggestions System](https://leetcode.com/problems/search-suggestions-system//) and leetcode's [March LeetCoding Challenge](https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/592/week-5-march-29th-march-31st/3689/) with `cpp`.

<!-- more -->

# Search Suggestions System

## Description

Given an array of strings `products` and a string `searchWord`. We want to design a system that suggests at most three product names from `products` after each character of `searchWord` is typed. Suggested products should have common prefix with the searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return *list of lists* of the suggested `products` after each character of `searchWord` is typed. 

 

**Example 1:**

```
Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [
["mobile","moneypot","monitor"],
["mobile","moneypot","monitor"],
["mouse","mousepad"],
["mouse","mousepad"],
["mouse","mousepad"]
]
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"]
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"]
After typing mou, mous and mouse the system suggests ["mouse","mousepad"]
```

**Example 2:**

```
Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
```

**Example 3:**

```
Input: products = ["bags","baggage","banner","box","cloths"], searchWord = "bags"
Output: [["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]
```

**Example 4:**

```
Input: products = ["havana"], searchWord = "tatiana"
Output: [[],[],[],[],[],[],[]]
```

 

**Constraints:**

- `1 <= products.length <= 1000`
- There are no repeated elements in `products`.
- `1 <= Σ products[i].length <= 2 * 10^4`
- All characters of `products[i]` are lower-case English letters.
- `1 <= searchWord.length <= 1000`
- All characters of `searchWord` are lower-case English letters.

## Solution

I've solved the problem in my interview. But that problem don't limit return amount.

``` cpp
class Solution {
public:
  vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    sort(products.begin(), products.end());
    vector<vector<string>> answer;
    auto begin = products.begin();
    auto end = products.end();
    for(int i = 0; i < searchWord.length(); ++i) {
      auto cmp = [=](string a, string b) {
        return a[i] < b[i];
      };
      auto newBegin = lower_bound(begin, end, searchWord, cmp);
      auto newEnd = upper_bound(begin, end, searchWord, cmp);
      begin = newBegin;
      end = newEnd;
      if(newEnd - newBegin > 3) newEnd = newBegin + 3;
      if(newEnd - newBegin <= 0) break;
      answer.push_back(vector<string>(newBegin, newEnd));
    }
    while(answer.size() < searchWord.length()) answer.push_back({});
    return answer;
  }
};

// Runtime: 32 ms, faster than 96.84% of C++ online submissions for Search Suggestions System.
// Memory Usage: 39.2 MB, less than 62.45% of C++ online submissions for Search Suggestions System.
```

trie tree looks great, but actually, cost of reconstructing string is huge.

# March LeetCoding challenge29

**Flip Binary Tree To Match Preorder Traversal**

You are given the `root` of a binary tree with `n` nodes, where each node is uniquely assigned a value from `1` to `n`. You are also given a sequence of `n` values `voyage`, which is the **desired** [**pre-order traversal**](https://en.wikipedia.org/wiki/Tree_traversal#Pre-order) of the binary tree.

Any node in the binary tree can be **flipped** by swapping its left and right subtrees. For example, flipping node 1 will have the following effect:

![img](https://assets.leetcode.com/uploads/2021/02/15/fliptree.jpg)

Flip the **smallest** number of nodes so that the **pre-order traversal** of the tree **matches** `voyage`.

Return *a list of the values of all **flipped** nodes. You may return the answer in **any order**. If it is **impossible** to flip the nodes in the tree to make the pre-order traversal match* `voyage`*, return the list* `[-1]`.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2019/01/02/1219-01.png)

```
Input: root = [1,2], voyage = [2,1]
Output: [-1]
Explanation: It is impossible to flip the nodes such that the pre-order traversal matches voyage.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2019/01/02/1219-02.png)

```
Input: root = [1,2,3], voyage = [1,3,2]
Output: [1]
Explanation: Flipping node 1 swaps nodes 2 and 3, so the pre-order traversal matches voyage.
```

**Example 3:**

![img](https://assets.leetcode.com/uploads/2019/01/02/1219-02.png)

```
Input: root = [1,2,3], voyage = [1,2,3]
Output: []
Explanation: The tree's pre-order traversal already matches voyage, so no nodes need to be flipped.
```

 

**Constraints:**

- The number of nodes in the tree is `n`.
- `n == voyage.length`
- `1 <= n <= 100`
- `1 <= Node.val, voyage[i] <= n`
- All the values in the tree are **unique**.
- All the values in `voyage` are **unique**.

## Solution

simulate traversal

code is not elegant...

``` cpp
class Solution {
  bool traversal(TreeNode* root, vector<int>& voyage, vector<int>& answer, int &idx) {
    if(!root) return true;
    if(root->val != voyage[idx]) return false;
    idx += 1;
    if(root->left == nullptr && root->right == nullptr) return true;
    if(root->left == nullptr) {
      return traversal(root->right, voyage, answer, idx);
    }
    if(root->left->val != voyage[idx]) {
      if(!traversal(root->right, voyage, answer, idx) || !traversal(root->left, voyage, answer, idx)) {
        return false;
      }
      answer.push_back(root->val);
      return true;
    }
    return traversal(root->left, voyage, answer, idx) && traversal(root->right, voyage, answer, idx);
  }
public:
  vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
    vector<int> answer;
    int idx = 0;
    if(traversal(root, voyage, answer, idx)) return answer;
    return {-1};
  }
};
```
