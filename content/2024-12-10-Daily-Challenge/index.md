+++
updated = 2024-12-10T20:18:06+08:00
title = "2024-12-10 Daily Challenge"
path = "2024-12-10-Daily-Challenge"
date = 2024-12-10T20:18:06+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 10

## Description

**Find Longest Special Substring That Occurs Thrice I**

<p>You are given a string <code>s</code> that consists of lowercase English letters.</p>

<p>A string is called <strong>special</strong> if it is made up of only a single character. For example, the string <code>&quot;abc&quot;</code> is not special, whereas the strings <code>&quot;ddd&quot;</code>, <code>&quot;zz&quot;</code>, and <code>&quot;f&quot;</code> are special.</p>

<p>Return <em>the length of the <strong>longest special substring</strong> of </em><code>s</code> <em>which occurs <strong>at least thrice</strong></em>, <em>or </em><code>-1</code><em> if no special substring occurs at least thrice</em>.</p>

<p>A <strong>substring</strong> is a contiguous <strong>non-empty</strong> sequence of characters within a string.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;aaaa&quot;
<strong>Output:</strong> 2
<strong>Explanation:</strong> The longest special substring which occurs thrice is &quot;aa&quot;: substrings &quot;<u><strong>aa</strong></u>aa&quot;, &quot;a<u><strong>aa</strong></u>a&quot;, and &quot;aa<u><strong>aa</strong></u>&quot;.
It can be shown that the maximum length achievable is 2.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;abcdef&quot;
<strong>Output:</strong> -1
<strong>Explanation:</strong> There exists no special substring which occurs at least thrice. Hence return -1.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;abcaba&quot;
<strong>Output:</strong> 1
<strong>Explanation:</strong> The longest special substring which occurs thrice is &quot;a&quot;: substrings &quot;<u><strong>a</strong></u>bcaba&quot;, &quot;abc<u><strong>a</strong></u>ba&quot;, and &quot;abcab<u><strong>a</strong></u>&quot;.
It can be shown that the maximum length achievable is 1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= s.length &lt;= 50</code></li>
	<li><code>s</code> consists of only lowercase English letters.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int maximumLength(string s) {
    unordered_map<string, int> count;
    for(int i = 0; i < s.length(); ++i) {
      for(int j = 1; i + j <= s.length() && s[i + j - 1] == s[i]; ++j) {
        count[s.substr(i, j)] += 1;
      }
    }
    string answer;
    for(const auto &[s, c] : count) {
      if(c > 2 && s.length() > answer.length()) answer = s;
    }
    return answer.length() ? answer.length() : -1;
  }
};

// Accepted
// 811/811 cases passed (15 ms)
// Your runtime beats 51.48 % of cpp submissions
// Your memory usage beats 62.59 % of cpp submissions (12.4 MB)
```
