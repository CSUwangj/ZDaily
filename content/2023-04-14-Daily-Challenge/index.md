+++
updated = 2023-04-14T10:48:02+08:00
title = "2023-04-14 Daily Challenge"
path = "2023-04-14-Daily-Challenge"
date = 2023-04-14T10:48:02+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/longest-palindromic-subsequence/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 14

## Description

**Longest Palindromic Subsequence**

<p>Given a string <code>s</code>, find <em>the longest palindromic <strong>subsequence</strong>&#39;s length in</em> <code>s</code>.</p>

<p>A <strong>subsequence</strong> is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;bbbab&quot;
<strong>Output:</strong> 4
<strong>Explanation:</strong> One possible longest palindromic subsequence is &quot;bbbb&quot;.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;cbbd&quot;
<strong>Output:</strong> 2
<strong>Explanation:</strong> One possible longest palindromic subsequence is &quot;bb&quot;.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> consists only of lowercase English letters.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int longestPalindromeSubseq(string s) {
    int len = s.length();
    vector<int> dp(len), dp_(len), dp__(len);

    for(int l = 1; l <= len; ++l) {
      for(int i = 0; i < len - l + 1; ++i) {
        int j = i + l - 1;
        if(l == 1) {
          dp[j] = 1;
        } else if(s[i] == s[j]) {
          dp[j] = dp__[j - 1] + 2;
        } else {
          dp[j] = max(dp_[j], dp_[j - 1]);
        }
      }
      swap(dp__, dp_);
      dp_ = dp;
    }
    
    return dp.back();
  }
};

// Accepted
// 86/86 cases passed (80 ms)
// Your runtime beats 88.97 % of cpp submissions
// Your memory usage beats 88.37 % of cpp submissions (6.7 MB)
```
