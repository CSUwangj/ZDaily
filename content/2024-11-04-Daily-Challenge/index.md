+++
updated = 2024-11-04T10:53:21+08:00
title = "2024-11-04 Daily Challenge"
path = "2024-11-04-Daily-Challenge"
date = 2024-11-04T10:53:21+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/string-compression-iii/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 4

## Description

**String Compression III**

<p>Given a string <code>word</code>, compress it using the following algorithm:</p>

<ul>
	<li>Begin with an empty string <code>comp</code>. While <code>word</code> is <strong>not</strong> empty, use the following operation:

	<ul>
		<li>Remove a maximum length prefix of <code>word</code> made of a <em>single character</em> <code>c</code> repeating <strong>at most</strong> 9 times.</li>
		<li>Append the length of the prefix followed by <code>c</code> to <code>comp</code>.</li>
	</ul>
	</li>
</ul>

<p>Return the string <code>comp</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">word = &quot;abcde&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">&quot;1a1b1c1d1e&quot;</span></p>

<p><strong>Explanation:</strong></p>

<p>Initially, <code>comp = &quot;&quot;</code>. Apply the operation 5 times, choosing <code>&quot;a&quot;</code>, <code>&quot;b&quot;</code>, <code>&quot;c&quot;</code>, <code>&quot;d&quot;</code>, and <code>&quot;e&quot;</code> as the prefix in each operation.</p>

<p>For each prefix, append <code>&quot;1&quot;</code> followed by the character to <code>comp</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">word = &quot;aaaaaaaaaaaaaabb&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">&quot;9a5a2b&quot;</span></p>

<p><strong>Explanation:</strong></p>

<p>Initially, <code>comp = &quot;&quot;</code>. Apply the operation 3 times, choosing <code>&quot;aaaaaaaaa&quot;</code>, <code>&quot;aaaaa&quot;</code>, and <code>&quot;bb&quot;</code> as the prefix in each operation.</p>

<ul>
	<li>For prefix <code>&quot;aaaaaaaaa&quot;</code>, append <code>&quot;9&quot;</code> followed by <code>&quot;a&quot;</code> to <code>comp</code>.</li>
	<li>For prefix <code>&quot;aaaaa&quot;</code>, append <code>&quot;5&quot;</code> followed by <code>&quot;a&quot;</code> to <code>comp</code>.</li>
	<li>For prefix <code>&quot;bb&quot;</code>, append <code>&quot;2&quot;</code> followed by <code>&quot;b&quot;</code> to <code>comp</code>.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>word</code> consists only of lowercase English letters.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  string compressedString(string word) {
    string answer;
    char cur = word.front();
    int count = 0;
    for(auto c : word) {
      if(count == 9 || cur != c) {
        answer.push_back(count + '0');
        answer.push_back(cur);
        count = 0;
        cur = c;
      }
      if(cur == c) {
        count += 1;
      }
    }
    answer.push_back(count + '0');
    answer.push_back(cur);
    return answer;
  }
};
```
