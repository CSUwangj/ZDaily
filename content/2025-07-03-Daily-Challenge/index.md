+++
updated = 2025-07-03T18:07:31+08:00
title = "2025-07-03 Daily Challenge"
path = "2025-07-03-Daily-Challenge"
date = 2025-07-03T18:07:31+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 3

## Description

**Find the K-th Character in String Game I**

<p>Alice and Bob are playing a game. Initially, Alice has a string <code>word = &quot;a&quot;</code>.</p>

<p>You are given a <strong>positive</strong> integer <code>k</code>.</p>

<p>Now Bob will ask Alice to perform the following operation <strong>forever</strong>:</p>

<ul>
	<li>Generate a new string by <strong>changing</strong> each character in <code>word</code> to its <strong>next</strong> character in the English alphabet, and <strong>append</strong> it to the <em>original</em> <code>word</code>.</li>
</ul>

<p>For example, performing the operation on <code>&quot;c&quot;</code> generates <code>&quot;cd&quot;</code> and performing the operation on <code>&quot;zb&quot;</code> generates <code>&quot;zbac&quot;</code>.</p>

<p>Return the value of the <code>k<sup>th</sup></code> character in <code>word</code>, after enough operations have been done for <code>word</code> to have <strong>at least</strong> <code>k</code> characters.</p>

<p><strong>Note</strong> that the character <code>&#39;z&#39;</code> can be changed to <code>&#39;a&#39;</code> in the operation.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">k = 5</span></p>

<p><strong>Output:</strong> <span class="example-io">&quot;b&quot;</span></p>

<p><strong>Explanation:</strong></p>

<p>Initially, <code>word = &quot;a&quot;</code>. We need to do the operation three times:</p>

<ul>
	<li>Generated string is <code>&quot;b&quot;</code>, <code>word</code> becomes <code>&quot;ab&quot;</code>.</li>
	<li>Generated string is <code>&quot;bc&quot;</code>, <code>word</code> becomes <code>&quot;abbc&quot;</code>.</li>
	<li>Generated string is <code>&quot;bccd&quot;</code>, <code>word</code> becomes <code>&quot;abbcbccd&quot;</code>.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">k = 10</span></p>

<p><strong>Output:</strong> <span class="example-io">&quot;c&quot;</span></p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= 500</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  char kthCharacter(int k) {
    char result = 0;
    int base = 1;
    int exp = 0;
    for(; base < k ; base *= 2) {
      base *= 2;
    }
    base /= 2;
    while(base) {
      if(k > base) {
        k -= base;
        result += 1;
        result %= 26;
      }
      base /= 2;
    }
    return result + 'a';
  }
};

// Accepted
// 502/502 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 100 % of cpp submissions (7.6 MB)
```

then I found that it's actually the sum of the count of lower zero bits and count of one bits minus one.

``` cpp
class Solution {
public:
  char kthCharacter(int k) {
    return __builtin_popcount(k) + __builtin_ffs(k) - 2 + 'a';
  }
};

// Accepted
// 502/502 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 100 % of cpp submissions (7.6 MB)
```
