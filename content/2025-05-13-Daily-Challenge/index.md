+++
updated = 2025-05-14T01:58:25+08:00
title = "2025-05-13 Daily Challenge"
path = "2025-05-13-Daily-Challenge"
date = 2025-05-14T01:58:25+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/total-characters-in-string-after-transformations-i/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 13

## Description

**Total Characters in String After Transformations I**

<p>You are given a string <code>s</code> and an integer <code>t</code>, representing the number of <strong>transformations</strong> to perform. In one <strong>transformation</strong>, every character in <code>s</code> is replaced according to the following rules:</p>

<ul>
	<li>If the character is <code>&#39;z&#39;</code>, replace it with the string <code>&quot;ab&quot;</code>.</li>
	<li>Otherwise, replace it with the <strong>next</strong> character in the alphabet. For example, <code>&#39;a&#39;</code> is replaced with <code>&#39;b&#39;</code>, <code>&#39;b&#39;</code> is replaced with <code>&#39;c&#39;</code>, and so on.</li>
</ul>

<p>Return the <strong>length</strong> of the resulting string after <strong>exactly</strong> <code>t</code> transformations.</p>

<p>Since the answer may be very large, return it <strong>modulo</strong><!-- notionvc: eb142f2b-b818-4064-8be5-e5a36b07557a --> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;abcyy&quot;, t = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">7</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li><strong>First Transformation (t = 1)</strong>:

	<ul>
		<li><code>&#39;a&#39;</code> becomes <code>&#39;b&#39;</code></li>
		<li><code>&#39;b&#39;</code> becomes <code>&#39;c&#39;</code></li>
		<li><code>&#39;c&#39;</code> becomes <code>&#39;d&#39;</code></li>
		<li><code>&#39;y&#39;</code> becomes <code>&#39;z&#39;</code></li>
		<li><code>&#39;y&#39;</code> becomes <code>&#39;z&#39;</code></li>
		<li>String after the first transformation: <code>&quot;bcdzz&quot;</code></li>
	</ul>
	</li>
	<li><strong>Second Transformation (t = 2)</strong>:
	<ul>
		<li><code>&#39;b&#39;</code> becomes <code>&#39;c&#39;</code></li>
		<li><code>&#39;c&#39;</code> becomes <code>&#39;d&#39;</code></li>
		<li><code>&#39;d&#39;</code> becomes <code>&#39;e&#39;</code></li>
		<li><code>&#39;z&#39;</code> becomes <code>&quot;ab&quot;</code></li>
		<li><code>&#39;z&#39;</code> becomes <code>&quot;ab&quot;</code></li>
		<li>String after the second transformation: <code>&quot;cdeabab&quot;</code></li>
	</ul>
	</li>
	<li><strong>Final Length of the string</strong>: The string is <code>&quot;cdeabab&quot;</code>, which has 7 characters.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;azbk&quot;, t = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">5</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li><strong>First Transformation (t = 1)</strong>:

	<ul>
		<li><code>&#39;a&#39;</code> becomes <code>&#39;b&#39;</code></li>
		<li><code>&#39;z&#39;</code> becomes <code>&quot;ab&quot;</code></li>
		<li><code>&#39;b&#39;</code> becomes <code>&#39;c&#39;</code></li>
		<li><code>&#39;k&#39;</code> becomes <code>&#39;l&#39;</code></li>
		<li>String after the first transformation: <code>&quot;babcl&quot;</code></li>
	</ul>
	</li>
	<li><strong>Final Length of the string</strong>: The string is <code>&quot;babcl&quot;</code>, which has 5 characters.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consists only of lowercase English letters.</li>
	<li><code>1 &lt;= t &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
  const int MOD = 1e9 + 7;
public:
  int lengthAfterTransformations(string s, int t) {
    vector<int> dp(26);
    for(auto c : s) {
      dp[c - 'a'] += 1;
    }
    for(int i = 0; i < t; ++i) {
      rotate(dp.rbegin(), dp.rbegin() + 1, dp.rend());
      dp[1] += dp[0];
      dp[1] %= MOD;
    }
    int answer = 0;
    for(int i = 0; i < 26; ++i) {
      answer += dp[i];
      answer %= MOD;
    }
    return answer;
  }
};

// Accepted
// 824/824 cases passed (261 ms)
// Your runtime beats 59.11 % of cpp submissions
// Your memory usage beats 65.52 % of cpp submissions (20.4 MB)
```
