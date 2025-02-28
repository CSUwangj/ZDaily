+++
updated = 2025-02-28T15:34:50+08:00
title = "2025-02-28 Daily Challenge"
path = "2025-02-28-Daily-Challenge"
date = 2025-02-28T15:34:50+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/shortest-common-supersequence/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 28

## Description

**Shortest Common Supersequence **

<p>Given two strings <code>str1</code> and <code>str2</code>, return <em>the shortest string that has both </em><code>str1</code><em> and </em><code>str2</code><em> as <strong>subsequences</strong></em>. If there are multiple valid strings, return <strong>any</strong> of them.</p>

<p>A string <code>s</code> is a <strong>subsequence</strong> of string <code>t</code> if deleting some number of characters from <code>t</code> (possibly <code>0</code>) results in the string <code>s</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> str1 = &quot;abac&quot;, str2 = &quot;cab&quot;
<strong>Output:</strong> &quot;cabac&quot;
<strong>Explanation:</strong> 
str1 = &quot;abac&quot; is a subsequence of &quot;cabac&quot; because we can delete the first &quot;c&quot;.
str2 = &quot;cab&quot; is a subsequence of &quot;cabac&quot; because we can delete the last &quot;ac&quot;.
The answer provided is the shortest such string that satisfies these properties.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> str1 = &quot;aaaaaaaa&quot;, str2 = &quot;aaaaaaaa&quot;
<strong>Output:</strong> &quot;aaaaaaaa&quot;
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= str1.length, str2.length &lt;= 1000</code></li>
	<li><code>str1</code> and <code>str2</code> consist of lowercase English letters.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  string shortestCommonSupersequence(string str1, string str2) {
    int len1 = str1.length();
    int len2 = str2.length();
    vector<vector<string>> dp(2, vector<string>(len2 + 1));
    for(int i = 1; i <= len2; ++i) {
      dp[0][i] = str2.substr(0, i);
    }

    for(int i = 0; i < len1; ++i) {
      int parity = i & 1;
      dp[parity ^ 1][0] = str1.substr(0, i + 1);
      for(int j = 0; j < len2; ++j) {
        if(str1[i] == str2[j]) {
          dp[parity ^ 1][j + 1] = dp[parity][j];
          dp[parity ^ 1][j + 1].push_back(str1[i]);
        } else {
          if(dp[parity ^ 1][j].length() < dp[parity][j + 1].length()) {
            dp[parity ^ 1][j + 1] = dp[parity ^ 1][j];
            dp[parity ^ 1][j + 1].push_back(str2[j]);
          } else {
            dp[parity ^ 1][j + 1] = dp[parity][j + 1];
            dp[parity ^ 1][j + 1].push_back(str1[i]);
          }
        }
      }
    }

    return dp[len1 & 1].back();
  }
};

// Accepted
// 49/49 cases passed (249 ms)
// Your runtime beats 6 % of cpp submissions
// Your memory usage beats 5.13 % of cpp submissions (35.8 MB)
```
