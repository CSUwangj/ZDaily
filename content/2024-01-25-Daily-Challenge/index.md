+++
updated = 2024-01-25T10:36:17+08:00
title = "2024-01-25 Daily Challenge"
path = "2024-01-25-Daily-Challenge"
date = 2024-01-25T10:36:17+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/longest-common-subsequence/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 25

## Description

**Longest Common Subsequence**

<p>Given two strings <code>text1</code> and <code>text2</code>, return <em>the length of their longest <strong>common subsequence</strong>. </em>If there is no <strong>common subsequence</strong>, return <code>0</code>.</p>

<p>A <strong>subsequence</strong> of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.</p>

<ul>
	<li>For example, <code>&quot;ace&quot;</code> is a subsequence of <code>&quot;abcde&quot;</code>.</li>
</ul>

<p>A <strong>common subsequence</strong> of two strings is a subsequence that is common to both strings.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> text1 = &quot;abcde&quot;, text2 = &quot;ace&quot; 
<strong>Output:</strong> 3  
<strong>Explanation:</strong> The longest common subsequence is &quot;ace&quot; and its length is 3.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> text1 = &quot;abc&quot;, text2 = &quot;abc&quot;
<strong>Output:</strong> 3
<strong>Explanation:</strong> The longest common subsequence is &quot;abc&quot; and its length is 3.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> text1 = &quot;abc&quot;, text2 = &quot;def&quot;
<strong>Output:</strong> 0
<strong>Explanation:</strong> There is no such common subsequence, so the result is 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= text1.length, text2.length &lt;= 1000</code></li>
	<li><code>text1</code> and <code>text2</code> consist of only lowercase English characters.</li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  int dp[2][1001] = {};
public:
  int longestCommonSubsequence(string text1, string text2) {
    int len1 = text1.length();
    int len2 = text2.length();
    for(int i = 0; i < len1; ++i) {
      int parity =  i & 1;
      for(int j = 0; j < len2; ++j) {
        dp[parity][j + 1] = max({dp[!parity][j + 1], dp[parity][j], dp[!parity][j] + (text1[i] == text2[j])});
      }
    }
    return dp[~len1 & 1][len2];
  }
};

// Accepted
// 47/47 cases passed (20 ms)
// Your runtime beats 90.94 % of cpp submissions
// Your memory usage beats 87.25 % of cpp submissions (8.3 MB)
```
