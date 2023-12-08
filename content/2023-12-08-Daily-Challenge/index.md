+++
updated = 2023-12-08T18:58:04+08:00
title = "2023-12-08 Daily Challenge"
path = "2023-12-08-Daily-Challenge"
date = 2023-12-08T18:58:04+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/construct-string-from-binary-tree/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 8

## Description

**Construct String from Binary Tree**

<p>Given the <code>root</code> of a binary tree, construct a string consisting of parenthesis and integers from a binary tree with the preorder traversal way, and return it.</p>

<p>Omit all the empty parenthesis pairs that do not affect the one-to-one mapping relationship between the string and the original binary tree.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/03/cons1-tree.jpg" style="width: 292px; height: 301px;" />
<pre>
<strong>Input:</strong> root = [1,2,3,4]
<strong>Output:</strong> &quot;1(2(4))(3)&quot;
<strong>Explanation:</strong> Originally, it needs to be &quot;1(2(4)())(3()())&quot;, but you need to omit all the unnecessary empty parenthesis pairs. And it will be &quot;1(2(4))(3)&quot;
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/03/cons2-tree.jpg" style="width: 207px; height: 293px;" />
<pre>
<strong>Input:</strong> root = [1,2,3,null,4]
<strong>Output:</strong> &quot;1(2()(4))(3)&quot;
<strong>Explanation:</strong> Almost the same as the first example, except we cannot omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>4</sup>]</code>.</li>
	<li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  string largestOddNumber(string num) {
    int begin = 0;
    while(begin < num.length() && !(num[begin] - '0')) {
      begin += 1;
    }
    int end = begin - 1;
    for(int i = begin; i < num.length(); ++i) {
      if((num[i] - '0') & 1) {
        end = i;
      }
    }
    return num.substr(begin, end - begin + 1);
  }
};

// Accepted
// 196/196 cases passed (32 ms)
// Your runtime beats 31.44 % of cpp submissions
// Your memory usage beats 24.39 % of cpp submissions (15.4 MB)
```
