+++
updated = 2025-11-16T18:15:21+01:00
title = "2025-11-16 Daily Challenge"
path = "2025-11-16-Daily-Challenge"
date = 2025-11-16T18:15:21+01:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/number-of-substrings-with-only-1s/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 16

## Description

**Number of Substrings With Only 1s**

<p>Given a binary string <code>s</code>, return <em>the number of substrings with all characters</em> <code>1</code><em>&#39;s</em>. Since the answer may be too large, return it modulo <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;0110111&quot;
<strong>Output:</strong> 9
<strong>Explanation:</strong> There are 9 substring in total with only 1&#39;s characters.
&quot;1&quot; -&gt; 5 times.
&quot;11&quot; -&gt; 3 times.
&quot;111&quot; -&gt; 1 time.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;101&quot;
<strong>Output:</strong> 2
<strong>Explanation:</strong> Substring &quot;1&quot; is shown 2 times in s.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;111111&quot;
<strong>Output:</strong> 21
<strong>Explanation:</strong> Each substring contains only 1&#39;s characters.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> is either <code>&#39;0&#39;</code> or <code>&#39;1&#39;</code>.</li>
</ul>


## Solution

``` cpp
class Solution {
  const int MOD = 1e9 + 7;
public:
  int numSub(string s) {
    int ones = 0;
    int answer = 0;
    for(auto c : s) {
      if(c == '1') {
        ones += 1;
        continue;
      }
      answer += 1LL * ones * (ones + 1) / 2 % MOD;
      answer %= MOD;
      ones = 0;
    }
    answer += 1LL * ones * (ones + 1) / 2 % MOD;
    answer %= MOD;
    return answer;
  }
};

// Accepted
// 56/56 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 72.24 % of cpp submissions (11.6 MB)
```
