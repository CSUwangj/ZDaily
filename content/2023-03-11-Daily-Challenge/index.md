+++
updated = 2023-03-11T12:19:33+08:00
title = "2023-03-11 Daily Challenge"
path = "2023-03-11-Daily-Challenge"
date = 2023-03-11T12:19:33+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 11

## Description

**Convert Sorted List to Binary Search Tree**

<p>Given the <code>head</code> of a singly linked list where elements are sorted in <strong>ascending order</strong>, convert <em>it to a </em><span data-keyword="height-balanced"><strong><em>height-balanced</em></strong></span> <em>binary search tree</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/17/linked.jpg" style="width: 500px; height: 388px;" />
<pre>
<strong>Input:</strong> head = [-10,-3,0,5,9]
<strong>Output:</strong> [0,-3,9,-10,null,5]
<strong>Explanation:</strong> One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> head = []
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in <code>head</code> is in the range <code>[0, 2 * 10<sup>4</sup>]</code>.</li>
	<li><code>-10<sup>5</sup> &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
  ListNode *cur;
  
  int length(ListNode *head) {
    int len = 0;
    while(head) {
      len += 1;
      head = head->next;
    }
    return len;
  }
  
  TreeNode *buildBST(int begin, int end) {
    if(begin > end) return nullptr;
    
    int mid = (begin + end) >> 1;
    TreeNode *left = buildBST(begin, mid - 1);
    
    TreeNode *root = new TreeNode(cur->val);
    root->left = left;
    
    cur = cur->next;
    root->right = buildBST(mid + 1, end);
    
    return root;
  }
  
public:
  TreeNode* sortedListToBST(ListNode* head) {
    int len = length(head);
    cur = head;
    return buildBST(0, len-1);
  }
};

// Accepted
// 32/32 cases passed (24 ms)
// Your runtime beats 84.58 % of cpp submissions
// Your memory usage beats 71.93 % of cpp submissions (28.4 MB)
```
