+++
title = "2021-01-20 Daily-Challenge"
path = "2021-01-20-Daily-Challenge"
date = 2021-01-20 18:00:59+08:00
updated = 2021-01-20 22:19:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Count The Repetitions](https://leetcode.com/problems/count-the-repetitions/), [All Possible Full Binary Trees](https://leetcode.com/problems/all-possible-full-binary-trees/) and leetcode's [January LeetCoding Challenge](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/581/week-3-january-15th-january-21st/3610/) with `cpp`.

<!-- more -->

# Count The Repetitions

## Description

Define `S = [s,n]` as the string S which consists of n connected strings s. For example, `["abc", 3]` ="abcabcabc".

On the other hand, we define that string s1 can be obtained from string s2 if we can remove some characters from s2 such that it becomes s1. For example, “abc” can be obtained from “abdbec” based on our definition, but it can not be obtained from “acbbe”.

You are given two non-empty strings s1 and s2 (each at most 100 characters long) and two integers $0 \le n1 \le10^6$ and $1 \le n2 \le 10^6$. Now consider the strings S1 and S2, where `S1=[s1,n1]` and `S2=[s2,n2]`. Find the maximum integer M such that `[S2,M]` can be obtained from `S1`.

**Example:**

```
Input:
s1="acb", n1=4
s2="ab", n2=2

Return:
2
```

## Solution

write elegant code is not easy

``` cpp
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int len1 = s1.length();
        int len2 = s2.length();
        if(len1 * n1 < len2 * n2) return 0;
        vector<int> indexr(len2+1);
        vector<int> countr(len2+1);
        int index = 0, count = 0;
        for(int i = 0; i < n1; ++i) {
            for(int j = 0; j < len1; ++j) {
                if(s1[j] == s2[index]) {
                    index += 1;
                }
                if(index == len2) {
                    count += 1;
                    index = 0;
                }
            }
            countr[i] = count;
            indexr[i] = index;
            for(int j = 0; j < i; ++j) {
                if(indexr[j] == index) {
                    int prevCount = countr[j];
                    int patternCount = (countr[i] - countr[j]) * ((n1 - 1 - j) / (i - j));
                    int remainCount = countr[j + (n1 - 1 - j) % (i - j)] - countr[j];
                    return (prevCount + patternCount + remainCount) / n2;
                }
            }
        }
        return countr[n1-1] / n2;
    }
};

```

# All Possible Full Binary Trees

## Description

A *full binary tree* is a binary tree where each node has exactly 0 or 2 children.

Return a list of all possible full binary trees with `N` nodes. Each element of the answer is the root node of one possible tree.

Each `node` of each tree in the answer **must** have `node.val = 0`.

You may return the final list of trees in any order.

 

**Example 1:**

```
Input: 7
Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
Explanation:
```

 

**Note:**

- `1 <= N <= 20`

## Solution

it's obviously that there is no possible full binary trees with even number of nodes. And we can generate them by recursively combine subtrees with odd-number-node.

``` cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<vector<TreeNode*>> PossibleFBTs;
    TreeNode *deepcopy(TreeNode *root) {
        if(!root) return root;
        TreeNode *newRoot = new TreeNode(0);
        newRoot->left = deepcopy(root->left);
        newRoot->right = deepcopy(root->right);
        return newRoot;
    }
    void helper(int N) {
        PossibleFBTs[1].push_back(new TreeNode(0));
        for(int n = 3; n <= N; n += 2) {
            for(int i = 1; i < n; i += 2) {
                for(auto leftNode : PossibleFBTs[i]) {
                    for(auto rightNode : PossibleFBTs[n - i - 1]) {
                        TreeNode *newRoot = new TreeNode(0);
                        newRoot->left = deepcopy(leftNode);
                        newRoot->right = deepcopy(rightNode);
                        PossibleFBTs[n].push_back(newRoot);
                    }
                }
            }
        }
    }
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        if(!(N&1)) return vector<TreeNode*>();
        PossibleFBTs.resize(N+1);
        helper(N);
        return PossibleFBTs[N];
    }
};
```

# January LeetCoding Challenge 20

## Description

**Valid Parentheses**

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.

 

**Example 1:**

```
Input: s = "()"
Output: true
```

**Example 2:**

```
Input: s = "()[]{}"
Output: true
```

**Example 3:**

```
Input: s = "(]"
Output: false
```

**Example 4:**

```
Input: s = "([)]"
Output: false
```

**Example 5:**

```
Input: s = "{[]}"
Output: true
```

 

**Constraints:**

- `1 <= s.length <= 104`
- `s` consists of parentheses only `'()[]{}'`.

## Solution

``` cpp
class Solution {
public:
    bool isValid(string s) {
        vector<char> st;
        for(auto c : s) {
            if(c == ']') {
                if(st.empty() || st.back() != '[') return false;
                st.pop_back();
            } else if(c == '}') {
                if(st.empty() || st.back() != '{') return false;
                st.pop_back();
            } else if(c == ')') {
                if(st.empty() || st.back() != '(') return false;
                st.pop_back();
            } else {
                st.push_back(c);
            }
        }
        return st.empty();
    }
};
```
