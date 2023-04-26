+++
updated = 2023-04-26T12:28:54+08:00
title = "2023-04-26 Daily Challenge"
path = "2023-04-26-Daily-Challenge"
date = 2023-04-26T12:28:54+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/add-digits/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 26

## Description

**Add Digits**

<p>Given an integer <code>num</code>, repeatedly add all its digits until the result has only one digit, and return it.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> num = 38
<strong>Output:</strong> 2
<strong>Explanation:</strong> The process is
38 --&gt; 3 + 8 --&gt; 11
11 --&gt; 1 + 1 --&gt; 2 
Since 2 has only one digit, return it.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> num = 0
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= num &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Could you do it without any loop/recursion in <code>O(1)</code> runtime?</p>


## Solution

``` cpp
class Solution {
public:
  int addDigits(int num) {
    if(!num) return num;
    if(!(num % 9)) return 9;
    return num % 9;
  }
};

// Accepted
// 1101/1101 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 7.98 % of cpp submissions (6 MB)
```
