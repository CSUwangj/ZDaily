+++
title = "2020-12-09 Daily-Challenge"
path = "2020-12-09-Daily-Challenge"
date = 2020-12-09 21:01:34+08:00
updated = 2020-12-09 22:03:38+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/) and [Distinct Subsequences II](https://leetcode.com/problems/distinct-subsequences-ii/) on leetcode and leetcode's [December LeetCoding Challenge](https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/570/week-2-december-8th-december-14th/3560/) with `cpp`.

<!-- more -->

# Distinct Subsequences

## Description

Given two strings `s` and `t`, return *the number of distinct subsequences of `s` which equals `t`*.

A string's **subsequence** is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., `"ACE"` is a subsequence of `"ABCDE"` while `"AEC"` is not).

It's guaranteed the answer fits on a 32-bit signed integer.

**Example 1:**

```
Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from S.
rabbbit
rabbbit
rabbbit
```

**Example 2:**

```
Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from S.
babgbag
babgbag
babgbag
babgbag
babgbag
```

**Constraints:**

- `0 <= s.length, t.length <= 1000`
- `s` and `t` consist of English letters.

## Solution

LCS DP, but I forgot it... fuck

``` cpp
class Solution {
public:
  int numDistinct(string s, string t) {
    int slen = s.length();
    int tlen = t.length();
    if(slen <= tlen) return s == t;
    vector<vector<long long>> dp(slen+1, vector<long long>(tlen+1));
    for(int i = 0; i <= slen; ++i) {
      dp[i][0] = 1;
    }
    for(int i = 1; i <= slen; ++i) {
      for(int j = max(1, tlen+i-slen-1); j <= min(slen-tlen+i, tlen); ++j) {
        dp[i][j] = dp[i-1][j];
        if(s[i-1] == t[j-1]) dp[i][j] += dp[i-1][j-1];
      }
    }
    return dp.back().back();
  }
};
```

# Distinct Subsequences II

## Description

Given a string `S`, count the number of distinct, non-empty subsequences of `S` .

Since the result may be large, **return the answer modulo `10^9 + 7`**.

**Example 1:**

```
Input: "abc"
Output: 7
Explanation: The 7 distinct subsequences are "a", "b", "c", "ab", "ac", "bc", and "abc".
```

**Example 2:**

```
Input: "aba"
Output: 6
Explanation: The 6 distinct subsequences are "a", "b", "ab", "ba", "aa" and "aba".
```

**Example 3:**

```
Input: "aaa"
Output: 3
Explanation: The 3 distinct subsequences are "a", "aa" and "aaa".
```

**Note:**

1. `S` contains only lowercase letters.
2. `1 <= S.length <= 2000`

## Solution

little thing similar to previous problem, check solution for more information.

``` cpp
class Solution {
public:
    int distinctSubseqII(string S) {
        const int MOD = 1000000007;
        int len = S.length();
        vector<int> dp(len+1);
        dp[0] = 1;
        vector<int> last(26, -1);
        for(int i = 1; i <= len; ++i) {
            dp[i] = dp[i-1] * 2 % MOD;
            int c = S[i-1] - 'a';
            if(last[c] != -1) {
                dp[i] -= dp[last[c]];
            }
            dp[i] = (dp[i] + MOD) % MOD;
            last[c] = i-1;
        }
        dp[len] = (dp[len] - 1 + MOD) % MOD;
        return dp.back();
    }
};
```

# December LeetCoding Challenge 9

## Description

**Binary Search Tree Iterator**

Implement the `BSTIterator` class that represents an iterator over the **[in-order traversal](https://en.wikipedia.org/wiki/Tree_traversal#In-order_(LNR))** of a binary search tree (BST):

- `BSTIterator(TreeNode root)` Initializes an object of the `BSTIterator` class. The `root` of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
- `boolean hasNext()` Returns `true` if there exists a number in the traversal to the right of the pointer, otherwise returns `false`.
- `int next()` Moves the pointer to the right, then returns the number at the pointer.

Notice that by initializing the pointer to a non-existent smallest number, the first call to `next()` will return the smallest element in the BST.

You may assume that `next()` calls will always be valid. That is, there will be at least a next number in the in-order traversal when `next()` is called.

**Example 1:**

![img](https://assets.leetcode.com/uploads/2018/12/25/bst-tree.png)

```
Input
["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
Output
[null, 3, 7, true, 9, true, 15, true, 20, false]

Explanation
BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
bSTIterator.next();    // return 3
bSTIterator.next();    // return 7
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 9
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 15
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 20
bSTIterator.hasNext(); // return False
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 105]`.
- `0 <= Node.val <= 106`
- At most `105` calls will be made to `hasNext`, and `next`.

**Follow up:**

- Could you implement `next()` and `hasNext()` to run in average `O(1)` time and use `O(h)` memory, where `h` is the height of the tree?

## Solution

nothing to say

``` cpp
class BSTIterator {
    vector<TreeNode*> previous;
    TreeNode* cur;
public:
    BSTIterator(TreeNode* root) {
        while(root && root->left) {
            previous.push_back(root);
            root = root->left;
        }
        cur = root;
    }
    
    int next() {
        int result = cur->val;
        if(cur->right) {
            TreeNode *root = cur->right;
            while(root && root->left) {
                previous.push_back(root);
                root = root->left;
            }
            cur = root;
        } else {
            if(previous.size()) {
                cur = previous.back();
                previous.pop_back();
            } else {
                cur = nullptr;
            }
        }
        return result;
    }
    
    bool hasNext() {
        return cur;
    }
};
```