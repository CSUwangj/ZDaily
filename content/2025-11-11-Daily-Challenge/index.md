+++
updated = 2025-11-11T08:23:08+01:00
title = "2025-11-11 Daily Challenge"
path = "2025-11-11-Daily-Challenge"
date = 2025-11-11T08:23:08+01:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/ones-and-zeroes/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 11

## Description

**Ones and Zeroes**

<p>You are given an array of binary strings <code>strs</code> and two integers <code>m</code> and <code>n</code>.</p>

<p>Return <em>the size of the largest subset of <code>strs</code> such that there are <strong>at most</strong> </em><code>m</code><em> </em><code>0</code><em>&#39;s and </em><code>n</code><em> </em><code>1</code><em>&#39;s in the subset</em>.</p>

<p>A set <code>x</code> is a <strong>subset</strong> of a set <code>y</code> if all elements of <code>x</code> are also elements of <code>y</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> strs = [&quot;10&quot;,&quot;0001&quot;,&quot;111001&quot;,&quot;1&quot;,&quot;0&quot;], m = 5, n = 3
<strong>Output:</strong> 4
<strong>Explanation:</strong> The largest subset with at most 5 0&#39;s and 3 1&#39;s is {&quot;10&quot;, &quot;0001&quot;, &quot;1&quot;, &quot;0&quot;}, so the answer is 4.
Other valid but smaller subsets include {&quot;0001&quot;, &quot;1&quot;} and {&quot;10&quot;, &quot;1&quot;, &quot;0&quot;}.
{&quot;111001&quot;} is an invalid subset because it contains 4 1&#39;s, greater than the maximum of 3.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> strs = [&quot;10&quot;,&quot;0&quot;,&quot;1&quot;], m = 1, n = 1
<strong>Output:</strong> 2
<b>Explanation:</b> The largest subset is {&quot;0&quot;, &quot;1&quot;}, so the answer is 2.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= strs.length &lt;= 600</code></li>
	<li><code>1 &lt;= strs[i].length &lt;= 100</code></li>
	<li><code>strs[i]</code> consists only of digits <code>&#39;0&#39;</code> and <code>&#39;1&#39;</code>.</li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    int len = strs.size();
    int count[len][2];
    for(int i = 0; i < len; ++i) {
      count[i][0] = 0;
      count[i][1] = 0;
      for(auto c : strs[i]) count[i][c == '1'] += 1;
    }
    int dp[m + 1][n + 1];
    for(int i = 0; i <= m; ++i) {
      for(int j = 0; j <= n; ++j) dp[i][j] = -1;
    }
    int answer = 0;
    dp[0][0] = 0;
    for(int i = 0; i < len; ++i) {
      for(int zero = m; zero >= count[i][0]; --zero) {
        for(int one = n; one >= count[i][1]; --one) {
          if(dp[zero - count[i][0]][one - count[i][1]] == -1) continue;
          dp[zero][one] = max(dp[zero - count[i][0]][one - count[i][1]] + 1, dp[zero][one]);
          answer = max(answer, dp[zero][one]);
        }
      }
    }
    
    return answer;
  }
};

// Accepted
// 77/77 cases passed (26 ms)
// Your runtime beats 98.6 % of cpp submissions
// Your memory usage beats 99.95 % of cpp submissions (12 MB)
```
