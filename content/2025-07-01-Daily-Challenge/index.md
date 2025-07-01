+++
updated = 2025-07-01T14:23:35+08:00
title = "2025-07-01 Daily Challenge"
path = "2025-07-01-Daily-Challenge"
date = 2025-07-01T14:23:35+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/find-the-original-typed-string-i/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 1

## Description

**Find the Original Typed String I**

<p>Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and <strong>may</strong> press a key for too long, resulting in a character being typed <strong>multiple</strong> times.</p>

<p>Although Alice tried to focus on her typing, she is aware that she may still have done this <strong>at most</strong> <em>once</em>.</p>

<p>You are given a string <code>word</code>, which represents the <strong>final</strong> output displayed on Alice&#39;s screen.</p>

<p>Return the total number of <em>possible</em> original strings that Alice <em>might</em> have intended to type.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">word = &quot;abbcccc&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">5</span></p>

<p><strong>Explanation:</strong></p>

<p>The possible strings are: <code>&quot;abbcccc&quot;</code>, <code>&quot;abbccc&quot;</code>, <code>&quot;abbcc&quot;</code>, <code>&quot;abbc&quot;</code>, and <code>&quot;abcccc&quot;</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">word = &quot;abcd&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<p>The only possible string is <code>&quot;abcd&quot;</code>.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">word = &quot;aaaa&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">4</span></p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 100</code></li>
	<li><code>word</code> consists only of lowercase English letters.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int possibleStringCount(string word) {
    char prev = 0;
    int answer = 1;
    for(auto c : word) {
      answer += (c == prev);
      prev = c;
    }
    return answer;
  }
};

// Accepted
// 780/780 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 29.69 % of cpp submissions (8.9 MB)
```
