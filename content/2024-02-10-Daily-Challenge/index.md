+++
updated = 2024-02-10T17:20:30+08:00
title = "2024-02-10 Daily Challenge"
path = "2024-02-10-Daily-Challenge"
date = 2024-02-10T17:20:30+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/palindromic-substrings/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 10

## Description

**Palindromic Substrings**

<p>Given a string <code>s</code>, return <em>the number of <strong>palindromic substrings</strong> in it</em>.</p>

<p>A string is a <strong>palindrome</strong> when it reads the same backward as forward.</p>

<p>A <strong>substring</strong> is a contiguous sequence of characters within the string.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;abc&quot;
<strong>Output:</strong> 3
<strong>Explanation:</strong> Three palindromic strings: &quot;a&quot;, &quot;b&quot;, &quot;c&quot;.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;aaa&quot;
<strong>Output:</strong> 6
<strong>Explanation:</strong> Six palindromic strings: &quot;a&quot;, &quot;a&quot;, &quot;a&quot;, &quot;aa&quot;, &quot;aa&quot;, &quot;aaa&quot;.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int countSubstrings(string s) {
    int dp[1001][1001] = {0};
    int len = s.length();
    int answer = len;
    for(int i = 0; i < len; ++i) {
      dp[i][i] = 1;
      dp[i][i + 1] = 1;
    }
    for(int l = 2; l <= len; ++l) {
      for(int j = 0; j + l <= len; ++j) {
        if(dp[j + 1][j + l - 1] && s[j] == s[j + l - 1]) {
          dp[j][j + l] = 1;
          answer += 1;
        }
      }
    }
    return answer;
  }
};

// Accepted
// 130/130 cases passed (19 ms)
// Your runtime beats 31.99 % of cpp submissions
// Your memory usage beats 52.79 % of cpp submissions (11.9 MB)
```
