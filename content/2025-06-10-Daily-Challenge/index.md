+++
updated = 2025-06-10T23:44:06+08:00
title = "2025-06-10 Daily Challenge"
path = "2025-06-10-Daily-Challenge"
date = 2025-06-10T23:44:06+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 10

## Description

**Maximum Difference Between Even and Odd Frequency I**

<p>You are given a string <code>s</code> consisting of lowercase English letters.</p>

<p>Your task is to find the <strong>maximum</strong> difference <code>diff = freq(a<sub>1)</sub> - freq(a<sub>2</sub>)</code> between the frequency of characters <code>a<sub>1</sub></code> and <code>a<sub>2</sub></code> in the string such that:</p>

<ul>
	<li><code>a<sub>1</sub></code> has an <strong>odd frequency</strong> in the string.</li>
	<li><code>a<sub>2</sub></code> has an <strong>even frequency</strong> in the string.</li>
</ul>

<p>Return this <strong>maximum</strong> difference.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;aaaaabbc&quot;</span></p>

<p><strong>Output:</strong> 3</p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>The character <code>&#39;a&#39;</code> has an <strong>odd frequency</strong> of <code><font face="monospace">5</font></code><font face="monospace">,</font> and <code>&#39;b&#39;</code> has an <strong>even frequency</strong> of <code><font face="monospace">2</font></code>.</li>
	<li>The maximum difference is <code>5 - 2 = 3</code>.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;abcabcab&quot;</span></p>

<p><strong>Output:</strong> 1</p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>The character <code>&#39;a&#39;</code> has an <strong>odd frequency</strong> of <code><font face="monospace">3</font></code><font face="monospace">,</font> and <code>&#39;c&#39;</code> has an <strong>even frequency</strong> of <font face="monospace">2</font>.</li>
	<li>The maximum difference is <code>3 - 2 = 1</code>.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> consists only of lowercase English letters.</li>
	<li><code>s</code> contains at least one character with an odd frequency and one with an even frequency.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int maxDifference(string s) {
    int minEven = 100;
    int maxOdd = 0;
    vector<int> count(26);
    for(auto c : s) {
      c -= 'a';
      count[c] += 1;
    }
    for(auto c : count) {
      if(!c) continue;
      if(c % 2 == 0) {
        minEven = min(minEven, c);
      } else {
        maxOdd = max(maxOdd, c);
      }
    }
    return maxOdd - minEven;
  }
};

// Accepted
// 805/805 cases passed (3 ms)
// Your runtime beats 34.81 % of cpp submissions
// Your memory usage beats 94.49 % of cpp submissions (9.2 MB)
```
