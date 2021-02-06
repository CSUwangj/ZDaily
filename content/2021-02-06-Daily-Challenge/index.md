+++
title = "2021-02-06 Daily-Challenge"
path = "2021-02-06-Daily-Challenge"
date = 2021-02-06 16:00:59+08:00
updated = 2021-02-06 18:39:04+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Wildcard Matching](https://leetcode.com/problems/wildcard-matching/) and leetcode's [February LeetCoding Challenge](https://leetcode.com/explore/featured/card/february-leetcoding-challenge-2021/584/week-1-february-1st-february-7th/3630/) with `cpp`.

<!-- more -->

# String Compression

## Description

Given an input string (`s`) and a pattern (`p`), implement wildcard pattern matching with support for `'?'` and `'*'` where:

- `'?'` Matches any single character.
- `'*'` Matches any sequence of characters (including the empty sequence).

The matching should cover the **entire** input string (not partial).

 

**Example 1:**

```
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
```

**Example 2:**

```
Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
```

**Example 3:**

```
Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
```

**Example 4:**

```
Input: s = "adceb", p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
```

**Example 5:**

```
Input: s = "acdcb", p = "a*c?b"
Output: false
```

 

**Constraints:**

- `0 <= s.length, p.length <= 2000`
- `s` contains only lowercase English letters.
- `p` contains only lowercase English letters, `'?'` or `'*'`.

## Solution

``` cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.length(), sPos = 0;
        int pLen = p.length(), pPos = 0;
        int starPos = -1, startpPos = -1;
        while(sPos < sLen) {
            if(pPos < pLen && (p[pPos] == '?' || p[pPos] == s[sPos])) {
                sPos += 1;
                pPos += 1;
            } else if(pPos < pLen && p[pPos] == '*') {
                while(pPos < pLen && p[pPos] == '*') pPos += 1;
                starPos = sPos;
                startpPos = pPos;
            } else if(starPos != -1) {
                starPos += 1;
                sPos = starPos;
                pPos = startpPos;
            }else return false;
        }
        // cout << pPos << ' ' << sPos << ' ' << s << ' ' << p << endl;
        while(pPos < pLen && p[pPos] == '*') pPos += 1;
        return pPos == pLen;
    }
};
```

# February LeetCoding Challenge6

**Binary Tree Right Side View**

## Description

Given a binary tree, imagine yourself standing on the *right* side of it, return the values of the nodes you can see ordered from top to bottom.

**Example:**

```
Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
```

## Solution

``` cpp
class Solution {
    vector<int> answer;
    void traversal(TreeNode* root, int level) {
        if(!root) return;
        if(level > answer.size()) answer.push_back(root->val);
        traversal(root->right, level + 1);
        traversal(root->left, level + 1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        traversal(root, 1);
        return move(answer);
    }
};
```