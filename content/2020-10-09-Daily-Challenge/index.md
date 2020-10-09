+++
title = "2020-10-09 Daily-Challenge"
path = "2020-10-09-Daily-Challenge"
date = 2020-10-09 01:15:46+08:00
updated = 2020-10-09 16:10:28+08:00
in_search_index = true

[taxonomies]
tags = ["Design", "Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is an example of *The non-Designer's Design Book* on bottom of Page 82 and *Remove Outermost Parentheses* on [leetcode](https://leetcode.com/problems/queries-on-a-permutation-with-key/) and leetcode's [October LeetCoding Challenge](https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/560/week-2-october-8th-october-14th/3489/) with `cpp`.

<!-- more -->

# The non-Designer's Design Book

my answer:

- [ ] extract `resume`
- [ ] left align
- [ ] change font to interesting fonts
- [ ] remove border so it looks less restrained
- [ ] title with bold font and same indent
- [ ] distance between text and upper、bottom border
- [ ] title is closer to the corresponding text

# Remove Outermost Parentheses

## Description

A valid parentheses string is either empty `("")`, `"(" + A + ")"`, or `A + B`, where `A` and `B` are valid parentheses strings, and `+` represents string concatenation. For example, `""`, `"()"`, `"(())()"`, and `"(()(()))"` are all valid parentheses strings.

A valid parentheses string `S` is **primitive** if it is nonempty, and there does not exist a way to split it into `S = A+B`, with `A` and `B` nonempty valid parentheses strings.

Given a valid parentheses string `S`, consider its primitive decomposition: `S = P_1 + P_2 + ... + P_k`, where `P_i` are primitive valid parentheses strings.

Return `S` after removing the outermost parentheses of every primitive string in the primitive decomposition of `S`.

**Example 1:**

```
Input: "(()())(())"
Output: "()()()"
Explanation: 
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".
```

**Example 2:**

```
Input: "(()())(())(()(()))"
Output: "()()()()(())"
Explanation: 
The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".
```

**Example 3:**

```
Input: "()()"
Output: ""
Explanation: 
The input string is "()()", with primitive decomposition "()" + "()".
After removing outer parentheses of each part, this is "" + "" = "".
```

**Note:**

1. `S.length <= 10000`
2. `S[i]` is `"("` or `")"`
3. `S` is a valid parentheses string

## Solution

``` cpp
class Solution {
public:
  string removeOuterParentheses(string S) {
    stringstream ss;
    int cnt = 0;
    for(int i = 0; i < S.length(); ++i) {
      if(S[i] == '(') {
        if(cnt) ss << S[i];
        cnt += 1;
      } else {
        cnt -= 1;
        if(cnt) ss << S[i];
      }
    }
    return ss.str();
  }
};
```

# October LeetCoding Challenge9

## Description

**Serialize and Deserialize BST**

Serialization is converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a **binary search tree**. There is no restriction on how your serialization/deserialization algorithm should work. You need to ensure that a binary search tree can be serialized to a string, and this string can be deserialized to the original tree structure.

**The encoded string should be as compact as possible.**

**Example 1:**

```
Input: root = [2,1,3]
Output: [2,1,3]
```

**Example 2:**

```
Input: root = []
Output: []
```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 104]`.
- `0 <= Node.val <= 104`
- The input tree is **guaranteed** to be a binary search tree.

## Solution

using UTF8-like encoding, use

|Number of bytes|First code point|Last code point|Byte 1	|Byte 2|
|---|---|---|---|---|
|1	|U+0000|	U+007F|	0xxxxxxx	|  |
|2	|U+0080|	U+07FF|	1xxxxxxx (except for 11111111)|1xxxxxxx	|

because the maximum is $10^4$ which is less than `1111111100000000`, so I use single byte `0xFF` for null node.

because there is no intersection between codes of nodes, so just put encoded nodes in level order.

``` cpp
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()) {
            TreeNode *cur = q.front();
            q.pop();
            if(!cur) {
                s += 0xff;
                continue;
            } else if (cur->val < 128) {
                s += cur->val;
            } else {
                s += 0x80 | (cur->val / 0b10000000);
                s += 0x80 | (cur->val % 0b10000000);
            }
            q.push(cur->left);
            q.push(cur->right);
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 1) return NULL;
        TreeNode* root = new TreeNode(0);
        queue<TreeNode*> q;
        q.push(root);
        int cur_index = 0;
        while(q.size() && cur_index < data.length()) {
            TreeNode *cur = q.front();
            q.pop();
            uint8_t cur_char = data[cur_index];
            if(cur_char == 0xff) {
                cur->val = 10001;
                cur_index += 1;
                continue;
            } else if(cur_char < 0b10000000u) {
                cur->val = data[cur_index];
                cur_index += 1;
            } else {
                cur->val = data[cur_index]&0b01111111;
                cur->val <<= 7;
                cur->val += data[cur_index+1]&0b01111111;
                cur_index += 2;
            }
            cur->left = new TreeNode(0);
            cur->right = new TreeNode(0);
            q.push(cur->left);
            q.push(cur->right);
        }
        while(q.size()) q.pop();
        q.push(root);
        while(q.size()) {
            TreeNode *cur = q.front();
            q.pop();
            if(cur->left->val == 10001) {
                cur->left=NULL;
            } else {
                q.push(cur->left);
            }
            if(cur->right->val == 10001) {
                cur->right=NULL;
            } else {
                q.push(cur->right);
            }
        }
        return root;
    }
};
```