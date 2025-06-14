+++
updated = 2025-06-15T05:43:58+08:00
title = "2025-06-14 Daily Challenge"
path = "2025-06-14-Daily-Challenge"
date = 2025-06-15T05:43:58+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 14

## Description

**Maximum Difference by Remapping a Digit**

<p>You are given an integer <code>num</code>. You know that Bob will sneakily <strong>remap</strong> one of the <code>10</code> possible digits (<code>0</code> to <code>9</code>) to another digit.</p>

<p>Return <em>the difference between the maximum and minimum&nbsp;values Bob can make by remapping&nbsp;<strong>exactly</strong> <strong>one</strong> digit in </em><code>num</code>.</p>

<p><strong>Notes:</strong></p>

<ul>
	<li>When Bob remaps a digit <font face="monospace">d1</font>&nbsp;to another digit <font face="monospace">d2</font>, Bob replaces all occurrences of <code>d1</code>&nbsp;in <code>num</code>&nbsp;with <code>d2</code>.</li>
	<li>Bob can remap a digit to itself, in which case <code>num</code>&nbsp;does not change.</li>
	<li>Bob can remap different digits for obtaining minimum and maximum values respectively.</li>
	<li>The resulting number after remapping can contain leading zeroes.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong> num = 11891
<strong>Output:</strong> 99009
<strong>Explanation:</strong> 
To achieve the maximum value, Bob can remap the digit 1 to the digit 9 to yield 99899.
To achieve the minimum value, Bob can remap the digit 1 to the digit 0, yielding 890.
The difference between these two numbers is 99009.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong> num = 90
<strong>Output:</strong> 99
<strong>Explanation:</strong>
The maximum value that can be returned by the function is 99 (if 0 is replaced by 9) and the minimum value that can be returned by the function is 0 (if 9 is replaced by 0).
Thus, we return 99.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= num &lt;= 10<sup>8</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int minMaxDifference(int num) {
    string n = to_string(num);
    string maxN = n;
    int len = n.length();
    int start = 0;
    while(start < len && maxN[start] == '9') start += 1;
    for(int i = start + 1; i < len; ++i) {
      if(maxN[i] == maxN[start]) maxN[i] = '9';
    }
    if(start < len) maxN[start] = '9';
    string minN = n;
    for(int i = 1; i < len; ++i) {
      if(minN[i] == minN[0]) minN[i] = '0';
    }
    minN[0] = '0';

    return stoi(maxN) - stoi(minN);
  }
};

// Accepted
// 214/214 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 37.33 % of cpp submissions (8.3 MB)
```
