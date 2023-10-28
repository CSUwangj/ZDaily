+++
updated = 2023-10-28T20:15:12+08:00
title = "2023-10-28 Daily Challenge"
path = "2023-10-28-Daily-Challenge"
date = 2023-10-28T20:15:12+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/count-vowels-permutation/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 28

## Description

**Count Vowels Permutation**

<p>Given an integer <code>n</code>, your task is to count how many strings of length <code>n</code> can be formed under the following rules:</p>

<ul>
	<li>Each character is a lower case vowel&nbsp;(<code>&#39;a&#39;</code>, <code>&#39;e&#39;</code>, <code>&#39;i&#39;</code>, <code>&#39;o&#39;</code>, <code>&#39;u&#39;</code>)</li>
	<li>Each vowel&nbsp;<code>&#39;a&#39;</code> may only be followed by an <code>&#39;e&#39;</code>.</li>
	<li>Each vowel&nbsp;<code>&#39;e&#39;</code> may only be followed by an <code>&#39;a&#39;</code>&nbsp;or an <code>&#39;i&#39;</code>.</li>
	<li>Each vowel&nbsp;<code>&#39;i&#39;</code> <strong>may not</strong> be followed by another <code>&#39;i&#39;</code>.</li>
	<li>Each vowel&nbsp;<code>&#39;o&#39;</code> may only be followed by an <code>&#39;i&#39;</code> or a&nbsp;<code>&#39;u&#39;</code>.</li>
	<li>Each vowel&nbsp;<code>&#39;u&#39;</code> may only be followed by an <code>&#39;a&#39;.</code></li>
</ul>

<p>Since the answer&nbsp;may be too large,&nbsp;return it modulo <code>10^9 + 7.</code></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 1
<strong>Output:</strong> 5
<strong>Explanation:</strong> All possible strings are: &quot;a&quot;, &quot;e&quot;, &quot;i&quot; , &quot;o&quot; and &quot;u&quot;.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 2
<strong>Output:</strong> 10
<strong>Explanation:</strong> All possible strings are: &quot;ae&quot;, &quot;ea&quot;, &quot;ei&quot;, &quot;ia&quot;, &quot;ie&quot;, &quot;io&quot;, &quot;iu&quot;, &quot;oi&quot;, &quot;ou&quot; and &quot;ua&quot;.
</pre>

<p><strong class="example">Example 3:&nbsp;</strong></p>

<pre>
<strong>Input:</strong> n = 5
<strong>Output:</strong> 68</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2 * 10^4</code></li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
int dp[2][5];
const int MOD = 1e9 + 7;
class Solution {
public:
  int countVowelPermutation(int n) {
    for(int i = 0; i < 5; ++i) dp[1][i] = 1;
    for(int l = 2; l <= n; ++l) {
      int parity = l & 1;
      dp[parity][3] = dp[!parity][2];
      dp[parity][4] = (dp[!parity][2] + dp[!parity][3]) % MOD;
      dp[parity][1] = (dp[!parity][2] + dp[!parity][0]) % MOD;
      dp[parity][0] = (dp[!parity][1] + dp[!parity][4]) % MOD;
      dp[parity][0] = (dp[parity][0] + dp[!parity][2]) % MOD;
      dp[parity][2] = (dp[!parity][3] + dp[!parity][1]) % MOD;
    }

    int answer = 0;
    for(int v = 0; v < 5; ++v) {
      answer += dp[n & 1][v];
      answer %= MOD;
    }
    return answer;
  }
};

// Accepted
// 43/43 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 93.61 % of cpp submissions (5.9 MB)
```
