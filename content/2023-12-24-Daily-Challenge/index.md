+++
updated = 2023-12-24T17:35:35+08:00
title = "2023-12-24 Daily Challenge"
path = "2023-12-24-Daily-Challenge"
date = 2023-12-24T17:35:35+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 24

## Description

**Minimum Changes To Make Alternating Binary String**

<p>You are given a string <code>s</code> consisting only of the characters <code>&#39;0&#39;</code> and <code>&#39;1&#39;</code>. In one operation, you can change any <code>&#39;0&#39;</code> to <code>&#39;1&#39;</code> or vice versa.</p>

<p>The string is called alternating if no two adjacent characters are equal. For example, the string <code>&quot;010&quot;</code> is alternating, while the string <code>&quot;0100&quot;</code> is not.</p>

<p>Return <em>the <strong>minimum</strong> number of operations needed to make</em> <code>s</code> <em>alternating</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;0100&quot;
<strong>Output:</strong> 1
<strong>Explanation:</strong> If you change the last character to &#39;1&#39;, s will be &quot;0101&quot;, which is alternating.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;10&quot;
<strong>Output:</strong> 0
<strong>Explanation:</strong> s is already alternating.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;1111&quot;
<strong>Output:</strong> 2
<strong>Explanation:</strong> You need two operations to reach &quot;0101&quot; or &quot;1010&quot;.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s[i]</code> is either <code>&#39;0&#39;</code> or <code>&#39;1&#39;</code>.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int minOperations(string s) {
    if(s.length() == 1) return 0;
    int count = 0;
    for(int i = 0; i < s.length(); ++i) {
      if(s[i] == (i & 1) + '0') count += 1;
    }
    return min<int>(count, s.length() - count);
  }
};

// Accepted
// 89/89 cases passed (6 ms)
// Your runtime beats 35.61 % of cpp submissions
// Your memory usage beats 86.65 % of cpp submissions (7.2 MB)

```
