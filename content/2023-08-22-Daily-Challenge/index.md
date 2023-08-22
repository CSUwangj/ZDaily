+++
updated = 2023-08-22T19:09:23+08:00
title = "2023-08-22 Daily Challenge"
path = "2023-08-22-Daily-Challenge"
date = 2023-08-22T19:09:23+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/excel-sheet-column-title/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 22

## Description

**Excel Sheet Column Title**

<p>Given an integer <code>columnNumber</code>, return <em>its corresponding column title as it appears in an Excel sheet</em>.</p>

<p>For example:</p>

<pre>
A -&gt; 1
B -&gt; 2
C -&gt; 3
...
Z -&gt; 26
AA -&gt; 27
AB -&gt; 28 
...
</pre>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> columnNumber = 1
<strong>Output:</strong> &quot;A&quot;
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> columnNumber = 28
<strong>Output:</strong> &quot;AB&quot;
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> columnNumber = 701
<strong>Output:</strong> &quot;ZY&quot;
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= columnNumber &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  string convertToTitle(int columnNumber) {
    string answer;
    while(columnNumber) {
      if(columnNumber % 26 != 0) {
        answer.push_back(columnNumber % 26 + 'A' - 1);
      } else {
        answer.push_back('Z');
        columnNumber -= 1;
      }
      columnNumber /= 26;
    }

    reverse(answer.begin(), answer.end());
    return answer;
  }
};

// Accepted
// 19/19 cases passed (2 ms)
// Your runtime beats 49.78 % of cpp submissions
// Your memory usage beats 37.93 % of cpp submissions (5.9 MB)
```
